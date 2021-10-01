// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// A simple recursive approach
// to replace all pi in a given
// function with "3.14". Firstly
// function is declared we don't
// need any helper function one
// function is enough
string replacePi(string s)
{

	// Base case if s is empty
	// or length of s is 1
	// return the s
	if (s.length() == 0 || s.length() == 1)
		return s;

	// If the 0th and 1st element
	// of s are p and i we have to
	// handle them for rest we have
	// to call recursion it will
	// give the result
	if (s[0] == 'p' && s[1] == 'i') {

		// Smalloutput is a variable
		// used to store recursion result
		string smallOutput = replacePi(s.substr(2));

		// And we have to add the recursion
		// result with the first part we
		// handled and return the answer
		return "3.14" + smallOutput;
	}
	else {
		// If 1st & 2nd element aren't "p" & "i", then keep
		// 1st index as it is & call recursion for rest of
		// the string.
		return s[0] + replacePi(s.substr(1));
	}
}

// Driver code
int main()
{
	string s ;
    cin>>s;

	// Function call
	string result = replacePi(s);

	cout << result << endl;

	return 0;
}
