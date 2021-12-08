// main.cpp file for the entry point of the controller, and managing it's behaviour.

// Common librays.
#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// FreeRTOS headers.
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Custom headers.
#include "RHT03.h"
#include "hardware.h"
#include "fan_controller.h"
#include "fan_controller_private.h"


// Global variables definition.

//Classes for controller and sensor.
RHT03 RHT;
fan_controllerModelClass controller;
fan_controllerModelClass::ExtU_fan_controller_T sensorInput;
fan_controllerModelClass::ExtY_fan_controller_T controllerOutput;
fan_controllerModelClass::P_fan_controller_T parameters;
 

// Controller power variable.
bool power = true;


// Main behaviour variables.
float extractorState = 0;
float currentHumidity = 0;
float currentTemperature = 0;


// Variables for WiFi connection.(Replace with your network credentials).
const char *ssid = "***";
const char *password = "***";


//Development server and iotPlotter variables.(Replace with your values)
const char *serverName = "http://192.168.1.102:8080/upload";
const char *iotAPIKey = "086d903f4e9b8a8053c3ec2ac60c8b5c3c2fbd0653";
const char *iotPlotterFeed = "http://iotplotter.com/api/v2/feed/252680283241329865";


// Function prototypes
void sendData();
void readSensorLoop(void *pvParameters);
void controllerLoop(void *pvParameters);

// Functions 

/**
 * Set up pinmodes, parameters, begin logging data from the RHT and conncect to WiFi.
 */
void setup()
{ 
  // Set pinmodes.
  pinMode(HW_BUTTON, INPUT_PULLUP);

  pinMode(HW_LED1, OUTPUT);
  pinMode(HW_LED_R, OUTPUT);
  pinMode(HW_LED2, OUTPUT);
  pinMode(HW_LED_Y, OUTPUT);
  pinMode(HW_LED3, OUTPUT);
  pinMode(HW_LED_G, OUTPUT);

  digitalWrite(HW_LED_R, HIGH);
  digitalWrite(HW_LED_Y, HIGH);
  digitalWrite(HW_LED_G, HIGH);

  digitalWrite(HW_LED1, HIGH);
  digitalWrite(HW_LED2, HIGH);
  digitalWrite(HW_LED3, HIGH);

  Serial.begin(115200);

  // Begin logging data from the RHT.
  RHT.begin(HW_SENSOR_DATA);

  // Set controller parameters.
  parameters.DiscreteDerivative_ICPrevScaled = 50;
  parameters.DiscreteDerivative1_ICPrevScale = 25;
  parameters.Constant_Value = 0;
  parameters.UnitDelay_InitialCondition = 0;
  parameters.Constant_Value_f = 35; // Expression: initial humidity (set this to expected value).
  parameters.Downsample1_ic = 35;   // Expression: initial humidity (set this to expected value).
  parameters.Gain_Gain = 16;
  parameters.Constant1_Value = 22; // Expression: initial temperature (set this to expected value).
  parameters.Downsample_ic = 22;   // Expression: initial temperature (set this to expected value).
  parameters.Gain1_Gain = 16;
  parameters.Saturation_UpperSat = 30;
  parameters.Saturation_LowerSat = 0;
  parameters.Backlash_BacklashWidth = 2;
  parameters.Backlash_InitialOutput = 0;
  parameters.Quantizer_Interval = 30 / 4;

  controller.setBlockParameters(&parameters);
  controller.initialize();

  // Connect to WiFi.
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}


/**
 * Main loop to intialize the readSensorLoop,controllerLoop, and handle the sendData function.
 */
void loop()
{

  // Create RTOS tasks to run readSensorLoop() and controllerLoop() functions.
  xTaskCreate(readSensorLoop, "readSensorLoop", 4096, NULL, 1, NULL);
  xTaskCreate(controllerLoop, "controllerLoop", 4096, NULL, 1, NULL);

  // Data publish loop
  while (1)
  {
    sendData();

    // Send once per ~10 s
    vTaskDelay(10000 / portTICK_PERIOD_MS);
  }
}


/**
 * Function to send data the database server and to iotplotter.
 */
