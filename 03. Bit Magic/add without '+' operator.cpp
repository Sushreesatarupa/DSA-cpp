/*
Here we have created a function that returns sum of two integers. 
Without using any of the arithmetic operators (+, ++, –, -, .. etc).
Sum of two bits can be obtained by performing XOR (^) of the two bits. 
Carry bits can be obtained by performing AND (&) of two bits. 

This approach is a simple Half Adder logic that can be used to add 2 single bits, but we can extend this logic for integers. 

If x and y don’t have set bits at same position(s), then bitwise XOR (^) of x and y gives the sum of x and y. 
To incorporate common set bits also, bitwise AND (&) is used. Bitwise AND of x and y gives all carry bits. 

We calculate (x & y) << 1 and add it to x ^ y to get the required result. 
Example:
        Input: 5,6
        Output: 11
        
    below is the c++ implementation for the above mentioned question
*/

#include <bits/stdc++.h>
using namespace std;
 
int Add(int x, int y)
{
    while (y != 0)			// Iterating untill there is no carry
    {
        // carry should be unsigned to
        // deal with -ve numbers
        // carry now contains common
        //set bits of x and y

        unsigned carry = x & y;
 
        // Sum of bits of x and y where at
        //least one of the bits is not set

        x = x ^ y;
 
        // Carry is shifted by one so that adding
        // it to x gives the required sum

        y = carry << 1;
    }
    return x;
}
 
// Driver code
int main()
{
    cout << Add(15, 32);
    return 0;
}
