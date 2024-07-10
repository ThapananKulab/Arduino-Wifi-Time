#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <Wire.h>

const char* ssid     = "NNN";
const char* password = "";

const char* serverName = "localhost";


void setup() 
{
  
}
WiFi.begin(ssid, password);  
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
}

}

void loop() 
{

 HTTPClient http; 
 WiFiClient client;

 http.begin(client, serverName);

 
  String a=1;
  String b=2;

  postData = "apost=" + a;

  http.begin("https://pwsprojectit.000webhostapp.com/sendwifi/arduino_insertdata.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  client.print(String("GET https://pwsprojectit.000webhostapp.com/sendwifi/arduino_insertdata.php?") + ("&temperature=") + a + ("&humidity=") + b + "" + "Host: " + serverName );
 

}
