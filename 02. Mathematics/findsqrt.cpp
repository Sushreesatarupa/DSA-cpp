#include <bits/stdc++.h>
using namespace std;


long long int floorSqrt(long long int x) 
{
    long long int i = 1;
        while(i*i <= x)
            i = i+1;
        return i-1;
}

int main(){
  long long int i;
  cin>>i;
  cout<<floorSqrt(i)<<endl;
  return 0;
}
