//trapped rainwater in blocks
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i=-1, n, pos = 0, por = 0, rain = 0, j;
    cin>>n;
    int a[n];
    while(++i<n)
    {
        cin>>a[i];
    } 
    i = 0;
    while(i<n-1)
    {
        while (i < n - 1 && a[i + 1] < a[i]) //loop to cross indices where
            i++;                             // blocks are in ascending order
                                             //and while in array

        while (i < n - 1 && a[i + 1] > a[i]) //upcoming block in decending order
        {                                    //and while in array

            if (a[i + 2] < a[i + 1] || i + 1 == n - 1) //upcoming peak condition
                                                       //or end of array condition
            {
                //pos = 0 or the last time peak was reached
                por = i + 1;
                int x = min(a[pos], a[por]);
                for (j = pos + 1; j < por; j++)
                    rain += (x - a[j] > 0) ? x - a[j] : 0;
                //pos and por are two blocks between which rain water
                //is trapped; whichever is smaller, water drops can go
                //only upto that level

                pos = por; //pos' position is updated
            }
            i++;
        }   
    }  
    cout<<rain<<endl; 
}
