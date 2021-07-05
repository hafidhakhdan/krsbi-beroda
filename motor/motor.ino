#define frontBACKWISE 5
#define frontCLOCKWISE 4
#define leftCLOCKWISE 7
#define leftBACKWISE 8
#define backBACKWISE 9
#define backCLOCKWISE 10
#define rightCLOCKWISE 11
#define rightBACKWISE 12

int speed = 90;

void setup(){
   pinMode(rightCLOCKWISE, OUTPUT);
   pinMode(rightBACKWISE, OUTPUT);
   pinMode(leftCLOCKWISE, OUTPUT);
   pinMode(leftBACKWISE, OUTPUT);
   pinMode(backBACKWISE, OUTPUT);
   pinMode(backCLOCKWISE, OUTPUT);
   pinMode(frontBACKWISE, OUTPUT);
   pinMode(frontCLOCKWISE, OUTPUT);
   Serial.begin(9600);
}

void moveBackward()
{
   analogWrite(rightCLOCKWISE, speed);
   analogWrite(rightBACKWISE, 0);
   analogWrite(leftCLOCKWISE, speed);
   analogWrite(leftBACKWISE, 0);

   analogWrite(backBACKWISE, 0);
   analogWrite(backCLOCKWISE, 0);
   analogWrite(frontBACKWISE, 0);
   analogWrite(frontCLOCKWISE, 0);
}

void moveForward()
{
   analogWrite(rightCLOCKWISE, 0);
   analogWrite(rightBACKWISE, speed);
   analogWrite(leftCLOCKWISE, 0);
   analogWrite(leftBACKWISE, speed);

   analogWrite(backBACKWISE, 0);
   analogWrite(backCLOCKWISE, 0);
   analogWrite(frontBACKWISE, 0);
   analogWrite(frontCLOCKWISE, 0);
}

void moveRight()
{
   analogWrite(backBACKWISE, speed);
   analogWrite(backCLOCKWISE, 0);
   analogWrite(frontBACKWISE, speed);
   analogWrite(frontCLOCKWISE, 0);

   analogWrite(leftCLOCKWISE, 0);
   analogWrite(leftBACKWISE, 0);
   analogWrite(rightCLOCKWISE, 0);
   analogWrite(rightBACKWISE, 0);
}

void moveLeft()
{
   analogWrite(backBACKWISE, 0);
   analogWrite(backCLOCKWISE, speed);
   analogWrite(frontBACKWISE, 0);
   analogWrite(frontCLOCKWISE, speed);

   analogWrite(leftCLOCKWISE, 0);
   analogWrite(leftBACKWISE, 0);
   analogWrite(rightCLOCKWISE, 0);
   analogWrite(rightBACKWISE, 0);
}

void loop(){
   if (Serial.available() > 0) {
    String c = Serial.readString();
    if (c == "F"){
      moveForward();
      delay(2000);
    }
    else if (c == "B"){
      moveBackward();
      delay(2000);
    }
    else if (c == "L"){
      moveLeft();
      delay(2000); 
    }
    else {
      moveRight();
      delay(2000);
    }
   }
}