#include <iostream>

using namespace std;

int main()
{
    int row,col;
    cout<<"Enter the number of rows and columns:\n";
    cin>>row;
    cin>>col;
    int mat[row][col],i,j;
    cout<<"Enter the elements of the matrix:\n";
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cin>>mat[i][j];
        }
    }
    int ele,k=0;
    cout<<"\nEnter the search element: ";
    cin>>ele;
    // Searching the element in the matrix using two for loops
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(mat[i][j]==ele)
            {
                cout<<"\nThe element is found at index "<<i+1<<" "<<j+1;
                k=1;
            }
        }
    }
    if(k==0)
    {
        cout<<"\nThe element is not found";
    }
    

    return 0;
}
