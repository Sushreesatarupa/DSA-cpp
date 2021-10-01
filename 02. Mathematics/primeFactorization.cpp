/* 
Time complexity = O(sqrt(n))
--logic--
Two arrays for keeping the prime factor and the exponent of the relevant prime factor.

Diving any number with prime factors will yeild 1 at the end. So the loop will end when the remainder hits 1.
The number 'n' will be divided by the divisor for as long as the modulus of the two will yeild zero.

Worst case -> n being a prime number will run the loop until d = n. 
Therefore to reduce unnecessary complexity the loop will determine if the number is a prime or not in the begining of the loop.
That is achived by  d * d <= n.
For more clarity, view the primeNumber.cpp.
The prime number recieved by the divisor will be handled seperately.

To handle n = 1 case,
Although 1 is not a prime number, 1 still can be written as a product of prime numbers which is the 0th power of 2.

The divisor 'd' is increased unit wise. d will take values = 2, 3, 4, 5, 6, ... 
As observed 4 and 6 are not primes. But any number which is not a prime can be a product of two primes. 
For example, when d = 4, the value n which is divisble by 4 is already handled by when d = 2. because 4 = 2 * 2.

*/

#include<iostream>
using namespace std;

int f[100], expo[100], len;

void primeFact(int n)
{
    if(n == 1)
    {
        len++;
        f[len] = 2;
        expo[len] = 0;
        return;
    }

    int d = 2;

    while((n > 1) && (d * d <= n))
    {
        int k = 0;

        while(n % d == 0)
        {
            n = n / d;
            k++;
        }

        if(k > 0)
        {
            len++;
            f[len] = d;
            expo[len] = k;
        }

        d++;
    }

    if(n > 1)
    {
        len++;
        f[len] = n;
        expo[len] = 1;
    }
}

int main()
{
    int n;
    cin >> n;

    primeFact(n);

    for(int i = 1; i <= len; i++)
    {
        cout << f[i] << " ^ " << expo[i] << endl;
    }

    return 0;
}