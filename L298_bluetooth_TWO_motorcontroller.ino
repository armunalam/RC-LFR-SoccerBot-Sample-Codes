//Thanks to CoolBoy IFTY
//LEFT
int ENA_L =7;
int IN1_L =8;
int IN2_L =9; 
int IN3_L =10; 
int IN4_L =11;
int ENB_L =12;

//RIGHT
int ENA_R= 5;
int IN1_R =15;
int IN2_R =16; 
int IN3_R =17; 
int IN4_R =18;
int ENB_R =6;

char incomingByte=0; // for incoming serial data
int speed_min = 135; //the minimum "speed" the motors will turn - take it lower and motors don't turn
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
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(ENA_L,OUTPUT);
pinMode(IN1_L,OUTPUT);
pinMode(IN2_L,OUTPUT);
pinMode(IN3_L,OUTPUT);
pinMode(IN4_L,OUTPUT);
pinMode(ENB_L,OUTPUT);
  // put your setup code here, to run once:
pinMode(ENA_R,OUTPUT);
pinMode(IN1_R,OUTPUT);
pinMode(IN2_R,OUTPUT);
pinMode(IN3_R,OUTPUT);
pinMode(IN4_R,OUTPUT);
pinMode(ENB_R,OUTPUT);
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
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,HIGH);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,HIGH);
  analogWrite(ENB_L,speed_left);
  //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,HIGH);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,HIGH);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,speed_right);

  
  };
void right(){
   //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,HIGH);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,HIGH);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,speed_left);
  //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,HIGH);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,HIGH);
  analogWrite(ENB_R,speed_right);
  
  };
void forward_left(){
  //left
  analogWrite(ENA_L,0);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,0);
  
  //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,HIGH);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,HIGH);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,speed_right);
  
  };
void forward_right(){
   //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,HIGH);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,HIGH);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,speed_left);

 //right
  analogWrite(ENA_R,0);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,0);
 
  };
void back_left(){
   //left
  analogWrite(ENA_L,0);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,0);
   //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,HIGH);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,HIGH);
  analogWrite(ENB_R,speed_right);

  
  };
void back_right(){
  //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,HIGH);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,HIGH);
  analogWrite(ENB_L,speed_left);

 //right
  analogWrite(ENA_R,0);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,0);
  
  
  };
void forward(){
 //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,HIGH);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,HIGH);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,speed_left);

 //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,HIGH);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,HIGH);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,speed_right);


  
  };
void backward(){
 //left
  analogWrite(ENA_L,speed_left);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,HIGH);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,HIGH);
  analogWrite(ENB_L,speed_left);

 //right
  analogWrite(ENA_R,speed_right);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,HIGH);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,HIGH);
  analogWrite(ENB_R,speed_right);


  };

void stopy(){
  //
    analogWrite(ENA_L,0);
  digitalWrite(IN1_L,LOW);
  digitalWrite(IN2_L,LOW);
  digitalWrite(IN3_L,LOW);
  digitalWrite(IN4_L,LOW);
  analogWrite(ENB_L,0);
  
  analogWrite(ENA_R,0);
  digitalWrite(IN1_R,LOW);
  digitalWrite(IN2_R,LOW);
  digitalWrite(IN3_R,LOW);
  digitalWrite(IN4_R,LOW);
  analogWrite(ENB_R,0); 
  };
