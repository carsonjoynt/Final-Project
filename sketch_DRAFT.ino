#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

AsyncDelay delay_2s;

float X, Y, Z, totalAccel;
bool rightButtonFlag;
bool leftButtonFlag;
int score = 0;
int randnumb = 0;
bool success = false;
bool gameOver = false;




void setup() {
  Serial.begin(9600);
  
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
  attachInterrupt(digitalPinToInterrupt(4), rightButtonToggle, CHANGE);
  attachInterrupt(digitalPinToInterrupt(5), leftButtonToggle, CHANGE);
  delay_2s.start(2000, AsyncDelay::MILLIS);

}

void rightButtonToggle(){
  rightButtonFlag = true;
}
//right Button

void leftButtonToggle(){
  leftButtonFlag = true;
}
//left button

void loop() {
  if (delay_2s.isExpired()){
    CircuitPlayground.clearPixels();
//clear pixles every loop

    randnumb = random(1, 4);
    Serial.println(randnumb);
//get the random number

    if (score < 11){
        for (int i = 0; i < score; i++){
          CircuitPlayground.setPixelColor(i, 0, 0, 255);
        }
    }
    //scoring 1-10

    if (score < 21 && score > 10){
        for (int i = 0; i < score-10; i++){
          CircuitPlayground.setPixelColor(i, 0, 255, 0);
        }
    }
    //scoring 10-20

    if (score < 31 && score > 20){
        for (int i = 0; i < score-20; i++){
          CircuitPlayground.setPixelColor(i, 0, 255, 255);
        }
    }
    //scoring 20-30

    if (score < 10){
      //level 1
      if (randnumb == 1){
//right button
        success = false;
        CircuitPlayground.playTone(200, 100);
        for (int i = 1; i < 4; i++){
          Serial.println("Count");
          delay(1000); 
          //timer

          if (success == false){
            if (rightButtonFlag && i < 4){
                Serial.println("Correct");
                (score ++);
                rightButtonFlag = false;
                gameOver = false;
                success = true;
            }else{
              gameOver = true;
            }
          }
        }
      }

      if (randnumb == 3){
        //left button
        success = false;
        CircuitPlayground.playTone(700, 100);
        for (int i = 1; i < 4; i++){
          Serial.println("Count");
          delay(1000); 

          if (success == false){
            if (leftButtonFlag && i < 4){
              Serial.println("Correct");
              (score ++);
              leftButtonFlag = false;
              gameOver = false;
              success = true;
            }
            else{
              gameOver = true;
            }  
          }
        }
      }

      if (randnumb == 2){
        //shake
        success = false;
        CircuitPlayground.playTone(1000, 100);
        for (int i = 1; i < 4; i++){
          Serial.println("Count");
          delay(1000); 


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

          if (success == false){
            if (totalAccel > 13 && i < 4 ){
              //if enough shake
              Serial.println("Correct!!");
              (score ++);
              rightButtonFlag = false;
              gameOver = false;
              success = true;
            }else{
              gameOver = true;
            }
          }
        }
      }
    }

    if (score >= 10 && score < 20){
      //level 2
      if (randnumb == 1){
//right button
        success = false;
        CircuitPlayground.playTone(200, 100);
        for (int i = 1; i < 5; i++){
          Serial.println("Count");
          delay(700); 

          if (success == false){
            if (rightButtonFlag && i < 3){
                Serial.println("Correct");
                (score ++);
                rightButtonFlag = false;
                gameOver = false;
                success = true;
            }else{
              gameOver = true;
            }
          }
        }
      }

      if (randnumb == 3){
        //left button
        success = false;
        CircuitPlayground.playTone(700, 100);
        for (int i = 1; i < 4; i++){
          Serial.println("Count");
          delay(700); 

          if (success == false){
            if (leftButtonFlag && i < 4){
              Serial.println("Correct");
              (score ++);
              leftButtonFlag = false;
              gameOver = false;
              success = true;
            }
            else{
              gameOver = true;
            }
         }
        }
      }

      if (randnumb == 2){
        //shake
        success = false;
        CircuitPlayground.playTone(1000, 100);
        for (int i = 1; i < 4; i++){
          Serial.println("Count");
          delay(700); 


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

          if (success == false){
            //if shaken enough
            if (totalAccel > 13 && i < 4 ){
              Serial.println("Correct!!");
              (score ++);
              rightButtonFlag = false;
              gameOver = false;
              success = true;
            }else{
              gameOver = true;
            }
          }
        }
      }
    }

    if (score >= 20 && score < 30){
      //level 3
      if (randnumb == 1){
        //right button
        success = false;
        CircuitPlayground.playTone(200, 100);
        for (int i = 1; i < 5; i++){
          Serial.println("Count");
          delay(500); 

          if (success == false){
            if (rightButtonFlag && i < 3){
                Serial.println("Correct");
                (score ++);
                rightButtonFlag = false;
                gameOver = false;
                success = true;
            }else{
              gameOver = true;
            }
          }
        }
      }

      if (randnumb == 3){
        //left button
        success = false;
        CircuitPlayground.playTone(700, 100);
        success = false;
        for (int i = 1; i < 4; i++){
          Serial.println("Count");
          delay(500); 

          if (success == false){
            if (leftButtonFlag && i < 4){
              Serial.println("Correct");
              (score ++);
              leftButtonFlag = false;
              gameOver = false;
              success = true;
            }else{
              gameOver = true;
            }
          }
        }
      }

      if (randnumb == 2){
        //shake
        success = false;
        CircuitPlayground.playTone(1000, 100);
        for (int i = 1; i < 4; i++){
          Serial.println("Count");
          delay(500); 


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

          if (success == false){
            if (totalAccel > 13 && i < 4 ){
              //shake check
              Serial.println("Correct!!");
              (score ++);
              rightButtonFlag = false;
              gameOver = false;
              success = true;
            }else{
              gameOver = true;
            }
          }
        }
      }
    }

    if (score >= 30){
      //win
        for (int i = 0; i < 2; i++){
          Serial.println("You Won!!!");
          CircuitPlayground.playTone(500, 100);
          CircuitPlayground.playTone(700, 200);
          CircuitPlayground.playTone(900, 300);


            for (int i = 0; i < 10; i++){
              CircuitPlayground.setPixelColor(i, 0, 255, 0);
            }       
            delay(500); 
            CircuitPlayground.clearPixels();

            for (int i = 0; i < 10; i++){
              CircuitPlayground.setPixelColor(i, 0, 0, 255);
            }       
            delay(500);  
            CircuitPlayground.clearPixels();

            for (int i = 0; i < 10; i++){
              CircuitPlayground.setPixelColor(i, 0, 255, 255);
            }       
          delay(500); 
          
          CircuitPlayground.clearPixels();
          (score = 0);

        }
    }

    Serial.print("Score: ");
    Serial.println(score);
    delay_2s.repeat();
  }

  if(gameOver == true){
    //lose
        for (int i = 0; i < 2; i++){
          Serial.println("You Lost!!!");
          CircuitPlayground.playTone(500, 100);
          CircuitPlayground.playTone(300, 200);
          CircuitPlayground.playTone(100, 300);


          for(int i = 0; i < 3; i++){

            for (int i = 0; i < 10; i++){
              CircuitPlayground.setPixelColor(i, 255, 0, 0);
            }
    
            delay(500); 

            CircuitPlayground.clearPixels();

            delay(500); 
          }
          (score = 0);
    gameOver = false;
  }
  }
}
