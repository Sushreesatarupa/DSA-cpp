#include <bits/stdc++.h>
using namespace std;

// romanToDecimal function returns value of a Roman symbol
int romanToDecimal(string &str)
{
    unordered_map<char, int> mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
   
        if (mp[str[i]] < mp[str[i + 1]])
        {
            sum+=mp[str[i+1]]-mp[str[i]];
            i++;
            continue;
        }
        sum += mp[str[i]];
    }
    return sum;
}
int main()
{
   
    string str = "VI";
    cout << "Integer value of the following Roman Number is "
         << romanToDecimal(str) << endl;
 
    return 0;
}
