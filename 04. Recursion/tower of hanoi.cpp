#include<iostream>
int toh(int,char,char,char);
using namespace std;
int main(){
    
    int n;
    cout<<"enter no. of disks ";
    cin>>n;
    toh(n,'a','b','c');
}
int toh(int n,char s,char a,char d){
    if(n==1)
    {
        cout<<"move disk "<<n<<" from "<< s <<" to "<<d<<"\n";
        return 0;
    }
    toh(n-1,s,d,a);
    cout<<"move disk "<<n<<" from "<<s<<" to "<< d <<endl;
    toh(n-1,a,s,d);
    return 0;
}
