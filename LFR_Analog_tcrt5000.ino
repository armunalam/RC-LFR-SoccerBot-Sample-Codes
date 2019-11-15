//after setting pins for motor driver it should be checked that the motor is working 
//forward or reverse
#define inA 6 
#define inB 7 
#define inC 8
#define inD 9
#define ena 5
#define enb 10
//sensor analog value should be taken before placing it to th[] array

int th[5]={134,146,170,160,37};
void wheel(int lm, int rm);
int i,sen[5],s[5], lastSensor,lastError;
int base_L=65;
int base_R=65;
float kp=2;
float kd=0;
void setup()
{
  mot_init();
  other_init();
}
void loop()
{
 line_follow();
  //wheel(255,255);
}


void other_init()
{
  lastSensor=0;
  lastError=0;
  Serial.begin(9600);
}

void mot_init()
{
  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inD,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  
  digitalWrite(inA,HIGH);
  digitalWrite(inB,HIGH);
  digitalWrite(inC,HIGH);
  digitalWrite(inD,HIGH);
}

void wheel(int lm, int rm)
{
  if(lm==0)
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,HIGH);
  }
  if(lm>0)
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,LOW);
  }
  else if(lm<0)
  {
    digitalWrite(inC,LOW);
    digitalWrite(inD,HIGH);
  }


  if(rm==0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,HIGH);
  }
  if(rm>0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }
  else if(rm<0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
  }
  if(lm>254) lm=254;
  if(lm<-254) lm=-254;
  if(rm>254) rm=254;
  if(rm<-254) rm=-254;
  
  analogWrite(ena,abs(rm));
  analogWrite(enb,abs(lm));
  
}

int readSensor()
{
  for(i=0;i<5;i++)
  { 
    sen[i]=analogRead(i);
    if(sen[i]<th[i])
    {
      s[i]=1;
    }
    else { 
      s[i]=0;
    }
  }
  
  int error,sum;
  sum=s[0]+s[1]+s[2]+s[3]+s[4];
  if(sum!=0)
  {
    error=(s[0]*10+s[1]*20+s[2]*30+s[3]*40+s[4]*50)/sum-30;
  }
  else
  {
     error=420;
  }
  
  if(s[0]==1) lastSensor=1;
  else if(s[4]==1) lastSensor =2;
Serial.println(error);
  return error;
}
 

void line_follow()
{
  int error,corr;
  float p,d;
 error=readSensor();
 if(error==420)
 {
   if(lastSensor==1) wheel(-180,180);
   else if(lastSensor==2) wheel(180,-180);
 }
 else 
 { 
   p=kp*error;
   d=kd*(error-lastError);
   corr=p+d;
 //  Serial.println(corr);
   wheel(base_L+corr,base_R-corr);
   if((error-lastError)!=0) delay(5);
   lastError=error;
 }
 
}
