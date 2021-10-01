#include <bits/stdc++.h>
using namespace std;

string commonPrefix(vector<string> strs){
   int n=strs.size(), index=0;
   string str="";
   if(n==0) return str;
   for(auto ch : strs[0]){
       for(int i=1; i<n; i++){
           if(index>= strs[i].size() || strs[i][index]!=ch) {
              if(str.size()==0) return "-1";
              else return str;
       }
     }
       str+=ch;
       index++;
   
   }
  return str;
}


int main() {
    int t; cin>>t; while(t--){
        string s;
        int n; cin>>n;
        vector<string> arr;
        while(n--){
            cin>>s;
            arr.push_back(s);
        }
        cout<<commonPrefix(arr)<<'\n';
    }
	return 0;
}
