#include <bits/stdc++.h> 

using namespace std; 

string removeDuplicates(string s) {
   stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        if(st.empty()) st.push(s[i]);
        else
        {
            if(st.top()==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    string ans ="";
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

int main()
{    
    int ans;
    cout<<"Enter the number of strings"<<endl;
    int t;
    cin>>t;
    cout<<"Enter the string"<<endl;
    while(t--)
    {
        string s;
        cin>>s;
        s = removeDuplicates(s);
        cout<<s<<endl;
        cout<<"Do you want to continue[0 -> N | 1 -> Y]";
        cin>>ans;
        if(!ans){
            return 0;
        }
    }    
    return 0;
}
