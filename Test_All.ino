//#include <WiFi.h>

//#include <NewPing.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h> // อุณหภูมิ
#include <ESP32Servo.h> // Servo
#include <SPI.h> // ส่วนของ OLED
#include <Adafruit_GFX.h> // การใช้งานแสดงค่าทาง OLED
#include <Adafruit_SSD1306.h> // การใช้งานหน่วยความจำชั่วคราว



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)


#define TRIGGER_PIN  12 //
#define ECHO_PIN     13 //กำหนดที่ ขา 13
#define MAX_DISTANCE 5 // 
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//
int tqr = 0;//


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

Servo qrservo;  // กำหนดใช้งาน Servo กด qr code
Servo gelservo; // กำหนดใช้งาน Servo ตัวที่กด เจล

String qr;
int i = 1;
int analogPin = 34; //เซนเซอร์วัดอุณหภูมิขาที่ 34
int DistanceTemp = 0; 
int Pos;
//int temp = 37;

int duration = 0;



void setup() {
  
  Serial.begin(9600);
  mlx.begin(); //เริ่มต้นการใช้งานที่ Scan อุณหภูมิ
  
  qrservo.attach(14);
  gelservo.attach(33); //กำหนด servo ตัวที่ ที่ขา 18


  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
 //myDFPlayer.volume(25);
 //myDFPlayer.play(1);


}


//ส่วนแสดงหน้าจอ กำหนด setup

void loop() {

 delay(50);
 
 // ส่วนการทำงานของ servo กด qr code
  //int cqr = sonar.ping_cm();
  //Serial.println(cqr);
  //if (tqr == 0) {
    //if (cqr <= 1) {
      //fservo.write(40);
    //}
    //else {
      //delay(250);
      //fservo.write(0);
      //delay(1000);
      //tqr = 1;
      //if (tqr == 1) {
    //fservo.write(0);
    //delay(1000);
    //tqr = 0;
    //}
  //}
// }

 display.clearDisplay();
 display.display();

  if (Serial.available() > 0)
  { 
  String qr = Serial.readString(); qr.toInt();
    
    display.setTextSize(1);                    
    display.setTextColor(WHITE);             
    display.setCursor(0,0);                
    display.println("Hello");
    Serial.println("Hello"); 
     
    display.setTextSize(2);
    display.setCursor(50,17);
    display.println(qr);
    Serial.println(qr);

    display.display();
    display.clearDisplay();
    
    delay(1000);
  

    DistanceTemp = analogRead(analogPin);
    Serial.print("DistanceTemp = "); 
    Serial.println(DistanceTemp);
    
   if (DistanceTemp == 4095) {

      delay(2000);
      double temp = mlx.readObjectTempC()+3;

      //int temp = 30;
      display.setTextSize(1);                    
      display.setTextColor(WHITE);             
      display.setCursor(0,0);                
      display.println("Temparature");
      Serial.println("Temparature");
  
      display.setTextSize(2);
      display.setCursor(50,17);
      display.println(temp,2);
      Serial.println(temp,2);
       
      display.setCursor(110,17);
      display.println("C");

      
      display.display();
      delay(1000);
       
   if(temp>=37.4)
       {         
          Serial.print("Not pass");
          //delay(2000);
        }
   else
        {          
          Serial.println("Pass");
           // รอสอง 2 วินาที 
          //delay(1000);
          //gelservo.write(0);
          //delay(1000);
          //gelservo.write(90);
         //delay(1000);
        }
        
        display.clearDisplay();
        display.display();
        delay(2000);
        return;
      
  
    }
 }
}
