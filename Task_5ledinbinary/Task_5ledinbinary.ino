//To glow led in binary manner till 15

bool statusPb;
int timer=1000;
int pin4=11;
int pin3=10;
int pin2=9;
int pin1=8;
int buttonPin=7;
int x=0;

void setup () 
{
  pinMode (7,INPUT);
  pinMode (12,OUTPUT);
  pinMode (11,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (9,OUTPUT);
}

void loop () {
    statusPb = digitalRead(buttonPin);
    delay(300);
    if(statusPb==1){
      x++;
    }
    switch(x){
      case 1:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,LOW);
      break;
      
      case 2:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,HIGH);
      break;
      
      case 3:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,HIGH);
      digitalWrite(pin4,LOW);
      break;

      case 4:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,HIGH);
      digitalWrite(pin4,HIGH);
      break;

      case 5:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,LOW);
      break;

      case 6:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,HIGH);
      break;

      case 7:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,HIGH);
      digitalWrite(pin4,LOW);
      break;

      case 8:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,HIGH);
      digitalWrite(pin4,HIGH);
      break;

      case 9:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,LOW);
      break;

      case 10:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,HIGH);
      break;

      case 11:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,HIGH);
      digitalWrite(pin4,LOW);
      break;

      case 12:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,HIGH);
      digitalWrite(pin4,HIGH);
      break;

      case 13:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,LOW);
      break;

      case 14:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,HIGH);
      break;

      case 15:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,HIGH);
      digitalWrite(pin4,LOW);
      break;

      case 16:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin3,HIGH);
      digitalWrite(pin4,HIGH);
      break;
  }
}
