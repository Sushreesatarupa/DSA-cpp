#include<iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter the number to find the sum of its digits: ";
	cin >> num;
	int sum = 0;
    	while (num != 0) {
        	sum = sum + num % 10;
        	num = num / 10;
    	}
    	cout << "\nSum of its digits is " << sum;
    	return 0; 	
}
