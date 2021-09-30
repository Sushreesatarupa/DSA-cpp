#include <stdio.h>

void Strassen(int n, int (*P)[n],int (*Q)[n], int (*R)[n] )
{
    if (n==1)
    {
        R[0][0]=P[0][0]*Q[0][0];
    }
    else 
    {
        int a[n/2][n/2], b[n/2][n/2], c[n/2][n/2], d[n/2][n/2];
        int e[n/2][n/2], f[n/2][n/2], g[n/2][n/2], h[n/2][n/2];
        int p1[n/2][n/2], p2[n/2][n/2], p3[n/2][n/2], p4[n/2][n/2], p5[n/2][n/2], p6[n/2][n/2], p7[n/2][n/2];
        int C1[n/2][n/2], C2[n/2][n/2], C3[n/2][n/2], C4[n/2][n/2];
        
        int t1[n/2][n/2], t2[n/2][n/2], t3[n/2][n/2], t4[n/2][n/2], t5[n/2][n/2];
        int t6[n/2][n/2], t7[n/2][n/2], t8[n/2][n/2], t9[n/2][n/2], t10[n/2][n/2];
        
        for (int i=0;i<n/2;i++)
        {
            for (int j=0;j<n/2;j++)
            {
                a[i][j] = P[i][j];
                b[i][j] = P[i][n/2 + j];
                c[i][j] = P[n/2+i][j];
                d[i][j] = P[n/2+i][n/2+j];
                
                e[i][j] = Q[i][j];
                f[i][j] = Q[i][n/2 + j];
                g[i][j] = Q[n/2+i][j];
                h[i][j] = Q[n/2+i][n/2+j];
            }
        }
        
        for (int i=0;i<n/2;i++)
        {
            for (int j=0;j<n/2;j++)
            {
                t1[i][j] = f[i][j] - h[i][j];
                t2[i][j] = a[i][j] + b[i][j];
                t3[i][j] = c[i][j] + d[i][j];
                t4[i][j] = g[i][j] - e[i][j];
                t5[i][j] = a[i][j] + d[i][j];
                t6[i][j] = e[i][j] + h[i][j];
                t7[i][j] = b[i][j] - d[i][j];
                t8[i][j] = g[i][j] + h[i][j];
                t9[i][j] = a[i][j] - c[i][j];
                t10[i][j] = e[i][j] + f[i][j];
                         
                
            }
        }
        
        Strassen(n/2,a,t1,p1);
        Strassen(n/2,t2,h,p2);
        Strassen(n/2,t3,e,p3);
        Strassen(n/2,d,t4,p4);
        Strassen(n/2,t5,t6,p5);
        Strassen(n/2,t7,t8,p6);
        Strassen(n/2,t9,t10,p7);
        
        for (int i=0;i<n/2;i++)
        {
            for (int j=0;j<n/2;j++)
            {
                C1[i][j] = p5[i][j] + p4[i][j] - p2[i][j] + p6[i][j];
                C2[i][j] = p1[i][j] + p2[i][j];
                C3[i][j] = p3[i][j] + p4[i][j];
                C4[i][j] = p1[i][j] + p5[i][j] - p3[i][j] - p7[i][j];
            }
        }
        
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<n/2 && j<n/2)
                {
                    R[i][j] = C1[i][j];
                }
                if(i<n/2 && j>=n/2)
                {
                    R[i][j] = C2[i][j - n/2];
                }
                if(i>=n/2 && j<n/2)
                {
                    R[i][j] = C3[i - n/2][j];
                }
                if(i>=n/2 && j>=n/2)
                {
                    R[i][j] = C4[i - n/2][j - n/2];
                }
                
            }
        }
    }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    
    int P[n][n], Q[n][n], R[n][n];
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&P[i][j]);
        }
    }
    
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&Q[i][j]);
        }
    }
    
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&R[i][j]);
        }
    }
    
    Strassen(n,P,Q,R);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\n", R[i][j]);
        }
    }
    
    return 0;
    
}