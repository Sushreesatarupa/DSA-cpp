//Driver cose starts

#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    //Calculate the length of string
	    int n=str.length();
	    
	    
	    //Code to Reverse the string:
	    //Swap the characters from beginning with characters from end. 
      //Move upto middle of string 
	    for(int begin=0;begin<(n/2);begin++)
	    {
	        int end= n-1-begin;
	        
	        //swapping the characters
	        int temp= str[begin];
	        str[begin]=str[end];
	        str[end]=temp;
	    }
	    
	    return str;
}
