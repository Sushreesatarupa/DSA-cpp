#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    vector<double>d;
    long int y_0=INT_MIN,x_0=INT_MIN,ny_0=INT_MAX,nx_0=INT_MAX;
    while(t--){
        long int x,y;
        cin>>x>>y;
        if(y==0){
            x_0=max(x_0,x);
            nx_0=min(nx_0,x);
        }
        else{
            y_0=max(y_0,y);
            ny_0=min(ny_0,y);
        }
    }
    long int x_y=max(abs((x_0-nx_0)),abs(y_0-ny_0)),x,y;
    d.push_back(sqrt(pow(x_y,2)));
    x=max(abs(x_0),abs(nx_0));
    y=max(abs(y_0),abs(ny_0));
    d.push_back(sqrt(pow(x,2)+pow(y,2)));
    if(d[0]>=d[1]) cout<<fixed<<setprecision(10)<<d[0];
    else cout<<fixed<<setprecision(10)<<d[1];
    return 0;
}