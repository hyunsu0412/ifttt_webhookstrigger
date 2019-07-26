#include <ifttt.h>

ifttt myifttt;

// Replace with your SSID and Password
//----------------------------------------------------------------------
const char* ssid     = "hyunsu's spot in arduino";
const char* password = "arduino12";
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
    //Serial Speed == 115200
    myifttt.connectWifi(ssid, password);
    myifttt.webHooksTriggerRequest(token, trigger_name);
    
    // Deep sleep mode until RESET pin is connected to a LOW signal (pushbutton is pressed)
    ESP.deepSleep(0);
}
void loop() 
{
}
