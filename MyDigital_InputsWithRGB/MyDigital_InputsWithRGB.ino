 //www.elegoo.com
//2016.12.08

//int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

// Define Pins
#define RED 3
#define GREEN 4
#define BLUE 5


byte leds = 0;

void setup() 
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void loop() 
{
  if (digitalRead(buttonApin) == LOW)
  {
    changeColors();
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    
  }
}

void changeColors(){
  #define delayTime 10 // fading time between colors
  // define variables
  int redValue;
  int greenValue;
  int blueValue;

  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 0;
  blueValue = 0;
  
  for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
    redValue -= 1;
    greenValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(RED, 255 - redValue);
    // analogWrite(GREEN, 255 - greenValue);
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(delayTime);
  }
  
  redValue = 0;
  greenValue = 255;
  blueValue = 0;
  
  for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(GREEN, 255 - greenValue);
    // analogWrite(BLUE, 255 - blueValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }
  
  redValue = 0;
  greenValue = 0;
  blueValue = 255;
  
  for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
  {
    // The following code has been rearranged to match the other two similar sections
    blueValue -= 1;
    redValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(BLUE, 255 - blueValue);
    // analogWrite(RED, 255 - redValue);
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(delayTime);
  }
  analogWrite(BLUE,255);
  analogWrite(GREEN,255);
  analogWrite(RED,255);
  delay(delayTime*60);
    analogWrite(BLUE,0);
  analogWrite(GREEN,0);
  analogWrite(RED,0);
}
