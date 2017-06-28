// cup_teensy_ESP8266
//
// Teensy based controller of the smartcup
//  with WiFi interface ESP8266
//    Interrupt driven with Tint= 
//  May 2016
// Authors: Vindhya & EJ
//

#define USB_Serial Serial
#define Test_Serial Serial2

 int timerSamp;
int buffer[100];
int bufptr=0; /* buffer pointer */
int i;
int tempRead = 0; // serial input/output temp
int tempRead2 = 0; // serial input/output temp
// Pin Definitions
#define WIFI_CE 2
#define WIFI_RST 3
void setup(void) {

 pinMode(WIFI_CE, OUTPUT);
 pinMode(WIFI_RST, OUTPUT);
 digitalWrite(WIFI_CE, HIGH);
 //digitalWrite(WIFI_RST, HIGH) ;
 //delay(10);
 digitalWrite(WIFI_RST, LOW) ;
 delay(1000);
 digitalWrite(WIFI_RST, HIGH) ;
// delay(500);
// Serial1.begin(115200);    // hardware serial connects to esp8266 module
 Serial1.begin(115200);    // hardware serial connects to esp8266 module
 Serial.begin(115200); // usb serial connects to to pc
 //delay(2000);    //wait for usb serial enumeration on 'Serial' & device startup

}


//******** The main program 
void loop(void) {
  
  if(Serial1.available() > 0) {
    // read the incoming byte
    tempRead = Serial1.read(); 
    Serial.write(tempRead);
    //Serial.println("WiFi");
  } // end WiFi serial available 
  
  //**** check for new messages
  if (Serial.available() > 0) {
    // read the incoming byte
    tempRead2 = Serial.read(); 
    Serial1.write(tempRead2);
    //Serial.println("USB");
  }

} // end loop


 
