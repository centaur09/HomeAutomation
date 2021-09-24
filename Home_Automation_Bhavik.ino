/*
 * auther : Bhavik chauhan from Expensive Engineers
 * 
*/

int sound = 2;            // digital
int LDRSec = A0;           // analog
int flame = A1;          // analog
int LDRlight = A2;         // analog
int FSR = A3;              // analog

int cl=7;
int bzr = 8;
int brt1 = 9;
int brt2 = 10;

int clap = 0;

int s1;
int s2;
int s3;
int s4;
int s5;

#include <Servo.h>
Servo door;

void setup() 
{
  Serial.begin(9600);

  pinMode(sound, INPUT);
  pinMode(LDRSec, INPUT);
  pinMode(flame, INPUT);
  pinMode(LDRlight, INPUT);
  pinMode(FSR, INPUT);

  pinMode(cl, OUTPUT);
  pinMode(bzr, OUTPUT);
  pinMode(brt1, OUTPUT);
  pinMode(brt2, OUTPUT);
  door.attach(12);  
}

void loop() 
{
  s1 = digitalRead(sound);
  s2 = analogRead(LDRSec);
  s3 = analogRead(flame);
  s4 = analogRead(LDRlight);
  s5 = analogRead(FSR);

  Serial.println(" ");

//  delay(3000);
  
  Serial.print(s1);
  Serial.println("   Sound sensor ");
  Serial.print(s2);
  Serial.println("   Security");
  Serial.print(s3);
  Serial.println("   Flame ");
  Serial.print(s4);
  Serial.println("   light");
  Serial.print(s5);
  Serial.println("   parking");

// ================= Clapping lights =================

/*    
// Prefer to use this section saperately

  if(s1 == 1)
    {
      if(clap == 0)
        {
          digitalWrite(cl, HIGH);
          clap = 1;
          Serial.println(" Clapped !!! Lights are On ");
        }
      else
        {
          digitalWrite(cl, LOW);
          clap = 0;
          Serial.println(" Clapped !!! Lights are Off ");
        }
    
    }    
*/
  
// ================= Security system =================


  if(s2 >= 200 )
    {
      Serial.println(" Security Alert !!! ");
      Serial.println(" Alarm on !");

      digitalWrite(bzr, HIGH);
      delay(50);
      digitalWrite(bzr, LOW);      
      delay(50);
      digitalWrite(bzr, HIGH);
      delay(50);
      digitalWrite(bzr, LOW);      
      delay(50);
      
    }
   else
    {
      Serial.println(" All safe !");      
      digitalWrite(bzr, LOW);      
    }
  
// ================= Fire Alarm =================


  if(s3 > 256 )
    {
      Serial.println(" Fire Alert !!! ");
      Serial.println(" Alarm on !");
      
      digitalWrite(bzr, HIGH);
      delay(50);
      digitalWrite(bzr, LOW);      
      delay(50);
      digitalWrite(bzr, HIGH);
      delay(50);
      digitalWrite(bzr, LOW);      
      delay(50);
    }
   else
    {
      Serial.println(" All safe !!! ");
      
      digitalWrite(bzr, LOW);      
    }

// ================= brightness and light =================


  if(s4 > 256 )
    {
      Serial.println(" It's enlighten !!");
      Serial.println(" Lights off !");
      digitalWrite(brt1, LOW);
      digitalWrite(brt2, LOW);
      delay(50);
    }
   else
    {
      Serial.println(" It's dark !!");
      Serial.println(" Lights ON !!");
      digitalWrite(brt1, HIGH);      
      digitalWrite(brt2, HIGH);      
      delay(50);
    }

// ================= Parking Automation =================

  if(s5>256)
    {
      Serial.println(" Welcome !!");
      Serial.println(" Door open !!");
      door.write(70);
      delay(1000);
    }
  else
    {
        Serial.println(" Door closed ");
        delay(100);
        door.write(0);
        delay(100);
    }
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  
}
