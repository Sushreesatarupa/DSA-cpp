//factorial of a number using recursion
#include <iostream>
using namespace std;

int factorial(int n){
    if (n==1 || n==0){
        return 1;
    }
    return n*factorial(n-1);
    
}
int main(){
    int number;
    cout<<"Enter number to find factorial of: ";
    cin>>number;
    int fact = factorial(number);
    cout<<"Factorial of "<<number<<" is: "<<fact;
    return 0;
}
