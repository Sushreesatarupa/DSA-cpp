#include<iostream>
using namespace std;

double taylorSeries(int n,int m);
double taylorSeriesHornersRule(int m, int n);

int main(){
    cout<<"Taylor series result : "<<taylorSeries(4,15)<<endl;
    cout<<"Taylor series using Horner's Rule result : "<<taylorSeriesHornersRule(4,15)<<endl;
    return 0;
}

double taylorSeries(int n,int m){
    static double p=1, f=1;
    double r;
    if(m==0)
        return 1;
    else{
        r = taylorSeries(n,m-1);
        p *= n;
        f *= m;
        return r + p/f;
    }
}

double taylorSeriesHornersRule(int m, int n){
    static double r;
    if(n==0)
        return r;

    r = 1+r*m/n;
    return taylorSeriesHornersRule(m,n-1);
}