void sendData()
{ 
  // Check if controller power is enabled.
  if(power)
  {
    // Check if WiFi is connected.
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("Sending data");
      
      // Define HTTP and json varibles.
      WiFiClient client;
      HTTPClient http;
      StaticJsonDocument<1024> jsonDoc;
      String httpRequestData;
      int httpResponseCode;

      
      // Start HTTP channel to server.
      http.begin(client, serverName);

      // Add values to the json structure which will be sent to the server.
      jsonDoc["humidity"] = currentHumidity;
      jsonDoc["temperature"] = currentTemperature;
      jsonDoc["Requestedventpowerlevel"] = controllerOutput.Requestedventpowerlevel;
      jsonDoc["Humiditychange"] = controllerOutput.Humiditychange;
      jsonDoc["Humiditybaseline"] = controllerOutput.Humiditybaseline;
      jsonDoc["Temperaturechange"] = controllerOutput.Temperaturechange;
      jsonDoc["Temperaturebaseline"] = controllerOutput.Temperaturebaseline;
      jsonDoc["Outputenabled"] = controllerOutput.Outputenabled;

      if (controllerOutput.StateID == StatesModeType_None)
      {
        jsonDoc["StateID"] = "None";
      }
      else if (controllerOutput.StateID == StatesModeType_OFF)
      {
        jsonDoc["StateID"] = "OFF";
      }
      else if (controllerOutput.StateID == StatesModeType_Detected)
      {
        jsonDoc["StateID"] = "Detected";
      }
      else if (controllerOutput.StateID == StatesModeType_Stable)
      {
        jsonDoc["StateID"] = "Stable";
      }
      else if (controllerOutput.StateID == StatesModeType_Stopping)
      {
        jsonDoc["StateID"] = "Stopping";
      }

      // Convert json structure to string, and serialize it to the httpRequestData.
      serializeJson(jsonDoc, httpRequestData);
      Serial.print("httpRequestData: ");
      Serial.println(httpRequestData);

      // Specify content-type header.
      http.addHeader("Content-Type", "application/json");

      // Send HTTP POST request.
      httpResponseCode = http.POST(httpRequestData);

      // Print response or error code.
      if (httpResponseCode > 0)
      {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
      }
      else
      {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }

      // Free resources after sending.
      http.end();

      // Send data to iotplotter.
      // Start new HTTP channel.
      http.begin(client, iotPlotterFeed);

      // Clear and add values to the json structure which will be sent to iotplotter.
      jsonDoc.clear();
      httpRequestData = "";
      
      jsonDoc["data"]["humidity"][0]["value"]=currentHumidity;
      jsonDoc["data"]["temperature"][0]["value"] = currentTemperature;
      jsonDoc["data"]["Requestedventpowerlevel"][0]["value"] = controllerOutput.Requestedventpowerlevel;
      jsonDoc["data"]["Humiditychange"][0]["value"] = controllerOutput.Humiditychange;
      jsonDoc["data"]["Humiditybaseline"][0]["value"] = controllerOutput.Humiditybaseline;
      jsonDoc["data"]["Temperaturechange"][0]["value"] = controllerOutput.Temperaturechange;
      jsonDoc["data"]["Temperaturebaseline"][0]["value"] = controllerOutput.Temperaturebaseline;
      jsonDoc["data"]["Outputenabled"][0]["value"] = controllerOutput.Outputenabled;
      
      // Convert json structure to string, and serialize it to the httpRequestData.
      serializeJson(jsonDoc, httpRequestData);
      Serial.print("httpRequestData: ");
      Serial.println(httpRequestData);

      // Specify content-type and api-key headers.
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      http.addHeader("api-key", iotAPIKey);

      // Send HTTP POST request.
      httpResponseCode = http.POST(httpRequestData);

      // Print response or error code.
      if (httpResponseCode > 0)
      {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
      }
      else
      {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }

      // Free resources after sending.
      http.end();
    }
    else
    {
      // Reconnect to WiFi.
      Serial.println("WiFi Disconnected");
      WiFi.begin(ssid, password);
      Serial.println("Connecting");

      while (WiFi.status() != WL_CONNECTED)
      {
        delay(500);
        Serial.print(".");
      }

      Serial.println("");
      Serial.print("Connected to WiFi network with IP Address: ");
      Serial.println(WiFi.localIP());
    }
  }
  else
  {
    delay(100);
  }
}


