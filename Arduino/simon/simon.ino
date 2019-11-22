
#include <Adafruit_NeoPixel.h>;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>






#define BUZZER1  4
#define BUZZER2  7

//got
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 void GameOfThrones()
  {
    for(int i=0; i<4; i++)
    {
    tone(BUZZER1, NOTE_G4);
    delay(500);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_C4);
    delay(500);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_DS4);
    delay(250);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_F4);
    delay(250);
    noTone(BUZZER1);
    }
    for(int i=0; i<4; i++)
    {
    tone(BUZZER1, NOTE_G4);
    delay(500);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_C4);
    delay(500);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_E4);
    delay(250);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_F4);
    delay(250);
    noTone(BUZZER1);
    }
        tone(BUZZER1, NOTE_G4);
        delay(500);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_C4);
        delay(500);
        tone(BUZZER1, NOTE_DS4);
        delay(250);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_F4);
        delay(250);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_D4);
        delay(500);
        noTone(BUZZER1);
    for(int i=0; i<3; i++)
    {
    tone(BUZZER1, NOTE_G3);
    delay(500);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_AS3);
    delay(250);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_C4);
    delay(250);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_D4);
    delay(500);
    noTone(BUZZER1);
    }//
        tone(BUZZER1, NOTE_G3);
        delay(500);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_AS3);
        delay(250);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_C4);
        delay(250);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_D4);
        delay(1000);
        noTone(BUZZER1);
         
        tone(BUZZER1, NOTE_F4);
        delay(1000);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_AS3);
        delay(1000);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_DS4);
        delay(250);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_D4);
        delay(250);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_F4);
        delay(1000);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_AS3);
        delay(1000);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_DS4);
        delay(250);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_D4);
        delay(250);
        noTone(BUZZER1);
        tone(BUZZER1, NOTE_C4);
        delay(500);
        noTone(BUZZER1);
    for(int i=0; i<3; i++)
    {
    tone(BUZZER1, NOTE_GS3);
    delay(250);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_AS3);
    delay(250);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_C4);
    delay(500);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_F3);
    delay(500);
    noTone(BUZZER1);
    }
          tone(BUZZER1, NOTE_G4);
          delay(1000);
          noTone(BUZZER1);
          tone(BUZZER1, NOTE_C4);
          delay(1000);
          noTone(BUZZER1);
          tone(BUZZER1, NOTE_DS4);
          delay(250);
          noTone(BUZZER1);
          tone(BUZZER1, NOTE_F4);
          delay(250);
          noTone(BUZZER1);
          tone(BUZZER1, NOTE_G4);
          delay(1000);
          noTone(BUZZER1);
          tone(BUZZER1, NOTE_C4);
          delay(1000);
          noTone(BUZZER1);
          tone(BUZZER1, NOTE_DS4);
          delay(250);
          noTone(BUZZER1);
          tone(BUZZER1, NOTE_F4);
          delay(250);
          noTone(BUZZER1);
          tone(BUZZER1, NOTE_D4);
          delay(500);
          noTone(BUZZER1);
    for(int i=0; i<4; i++)
    {
    tone(BUZZER1, NOTE_G3);
    delay(500);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_AS3);
    delay(250);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_C4);
    delay(250);
    noTone(BUZZER1);
    tone(BUZZER1, NOTE_D4);
    delay(500);
    noTone(BUZZER1);
    }
}









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
  



#define PIN 3
#define PIN2 5
#define PIN3 6
#define PIN4 9



#define NUMPIXELS 5
#define NUMPIXELS2 5
#define NUMPIXELS3 5
#define NUMPIXELS4 5



#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif



int sensorpin = 0;                 // analog pin used to connect the sharp sensor
int sensorpin2 = 1;
int sensorpin3 = 2;
int sensorpin4 = 3;



Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS4, PIN4, NEO_GRB + NEO_KHZ800);



void setup()
{
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
}

