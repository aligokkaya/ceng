//com4 yeni nextion takılacak
#include "Nextion.h"

const int role1=7;
const int role2=8;
const int role3=9;
const int role4=10;

const int bazer =12; 
const int role5 =13;
String songelenhiz="";
 const int geril=A8;
  double deger;
NexGauge z0 = NexGauge(1,1,"z0");
NexNumber n5 = NexNumber(1, 7, "n5");
NexNumber n0 = NexNumber(1, 2, "n0");
NexNumber n4 = NexNumber(1, 6, "n4");
NexNumber n2 = NexNumber(1, 4, "n2");
NexNumber n3 = NexNumber(1, 5, "n3");


//NexText t3=NexText (1,4,"t3");
String k="";
String veri="";
double hesap;
String gelenhiz="";
boolean durum=false;
boolean hizdurum=false;
float dizi1[]={};
float enkucuk=0;
String sicaklikveri="";
boolean sicaklikdurum=false;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial1.begin(9600);
//Serial2.begin(9600);
//Serial2.begin(9600);
 nexSerial.begin(9600);
 nexInit();
 //mySerial.begin(9600);
Serial3.begin(9600);
pinMode(role1, OUTPUT);
pinMode(role2, OUTPUT);
pinMode(role3, OUTPUT);
pinMode(role4, OUTPUT);
pinMode(role5,OUTPUT);
pinMode(bazer,OUTPUT);
}

void loop() {
 
  // put your main code here, to run repeatedly:
if (Serial1.available())
  {
    char gelen = char(Serial1.read());
    veri += gelen;
    if (gelen == '\n')
    { 
      durum = true;  
    }    
  }
   if(Serial3.available())
      {
        char hiz= char(Serial3.read());
        gelenhiz+=hiz;
        if (hiz="\n")
        {
          hizdurum=true; 
        }
      }/*
      if(Serial2.available())
      {
        char veri1= char(Serial2.read());
        sicaklikveri+=veri1;
        if (veri1="\n")
        {
          sicaklikdurum=true; 
        }
      }*/
  if(durum)
  {
     //Serial.println(veri);  
    // Serial.print("hiz");
     //Serial.println(gelenhiz);
     sicaklik();
     delay(1);
     gerilim();
     delay(1);
     gonder();
     delay(1);
     role();
     delay(1);
     ekranayaz();
       if(gelenhiz!="")
          {
          if(gelenhiz!="0")
        {
            songelenhiz=gelenhiz;
          }
          }
    z0.setValue(songelenhiz.toInt());
    veri="";
    gelenhiz="";
    sicaklikveri="";
    durum=false;
    sicaklikdurum=false;
    hizdurum=false;
    enkucuk=0;
    
  }
} 

void sicaklik()
{

  for(int i=2; i<=2; i++)
  {
const int analogPin = i;

float gerilimDeger = 0;
float sensorDeger = 0;
float sicaklikDeger = 0;
 sensorDeger = analogRead(analogPin); 
 gerilimDeger = (sensorDeger/1023)*5000;
 sicaklikDeger = gerilimDeger / 10.0;
 dizi1[i]=sicaklikDeger;
if(i==2)
 {     
  enkucuk=dizi1[0];
  for(int k=0; k<3; k++)
  {
    if(enkucuk<dizi1[k])
    {
      enkucuk=dizi1[k];
    }
  }

 
 }
 
}

}

void gerilim()
{
 deger=analogRead(geril);
 hesap=(deger/54)*20;
 }
void role()
{
  if(enkucuk>=40)
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);    
  }
  if (enkucuk>=50)
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
     digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
  }
 
if(enkucuk>=15

)
  {
    digitalWrite(bazer,HIGH);
    //delay(4000);
    digitalWrite(role5,HIGH);
  }
}

void gonder()
{
   Serial.println(" ");
  Serial.print("/");
  Serial.println(enkucuk);
   Serial.print("*");
  Serial.println(songelenhiz);
   Serial.print("<");
   Serial.print(veri);
   Serial.print(hesap);  
  Serial.println("x");
  Serial.println(hesap); 
}
void ekranayaz()
{
 
  n5.setValue(songelenhiz.toInt());
  n0.setValue(songelenhiz.toInt()); 
  n4.setValue(veri.toInt()); 
  n2.setValue(enkucuk);
  n3.setValue(deger);
}

