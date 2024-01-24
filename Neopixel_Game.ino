#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#include "Timer.h"
Timer timer;
#define PRZYCISK_ON 4
#define PRZYCISK_MID 2
#define PRZYCISK_OFF 3

#define LED_PIN 6
#define LICZBA_PIKSELI 8
Adafruit_NeoPixel pixels(LICZBA_PIKSELI, LED_PIN, NEO_GRB + NEO_KHZ800);

#define zielona_1 11
#define zielona_2 10
#define zielona_3 9
#define zielona_4 8

 int R1;
 int G1;
 int B_1;
 int wariant1;
 
 int R2;
 int G2;
 int B2;
 int wariant2;

 int R3;
 int G3;
 int B3;
 int wariant3;

 int R4;
 int G4;
 int B4;
 int wariant4;


void setup() 
{
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif

  Serial.begin(9600); //do wyswietlania w porcie szeregowym
  randomSeed(analogRead(A1)); //do liczb losowych

  pinMode(PRZYCISK_ON, INPUT_PULLUP); //Przycisk start
  pinMode(PRZYCISK_OFF,INPUT_PULLUP); //przycisk stop
  pinMode(PRZYCISK_MID, INPUT_PULLUP);

//  pinMode(czerwona, OUTPUT);
  pinMode(zielona_1, OUTPUT);
  pinMode(zielona_2, OUTPUT); 
  pinMode(zielona_3, OUTPUT);
  pinMode(zielona_4, OUTPUT); 

  R1 = random(255);
  G1 = random(255);
  B_1 = random(255);
  wariant1 = random(1,3);

  R2 = random(255);
  G2 = random(255);
  B2 = random(255);
  wariant2 = random(1,3);

  R3 = random(255);
  G3 = random(255);
  B3 = random(255);
  wariant3 = random(1,3);

  R4 = random(255);
  G4 = random(255);
  B4 = random(255);
  wariant4 = random(1,3);     

  pixels.begin(); //do odpalenia paska
 }



//ZMIENNE GLOBALNE - zeby byly raz i loop je widzial





int START = 0;
int MIEDZYCZAS = 0;
int ostatniadioda = 0; 
int punkt_1 = 0;
int punkt_2 = 0;
int punkt_3 = 0;
int punkt_4 = 0;
double best = 1000;