// On suppose a<b
int rand_a_b(int a, int b){
  return rand()%(b-a) +a;
}

void change_couleur_des_led(int couleur){
  switch(couleur){
        case 1:  pixels.setPixelColor(0, pixels.Color(0, 0, 255));  pixels.show();tone(4,440,100); delay(500);pixels.clear();pixels.show();delay(500);break;//bleu
        case 2:  pixels2.setPixelColor(0, pixels2.Color(0, 255, 0));  pixels2.show();tone(4,350,100);delay(500); pixels2.clear();pixels2.show();delay(500);break;//vert
        case 3:  pixels3.setPixelColor(0, pixels3.Color(255, 0, 0));  pixels3.show();tone(4,500,100);delay(500); pixels3.clear();pixels3.show();delay(500);break;// rouge
        case 4:  pixels4.setPixelColor(0, pixels4.Color(125, 0, 125));  pixels4.show();tone(4,250,100);delay(500);pixels4.clear();pixels4.show();delay(500);break;// mauve
  }
}

void change_couleur_des_led_real_time(int couleur){
  switch(couleur){
        case 1:  pixels.setPixelColor(0, pixels.Color(0, 0, 255));  pixels.show();tone(4,440,100); break;//bleu
        case 2:  pixels2.setPixelColor(0, pixels2.Color(0, 255, 0));  pixels2.show();tone(4,350,100);break;//vert
        case 3:  pixels3.setPixelColor(0, pixels3.Color(255, 0, 0));  pixels3.show();tone(4,500,100); break;// rouge
        case 4:  pixels4.setPixelColor(0, pixels4.Color(125, 0, 125));  pixels4.show();tone(4,250,100);break;// mauve
        case 99: pixels.clear(); pixels.show();pixels2.clear(); pixels2.show();pixels3.clear(); pixels3.show();pixels4.clear(); pixels4.show();break;
  }
}



 int val = 0;
 int  val2 = 0;
 int  val3 =0;
 int  val4 = 0;
 
 int choix_utilisateur = 0;

 bool pret = false ;

 int tab[13];
 int  TAILLE = 5;
 

 int perdu = 0;
 unsigned long debut_partie;
 int iteration = 0;
 bool affiche_couleur = false;
 int nbr_jeux = 1;
 


 
  
void loop(){

  val = analogRead(sensorpin);
  val2 = analogRead(sensorpin2);
  val3 = analogRead(sensorpin3);
  val4 = analogRead(sensorpin4);

    

if (val>250 and val4>250){
  pret = true ;
  }else{
    pret = false;
  }
  
 
  
  if (pret){
    Serial.println("Démarrage du jeux dans 5");
    for (int i=0; i<5; i++){
      Serial.println(5-i);
      delay(1000);
    }
    srand (time (NULL));
    for(int i=0; i<TAILLE; i++){
      tab[i] = rand_a_b(1,5);
      Serial.print(tab[i]);
      //change_couleur_des_led(tab[i]);
    }
    
    while (nbr_jeux < TAILLE+1 and perdu == 0){
      while (iteration < nbr_jeux and perdu == 0){  //1?
        if (affiche_couleur == false){
          for (int z = 0; z < nbr_jeux; z++){
            change_couleur_des_led(tab[z]);
            Serial.println("allume le ");
            Serial.print(tab[z]);
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
          Serial.println(choix_utilisateur);
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
            Serial.println("gagné la couleur");
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
      Serial.println("Jeu validé");
      affiche_couleur = false;
      iteration = 0;
      nbr_jeux++;
      delay(400);
    }

    if (perdu == 0){
      Serial.println("Youhooooooo!!!!!");
      jingleBells();
    }else{
      Serial.println("Tu as perdu!!!");  
       GameOfThrones();
    }

    nbr_jeux = 1;
    iteration = 0;
    perdu = 0;
    pret = false;
 
   }
  
}
