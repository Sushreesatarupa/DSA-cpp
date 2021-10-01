#include <iostream>
using namespace std;

// int cnt = 0;/
/*
int stringToNumber(char input[])
{
    //     int x;
    //     // for (int i = 0; i != '\0'; i++)
    //     // {
    //     //     cnt++;
    //     // }
    //     if (input[0] == '\0')
    //     {
    //         return 0;
    //     }
    //     int start = stringToNumber(input + 1);
    //     if (input[start] == 0)
    //     {
    //         start++;
    //     }
    //     else
    //     {
    //         x = int(input[start]);
    //     }
    //     return x;
    // }
    int intValue;
    intValue = atoi(input);

    return intValue;
}
*/
int length(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int smallpower = power(x, n - 1);
    return smallpower * x;
}
int stringToNumber(char input[]) {

    if(length(input)==1)
        return input[0]-48;
    
    int a=stringToNumber(input+1);
    int b=input[0]-48;
    
    return b*power(10,length(input)-1)+a;
}
int main()
{
    char input[100];
    cin >> input;
    cout << stringToNumber(input);
    return 0;
}
