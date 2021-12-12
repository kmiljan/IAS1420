# Installing PlatformIO 
This code was written for the ESP32 using the PlatformIO addon for VScode, which must be installed to load the code on to the microcontroller. To install PlatformIO please see the online guide: https://platformio.org/install
Once installed you must select the ESP32 folder as the project folder using the editor. 

# Library for RHT03
The library to interface with the RHT03 can be found on GitHub:https://github.com/sparkfun/SparkFun_RHT03_Particle_Library
Please install this before compiling the code.

# Configurable variables
The main configurable variables are as follows. The WiFi parameters ssid and password, which must be set to your specific parameters. The HTTP server address (serverName) and the iotPlotter parameters iotAPIKey and iotPlotterFeed, which can be found on http://iotplotter.com once you configure your feed. The instruction for configuring your iotPlotter feed can be found online: https://iotplotter.com/docs/

# Short description of used functions in Estionian. (Koodis kasutatud funktsioonid ja nende lühikirjeldused):

void sendData() – Funktsioon edastamaks andmeid serverile ja iotPlotter-isse. Esmalt kontrollitakse kas kontrolleri on automaat või manuaal režiimis. Kui kontroller on automaat režiimis siis edastatakse ühe formaadiga JSON andmebaasi serverile, ja teise formaadiga JSON iotPlotter-isse, üle HTTP.

void readSensorLoop(void *pvParameters) – Funktsioon lugemaks anduri väljundit ja nupu vajutusi. Kui nupp on vajutatud jäädakse ootama kuni nupp on vabastatud või kolm sekundit on möödunud, mis puhul lülitatakse kontrolleri režiim(manuaal/automaat) ümber. Automaat režiimis kontrollitakse ka anduri väljundit.

void controllerLoop(void *pvParameters) – Funktsioon käivitamaks juhtimissüsteemi iga sekund, ja seadmaks LED-e vastavalt selle väljundile. Automaat režiimis edastatakse juhtimissüsteemile sisend parameetrid niiskuse tase ja temperatuur, ning loetakse selle väljund, mille põhjal seatakse LED-id kas välja, punaseks, kollaseks või roheliseks.

void setup() – Arduino raamistiku standard funktsioon mis käivitatakse vaid ühekorra, kohe kontrolleri käivitumisel. Funktsioonis seatakse LED-ide, nupu ja anduri ühendused mikrokontrolleriga, laetakse juhtimissüsteemi parameetrid, ning ühendutakse WiFi-ga.

void loop() - Arduino raamistiku standard funktsioon mis käivitatakse peale setup funktsiooni. Funktsioonis seatakse üles teiste funktsioonide ajaline kutsumine kasutades reaalaja operatsioonisüsteemi ja kutsutakse välja sendData funktsiooni umbes iga kümne sekundi tagant.