/**
 * Read the sensor and button input as fast as possible.
 */
void readSensorLoop(void *pvParameters)
{
  while (1)
  {
    // Read button input.
    int buttonState = digitalRead(HW_BUTTON);

    // If pressed recheck for 30 presses to toggle power of device.
    if(buttonState == LOW)
    {
      int i = 30;
      while(i != 0)
      {
        // Read button input.
        int buttonState = digitalRead(HW_BUTTON);

        // Toggle device power and flash LEDs to indicate.
        if(i == 1)
        {
          if(power == false)
          {
            for(i = 3; i != 0; i--)
            {
              digitalWrite(HW_LED_R,HIGH);
              digitalWrite(HW_LED_Y,HIGH);
              digitalWrite(HW_LED_G,HIGH);
              delay(500);
              digitalWrite(HW_LED_R,LOW);
              digitalWrite(HW_LED_Y,LOW);
              digitalWrite(HW_LED_G,LOW);
              delay(500);
            }
            Serial.println("Powering ON!");
            power = true;
          }
          else
          {
            power = false;
            for(i = 3; i != 0; i--)
            {
              digitalWrite(HW_LED_R,HIGH);
              digitalWrite(HW_LED_Y,HIGH);
              digitalWrite(HW_LED_G,HIGH);
              delay(500);
              digitalWrite(HW_LED_R,LOW);
              digitalWrite(HW_LED_Y,LOW);
              digitalWrite(HW_LED_G,LOW);
              delay(500);
            }
            // Turn off LEDs.
            digitalWrite(HW_LED_R,HIGH);
            digitalWrite(HW_LED_Y,HIGH);
            digitalWrite(HW_LED_G,HIGH);
            Serial.println("Powering OFF!");
          }
          break;
        }
        else if(buttonState == LOW)
        {
          i--;
        }
        delay(100);
      }
    }

    // If device power is enabled read sensor data.
    if (power)
    {
      // Run update of sensor data.
      Serial.println("Updating from RHT sensor");
      int updateReturn1 = RHT.update();

      // On successful update.
      if (updateReturn1 == 1)
      { 
        // Read current humidity and temperature.
        currentHumidity = RHT.humidity();
        currentTemperature = RHT.tempC();
      }
      else
      { 
        // If failed to read sensor data.
        delay(RHT_READ_INTERVAL_MS);
      }
    }
    else
    {
      delay(100);
    }
  }
}


/**
 * Run the controller loop once per second, and set LEDs based on output.
 */
void controllerLoop(void *pvParameters)
{
  TickType_t xLastWakeTime;
  const TickType_t xPeriod = 1000 / portTICK_PERIOD_MS;

  while (1)
  {
    // Initialise the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    // If automatic mode is enabled run the controller.
    if (power) 
    {
      Serial.println("Running controller");
      sensorInput.Humiditysensorvalue = currentHumidity;
      sensorInput.Temperaturesensorvalue = currentTemperature;

      controller.setExternalInputs(&sensorInput);

      controller.step();

      //Get the controller outputs and calculate wanted extractor state.
      controllerOutput = controller.getExternalOutputs();
      extractorState = controllerOutput.Requestedventpowerlevel / 10;

      //Set LEDs based on wanted extractor state.
      if (extractorState >= 2.25)
      {
        digitalWrite(HW_LED_G, LOW);
        digitalWrite(HW_LED_R, HIGH);
        digitalWrite(HW_LED_Y, HIGH);
      }
      else if (extractorState >= 1.5)
      {
        digitalWrite(HW_LED_Y, LOW);
        digitalWrite(HW_LED_R, HIGH);
        digitalWrite(HW_LED_G, HIGH);
      }
      else if (extractorState >= 0.75)
      {
        digitalWrite(HW_LED_R, LOW);
        digitalWrite(HW_LED_Y, HIGH);
        digitalWrite(HW_LED_G, HIGH);
      }
      else
      {
        digitalWrite(HW_LED_R, HIGH);
        digitalWrite(HW_LED_Y, HIGH);
        digitalWrite(HW_LED_G, HIGH);
      }
    }
    else{
      delay(100);
    }

    vTaskDelayUntil(&xLastWakeTime, xPeriod);
  }
}