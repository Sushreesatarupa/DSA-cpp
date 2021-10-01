#include<iostream>  

using namespace std; 

int factorial(int n)  
{  
if(n<0)  
return(-1); /*Wrong value*/    
if(n==0)  
return(1);  /*Terminating condition*/  
else  
{  
return(n*factorial(n-1));      //recursive function
}  
}

int main()  
{  
int fact,value;  
cout<<"Enter any number: ";  
cin>>value;  
int factorial(int);  //define factorial funtion
fact=factorial(value);  //factorial value stored in fact variable
cout<<"Factorial of a number is: "<<fact<<endl;  
return 0;  
}  
