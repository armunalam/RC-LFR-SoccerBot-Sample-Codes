//Thanks to CoolBoy IFTY
#define ENA 5
#define IN1 6
#define IN2 7 
#define IN3 8 
#define IN4 9
#define ENB 10
int incomingByte=0; // for incoming serial data
int speed_min = 125; //the minimum "speed" the motors will turn - take it lower and motors don't turn
int speed_max = 255; //

int speed_left = speed_max; // set both motors to maximum speed
int speed_right = speed_max;

void left();
void right();
void forward();
void backward();
void forward_left();
void forward_right();
void back_left();
void back_right();


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(ENA,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(ENB,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
    incomingByte = Serial.read();
    }
  switch(incomingByte)
  {
     case 'S':
      {
        stopy();
       //Serial.println("Stop\n"); 
       incomingByte='*';}
     break;
     
     case 'B':
      
     {  backward();
       
      // Serial.println("Forward\n");
       incomingByte='*';}
     break;
    
      case 'F':
       
    {   forward();
      // Serial.println("Backward\n");
       incomingByte='*';}
     break;
     
     case 'R':
     // turn right
     {  
       right(); 
      // Serial.println("Rotate Right\n");
       incomingByte='*';}
     break;
       case 'L':
      { 
       left();     
       //Serial.println("Rotate Left\n");
       incomingByte='*';}
     break;
     case '1':
        
      { speed_left = 20; 
       speed_right = 20;
       //Serial.println("Speed 1\n");
       incomingByte='*';}
     break;
    case '2':
      { 
        speed_left = 40; 
       speed_right = 40;
       //Serial.println("Speed 2 \n");
       incomingByte='*';}
     break;
    case '3':
      { 
        speed_left = 60; 
       speed_right = 60;
       //Serial.println("Speed 3 \n");
       incomingByte='*';}
     break; 
        case '4':
      { 
        speed_left = 80; 
       speed_right = 80;
       //Serial.println("Speed 4 \n");
       incomingByte='*';}
     break; 
        case '5':
      { 
        speed_left = 100; 
       speed_right = 100;
       //Serial.println("Speed 5 \n");
       incomingByte='*';}
     break; 
        case '6':
      { 
        speed_left = 120; 
       speed_right = 120;
       //Serial.println("Speed 6 \n");
       incomingByte='*';}
     break; 
        case '7':
      { 
        speed_left = 140; 
       speed_right = 140;
      // Serial.println("Speed 7 \n");
       incomingByte='*';}
     break; 
        case '8':
      { 
        speed_left = 160; 
       speed_right = 160;
       //Serial.println("Speed 8 \n");
       incomingByte='*';}
     break; 
        case '9':
      { 
        speed_left = 200; 
       speed_right = 200;
       //Serial.println("Speed 9 \n");
       incomingByte='*';}
     break; 
        case 'q':
      { 
        speed_left = 255; 
       speed_right = 255;
       Serial.println("Speed full \n");
       incomingByte='*';}
     break; 
        case 'J':
      { 
       back_right();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'H':
      { 
       back_left();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'I':
      { 
       forward_right();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;
      case 'G':
      { 
      forward_left();
       Serial.println("Speed full \n");
       incomingByte='*';}
     break;      
  }

}
void left(){
  //left
  analogWrite(ENA,speed_left);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,speed_right);
  };
void right(){
   //right
  analogWrite(ENA,speed_left);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,speed_right);

  };
void forward_left(){
  forward_left
  analogWrite(ENA,speed_left);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,speed_right);
  

  };
void forward_right(){
   //forward right
  analogWrite(ENA,speed_left);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,speed_right);


  };
void back_right(){
   //backward right
  analogWrite(ENA,speed_left);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,speed_right);
 
  };
void back_left(){
  
  //backward left
  analogWrite(ENA,speed_left);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,speed_right);


  
  };
void forward(){
 //forward
  analogWrite(ENA,speed_left);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,speed_right);

  
  };
void backward(){
 //backward
  analogWrite(ENA,speed_left);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,speed_right);



  };

void stopy(){
  //stop
  analogWrite(ENA,0);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,0);
  };
