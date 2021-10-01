#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main()
{
    int A[100][100];
    int i,j,k,n,res;
    printf("Enter the order of the matrix: \n");
    scanf("%d",&n);
    printf("\nEnter the elements of the matrix one by one: \n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            printf("%5d",A[i][j]);
        }
        printf("\n");
    }
    res = det(A,n);
    printf("%d",res);
}
int det(int A[100][100], int n)
{
    int Minor[100][100];
    int i,j,k,c1,c2;
    int determinant;
    int c[100];
    int O=1;

    if(n == 2)
    {
        determinant = 0;
        determinant = A[0][0]*A[1][1]-A[0][1]*A[1][0];
        return determinant;
    }
    else
    {
        for(i = 0 ; i < n ; i++)
        {
            c1 = 0, c2 = 0;
            for(j = 0 ; j < n ; j++)
            {
                for(k = 0 ; k < n ; k++)
                {
                    if(j != 0 && k != i)
                    {
                        Minor[c1][c2] = A[j][k];
                        c2++;
                        if(c2>n-2)
                        {
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            determinant = determinant + O*(A[0][i]*det(Minor,n-1));
            O=-1*O;
        }
    }
    return determinant;
}
