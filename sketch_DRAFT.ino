#include <Adafruit_CircuitPlayground.h>

float X, Y, Z, totalAccel;
bool rightButtonFlag;
bool leftButtonFlag;
volatile bool switchFlag;
volatile int onoff = 0;
volatile int score = 0;
int randnumb = 0;



void setup() {
  Serial.begin(9600);
  
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
  attachInterrupt(digitalPinToInterrupt(4), rightButtonToggle, CHANGE);
  attachInterrupt(digitalPinToInterrupt(5), leftButtonToggle, CHANGE);
  attachInterrupt(digitalPinToInterrupt(7), switchToggle, CHANGE);
}

void rightButtonToggle(){
  rightButtonFlag = true;
}

void leftButtonToggle(){
  leftButtonFlag = true;
}

void switchToggle(){
  switchFlag = true;
}

void loop() {
  randnumb = random(1, 4);
  Serial.println(randnumb);


  X = 0;
  Y = 0;
  Z = 0;
  for (int i=0; i<10; i++) {
    X += CircuitPlayground.motionX();
    Y += CircuitPlayground.motionY();
    Z += CircuitPlayground.motionZ();
    delay(1);
  }

  X /= 10;
  Y /= 10;
  Z /= 10;

  totalAccel = sqrt(X*X + Y*Y + Z*Z);

 // Serial.println(totalAccel);

  if (switchFlag == true){
      if (digitalRead(7) == 1){
        (onoff = 1);
      }
      if (digitalRead(7) == 0){
        (onoff = 0);
      }
     switchFlag = false;

  }

  if (randnumb == 1){
    CircuitPlayground.playTone(200, 100);
    for (int i = 1; i < 4; i++){
      Serial.println(":)");
      delay(1000); 


      if (rightButtonFlag && i < 4){
        Serial.println("YAY");
                //score + 1
        rightButtonFlag = false;
      }
      //else
        //clear pixles
        //play song
        //blink red
      //}
    }
  }

  if (randnumb == 2){
    CircuitPlayground.playTone(700, 100);
    for (int i = 1; i < 4; i++){
      Serial.println("HAPPY WORDS");
      delay(1000); 


      if (leftButtonFlag && i < 4){
        Serial.println("YOU DID GOOD");
                //score + 1
        rightButtonFlag = false;
      }
      //else
        //clear pixles
        //play song
        //blink red
      //}
    }
  }

  if (randnumb == 3){
    CircuitPlayground.playTone(1000, 100);
    for (int i = 1; i < 4; i++){
      Serial.println("Yay");
      delay(1000); 


      if (rightButtonFlag && i < 4){
        Serial.println("YOU DID IT!!");
                //score + 1
        rightButtonFlag = false;
      }
      //else
        //clear pixles
        //play song
        //blink red
      //}
    }
  }

  delay(2000); 

}
