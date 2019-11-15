
#include <Adafruit_NeoPixel.h>;
#define PIN 3
#define PIN2 5
#define PIN3 6
//#define PIN4

#define NUMPIXELS 5
#define NUMPIXELS2 5
#define NUMPIXELS3 10

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
int sensorpin = 0;                 // analog pin used to connect the sharp sensor
int sensorpin2 = 1;
int sensorpin3 = 2;
int sensorpin4 = 3;
int val = 0;                 // variable to store the values from sensor(initially zero)
int val2 = 0;
int val3 = 0;
int val4 = 0;
int compteur;
int compteur2;
int compteur3;
int compteur4;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels4(NUMPIXELS4, PIN4, NEO_GRB + NEO_KHZ800);
void setup()
{
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  Serial.begin(9600);
  pixels.begin();
  pixels2.begin();
  pixels3.begin();
  //pixels4.begin();
}
 
void loop()
{
  val = analogRead(sensorpin);
  val2 = analogRead(sensorpin2);
  val3 = analogRead(sensorpin3);
  val4 = analogRead(sensorpin4);
  
  
 if (val > 200){
  for (compteur = 0 ; compteur < NUMPIXELS ; compteur ++)
  {
    pixels.setPixelColor(compteur, pixels.Color(0, 255, 0));
  }
  
  pixels.show();

  }
   else if (val2 > 200){
     for (compteur2 = 0 ; compteur2 < NUMPIXELS2 ; compteur2 ++)
  {
    pixels2.setPixelColor(compteur2, pixels2.Color(0, 0, 255));
  }
  
  pixels2.show();
  }


    else if (val3 > 200){
     for (compteur3 = 0 ; compteur3 < 5 ; compteur3 ++)
  {
    pixels3.setPixelColor(compteur3, pixels3.Color(255, 0, 0));
  }
  
  pixels3.show();
  }
  

     else if (val4 > 200){
     for (compteur4 = 5 ; compteur4 < 10 ; compteur4 ++)
  {
    pixels3.setPixelColor(compteur4, pixels3.Color(255, 175, 0));
  }
  
  pixels3.show();
  }
  
  
  else{pixels.clear(); pixels.show();pixels2.clear(); pixels2.show();pixels3.clear(); pixels3.show();}//pixels4.clear(); pixels4.show();}
  delay(100);
}