void loop() 
{
  pixels.clear();
  double potencjometr = analogRead(A0);
  double potencjometr2 = potencjometr*255/1024;
  
  if (digitalRead(PRZYCISK_ON) == LOW)
  {
    timer.start();
    Serial.println("START!");
    START++;
    
    delay(300);
  }



  if(START==1)
  {
        if(wariant1 == 1)
        {
          pixels.setPixelColor(0, pixels.Color(R1, G1, B_1));
          pixels.setPixelColor(1, pixels.Color(R1, G1, potencjometr2)); 

//                    Serial.println(B_1);
//                    Serial.println(potencjometr2);        
          
        }
        else if (wariant1 == 2)
        {
          pixels.setPixelColor(0, pixels.Color(R1, G1, B_1));
          pixels.setPixelColor(1, pixels.Color(R1, potencjometr2, B_1));
//                    Serial.println(G1);
//                    Serial.println(potencjometr2);        
        
        }
        else if (wariant1 == 3)
        {
          pixels.setPixelColor(0, pixels.Color(R1, G1, B_1));
          pixels.setPixelColor(1, pixels.Color(potencjometr2, G1, B_1)); 
//                    Serial.println(R1);
//                    Serial.println(potencjometr2);        
        
        }
    
      delay(100);
  }


  if (digitalRead(PRZYCISK_OFF) == LOW)
  {
    MIEDZYCZAS++;
    delay(300);

    
  }

  
  if(MIEDZYCZAS>=1)
  { 
    //digitalWrite(zielona, LOW);  
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    delay(10);
  }

if (digitalRead(PRZYCISK_OFF) == LOW)
{
 if(MIEDZYCZAS == 1)
 {
        if(wariant1 == 1)
        {

            if(B_1-25 <= potencjometr2 && B_1+25 >= potencjometr2)
            {
              digitalWrite(zielona_1, HIGH);
              punkt_1 = 1;
              delay(300);
            }

        }
        else if (wariant1 == 2)
        {

            if(G1-25 <= potencjometr2 && G1+25 >= potencjometr2)
            {
              digitalWrite(zielona_1,HIGH);
              punkt_1 = 1;
              delay(300);
            }
                  
        }
        else if (wariant1 == 3)
        {     

            if(R1-25 <= potencjometr2 && R1+25 >= potencjometr2)
            {
              digitalWrite(zielona_1,HIGH);
              punkt_1 = 1;
              delay(300);
            }  
                  
        }            
 }

 if(MIEDZYCZAS == 2)
 {

        if(wariant2 == 1)
        {

            if(B2-25 <= potencjometr2 && B2+25 >= potencjometr2)
            {
              digitalWrite(zielona_2, HIGH);
              punkt_2 = 1;
              delay(300);
            }

        }
        else if (wariant2 == 2)
        {

            if(G2-25 <= potencjometr2 && G2+25 >= potencjometr2)
            {
              digitalWrite(zielona_2,HIGH);
              punkt_2 = 1;
              delay(300);
            }
                  
        }
        else if (wariant2 == 3)
        {     

            if(R2-25 <= potencjometr2 && R2+25 >= potencjometr2)
            {
              digitalWrite(zielona_2,HIGH);
              punkt_2 = 1;
              delay(300);
            }  
                  
        }  
 }

 if(MIEDZYCZAS==3)
 {
    if(wariant3 == 1)
        {

            if(B3-25 <= potencjometr2 && B3+25 >= potencjometr2)
            {
              digitalWrite(zielona_3, HIGH);
              punkt_3 = 1;
              delay(300);
            }

        }
        else if (wariant3 == 2)
        {

            if(G3-25 <= potencjometr2 && G3+25 >= potencjometr2)
            {
              digitalWrite(zielona_3,HIGH);
              punkt_3 = 1;
              delay(300);
            }
                  
        }
        else if (wariant3 == 3)
        {     

            if(R3-25 <= potencjometr2 && R3+25 >= potencjometr2)
            {
              digitalWrite(zielona_3,HIGH);
              punkt_3 = 1;
              delay(300);
            }  
                  
        }  
 }

 if(MIEDZYCZAS == 4)
 {
          if(wariant4 == 1)
        {

            if(B4-25 <= potencjometr2 && B4+25 >= potencjometr2)
            {
              digitalWrite(zielona_4, HIGH);
              punkt_4 = 1;
              delay(300);
            }

        }
        else if (wariant4 == 2)
        {

            if(G4-25 <= potencjometr2 && G4+25 >= potencjometr2)
            {
              digitalWrite(zielona_4,HIGH);
              punkt_4 = 1;
              delay(300);
            }
                  
        }
        else if (wariant4 == 3)
        {     

            if(R4-25 <= potencjometr2 && R4+25 >= potencjometr2)
            {
              digitalWrite(zielona_4,HIGH);
              punkt_4 = 1;
              delay(300);
            }  
                  
        }  
 }
    
}

  if(MIEDZYCZAS==1)
  {

        if(wariant2 == 1)
        {
          pixels.setPixelColor(2, pixels.Color(R2, G2, B2));
          pixels.setPixelColor(3, pixels.Color(R2, G2, potencjometr2)); 
//                    Serial.println(B2);
//                    Serial.println(potencjometr2); 
        }
        else if (wariant2 == 2)
        {
          pixels.setPixelColor(2, pixels.Color(R2, G2, B2));
          pixels.setPixelColor(3, pixels.Color(R2, potencjometr2, B2));
//                    Serial.println(G2);
//                    Serial.println(potencjometr2);          
        }
        else if (wariant2 == 3)
        {
          pixels.setPixelColor(2, pixels.Color(R2, G2, B2));
          pixels.setPixelColor(3, pixels.Color(potencjometr2, G2, B2));     
//                    Serial.println(R2);
//                    Serial.println(potencjometr2);              
        }
       delay(100);
  }

      
  if(MIEDZYCZAS==2)
  {
 
//
//        if(wariant2 == 1)
//        {
//
//            if(B2-25 <= potencjometr2 && B2+25 >= potencjometr2)
//            {
//              digitalWrite(zielona_2, HIGH);
//              punkt_2 = 1;
//            }
//
//        }
//        else if (wariant2 == 2)
//        {
//
//            if(G2-25 <= potencjometr2 && G2+25 >= potencjometr2)
//            {
//              digitalWrite(zielona_2,HIGH);
//              punkt_2 = 1;
//            }
//                  
//        }
//        else if (wariant2 == 3)
//        {     
//
//            if(R2-25 <= potencjometr2 && R2+25 >= potencjometr2)
//            {
//              digitalWrite(zielona_2,HIGH);
//              punkt_2 = 1;
//            }  
//                  
//        }
      
        if(wariant3 == 1)
        {
          pixels.setPixelColor(4, pixels.Color(R3, G3, B3));
          pixels.setPixelColor(5, pixels.Color(R3, G3, potencjometr2)); 
//                    Serial.println(B3);
//                    Serial.println(potencjometr2);          
        }
        else if (wariant3 == 2)
        {
          pixels.setPixelColor(4, pixels.Color(R3, G3, B3));
          pixels.setPixelColor(5, pixels.Color(R3, potencjometr2, B3));
//                    Serial.println(G3);
//                    Serial.println(potencjometr2);          
        }
        else if (wariant3 == 3)
        {
          pixels.setPixelColor(4, pixels.Color(R3, G3, B3));
          pixels.setPixelColor(5, pixels.Color(potencjometr2, G3, B3));   
//                    Serial.println(R3);
//                    Serial.println(potencjometr2);                
        }
       delay(100); 
  }

  if(MIEDZYCZAS==3)
  {        
//    if(wariant3 == 1)
//        {
//
//            if(B3-25 <= potencjometr2 && B3+25 >= potencjometr2)
//            {
//              digitalWrite(zielona_3, HIGH);
//              punkt_3 = 1;
//            }
//
//        }
//        else if (wariant3 == 2)
//        {
//
//            if(G3-25 <= potencjometr2 && G3+25 >= potencjometr2)
//            {
//              digitalWrite(zielona_3,HIGH);
//              punkt_3 = 1;
//            }
//                  
//        }
//        else if (wariant3 == 3)
//        {     
//
//            if(R3-25 <= potencjometr2 && R3+25 >= potencjometr2)
//            {
//              digitalWrite(zielona_3,HIGH);
//              punkt_3 = 1;
//            }  
//                  
//        }
        
        if(wariant4 == 1)
        {
          pixels.setPixelColor(6, pixels.Color(R4, G4, B4));
          pixels.setPixelColor(7, pixels.Color(R4, G4, potencjometr2)); 
//                    Serial.println(B4);
//                    Serial.println(potencjometr2);           
        }
        else if (wariant4 == 2)
        {
          pixels.setPixelColor(6, pixels.Color(R4, G4, B4));
          pixels.setPixelColor(7, pixels.Color(R4, potencjometr2, B4));
//                    Serial.println(G4);
//                    Serial.println(potencjometr2);           
        }
        else if (wariant4 == 3)
        {
          pixels.setPixelColor(6, pixels.Color(R4, G4, B4));
          pixels.setPixelColor(7, pixels.Color(potencjometr2, G4, B4));   
//                    Serial.println(R4);
//                    Serial.println(potencjometr2);                 
        }
       delay(100);  
  }


 if(MIEDZYCZAS == 4)
 {
          if(wariant4 == 1)
        {

            if(B4-25 <= potencjometr2 && B4+25 >= potencjometr2)
            {
              digitalWrite(zielona_4, HIGH);
              punkt_4 = 1;
            }

        }
        else if (wariant4 == 2)
        {

            if(G4-25 <= potencjometr2 && G4+25 >= potencjometr2)
            {
              digitalWrite(zielona_4,HIGH);
              punkt_4 = 1;
            }
                  
        }
        else if (wariant4 == 3)
        {     

            if(R4-25 <= potencjometr2 && R4+25 >= potencjometr2)
            {
              digitalWrite(zielona_4,HIGH);
              punkt_4 = 1;
            }  
                  
        }
 }


  if (digitalRead(2) == LOW)
  {
    int punkty = punkt_1 + punkt_2 + punkt_3 + punkt_4;       
    timer.stop();
    
    if(punkty == 4)
    {
      Serial.println("WYGRALES!");
    }
    if(punkty == 3)
    {
      Serial.println("Przegrales :(  1 pomylka");
    }
    if(punkty == 2)
    {
      Serial.println("Przegrales :(  2 pomylki");
    }
    if(punkty == 1)
    {
      Serial.println("Przegrales :(  3 pomylki");
    }
    if(punkty == 0)
    {
      Serial.println("Przegrales :(  4 pomylki");
    }    
        
    Serial.print("Twoj czas: ");
    double czas_ms = timer.read();
    double czas_s = czas_ms * 1/1000;
    Serial.print(czas_s);
    Serial.println(" s");


    if(punkty == 4)
    {
      Serial.print("Najlepszy czas: ");
      if(czas_s <= best)
      {
        Serial.print(czas_s); 
        Serial.println(" s");
      }
      else
      {
        Serial.print(best);
        Serial.println(" s");
      }

      best = czas_s;
    }
    
    START=0;
    MIEDZYCZAS=0;
    punkt_1 = 0;
    punkt_2 = 0;
    punkt_3 = 0;
    punkt_4 = 0;
    
    digitalWrite(zielona_1,LOW);
    digitalWrite(zielona_2,LOW);
    digitalWrite(zielona_3,LOW);
    digitalWrite(zielona_4,LOW);
    
    delay(500);

    
  }



 


 pixels.show();
 delay(50);

}
