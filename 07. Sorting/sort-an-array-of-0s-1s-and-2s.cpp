// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int ar[], int n)
{   int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
        if (ar[i]==0)a++;
        if (ar[i]==1)b++;
        if (ar[i]==2)c++;
    }
    for(int i=0;i<a;i++)ar[i]=0;
    for(int i=0;i<b;i++)ar[i+a]=1;
    for(int i=0;i<c;i++)ar[i+a+b]=2;
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends
