#include <Adafruit_NeoPixel.h>;
/*#include <stdio.h>
#include <stdlib.h>*/
#include <time.h>
#include <LEDMatrixDriver.hpp>


#define BUZZER1  4
#define BUZZER2  7

/*
//noel
const float note[12] = {65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47
                       };
void jingleBells(void) {

  // Vive le vent
const int nombreDeNotes = 49;
  const int tempo = 150; // plus c'est petit, plus c'est rapide
  const int melodie[][3] = { {4, 2, 2}, {4, 2, 2}, {4, 2, 4}, {4, 2, 2}, {4, 2, 2}, {4, 2, 4},
    {4, 2, 2}, {7, 2, 2},  {0, 2, 3},  {2, 2, 1},  {4, 2, 8},
    {5, 2, 2}, {5, 2, 2}, {5, 2, 3}, {5, 2, 1}, {5, 2, 2}, {4, 2, 2}, {4, 2, 3},
    {4, 2, 1}, {4, 2, 2}, {2, 2, 2}, {2, 2, 2}, {4, 2, 2}, {2, 2, 4}, {7, 2, 4},
    {4, 2, 2}, {4, 2, 2}, {4, 2, 4}, {4, 2, 2}, {4, 2, 2}, {4, 2, 4},
    {4, 2, 2}, {7, 2, 2},  {0, 2, 3},  {2, 2, 1},  {4, 2, 8},
    {5, 2, 2}, {5, 2, 2}, {5, 2, 3}, {5, 2, 1}, {5, 2, 2}, {4, 2, 2}, {4, 2, 3},
    {4, 2, 1}, {7, 2, 2}, {7, 2, 2}, {5, 2, 2}, {2, 2, 2}, {0, 2, 8}
  };

  int frequence;

  for ( int i = 0; i < nombreDeNotes ; i++ ) {
    frequence = round(note[melodie[i][0]] * 2 * (melodie[i][1] - 1));
    tone(4, frequence);
    delay(tempo * melodie[i][2] - 50);
    noTone(4);
    delay(50);
  }
}
  */


#define PIN 3
#define PIN2 5
#define PIN3 6
#define PIN4 10



#define NUMPIXELS 25
#define NUMPIXELS2 25
#define NUMPIXELS3 25
#define NUMPIXELS4 5



#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif



#define sensorpin  0 
#define sensorpin2  1
#define sensorpin3  2
#define sensorpin4  3



Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS4, PIN4, NEO_GRB + NEO_KHZ800);

 //Matrix
  const uint8_t LEDMATRIX_CS_PIN = 9;
  const int LEDMATRIX_SEGMENTS = 8;
  const int LEDMATRIX_WIDTH    = LEDMATRIX_SEGMENTS * 8;
  LEDMatrixDriver lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN);
  char text[] = "** LED MATRIX DEMO! ** (1234567890) ++ \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\" ++ <$%/=?'.@,> --";
  //const int ANIM_DELAY = 30;

void setup()
{

  //Matrix
    lmd.setEnabled(true);
    lmd.setIntensity(5); // 0 = low, 10 = high

  //Jeu Simon
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif

  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);

  Serial.begin(9600);
  pixels.begin();
  pixels2.begin();
  pixels3.begin();
  pixels4.begin();

  pixels.clear();pixels.show();
  pixels2.clear();pixels2.show();
  pixels3.clear();pixels3.show();
  pixels4.clear();pixels4.show();
  //Fin setup.
 }





 
//Simon
 int val = 0;
 int  val2 = 0;
 int  val3 =0;
 int  val4 = 0;

 int i = 0;
 int z = 0;
 

 int choix_utilisateur = 0;

 bool pret = false ;

 String myString;

 int tab[13];
 int  TAILLE = 13;

 int perdu = 0;
 unsigned long debut_partie;
 int iteration = 0;
 bool affiche_couleur = false;
 int nbr_jeux = 1;


  //Matrix
  int x=0, y=0;   // start top left
byte font[95][8] = { {0,0,0,0,0,0,0,0}, // SPACE
                     {0x10,0x18,0x18,0x18,0x18,0x00,0x18,0x18}, // EXCL
                     {0x28,0x28,0x08,0x00,0x00,0x00,0x00,0x00}, // QUOT
                     {0x00,0x0a,0x7f,0x14,0x28,0xfe,0x50,0x00}, // #
                     {0x10,0x38,0x54,0x70,0x1c,0x54,0x38,0x10}, // $
                     {0x00,0x60,0x66,0x08,0x10,0x66,0x06,0x00}, // %
                     {0,0,0,0,0,0,0,0}, // &
                     {0x00,0x10,0x18,0x18,0x08,0x00,0x00,0x00}, // '
                     {0x02,0x04,0x08,0x08,0x08,0x08,0x08,0x04}, // (
                     {0x40,0x20,0x10,0x10,0x10,0x10,0x10,0x20}, // )
                     {0x00,0x10,0x54,0x38,0x10,0x38,0x54,0x10}, // *
                     {0x00,0x08,0x08,0x08,0x7f,0x08,0x08,0x08}, // +
                     {0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x08}, // COMMA
                     {0x00,0x00,0x00,0x00,0x7e,0x00,0x00,0x00}, // -
                     {0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06}, // DOT
                     {0x00,0x04,0x04,0x08,0x10,0x20,0x40,0x40}, // /
                     {0x00,0x38,0x44,0x4c,0x54,0x64,0x44,0x38}, // 0
                     {0x04,0x0c,0x14,0x24,0x04,0x04,0x04,0x04}, // 1
                     {0x00,0x30,0x48,0x04,0x04,0x38,0x40,0x7c}, // 2
                     {0x00,0x38,0x04,0x04,0x18,0x04,0x44,0x38}, // 3
                     {0x00,0x04,0x0c,0x14,0x24,0x7e,0x04,0x04}, // 4
                     {0x00,0x7c,0x40,0x40,0x78,0x04,0x04,0x38}, // 5
                     {0x00,0x38,0x40,0x40,0x78,0x44,0x44,0x38}, // 6
                     {0x00,0x7c,0x04,0x04,0x08,0x08,0x10,0x10}, // 7
                     {0x00,0x3c,0x44,0x44,0x38,0x44,0x44,0x78}, // 8
                     {0x00,0x38,0x44,0x44,0x3c,0x04,0x04,0x78}, // 9
                     {0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x00}, // :
                     {0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x08}, // ;
                     {0x00,0x10,0x20,0x40,0x80,0x40,0x20,0x10}, // <
                     {0x00,0x00,0x7e,0x00,0x00,0xfc,0x00,0x00}, // =
                     {0x00,0x08,0x04,0x02,0x01,0x02,0x04,0x08}, // >
                     {0x00,0x38,0x44,0x04,0x08,0x10,0x00,0x10}, // ?
                     {0x00,0x30,0x48,0xba,0xba,0x84,0x78,0x00}, // @
                     {0x00,0x1c,0x22,0x42,0x42,0x7e,0x42,0x42}, // A
                     {0x00,0x78,0x44,0x44,0x78,0x44,0x44,0x7c}, // B
                     {0x00,0x3c,0x44,0x40,0x40,0x40,0x44,0x7c}, // C
                     {0x00,0x7c,0x42,0x42,0x42,0x42,0x44,0x78}, // D
                     {0x00,0x78,0x40,0x40,0x70,0x40,0x40,0x7c}, // E
                     {0x00,0x7c,0x40,0x40,0x78,0x40,0x40,0x40}, // F
                     {0x00,0x3c,0x40,0x40,0x5c,0x44,0x44,0x78}, // G
                     {0x00,0x42,0x42,0x42,0x7e,0x42,0x42,0x42}, // H
                     {0x00,0x7c,0x10,0x10,0x10,0x10,0x10,0x7e}, // I
                     {0x00,0x7e,0x02,0x02,0x02,0x02,0x04,0x38}, // J
                     {0x00,0x44,0x48,0x50,0x60,0x50,0x48,0x44}, // K
                     {0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x7c}, // L
                     {0x00,0x82,0xc6,0xaa,0x92,0x82,0x82,0x82}, // M
                     {0x00,0x42,0x42,0x62,0x52,0x4a,0x46,0x42}, // N
                     {0x00,0x3c,0x42,0x42,0x42,0x42,0x44,0x38}, // O
                     {0x00,0x78,0x44,0x44,0x48,0x70,0x40,0x40}, // P
                     {0x00,0x3c,0x42,0x42,0x52,0x4a,0x44,0x3a}, // Q
                     {0x00,0x78,0x44,0x44,0x78,0x50,0x48,0x44}, // R
                     {0x00,0x38,0x40,0x40,0x38,0x04,0x04,0x78}, // S
                     {0x00,0x7e,0x90,0x10,0x10,0x10,0x10,0x10}, // T
                     {0x00,0x42,0x42,0x42,0x42,0x42,0x42,0x3e}, // U
                     {0x00,0x42,0x42,0x42,0x42,0x44,0x28,0x10}, // V
                     {0x80,0x82,0x82,0x92,0x92,0x92,0x94,0x78}, // W
                     {0x00,0x42,0x42,0x24,0x18,0x24,0x42,0x42}, // X
                     {0x00,0x44,0x44,0x28,0x10,0x10,0x10,0x10}, // Y
                     {0x00,0x7c,0x04,0x08,0x7c,0x20,0x40,0xfe}, // Z
                      // (the font does not contain any lower case letters. you can add your own.)
                  };    // {}, //



 
