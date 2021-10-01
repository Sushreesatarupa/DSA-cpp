//check whether array is sorted(non decreasing order)then rotated.

#include<bits/stdc++.h>
using namespace std;

bool checkSortedRotated(vector<int>v)
{
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>v[(i+1)%v.size()])
        {
            count+=1;
        }
    }
    if(count<=1)
        return true;
    else
        return false;
}

int main()
{
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    bool check = checkSortedRotated(v);
    if(check==true)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}