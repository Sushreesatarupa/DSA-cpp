// This program is used to find Combination of two numbers with the help of Recursion
// Consists two approachs

#include <iostream>
using namespace std;

// nCr = n! / (r! * (n - r)!)
// nCr = (n-1)Cr + (n-1)C(r-1)

// Approach 1 starts
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int combination(int n, int r)
{
    int a, b, c;

    a = factorial(n);
    b = factorial(r);
    c = factorial(n - r);

    return a / (b * c);
}
// Approach 1 ends

// Approach 2 starts
int PascalCombination(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }

    return PascalCombination(n - 1, r - 1) + PascalCombination(n - 1, r);
}
// Approach 2 ends

// driver code
int main()
{
    int p, q;
    cout<<"Enter two numbers : ";
    cin>>p>>q;
    
    if(p>=q) // Condition of Combination
    {
        // Approach 1
        cout << combination(p, q) << endl;                              
  
        // Approach 2
        cout << PascalCombination(p, q) << endl;                        
    }
  
    return 0;
}
