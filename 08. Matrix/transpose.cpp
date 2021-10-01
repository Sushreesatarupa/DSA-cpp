#include<stdio.h>
int main()
{
	int m,n;
	printf("\n Enter number of rows in matrix \n");
	scanf("%d",&m);
	printf("\n Enter number of columns in matrix \n");
	scanf("%d",&n);
	int arr[m][n];
	int trans[n][m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("\n Enter matrix element \n");
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\n Original matrix: \n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			trans[j][i]=arr[i][j];
		}
	}
	printf("\n Transpose matrix: \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%5d",trans[i][j]);
		}
		printf("\n");
	}
}
