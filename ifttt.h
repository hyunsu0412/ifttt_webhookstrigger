#ifndef ifttt_h
#define ifttt_h


#include <Arduino.h>
#include <ESP8266WiFi.h>

class ifttt
{
    public :
    	ifttt();
    	~ifttt();
    	void connectWifi(const char* ssid0, const char* password0);
        void webHooksTriggerRequest(const char* token0, const char* trigger_name0);        
};
#endif
