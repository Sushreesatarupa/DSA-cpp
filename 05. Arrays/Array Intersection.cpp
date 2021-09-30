/*
Question : 
You have been given two integer arrays/list(ARR1 and ARR2) of size M and N, respectively. 
You need to print their intersection; 
An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, 
when there is a common value that exists in both the arrays/lists.
*/

// Code : 

#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

//Array Intersection Function
void intersection(int *input1, int *input2, int size1, int size2)
{
    int i=0,j=0,k=0,f=0,n=0;
    int b[size1];
    for(i=0;i<size1;i++)
    {
        for(j=0;j<size2;j++)
        {
            if(*(input1+i)==*(input2+j))
            {
                    b[n]=*(input2+j);
                    n++;
                	*(input1+i)=INT_MIN;
                	*(input2+j)=INT_MIN;
                	break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}

// Driver Code
int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}
