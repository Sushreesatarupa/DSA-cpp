/* Program to find GCD(Greatest Common Divisor) or HCF(Highest Common Factor) of two numbers
GCD or HCF of two numbers is the largest number that divides both of them. */

#include <iostream>
using namespace std;

int main()
{
    int num1, num2, hcf; // defining variables
    cout << "Enter two numbers: ";
    cin >> num1 >> num2; // Input two numbers

    // swapping variables num1 and num2 if n2 is greater than num1.
    if (num2 > num1)
    {
        int temp = num2;
        num2 = num1;   //the smaller integer between num1 and num2 is stored in num2
        num1 = temp;
    }

    for (int i = 1; i <= num2; ++i) //loop is iterating from 1 to num2
    {
        if (num1 % i == 0 && num2 % i == 0) //checking if num1 and num2 are divisible by i
        {
            hcf = i; //if both are divisible by i, then i is the HCF
        }
    }
    cout << "HCF of " << num1 << " and " << num2 << " is " << hcf << endl;
    
    return 0;
}

