#include <LEDMatrixDriver.hpp>

// This draw a moving sprite on your LED matrix using the hardware SPI driver Library by Bartosz Bielawski.
// Example written 16.06.2017 by Marko Oette, www.oette.info

// Define the ChipSelect pin for the led matrix (Dont use the SS or MISO pin of your Arduino!)
// Other pins are Arduino specific SPI pins (MOSI=DIN, SCK=CLK of the LEDMatrix) see https://www.arduino.cc/en/Reference/SPI
const uint8_t LEDMATRIX_CS_PIN = 9;

// Number of 8x8 segments you are connecting
const int LEDMATRIX_SEGMENTS = 4;
const int LEDMATRIX_WIDTH    = LEDMATRIX_SEGMENTS * 8;

// The LEDMatrixDriver class instance
LEDMatrixDriver lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN);

void setup() {
  // init the display
  lmd.setEnabled(true);
  lmd.setIntensity(2);   // 0 = low, 10 = high
}

int x=-1, y=0;   // start top left
bool s = true;  // start with led on

byte a[8]={ B00001000,
            B00101010,
            B00010100,
            B01101011,
            B00010100,
            B00101010,
            B00001000,
            B00000000};

byte b[8]={ B00001000,
            B00101010,
            B00010100,
            B01101011,
            B00010100,
            B00101010,
            B00001000,
            B00000000};

byte c[8]={ B00001000,
            B00101010,
            B00010100,
            B01101011,
            B00010100,
            B00101010,
            B00001000,
            B00000000};

byte d[8]={ B00001000,
            B00101010,
            B00010100,
            B01101011,
            B00010100,
            B00101010,
            B00001000,
            B00000000};

byte e[8]={ B00001000,
            B00101010,
            B00010100,
            B01101011,
            B00010100,
            B00101010,
            B00001000,
            B00000000};

byte f[8]={ B00001000,
            B00101010,
            B00010100,
            B01101011,
            B00010100,
            B00101010,
            B00001000,
            B00000000};

const int ANIM_DELAY = 100;

void loop() {


  
  if (Serial.available()>0){
    if(Serial.read() == 'A')


  
  drawSprite( (byte*)&a, x++, 0, 8, 8 );
  lmd.display();
  delay(ANIM_DELAY);

  lmd.clear();
  drawSprite( (byte*)&b, x++, 0, 8, 8 );
  lmd.display();
  delay(ANIM_DELAY);

  lmd.clear();
  drawSprite( (byte*)&c, x++, 0, 8, 8 );
  lmd.display();
  delay(ANIM_DELAY);

  lmd.clear();
  drawSprite( (byte*)&d, x++, 0, 8, 8 );
  lmd.display();
  delay(ANIM_DELAY);

  lmd.clear();
  drawSprite( (byte*)&e, x++, 0, 8, 8 );
  lmd.display();
  delay(ANIM_DELAY);

  lmd.clear();
  drawSprite( (byte*)&f, x++, 0, 8, 8 );
  lmd.display();
  delay(ANIM_DELAY);

  if( x > LEDMATRIX_WIDTH )
    x= -1;
}
    else
      Serial.print("Prout");
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
