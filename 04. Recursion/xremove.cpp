// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

string remove(string s)
{

    // Base case if s is empty
    
    // return the s
    // here s will return' '
    if (s.length() == 0)
        return s;

    if (s[0] == 'x')
    {

        // Smalloutput is a variable
        // used to store recursion result
        string smallOutput = remove(s.substr(1));

        return smallOutput;
    }
    else
    {

        return s[0] + remove(s.substr(1));
    }
}

// Driver code
int main()
{
  string s;
    cin >> s;

    // Function call
    string result = remove(s);

    cout << result << endl;

    return 0;
}
