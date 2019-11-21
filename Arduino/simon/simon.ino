
#include <Adafruit_NeoPixel.h>;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIN 3
#define PIN2 5
#define PIN3 6
#define PIN4 9

#define NUMPIXELS 5
#define NUMPIXELS2 5
#define NUMPIXELS3 10
#define NUMPIXELS4 150

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
int sensorpin = 0;                 // analog pin used to connect the sharp sensor
int sensorpin2 = 1;
int sensorpin3 = 2;
int sensorpin4 = 3;
/*int val = 0;                 // variable to store the values from sensor(initially zero)
int val2 = 0;
int val3 = 0;
int val4 = 0;
int compteur;
int compteur2;
int compteur3;
int compteur4;*/
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS4, PIN4, NEO_GRB + NEO_KHZ800);




void setup()
{
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
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
        case 1:  pixels.setPixelColor(0, pixels.Color(0, 0, 255));  pixels.show(); delay(1000);pixels.clear();pixels.show();delay(500);break;//bleu
        case 2:  pixels2.setPixelColor(0, pixels2.Color(0, 255, 0));  pixels2.show(); delay(1000); pixels2.clear();pixels2.show();delay(500);break;//vert
        case 3:  pixels3.setPixelColor(0, pixels3.Color(255, 0, 0));  pixels3.show(); delay(1000); pixels3.clear();pixels3.show();delay(500);break;// rouge
        case 4:  pixels.setPixelColor(2, pixels.Color(255, 255, 255));  pixels.show(); delay(1000);pixels.clear();pixels.show();delay(500);break;// bleu
  }
}

void change_couleur_des_led_real_time(int couleur){
  switch(couleur){
        case 1:  pixels.setPixelColor(0, pixels.Color(0, 0, 255));  pixels.show(); break;//bleu
        case 2:  pixels2.setPixelColor(0, pixels2.Color(0, 255, 0));  pixels2.show();break;//vert
        case 3:  pixels3.setPixelColor(0, pixels3.Color(255, 0, 0));  pixels3.show(); break;// rouge
        case 4:  pixels.setPixelColor(2, pixels.Color(255, 255, 255));  pixels.show();break;// rouge
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
 int  TAILLE = 13;
 

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
          if ((millis()-debut_partie) >= 1000000){
            perdu = 1;
          }
        }
      }
      Serial.println("Jeu validé");
      affiche_couleur = false;
      iteration = 0;
      nbr_jeux++;
      delay(2000);
    }

    if (perdu == 0){
      Serial.println("Youhooooooo!!!!!");
    }else{
      Serial.println("Tu as perdu!!!");
    }

    nbr_jeux = 1;
    iteration = 0;
    perdu = 0;
    pret = false;
    /*for (int i=0; i<TAILLE and pret and i<TAILLE_MAX; i++){
      
      
      if (choix_utilisateur == tab[i]){
        
        pret == true;
      }
      else{
        pret = false;
        }
        }*/
   }
}
    
  

    

  
  


  

  
  
 /*if (val > 200){
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
  
  delay(100);*/