void loop(){
 /*
  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels2.setPixelColor(i, pixels2.Color(0, 255, 0));
    pixels3.setPixelColor(i, pixels3.Color(255, 0, 0));
    pixels4.setPixelColor(i, pixels4.Color(125, 0, 125));
   
    
     for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));


      for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));


      for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

*/
  
//Simon
  val = analogRead(sensorpin);
  val2 = analogRead(sensorpin2);
  val3 = analogRead(sensorpin3);
  val4 = analogRead(sensorpin4);

if (val>400 and val4>400){
  pret = true ;
  }else{
    pret = false;
  }
  
  if (pret){
    affichage("START DANS");
    delay(500);
    for (i=0; i<4; i++){
      myString = String(3-i);
      if (i==3){
         affichage("START");
      }else{
        affichage(myString);
      }
      delay(500);
    }

    // tableau
     for(int i =0; i<TAILLE; i++){
        tab[i] = random(1, 5);
   
    }

    
    while (nbr_jeux < TAILLE+1 and perdu == 0){
      while (iteration < nbr_jeux and perdu == 0){ 
        if (affiche_couleur == false){
          for (z = 0; z < nbr_jeux; z++){
            change_couleur_des_led(tab[z]);
          }
          affiche_couleur = true;
          debut_partie = millis();
        }
        val = analogRead(sensorpin);
        val2 = analogRead(sensorpin2);
        val3 = analogRead(sensorpin3);
        val4 = analogRead(sensorpin4);
        if(val>400){
          choix_utilisateur = 1;
          }
        else if (val2>400){
          choix_utilisateur = 2;
          }
        else if (val3>400){
          choix_utilisateur = 3;
          }
        else if (val4>400){
          choix_utilisateur = 4;
          }
        if (choix_utilisateur == 1 || choix_utilisateur == 2 || choix_utilisateur == 3 || choix_utilisateur == 4){
          change_couleur_des_led_real_time(choix_utilisateur);
          if (choix_utilisateur == tab[iteration]){
            while (val >= 250 || val2 >= 250 || val3 >= 250 || val4 >= 250){
              val = analogRead(sensorpin);
              val2 = analogRead(sensorpin2);
              val3 = analogRead(sensorpin3);
              val4 = analogRead(sensorpin4);
            }
            change_couleur_des_led_real_time(99);
            iteration++;
            debut_partie = millis();
          }else{
            perdu = 1;
            change_couleur_des_led_real_time(99);
          }
          choix_utilisateur = 0;
        }else{
          if ((millis()-debut_partie) >= 3000){
            perdu = 1;
          }
        }
      }
      affiche_couleur = false;
      iteration = 0;
      nbr_jeux++;
      delay(400);
    }

    if (perdu == 0){
      affichage("BIEN JOUE VOUS AVEZ GAGNE");
      //jingleBells();
    }else{
      affichage("VOUS AVEZ PERDU AU LEVEL"+ String(nbr_jeux-1));
    }

    nbr_jeux = 1;
    iteration = 0;
    perdu = 0;
    pret = false;
 
   }
}
//Fonctions Simon
void change_couleur_des_led_real_time(int couleur){
  switch(couleur){
        case 1:  for(int i=0; i<NUMPIXELS; i++) { pixels.setPixelColor(i, pixels.Color(0, 0, 255));} pixels.show();tone(4,440,100); break;//bleu
        case 2:  for(int i=0; i<NUMPIXELS2; i++) { pixels2.setPixelColor(i, pixels2.Color(0, 255, 0));} pixels2.show();tone(4,350,100);break;//vert
        case 3:  for(int i=0; i<NUMPIXELS3; i++) { pixels3.setPixelColor(i, pixels3.Color(255, 0, 0));} pixels3.show();tone(4,500,100); break;// rouge
        case 4:  for(int i=0; i<NUMPIXELS4; i++) { pixels4.setPixelColor(i, pixels4.Color(125, 0, 125));} pixels4.show();tone(4,250,100);break;// mauve
        case 99: pixels.clear(); pixels.show();pixels2.clear(); pixels2.show();pixels3.clear(); pixels3.show();pixels4.clear(); pixels4.show();break;
  }
}
void change_couleur_des_led(int couleur){
  switch(couleur){
        case 1:  for(int i=0; i<NUMPIXELS; i++) { pixels.setPixelColor(i, pixels.Color(0, 0, 255));};  pixels.show();tone(4,440,100); delay(500);pixels.clear();pixels.show();delay(500);break;//bleu
        case 2:  for(int i=0; i<NUMPIXELS2; i++) { pixels2.setPixelColor(i, pixels2.Color(0, 255, 0));};  pixels2.show();tone(4,350,100);delay(500); pixels2.clear();pixels2.show();delay(500);break;//vert
        case 3:  for(int i=0; i<NUMPIXELS3; i++) { pixels3.setPixelColor(i, pixels3.Color(255, 0, 0));};  pixels3.show();tone(4,500,100);delay(500); pixels3.clear();pixels3.show();delay(500);break;// rouge
        case 4:  for(int i=0; i<NUMPIXELS4; i++) { pixels4.setPixelColor(i, pixels4.Color(125, 0, 125));};  pixels4.show();tone(4,250,100);delay(500);pixels4.clear();pixels4.show();delay(500);break;// mauve
  }
}




//Fonctions Matrix




void drawString(char* text, int len, int x, int y )
{
  for( int idx = 0; idx < len; idx ++ )
  {
    int c = text[idx] - 32;
    if( x + idx * 8  > LEDMATRIX_WIDTH )
      return;

    if( 8 + x + idx * 8 > 0 )
      drawSprite( font[c], x + idx * 8, y, 8, 8 );
  }
}




void drawSprite( byte* sprite, int x, int y, int width, int height )
{

  byte mask = B10000000;

  for( int iy = 0; iy < height; iy++ )
  {
    for( int ix = 0; ix < width; ix++ )
    {
      lmd.setPixel(x + ix, y + iy, (bool)(sprite[iy] & mask ));

      mask = mask >> 1;
    }
    mask = B10000000;
  }
}




 void affichage(String mot){
  Serial.print(mot);
  char text[mot.length()+1];
  mot.toCharArray(text, mot.length()+1);
  x=63;
  int len = strlen(text);

  for (int i=0; i<((len*8)+64); i++){
    drawString(text, len, x, 0);
    lmd.display();
    delay(30);
    if( --x < len * -8 ) {
      x = LEDMATRIX_WIDTH;
      }
    } 
  }
