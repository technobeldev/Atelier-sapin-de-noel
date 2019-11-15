
#include <Adafruit_NeoPixel.h>;
#define PIN 3
#define PIN2 
#define NUMPIXELS 5
#define NUMPIXELS2 5
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
int sensorpin = 0;                 // analog pin used to connect the sharp sensor
int sensorpin2 =
int val = 0;                 // variable to store the values from sensor(initially zero)
int val2 = 0;
int compteur;
int compteur2;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  Serial.begin(9600);
  pixels.begin();
}
 
void loop()
{
  val = analogRead(sensorpin);
  val2 = analogRead(sensorpin2);
 if (val > 150){
  for (compteur = 0 ; compteur < NUMPIXELS ; compteur ++)
  {
    pixels.setPixelColor(compteur, pixels.Color(0, 255, 0));
  }
  pixels.show();

  }
   else if (val2 > 150){
     for (compteur2 = 0 ; compteur2 < NUMPIXELS2 ; compteur2 ++)
  {
    pixels.setPixelColor(compteur, pixels.Color(0, 0, 255));
  }
  pixels.show();
  }
  }
  
  else{pixels.clear(); pixels.show();}
  delay(100);
}
