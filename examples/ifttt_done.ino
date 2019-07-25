#include "ifttt.h"

// Replace with your SSID and Password
//----------------------------------------------------------------------
const char* ssid     = "KPU_WiFi1432";
const char* password = "";
//----------------------------------------------------------------------

// Replace with your unique IFTTT WebHooks Token
//----------------------------------------------------------------------
const char* token = "bcq3KeQ8jgzmuQzc-b0oDk";
//----------------------------------------------------------------------

//Replace with your unique WebHooks trigger
//----------------------------------------------------------------------
const char* trigger_name = "sw_on";
//----------------------------------------------------------------------

void setup() 
{
    Serial.begin(115200); 
    
    connectWifi(ssid, password);
    webHooksTriggerRequest(token, trigger_name);
    
    // Deep sleep mode until RESET pin is connected to a LOW signal (pushbutton is pressed)
    ESP.deepSleep(0);
}
void loop() 
{
}
