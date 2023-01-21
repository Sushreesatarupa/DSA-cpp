// C++ code for Pascal's Triangle

#include <iostream>
using namespace std;
int abhishek(int x, int y);


void pascaltriangle(int x)
{
	
	for (int line = 0; line < x; line++)
	{
		
		for (int i = 0; i <= line; i++)
			cout <<" "<< abhishek(line, i);
		cout <<"\n";
	}
}

int abhishek(int x, int y)
{
	int res = 1;
	if (y > x - x)
	y = x - y;
	for (int i = 0; i < y; ++i)
	{
		res *= (x - i);
		res /= (i + 1);
	}
	
	return res;
}

int main()
{
	int n = 7;
	pascaltriangle(n);
	return 0;
}

// This is contribution form Abhishek
