#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/*#include <LiquidCrystal.h>
LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);*/

char auth[] = "8507cac915f04a1bb4b00987e420afa0";

/*char ssid[] = "ESPServer_RAJ";
char pass[] = "RAJ@12345";*/
char ssid[] = "ESPServer_RAJ";
char pass[] = "RAJ@12345";

int BULB=D5;
int FAN=D6;
int EX_FAN=D3;
int GYSER=D4;

BLYNK_WRITE(V1)
{
  int BULB_VAL = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(BULB_VAL==HIGH)
  {
    //lcd.clear();
    digitalWrite(BULB,HIGH);
    digitalWrite(FAN,LOW);
    digitalWrite(EX_FAN,LOW);
    digitalWrite(GYSER,LOW);
   /* lcd.setCursor(0,0);
    lcd.print("BULB ON");
    delay(10);*/
    }
    
}

BLYNK_WRITE(V2)
{
  int FAN_VAL = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(FAN_VAL==HIGH)
  {
    //lcd.clear();
    digitalWrite(BULB,LOW);
    digitalWrite(FAN,HIGH);
    digitalWrite(EX_FAN,LOW);
    digitalWrite(GYSER,LOW);
    /*lcd.setCursor(0,1);
    lcd.print("FAN ON");
    delay(10);*/
   }
 }
BLYNK_WRITE(V3)
{
  int EX_FAN_VAL = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(EX_FAN_VAL==HIGH)
  {
   // lcd.clear();
    digitalWrite(BULB,LOW);
    digitalWrite(FAN,LOW);
    digitalWrite(EX_FAN,HIGH);
    digitalWrite(GYSER,LOW);
    /*/lcd.setCursor(0,2);
    lcd.print("EX FAN ON");
    delay(10);*/
   }
 }

 BLYNK_WRITE(V4)
{
  int GYSER_VAL = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(GYSER_VAL=HIGH)
  {
   // lcd.clear();
    digitalWrite(BULB,LOW);
    digitalWrite(FAN,LOW);
    digitalWrite(EX_FAN,LOW);
    digitalWrite(GYSER,HIGH);
   /* lcd.setCursor(0,3);
    lcd.print("GYSER ON");
    delay(10);*/
   }
 }
 BLYNK_WRITE(V5)
{
  int ALLOFF_VAL = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(ALLOFF_VAL =HIGH)
  {
  //  lcd.clear();
    digitalWrite(BULB,LOW);
    digitalWrite(FAN,LOW);
    digitalWrite(EX_FAN,LOW);
    digitalWrite(GYSER,LOW);
    /*lcd.setCursor(0,0);
    lcd.print("ALL OFF");
    delay(10);*/
   }
     if(ALLOFF_VAL =LOW)
   {
   // lcd.clear();
    digitalWrite(BULB,HIGH);
    digitalWrite(FAN,HIGH);
    digitalWrite(EX_FAN,HIGH);
    digitalWrite(GYSER,HIGH);
   /* lcd.setCursor(0,0);
    lcd.print("STOP");
    delay(10);*/
   }
 }


void setup()
{
  Serial.begin(9600);
  //lcd.begin(20,4);
  Blynk.begin(auth, ssid, pass);
  pinMode(BULB,OUTPUT);//D6 pin of NodeMCU
  pinMode(FAN,OUTPUT);//D7 pin of NodeMCU
  pinMode(EX_FAN,OUTPUT);//D8 pin of NodeMCU
  pinMode(GYSER,OUTPUT);//D9 pin of NodeMCU
}

void loop()
{
  Blynk.run();
}
