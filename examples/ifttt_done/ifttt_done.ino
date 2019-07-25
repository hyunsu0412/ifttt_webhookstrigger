#include "ifttt.h"

ifttt myifttt;

// Replace with your SSID and Password
//----------------------------------------------------------------------
const char* ssid     = "";
const char* password = "";
//----------------------------------------------------------------------

// Replace with your unique IFTTT WebHooks Token
//----------------------------------------------------------------------
const char* token = "";
//----------------------------------------------------------------------

//Replace with your unique WebHooks trigger
//----------------------------------------------------------------------
const char* trigger_name = "";
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
