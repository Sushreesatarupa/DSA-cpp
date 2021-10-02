#include<iostream.h>
#include<conio.h>
void main()
{
float a,b,c;
clrscr();
cout<<"Enter three numbers - "<<endl;
cin>>a>>b>>c;
if(a>b&&a>c)
 cout<<"The greatest number is - "<<a<<endl;
else
 {
 if(b>c)
  cout<<"The greatest number is - "<<b<<endl;
 else
  cout<<"The greatest number is - "<<c<<endl;
 }
getch();
}
