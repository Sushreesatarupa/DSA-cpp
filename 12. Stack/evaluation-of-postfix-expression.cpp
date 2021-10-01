/*Postfix Evaluation of an expression using stack. */

#include<iostream>
#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

#define SIZE 1000
int top=-1;
int stackk[SIZE];

int pop()
{
    if(top==-1)
    {printf("Stack UnderFlow\n");
     return -12345678;}
    else
    return stackk[top--];
}
void push(int data)
{
    if(top==SIZE-1)
    printf("Stack OverFlow!\n");
    else    
    stackk[++top]=data;
}
int peek()
{
     if(top==-1)
    {printf("Stack UnderFlow!\n");
     return -1;}
    else
    return stackk[top];
}
int main()
{
    string exp;
    printf("Enter the Postfix expression--\n");
    cin>>exp;
    int l=exp.length(),k,op1,op2;
    for(int i=0;i<l;i++)
    {        
        k=(int)exp[i];
        if(k>=48&&k<=57)
        push(k-48);
        else
        {
             op1=pop();
             op2=pop();
            if(op1==-12345678||op2==-12345678)
            {
                printf("Not Enough Operands...Sorry!\n");
                break;
            }
            char ch=exp[i];
            switch(ch)
            {
                case '*': push(op2*op1);
                          break;
                case '/': push(op2/op1);
                          break;
                case '-': push(op2-op1);
                          break;
                case '+': push(op2+op1);
                          break;
                case '^': push(pow(op2,op1));
                          break;
            }
        }
    }
    if(op1!=-12345678&&op2!=-12345678)
    {if(top==0){
        printf("Output of %s is: %d\n\n",exp,peek());
    }
    else
    printf("Too many Operands...Oops!\n");}
     cout<<"Thank you!"<<endl;

    return 0;
}
