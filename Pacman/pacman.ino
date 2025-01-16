#include <FastLED.h>
#include "tables.h"


#define NUM_COLS 60
#define NUM_ROWS 10

#define NUM_LEDS NUM_COLS*NUM_ROWS

CRGB leds[NUM_LEDS];
// Array untuk mengelompokan LED pertama
const int jumlahLED1 = 53;
int pinLED1[jumlahLED1] = {22,24,26,28,30,16,32,34,36,38,40,42,
44,46,48,50,52,1,4,6,8,10,12,14};

// Array untuk mengelompokan LED kedua
const int jumlahLED2 = 53;
int pinLED2[jumlahLED2] = {23,25,27,29,31,17,33,35,37,39,41,43,
45,47,49,51,53,2,5,7,9,11,13,15};

void setup() {
  FastLED.addLeds<WS2812B, 3, GRB>(leds, NUM_LEDS);
 
 // Inisialisasi semua pin LED di kelompok pertama sebagai output
  for (int i = 0; i < jumlahLED1; i++) {
    pinMode(pinLED1[i], OUTPUT);
  }

// Inisialisasi semua pin LED di kelompok kedua sebagai output 
  for (int i = 0; i < jumlahLED2; i++) {
    pinMode(pinLED2[i], OUTPUT);
  }

}
void loop() {
 pacman(); 
 FastLED.delay(60);

  // Menyalakan kelompok pertama dan mematikan kelompok kedua
  for (int i = 0; i < jumlahLED1; i++) {
    digitalWrite(pinLED1[i], HIGH);
  }
   for (int i = 0; i < jumlahLED2; i++) {
    digitalWrite(pinLED2[i], LOW); // Mematikan kelompok kedua
  }
  delay(100);
 
 // Mematikan kelompok pertama dan menyalakan kelompok kedua
  for (int i = 0; i < jumlahLED1; i++) {
    digitalWrite(pinLED1[i], LOW); //Matikan kelompok pertama 
  }
   for (int i = 0; i < jumlahLED2; i++) {
    digitalWrite(pinLED2[i], HIGH); // Menyalakan kelompok kedua
  }
  delay(100);
  
  

}

void pacman() {
  static byte frame = 0;
  static byte path = 0;
  byte virtWight = 100;
  byte next_Sprite_offset = 20;
  byte xIndex=0;
  int Leds_index;

  LEDS.clear();
  int index = frame*100;
  

  for (int i = 0; i < 3; i++) {
    for (int x = 0; x < 20; x++) {
      for (int y = 0; y < 2; y++) {
        int index = XY (x+i*20, 4+y);
        leds[index] = pgm_read_dword (Dots+y*20+(x+path)%4);
      }
    }
  }

  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
     
      int Spr_index = (y<<3)+(y<<1)+index+x;

      xIndex= (x+path)%virtWight;
      if (xIndex<60){
        Leds_index = XY (xIndex, y);
        leds[Leds_index] = pgm_read_dword (Mask11+Spr_index);
      }

      xIndex = (x+path+next_Sprite_offset)%virtWight;
      if (xIndex<60) {
        Leds_index = XY (xIndex, y);
        leds[Leds_index] = pgm_read_dword (Mask42+Spr_index);
      }

      xIndex = (x+path+next_Sprite_offset*2)%virtWight;
      if (xIndex<60) {
        Leds_index = XY (xIndex, y);
        leds[Leds_index] = pgm_read_dword (Mask41+Spr_index);
      }

      xIndex = (x+path+next_Sprite_offset*3)%virtWight;
      if (xIndex<60) {
       Leds_index = XY (xIndex, y);
       leds[Leds_index] = pgm_read_dword (Mask43+Spr_index);
      }

      xIndex = (x+path+next_Sprite_offset*4)%virtWight;
      if (xIndex<60) {
        Leds_index = XY (xIndex, y);
        leds[Leds_index] = pgm_read_dword (Mask44+Spr_index);
      }

    }
  }

 

  frame=(frame+1)%4;
  path=(path+1)%virtWight;
  
}


uint16_t XY (byte x, byte y) {
  return (y*NUM_COLS+x);
}