#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#include "Timer.h"
Timer timer;
#define BUTTON_ON 4
#define BUTTON_MID 2
#define BUTTON_OFF 3

#define LED_PIN 6
#define PIXEL_AMOUNT 8
Adafruit_NeoPixel pixels(PIXEL_AMOUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

#define GREEN_LED_PIN_1 11
#define GREEN_LED_PIN_2 10
#define GREEN_LED_PIN_3 9
#define GREEN_LED_PIN_4 8

//Global variables - not defined
 int R1;
 int G1;
 int B1;
 int case1;
 
 int R2;
 int G2;
 int B2;
 int case2;

 int R3;
 int G3;
 int B3;
 int case3;

 int R4;
 int G4;
 int B4;
 int case4;

void setup() 
{
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif

  Serial.begin(9600); //for display
  randomSeed(analogRead(A1)); //for random numbers
  
  pinMode(BUTTON_ON, INPUT_PULLUP); //Start Button
  pinMode(BUTTON_OFF,INPUT_PULLUP); //Stop Button
  pinMode(BUTTON_MID, INPUT_PULLUP);

  pinMode(GREEN_LED_PIN_1, OUTPUT);
  pinMode(GREEN_LED_PIN_2, OUTPUT); 
  pinMode(GREEN_LED_PIN_3, OUTPUT);
  pinMode(GREEN_LED_PIN_4, OUTPUT); 

  R1 = random(255);
  G1 = random(255);
  B1 = random(255);
  case1 = random(1,3);

  R2 = random(255);
  G2 = random(255);
  B2 = random(255);
  case2 = random(1,3);

  R3 = random(255);
  G3 = random(255);
  B3 = random(255);
  case3 = random(1,3);

  R4 = random(255);
  G4 = random(255);
  B4 = random(255);
  case4 = random(1,3);     

  pixels.begin(); //to start Adafruit NeoPixel
 }

//Global variables - defined
int START = 0;
int INTERVAL = 0;
int last_diode = 0; 
int point_1 = 0;
int point_2 = 0;
int point_3 = 0;
int point_4 = 0;
double best = 1000;

void loop() 
{
  pixels.clear();
  double potentiometer_1 = analogRead(A0);
  double potentiometer_2 = potentiometer_1*255/1024; //from analogread scale to RGB scale
  
  if (digitalRead(BUTTON_ON) == LOW){
    timer.start();
    Serial.println("START!");
    START++;
    delay(300);
  }



  if(START==1){
        if(case1 == 1){
          pixels.setPixelColor(0, pixels.Color(R1, G1, B1));
          pixels.setPixelColor(1, pixels.Color(R1, G1, potentiometer_2)); 
        }
        else if (case1 == 2){
          pixels.setPixelColor(0, pixels.Color(R1, G1, B1));
          pixels.setPixelColor(1, pixels.Color(R1, potentiometer_2, B1));
        }
        else if (case1 == 3){
          pixels.setPixelColor(0, pixels.Color(R1, G1, B1));
          pixels.setPixelColor(1, pixels.Color(potentiometer_2, G1, B1)); 
        }
    
      delay(100);
  }


  if (digitalRead(BUTTON_OFF) == LOW){
    INTERVAL++;
    delay(300);
  }

  
  if(INTERVAL>=1){  
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    delay(10);
  }

if (digitalRead(BUTTON_OFF) == LOW){
  if(INTERVAL == 1){
        if(case1 == 1){
            if(B1-25 <= potentiometer_2 && B1+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_1, HIGH);
              point_1 = 1;
              delay(300);
            }
        }
        else if (case1 == 2){
            if(G1-25 <= potentiometer_2 && G1+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_1,HIGH);
              point_1 = 1;
              delay(300);
            }        
        }
        else if (case1 == 3){     
            if(R1-25 <= potentiometer_2 && R1+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_1,HIGH);
              point_1 = 1;
              delay(300);
            }          
        }            
 }

 if(INTERVAL == 2){
        if(case2 == 1){
            if(B2-25 <= potentiometer_2 && B2+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_2, HIGH);
              point_2 = 1;
              delay(300);
            }
        }
        else if (case2 == 2){
            if(G2-25 <= potentiometer_2 && G2+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_2,HIGH);
              point_2 = 1;
              delay(300);
            }          
        }
        else if (case2 == 3){     
            if(R2-25 <= potentiometer_2 && R2+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_2,HIGH);
              point_2 = 1;
              delay(300);
            }           
        }  
 }

 if(INTERVAL==3){
    if(case3 == 1){
            if(B3-25 <= potentiometer_2 && B3+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_3, HIGH);
              point_3 = 1;
              delay(300);
            }
        }
        else if (case3 == 2){
            if(G3-25 <= potentiometer_2 && G3+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_3,HIGH);
              point_3 = 1;
              delay(300);
            }        
        }
        else if (case3 == 3){     
            if(R3-25 <= potentiometer_2 && R3+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_3,HIGH);
              point_3 = 1;
              delay(300);
            }          
        }  
 }

 if(INTERVAL == 4){
          if(case4 == 1){
            if(B4-25 <= potentiometer_2 && B4+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_4, HIGH);
              point_4 = 1;
              delay(300);
            }
        }
        else if (case4 == 2){
            if(G4-25 <= potentiometer_2 && G4+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_4,HIGH);
              point_4 = 1;
              delay(300);
            }          
        }
        else if (case4 == 3){     
            if(R4-25 <= potentiometer_2 && R4+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_4,HIGH);
              point_4 = 1;
              delay(300);
            }          
        }  
 }   
}

  if(INTERVAL==1){

        if(case1 == 1){
          pixels.setPixelColor(2, pixels.Color(R2, G2, B2));
          pixels.setPixelColor(3, pixels.Color(R2, G2, potentiometer_2)); 
        }
        else if (case1 == 2){
          pixels.setPixelColor(2, pixels.Color(R2, G2, B2));
          pixels.setPixelColor(3, pixels.Color(R2, potentiometer_2, B2));         
        }
        else if (case1 == 3){
          pixels.setPixelColor(2, pixels.Color(R2, G2, B2));
          pixels.setPixelColor(3, pixels.Color(potentiometer_2, G2, B2));                  
        }
       delay(100);
  }

      
  if(INTERVAL==2){
        if(case2 == 1){
          pixels.setPixelColor(4, pixels.Color(R3, G3, B3));
          pixels.setPixelColor(5, pixels.Color(R3, G3, potentiometer_2));           
        }
        else if (case2 == 2)
        {
          pixels.setPixelColor(4, pixels.Color(R3, G3, B3));
          pixels.setPixelColor(5, pixels.Color(R3, potentiometer_2, B3));         
        }
        else if (case2 == 3)
        {
          pixels.setPixelColor(4, pixels.Color(R3, G3, B3));
          pixels.setPixelColor(5, pixels.Color(potentiometer_2, G3, B3));                  
        }
       delay(100); 
  }

  if(INTERVAL==3){            
        if(case3 == 1){
          pixels.setPixelColor(6, pixels.Color(R4, G4, B4));
          pixels.setPixelColor(7, pixels.Color(R4, G4, potentiometer_2));           
        }
        else if (case3 == 2){
          pixels.setPixelColor(6, pixels.Color(R4, G4, B4));
          pixels.setPixelColor(7, pixels.Color(R4, potentiometer_2, B4));           
        }
        else if (case3 == 3){
          pixels.setPixelColor(6, pixels.Color(R4, G4, B4));
          pixels.setPixelColor(7, pixels.Color(potentiometer_2, G4, B4));                    
        }
       delay(100);  
  }


 if(INTERVAL == 4){
          if(case4 == 1){
            if(B4-25 <= potentiometer_2 && B4+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_4, HIGH);
              point_4 = 1;
            }
        }
        else if (case4 == 2){
            if(G4-25 <= potentiometer_2 && G4+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_4,HIGH);
              point_4 = 1;
            }       
        }
        else if (case4 == 3){     
            if(R4-25 <= potentiometer_2 && R4+25 >= potentiometer_2){
              digitalWrite(GREEN_LED_PIN_4,HIGH);
              point_4 = 1;
            }         
        }
 }

  if (digitalRead(2) == LOW){
    int points_total = point_1 + point_2 + point_3 + point_4;       
    timer.stop();
    
    if(points_total == 4) {Serial.println("YOU WIN!");}
    else if(points_total == 3) {Serial.println("You lose :(  1 mistake");}
    else if(points_total == 2) {Serial.println("You lose :(  2 mistakes");}
    else if(points_total == 1){Serial.println("You lose :(  3 mistakes");}
    else if(points_total == 0){Serial.println("You lose :(  4 mistakes");}
        
    Serial.print("Your time: ");
    double time_ms = timer.read();
    double time_s = time_ms * 1/1000;
    Serial.print(time_s);
    Serial.println(" s");


    if(points_total == 4){
      Serial.print("Best time: ");
      if(time_s <= best){
        Serial.print(time_s); 
        Serial.println(" s");
      }
      else{
        Serial.print(best);
        Serial.println(" s");
      }
      best = time_s;
    }
    
    START=0;
    INTERVAL=0;
    point_1 = 0;
    point_2 = 0;
    point_3 = 0;
    point_4 = 0;
    
    digitalWrite(GREEN_LED_PIN_1,LOW);
    digitalWrite(GREEN_LED_PIN_2,LOW);
    digitalWrite(GREEN_LED_PIN_3,LOW);
    digitalWrite(GREEN_LED_PIN_4,LOW);
    
    delay(500);
  }
  
 pixels.show();
 delay(50);
}
