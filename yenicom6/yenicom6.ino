  //Yeni com6
#include <EEPROM.h>
String veri="";
boolean durum=false;
int toplam =0;
unsigned long full=10800000;
unsigned long sarj=10800000.0;
double yuzdelik=100.0;
int kayitadresi=2;
unsigned long okunanveri;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial1.begin(9600);
  /* Verinin yazılacağı EEPROM adresi */ 
 /* EEPROMA kaydedilecek veri */
 

}

void loop() {

  for(int i=0;i<10;i++){
const int analogchannel = i; //Connect current sensor with A0 of Arduino
int sensitivity = 66; // use 100 for 20A Module and 66 for 30A Module
int adcvalue1= 0;
int offsetvoltage = 2500; 
double Voltage = 0; //voltage measuring
double akim = 0;// Current measuring



 adcvalue1 = analogRead(analogchannel);//reading the value from the analog pin
 Voltage = ((adcvalue1 / 1024.0) * 5000); // Gets you mV
 akim = ((Voltage - offsetvoltage) / sensitivity);
//okunanveri= EEPROM.read(kayitadresi);
 
// Serial.println(toplam); 
 //delay(300);
 
// Serial.print("akim");
// Serial.print(i+1); 
// Serial.print("=");// shows the voltage measured 
// Serial.println(akim,3);// the '3' after voltage allows you to display 3 digits after decimal point
  // 10 adresini okuyacağız
 //okunanVeri = EEPROM.read(okunacakAdres ); /* EEPROMun 10 adresindeki veri okunanVeri değişkenine aktarılıyor. */

//  sarj= EEPROM.read(2);
 // delay(10);
    toplam=toplam+akim;
    sarj=sarj+toplam;
   // 
     //full=sarj;
    
    //EEPROM.write(2, sarj); /* EEPROMun 10 adresine 50 verisi yazdırıldı. */
  // delay(10);
   // Serial.print("sarj");
   // Serial.println(sarj);
 
    //Serial.print("toplam");
    //Serial.println(abs(toplam));
 //full=sarj;
 // EEPROM.write(2,sarj);
 //delay(500);
  }
  
 // Serial1.print("akim toplamlari      :");
 //Serial1.println(toplam);
 // Serial.println(toplam);

 
 //int yuz=map(sarj,0,10800000,0,100);
if(yuzdelik>100.0 || yuzdelik<=4.0)
{
  Serial.println("yüzdelik 100 den büyük");
  }else{
    
  yuzdelik=(sarj/108000.0);
    
    }
 
      toplam=0;


    Serial.print("%");
    Serial.println(yuzdelik);
    Serial1.println(yuzdelik);
    //delay(10);
  
}
  

