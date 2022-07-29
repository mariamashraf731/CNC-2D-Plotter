#include <Servo.h>

const int StepX = 3;
const int DirX = 6;
const int StepY = 2;
const int DirY = 5;

Servo servo;
bool servoPos = LOW;

char command;
int Xpos = 0;
int Ypos = 0;

void moveX(bool dirX,int steps_num, int speedX );
void moveY(bool dirY,int steps_num, int speedY );

void pen_write(bool penDown);

void draw_square();
void draw_rectangle();
void draw_triangle();
void draw_face();
void draw_H();
void cube();

void setup() {
  
  Serial.begin(9600);
  
  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  servo.attach(11);
  servo.write(0);
}

void loop() {
  
  while(!Serial.available()){}
  command = Serial.read();
  Serial.println(command);
  switch(command)
  {
    
    case '0':
            draw_square();
    break;
    
    case '1':      
            draw_triangle();
    break;
    
    case '2':
            draw_rectangle();
    break;
    
    case '3':
            draw_H();
    break;
    
    case '4':
              pen_write(true);
              Serial.println(servoPos);
    break;
    
    case '5':
              pen_write(false);
              Serial.println(servoPos);
    break;
    
    case 'w':
            moveY(true,100,200);
    break;
    
    case 's':
             moveY(false,100,200);
    break;
    
    case 'd':
            moveX(true,100,200);
    break;
    
    case 'a':
            moveX(false,100,200);
    break;
  }
    
}
void moveX(bool dirX,int steps_num, int speedX )
{
  
  digitalWrite(DirX,dirX);
  for(int i = 0; i < steps_num;i++)
  {
    digitalWrite(StepX,HIGH);
    delayMicroseconds(speedX);
    digitalWrite(StepX,LOW);
    delayMicroseconds(speedX);
  }
  if(dirX)
  {
    Xpos+= steps_num;
  }
  else
  {
    Xpos-= steps_num;
  }
  
}
void moveY(bool dirY,int steps_num, int speedY )
  {
    digitalWrite(DirY,dirY);
    for(int i = 0; i < steps_num;i++)
    {
      digitalWrite(StepY,HIGH);
      delayMicroseconds(speedY);
      digitalWrite(StepY,LOW);
      delayMicroseconds(speedY);
    }
  if(dirY)
  {
    Ypos += steps_num;
  }
  else
  {
    Ypos -= steps_num;
  }
}

  
void pen_write(bool penDown)
{
 if(penDown)
 {
    servo.write(160);
    servoPos = HIGH;
 }   
 else
 {
    servo.write(40);
    servoPos = LOW;
 }    
  delay(500);
}

void draw_square()
{
  for(int i = 0;i< 500; i++)
  {
    moveX(true,1,200);
    moveY(false,1,200);
  }
  pen_write(true);
  
  moveX(true,1500,200);
  moveY(false,1500,200);
  moveX(false,1500,200);
  moveY(true,1500,200);
  
  pen_write(false);
  for(int i = 0;i< 500; i++)
  {
    moveX(false,1,200);
    moveY(true,1,200);
  }
}
void draw_rectangle()
{
  for(int i = 0;i< 500; i++)
  {
    moveX(true,1,200);
    moveY(false,1,200);
  }
  pen_write(true);
  
  moveX(true,1500,200);
  moveY(false,750,200);
  moveX(false,1500,200);
  moveY(true,750,200);
  
  pen_write(false);
  for(int i = 0;i< 500; i++)
  {
    moveX(false,1,200);
    moveY(true,1,200);
  }
}
void draw_triangle()
{
    
  for(int i = 0;i< 1000; i++)
  {
    moveX(true,1,200);
    moveY(false,1,200);
  }
  pen_write(true);
  for(int i = 0;i< 1000; i++)
  {
    moveX(true,1,200);
    moveY(false,2,200);
  }
  moveX(false,2000,200);
  for(int i = 0;i< 1000; i++)
  {
    moveX(true,1,200);
    moveY(true,2,200);
  }
  pen_write(false);
  for(int i = 0;i< 1000; i++)
  {
    moveX(false,1,200);
    moveY(true,1,200);
  }
  
}

void cube(){
  draw_square();
   for(int i=0;i<30 ; i++){
    moveY(false,30,200);
    moveX(true,30,200);}
    draw_square();
    for(int i=0;i<5 ; i++){
    moveY(true,500,200);}
    for(int i=0;i<30 ; i++){
    moveY(true,30,200);
    moveX(false,30,200);}
    for(int i=0;i<5 ; i++){
    moveX(false,250,200);}
    for(int i=0;i<30 ; i++){
    moveY(false,30,200);
    moveX(true,30,200);}
    for(int i=0;i<5; i++){
    moveY(false,500,200);}
    for(int i=0;i<30 ; i++){
    moveY(true,30,200);
    moveX(false,30,200);}   
}

void draw_face()
{ 
  for(int i = 0;i< 1000; i++)
  {
    moveX(true,1,200);
    moveY(false,1,200);
  }
  pen_write(true);
  
  moveY(false,500,200);
  
  pen_write(false);
  moveX(false,800,200);
  
  pen_write(true);
  moveY(true,500,200);
  pen_write(false);
    
  moveY(false,1500,200);
  moveX(false,300,200);
  pen_write(true);

  moveX(true,1400,200);
  pen_write(false);

  moveX(false,1400,200);
  moveY(true,2500,200);
}
void draw_H()
{
  for(int i = 0;i< 500; i++)
  {
    moveX(true,1,200);
    moveY(false,1,200);
  }
  pen_write(true);
  moveY(false,1500,200);
  moveY(true,750,200);
  moveX(true,500,200);
  moveY(true,750,200);
  moveY(false,1500,200);
  
 pen_write(false);
 moveX(false,500,200);
 
for(int i = 0;i< 500; i++)
  {
    moveX(false,1,200);
    moveY(true,1,200);
  }
}
