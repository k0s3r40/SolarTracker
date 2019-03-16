#include <Servo.h>
int topleft;
int topright;
int downleft;
int downright;
int waittime = 1;
#define   A_0  (A4)
#define   A_1  (A5)
#define   A_2  (A6)
#define   A_3  (A7)
Servo X;
Servo Y;
int Ypos;
int Xpos;


void setup() {
  Serial.begin(9600);
  Y.attach(13);
  X.attach(12);
  Ypos = 90;
  Xpos = 90;
  X.write(Xpos);
  Y.write(Ypos);



}

void loop() {
  topleft = analogRead(A_0);
  topright = analogRead(A_1);
  downleft = analogRead(A_2);
  downright = analogRead(A_3);

  if (topleft < downleft) {


    if (Ypos > 1) {
      Ypos -= 1;
      Y.write(Ypos);
    }

  }
  if (topleft > downleft) {

    if (Ypos < 179) {
      Ypos += 1;
      Y.write(Ypos);
    }


  }

  if (topright < downright) {

    if (Ypos > 1) {
      Ypos -= 1;
      Y.write(Ypos);
    }

  }
  if (topright > downright) {

    if (Ypos < 179) {
      Ypos += 1;
      Y.write(Ypos);
    }


  }


  if (downleft > downright) {

    if (Xpos < 179) {
      Xpos += 1;
      X.write(Xpos);
    }
  }



  if (downleft < downright)  {

    if (Xpos > 1) {
      Xpos -= 1;
      X.write(Xpos);
    }
  }

  if (topleft > topright) {

    if (Xpos < 179) {
      Xpos += 1;
      X.write(Xpos);
    }
  }



  if (topleft < topright)  {

    if (Xpos > 1) {
      Xpos -= 1;
      X.write(Xpos);
    }
  }

  delay(waittime);

}
