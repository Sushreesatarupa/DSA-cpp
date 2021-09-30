// Newton Raphson can be used to calculate the square root of a number to a given precision.
#include<iostream>

using namespace std;

double newtonRaphson(double n, double prec){
    double x = n;
    double root ;
    while(true){
        root = 0.5 * (x + (n/x));

        if(abs(root - x) < prec){
            break;
        }
        x = root;
    }
    return root;
}

int main(){
    double n = 46;      // Number of which square root is to be calculated.
    double prec = 0.5; // precison
    cout<<newtonRaphson(n,prec)<<endl;
}