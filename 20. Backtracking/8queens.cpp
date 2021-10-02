#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;

int place(int);

// place(k) is a function that that tells whether  the queen in the current row 
// can be paced in the current column 

int  M[9][9], X[9], i, j, k, flag;

int main() 
{ 
	k=1; 
	X[k]=0 ;   
	int count=1;

     // k represents the Row number , X[k] represents the column
     //number in the Row k


while(k>0)
{ 
	// This loop continues until forced to backtrack from the first Row
    // This means the entire problem space ( state space ) is searched.

	X[k]+=1; 
    while( place(k)==0 && X[k]<9 ) 
	{ 
		X[k]=X[k]+1;
	};


	// The above loop continues until a proper place is found in the 
	// current row if there is one


    if(X[k]<9)
	{ 
		if(k==8)
			{
			cout<<"The solution number "<<count<<"= ";
			for(i=1;i<9;i++) 
			cout<<X[i]<<" "; 
            count++;
			cout<<endl;
			cout<<endl;
			cout<<"For the next solution press any key\n";
			}

		//If can place a queen successfully in last row print the solution//
		else{k=k+1;X[k]=0;};
	}

	//if not last row go to the next row//
    else k=k-1;
    
};   /////if can not find a place in this row then backtrack
                               //( go back to previous row)//
	cout<<count<<endl;
	
	system("pause");
	return 0;
}

    // the function place can tell if a queen can be placed in a position or not//
	// by checking if any other queen is already in the same row or
	// column or diagonals//

    
int place(int j)
{ 
	flag=1; 

	for(i=1;i<j;i++)
	{ 
		if(X[i]==X[j]|| abs(i-j)==abs(X[i]-X[j]))
			flag=0;
	}

		 return flag; 
}
