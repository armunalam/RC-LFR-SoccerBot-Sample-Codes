int value[6];
void setup()
{
Serial.begin(9600);
}
void loop(){
for(int i=0;i<=5;i++)
{
value[i]=analogRead(i);
Serial.print(value[i]);
Serial.print(" ");
}
Serial.println(" ");
}
