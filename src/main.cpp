
//    https://github.com/blynkkk/blynk-library/releases/latest

//  This example runs directly on ESP8266 chip.
// ESP8266_standalone_smartconfig

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);

  int cnt = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    if (cnt++ >= 10)
    {
      WiFi.beginSmartConfig();
      while (1)
      {
        delay(1000);
        if (WiFi.smartConfigDone())
        {
          Serial.println();
          Serial.println("SmartConfig: Success");
          break;
        }
        Serial.print("|");
      }
    }
  }

  WiFi.printDiag(Serial);

  Blynk.config(auth);
}

void loop()
{
  Blynk.run();
}
