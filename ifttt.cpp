#include "ifttt.h"

const char* u1 = "https://maker.ifttt.com/trigger/";
const char* u2 = "/with/key/";
const char* server = "maker.ifttt.com";

ifttt::ifttt()
{
	Serial.begin(1152000);
}
ifttt::~ifttt()
{
	/*nothing to destruct*/
}

void ifttt::connectWifi(const char* ssid0, const char* password0)
{
    Serial.print("Connecting to: "); 
    Serial.print(ssid0);
    WiFi.begin(ssid0, password0);  
    
    int timeout = 10 * 4; // 10 seconds
    while(WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) 
    {
        delay(250);
        Serial.print(".");
    }
    Serial.println("");
    
    if(WiFi.status() != WL_CONNECTED) 
    {
        Serial.println("Failed to connect, going back to sleep");
    }
    
    Serial.print("WiFi connected in: "); 
    Serial.print(millis());
    Serial.print(", IP address: "); 
    Serial.println(WiFi.localIP());
}

// Make an HTTP request to the IFTTT web service
void ifttt::webHooksTriggerRequest(const char* token0, const char* trigger_name0)
{
    Serial.print("Connecting to "); 
    Serial.print(server);
    
    WiFiClient client;
    int retries = 5;
    while(!!!client.connect(server, 80) && (retries-- > 0)) 
    {
        Serial.print(".");
    }
    Serial.println();
    if(!!!client.connected()) 
    {
        Serial.println("Failed to connect, going back to sleep");
    }
    String URL = String(u1) + trigger_name0 + u2 + token0;
    Serial.print("Request resource: "); 
    Serial.println(URL);
    client.print(String("GET ") + URL + " HTTP/1.1\r\n" +"Host: " + server + "\r\n" + "Connection: close\r\n\r\n");
    
    int timeout = 5 * 10; // 5 seconds             
    while(!!!client.available() && (timeout-- > 0))
    {
        delay(100);
    }
}
