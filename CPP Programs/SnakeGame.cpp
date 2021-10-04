#include<iostream.h>
#include<graphics.h>/*For use of circle, rectangle and fillellipse command to use as snake and border*/
#include<conio.h>
#include<stdlib.h>
#include<dos.h>/*to use the function delay*/
#include<fstream.h>/*To use file that saves the highest score*/
int a[2000],b[2000],x,flag,y,gameover,fx,fy,count,d,n;
void initial() /*Initial data for the border and the starting of snake and the location of the food*/
 {
 x=6,flag=0,y=54,gameover=0,count=0;
  a[0]=x;
  b[0]=y;
  n=0;
  rectangle(0,450,600,48);
  fillellipse(x,y,3,3);
  c:
  fx=rand()%600;
  if(fx<=0||fx%6!=0)
  goto c;
  d:
  fy=rand()%450;
  if(fy<=48||fy%6!=0)
  goto d;
  }
void movement()/* This is used to detect if a key is pressed during running of the program*/
{
 if(kbhit())
 {
  switch(getch())
  {
   case 'a':
   flag=1;
   break;
   case 's':
   flag=2;
   break;
   case 'd':
   flag=3;
   break;
   case 'w':
   flag=4;
   break;
   case 'x':
   gameover=1;
  }
 }
}
void check()/* It is main part of program that checks that snake is not touched to the boundry and to itself. It also increases the score when food is eatten by the snake.*/
{
 int i,l,k;
 for(i=n;i>=1;i--)
 {
  a[i]=a[i-1];
  b[i]=b[i-1];
 }
 switch(flag)
 {
  case 1:
   x=x-6;
   a[0]=x;
   n++;
  break;
  case 2:
   y=y+6;
   b[0]=y;
   n++;
  break;
  case 3:
   x=x+6;
   a[0]=x;
   n++;
  break;
  case 4:
   y=y-6;
   b[0]=y;
  n++;
  break;
 }

 if(a[0]<=0||a[0]>=600||b[0]<=48||b[0]>=450)
 {
  gameover=1;
 }
 if(a[0]==fx&&b[0]==fy)
 {
  count++;
  c:
  fx=rand()%600;
  if(fx<=0||fx%6!=0)
  goto c;
  d:
  fy=rand()%450;
  if(fy<=48||fy%6!=0)
  goto d;
 }
 fillellipse(a[0],b[0],3,3);
 fillellipse(fx,fy,3,3);
 for(i=0;i<count;i++)
 {
  circle(a[i+1],b[i+1],3);
 }

 for(i=0;i<count;i++)
 {
  if(a[0]==a[i+1]&&b[0]==b[i+1])
  {
   gameover=1;
  }
 }
}
void main()
{ int l;
  textmode(1);/*Text mode in c++*/
  textcolor(BLACK);/*Adding black text colour*/
  textbackground(GREEN);/*Adding green background color*/
  cprintf("               SNAKE GAME               \n");
  textbackground(YELLOW);
  cprintf("              INSTRUCTIONS              \n");
  cprintf("USE a,s,w,d FOR MOVEMENT                \n");
  cprintf("AVOID BOUNDRY                           \n");
  cprintf("AVOID TOUCHING SNAKES OWN BODY          \n");
  cprintf("DONOT MOVE IN OPPOSITE DIRECTION        \n");
  cprintf("SCORE WILL BE DISPLAYED AT THE END      \n");
  cprintf("PRESS ANY KEY TO START                  ");
  getch();
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  initial();
  while(!gameover)
  {
    rectangle(0,450,600,48);
    movement();
    check();
    delay(100);/* Using delay to slow down the speed of program so that movement of snake can be seen.*/
    cleardevice();
  }
 delay(1000);
 closegraph();
 textcolor(WHITE);
 textbackground(BLACK);
 cprintf("YOUR SCORE IS :%d",count) ;
 delay(1500);
 clrscr();
 p:
 ifstream myfile;
 myfile.open("high.txt");
 myfile>>l;
 if(l<count)
 {
  ofstream myfile;
  myfile.open("high.txt");
  myfile<<count;/* Changes high score if the score achieved by the person is more than the highest score so far.*/
  goto p;
 }
 myfile.close();
 textcolor(BLACK);
 textbackground(WHITE);
 cprintf("HIGHEST SCORE IS :%d ",l);
 getch();/*holds screen and wait for key to be pressed*/
}