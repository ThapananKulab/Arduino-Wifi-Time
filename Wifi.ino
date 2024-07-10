#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <Wire.h>

const char* ssid     = "NNN";
const char* password = "";

const char* serverName = "https://pwsprojectit.000webhostapp.com/sendwifi/arduino_insertdata.php";

String apiKeyValue = "tPmAT5Ab3j7F9";



void setup() 
{
Serial.begin(9600);
WiFi.begin(ssid, password); 
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
}
}



void loop() 
{

 if(WiFi.status()== WL_CONNECTED){
  
    HTTPClient http;
   http.begin(serverName);

  
  String st_id = "1";
  String temp = "2";
  //Serial.println(st);
  //Serial.println(temp);

    
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String httpRequestData = "api_key=" + apiKeyValue + "&st_id=" + st_id + "&temp=" + temp + "";
  Serial.print("httpRequestData: ");
  Serial.println(httpRequestData);


  int httpResponseCode = http.POST(httpRequestData);
  
 if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  

 

}
