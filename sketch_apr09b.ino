#include <Adafruit_NeoPixel.h>

#define PIN1        11 // On Trinket or Gemma, suggest changing this to 1
#define PIN2       12 //orange small ring 12 
#define PIN3       13

#define NUMPIXELS2      12
#define NUMPIXELS3      16
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS1 16 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels1(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int busyRead = 4;
int knockRead = 6;
int nothingRead = 8;

int busyState;
int knockState;
int nothingState;

void setup() {
  // put your setup code here, to run once:
  pinMode(busyRead, INPUT);
  pinMode(knockRead, INPUT);
  pinMode(nothingRead, INPUT);
  pixels1.begin();
pixels2.begin();
pixels3.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  busyState = digitalRead(busyRead);
  knockState = digitalRead(knockRead);
  nothingState = digitalRead(nothingRead);
  if((busyState == HIGH) && (knockState == LOW) && (nothingState == LOW)){
    for(int i = 0; i<NUMPIXELS1;i++){
      pixels1.setPixelColor(i, pixels1.Color(250,0,0));
    }
    pixels1.show();
  }
  else if((busyState == LOW) && (knockState == HIGH) && (nothingState == LOW)){
    for(int i = 0; i<NUMPIXELS2;i++){
      pixels2.setPixelColor(i, pixels2.Color(250,250,0));
    }
    pixels2.show();
  }
   else if((busyState == LOW) && (knockState == LOW) && (nothingState == HIGH)){
    for(int i = 0; i<NUMPIXELS3;i++){
      pixels3.setPixelColor(i, pixels3.Color(0,250,0));
    }
    pixels3.show();
  }
  else{
    for(int i = 0; i<NUMPIXELS1;i++){
      pixels1.setPixelColor(i, pixels1.Color(0,0,0));
    }
    pixels1.show();
  }
  for(int j = 0; j<NUMPIXELS2;j++){
      pixels2.setPixelColor(j, pixels2.Color(0,0,0));
    }
    pixels2.show();
    for(int k = 0; k<NUMPIXELS3;k++){
      pixels3.setPixelColor(k, pixels2.Color(0,0,0));
    }
    pixels3.show();
}
