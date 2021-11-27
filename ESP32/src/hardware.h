//Sensor data line. With 1k pull-up to 3.3V on breadboard.
#define HW_SENSOR_DATA1 2
#define HW_SENSOR_DATA2 0
//Button input. Use an internal pull-up (https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html)
//  HIGH - not pressed
//  LOW - pressed
#define HW_BUTTON 4

//LED anodes (pulling HIGH will turn the corresponding number LED ON, if their cathodes are LOW)
#define HW_LED1 13
#define HW_LED2 12
#define HW_LED3 14

//LED cathodes (pulling LOW will turn the corresponding color LEDs ON, if their anodes are HIGH)
#define HW_LED_R 19
#define HW_LED_Y 5
#define HW_LED_G 18