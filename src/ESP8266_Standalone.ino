


#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#include "project_config.h"


void setup() {
    Serial.begin(9600);

    //Blynk.begin(BLYNK_auth, wifi_ssid, wifi_pass);

    WIFI_Config_Set_Fixed_ip();

    WIFI_Config_Set_SSID();
    
    BLYNK_Setup();
    

    while (Blynk.connect() == false) {
        
    }
}



void loop() {
    Blynk.run();
}


// This is called when Smartphone App is opened
BLYNK_APP_CONNECTED() {
  Serial.println("App Connected.");
}

// This is called when Smartphone App is closed
BLYNK_APP_DISCONNECTED() {
  Serial.println("App Disconnected.");
}

        

// Standalone //////////////////////////////////////
//    #define BLYNK_PRINT Serial
//    
//    
//    #include <ESP8266WiFi.h>
//    #include <BlynkSimpleEsp8266.h>
//    
//    // You should get Auth Token in the Blynk App.
//    // Go to the Project Settings (nut icon).
//    char auth[] = "YourAuthToken";
//    
//    // Your WiFi credentials.
//    // Set password to "" for open networks.
//    char ssid[] = "YourNetworkName";
//    char pass[] = "YourPassword";
//    
//    void setup()
//    {
//      // Debug console
//      Serial.begin(9600);
//    
//      Blynk.begin(auth, ssid, pass);
//    }
//    
//    void loop()
//    {
//      Blynk.run();
//    }



// SmartConfig /////////////////////////////////////////////////////
//    #define BLYNK_PRINT Serial
//    
//    
//    #include <ESP8266WiFi.h>
//    #include <BlynkSimpleEsp8266.h>
//    
//    // You should get Auth Token in the Blynk App.
//    // Go to the Project Settings (nut icon).
//    char auth[] = "YourAuthToken";
//    
//    void setup()
//    {
//        // Debug console
//        Serial.begin(9600);
//    
//        WiFi.mode(WIFI_STA);
//    
//        int cnt = 0;
//        while (WiFi.status() != WL_CONNECTED) {
//            delay(500);
//            Serial.print(".");
//            if (cnt++ >= 10) {
//                WiFi.beginSmartConfig();
//                while (1) {
//                    delay(1000);
//                    if (WiFi.smartConfigDone()) {
//                        Serial.println();
//                        Serial.println("SmartConfig: Success");
//                        break;
//                    }
//                    Serial.print("|");
//                }
//            }
//        }
//    
//        WiFi.printDiag(Serial);
//    
//        Blynk.config(auth);
//    }
//    
//    void loop() {
//        Blynk.run();
//    }


// Manual IP /////////////////////////////////////////////////////////////////

//    /* Comment this out to disable prints and save space */
//    #define BLYNK_PRINT Serial
//    
//    
//    #include <ESP8266WiFi.h>
//    #include <BlynkSimpleEsp8266.h>
//    
//    // You should get Auth Token in the Blynk App.
//    // Go to the Project Settings (nut icon).
//    char auth[] = "YourAuthToken";
//    
//    // Your WiFi credentials.
//    // Set password to "" for open networks.
//    char ssid[] = "YourNetworkName";
//    char pass[] = "YourPassword";
//    
//    
//    // Mac address should be different for each device in your LAN
//    byte arduino_mac[] = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
//    IPAddress device_ip  (192, 168,   0,  80);
//    IPAddress dns_ip     (  8,   8,   8,   8);
//    IPAddress gateway_ip (192, 168,   0,   1);
//    IPAddress subnet_mask(255, 255, 255,   0);
//    
//    void setup()
//    {
//      // Debug console
//      Serial.begin(9600);
//    
//      // Setup WiFi network
//      WiFi.config(device_ip, gateway_ip, subnet_mask);
//      WiFi.begin(ssid, pass);
//    
//      // Setup Blynk
//      Blynk.config(auth);
//      while (Blynk.connect() == false) {
//      }
//    
//    }
//    
//    void loop()
//    {
//      Blynk.run();
//    }
//    