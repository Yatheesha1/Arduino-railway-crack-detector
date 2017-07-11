#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#include <TinyGPS++.h>

int RXPin = 2, TXPin = 3;//GSM pins

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
AltSoftSerial gpsSerial;//(RX 9, TX 8);

// The serial connection to the GSM device
SoftwareSerial mySerial(RXPin, TXPin);

int sensepin=5;
int flag=0;

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  if (mySerial.available()>0)
  {
    Serial.println(mySerial.readString());
  }
  gpsSerial.begin(9600); 
   
  pinMode(sensepin,INPUT);
  
}

void loop()
{
  while (gpsSerial.available())
  {
    if (gps.encode(gpsSerial.read()))
    {
      displaygpsInfo();
    }
  }    

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
  
}

