//Esclavo

#include <SoftwareSerial.h>
int rxPin = 10;
int txPin = 11;
SoftwareSerial xbee = SoftwareSerial(rxPin, txPin);
void setup() {
  // put your setup code here, to run once:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  xbee.begin(9600);

  
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(3,OUTPUT);

}
  int derecha = 0;
  int izquierda = 0;
  int movderecha = 0;
  int movizquierda = 0;
  int vel = 0;
  int angulo = 0;
  
void loop() {
  // put your main code here, to run repeatedly:
  //Aumento de velocidad
  delay(1000);
  Serial.println("-----------------");
  Serial.println("");
  Serial.print("Derecha");
  Serial.print(movderecha);
  Serial.println("");
  Serial.print("Izquierda");
  Serial.print(movizquierda);
  Serial.println("");
  

  Serial.println("");
  Serial.println("velocidad:");
  Serial.println(vel);
  Serial.println("");
  
  if(movderecha>0){
    derecha = HIGH;
    izquierda = LOW;
  }
  if(movizquierda>0)
  {
    derecha = LOW;
    izquierda= HIGH;
  }
  
 
  digitalWrite(6,derecha);
  digitalWrite(7,izquierda);
  digitalWrite(3,vel);

  
  if(xbee.available()){
    angulo = xbee.read();
    Serial.println("");
    Serial.print("Angulo: ");
    Serial.print(angulo);
    Serial.println("");
  }
  angulo = angulo - 82;
    Serial.println("");
    Serial.print("Angulo procesado: ");
    Serial.print(angulo);
    Serial.println("");
  
  if(angulo > 0){
    movderecha = 1;
    movizquierda = 0;
  }
  if(angulo < 0){
    movderecha = 0;
    movizquierda = 1;  
  }
    
    
  if( (angulo<0 && angulo>-17) || (angulo>0 && angulo<17) )
    vel =0;
    
  if( (angulo<-18 && angulo>-42) || (angulo>18 && angulo<40) )
    vel =50;

  if( (angulo<-43 && angulo>-57) || (angulo>41 && angulo<57) )
    vel =100;

  if( angulo<-58 || angulo>58 )
    vel =200;

}

 
