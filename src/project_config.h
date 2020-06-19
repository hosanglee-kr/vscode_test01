#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>





/// IP CONFIG ////////////////////////////
#define WIFI_IP_FIXED    1
#ifdef WIFI_IP_FIXED
    //byte arduino_mac[] = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
    IPAddress WIFI_device_ip  (192, 168,   0,  80);
    IPAddress WIFI_dns_ip     (  8,   8,   8,   8);
    IPAddress WIFI_gateway_ip (192, 168,   0,   1);
    IPAddress WIFI_subnet_mask(255, 255, 255,   0);
#endif

void    WIFI_Config_Set_Fixed_ip(){
    #ifdef WIFI_IP_FIXED
        WiFi.config(WIFI_device_ip, WIFI_gateway_ip, WIFI_subnet_mask, WIFI_dns_ip);
    #endif
}

///  SSID Config //////////////////////////////
enum E_WIFI_CONFIG_MODE {
    WIFI_CONFIG_MODE_FIXED_CONFIG,
    WIFI_CONFIG_MODE_SMARTCONFIG
};


uint8_t g_WIFI_Config_mode = WIFI_CONFIG_MODE_SMARTCONFIG;

char wifi_ssid[] = "YourNetworkName";
char wifi_pass[] = "YourPassword"   ;

void WIFI_Config_Set_SSID(){
    
    if (g_WIFI_Config_mode == WIFI_CONFIG_MODE_SMARTCONFIG ) {
        WiFi.mode(WIFI_STA);
    
        int cnt = 0;
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
            if (cnt++ >= 10) {
                WiFi.beginSmartConfig();
                while (1) {
                    delay(1000);
                    if (WiFi.smartConfigDone()) {
                        Serial.println();
                        Serial.println("SmartConfig: Success");
                        break;
                    }
                    Serial.print("|");
                }
            }
        }
    } else if (g_WIFI_Config_mode == WIFI_CONFIG_MODE_FIXED_CONFIG ) {
        WiFi.begin(wifi_ssid, wifi_pass);
    }
}


/// Blynk config 

char BLYNK_auth[] = "YourAuthToken";

const char* BLYNK_2540_DOMAIN   =  "hosanglee.iptime.org";
uint16_t    BLYNK_2540_PORT     = 80;


void BLYNK_Setup(){   
    Blynk.config(BLYNK_auth, BLYNK_2540_DOMAIN, BLYNK_2540_PORT);
    //void config(const char* auth, const char* domain = BLYNK_DEFAULT_DOMAIN, uint16_t    port   = BLYNK_DEFAULT_PORT)
    //void config(const char* auth, IPAddress   ip, uint16_t    port = BLYNK_DEFAULT_PORT)
    //Blynk.config(BLYNK_auth);
}

void BLYNK_Config_Server_Address(){
    Blynk.config(BLYNK_auth, BLYNK_2540_DOMAIN, BLYNK_2540_PORT);
}


void BLYNK_Config_Auth_Key(){
    Blynk.config(BLYNK_auth);
}