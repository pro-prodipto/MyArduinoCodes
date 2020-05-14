//Code:
#define lmfor 7
#define lmbac 5
#define rmfor 2
#define rmbac 4
#define light 13

#define pwmr 6
#define pwml 3

int s1,s2,s3,s4,s5,s6,s7,s8;


void setup()
{
  pinMode(lmfor,OUTPUT);
  pinMode(lmbac,OUTPUT);
  pinMode(rmfor,OUTPUT);
  pinMode(rmbac,OUTPUT);

  pinMode(pwmr,OUTPUT);
  pinMode(pwml,OUTPUT);

  pinMode(light,OUTPUT); digitalWrite(light,LOW); //glitch..!!
 
  pinMode(15,INPUT);
  pinMode(14,INPUT);
  pinMode(16,INPUT);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
  pinMode(8,INPUT);
}

//take input..!!
void read(void)
{
  s1=digitalRead(14);
  s2=digitalRead(15);
  s3=digitalRead(16);
  s4=digitalRead(12);
  s5=digitalRead(11);
  s6=digitalRead(10);
  s7=digitalRead(9);
  s8=digitalRead(8);
}

void right(void)
{
  digitalWrite(lmfor,HIGH);
  digitalWrite(rmbac,LOW);
  digitalWrite(rmfor,LOW);
  digitalWrite(lmbac,LOW);
 
  analogWrite(pwmr,0);
  analogWrite(pwml,150);
}

void left(void)
{
  digitalWrite(rmfor,HIGH);
  digitalWrite(lmbac,LOW);
  digitalWrite(lmfor,LOW);
  digitalWrite(rmbac,LOW);
 
  analogWrite(pwmr,160);
  analogWrite(pwml,0);
}

void straight(void)
{
  digitalWrite(rmfor,HIGH);
  digitalWrite(lmfor,HIGH);
  digitalWrite(lmbac,LOW);
  digitalWrite(rmbac,LOW);
 
 
  analogWrite(pwmr,170);   //changed this i..!!(160)(20 diff)
  analogWrite(pwml,180);  
  
}
void stoppp(void)
{
  digitalWrite(rmfor,LOW);
  digitalWrite(rmbac,LOW);
  digitalWrite(lmfor,LOW);
  digitalWrite(lmbac,LOW);
 
  analogWrite(pwmr,0);
  analogWrite(pwml,0);
 
}

void sharpleft(void)
{
  digitalWrite(rmfor,HIGH);
  digitalWrite(rmbac,LOW);
  digitalWrite(lmfor,LOW);
  digitalWrite(lmbac,HIGH);
 
  analogWrite(pwmr,190);   //right less
  analogWrite(pwml,200);
 
}
void sharpright(void)
{
  digitalWrite(rmfor,LOW);
  digitalWrite(rmbac,HIGH);
  digitalWrite(lmfor,HIGH);
  digitalWrite(lmbac,LOW);
 
  analogWrite(pwmr,190);  //220
  analogWrite(pwml,200);  //240
}
void reverse(void)
{
  digitalWrite(rmfor,LOW);
  digitalWrite(rmbac,HIGH);
  digitalWrite(lmfor,LOW);
  digitalWrite(lmbac,HIGH);
 
  analogWrite(pwmr,125);
  analogWrite(pwml,125);
 
}

void loop()
{
read();
digitalWrite(light,HIGH);
delay(300);
digitalWrite(light,LOW);
read();
if((s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0 && s7==0 && s8==0))
{
digitalWrite(light,HIGH);
delay(300);
digitalWrite(light,LOW);
stoppp();
}
else if((s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1 && s7==1 && s8==1))
{
  reverse();
}
else if((s1==0 && s2==0 && s3==0 && s4==0 && s5==0) && (s6==1 && s7==1 &&s8==1))
{
  sharpleft();
}
else if((s1==1 && s2==1 && s3==1) && (s4==0&& s5==0 && s6==0 && s7==0&&s8==0))
{
  sharpright();
}
else if((s1+s2+s3)==(s6+s7+s8))
{
  straight();
}
else if((s1+s2+s3+s4)<(s5+s6+s7+s8))
{
  left();
}  
else if((s1+s2+s3+s4)>(s5+s6+s7+s8))
{
  right();
}  
}
