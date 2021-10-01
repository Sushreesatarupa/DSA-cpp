/* Question:
    Given an array A containing 2*N+2 positive numbers,
    out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct.
    Find the other two numbers.

    Example:
    Input:
    N = 2
    arr[] = {1, 2, 3, 2, 1, 4}
    Output:
    3 4
    Explanation:
    3 and 4 occur exactly once.
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    int xr = 0;
    for(int i=0;i<nums.size();i++)
    {
        xr^=nums[i];
    }
    int set_bit = xr & (~(xr-1));
    int x=0;
    int y=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] & set_bit)
        {
            x^=nums[i];
        }
        else
        {
            y^=nums[i];
        }
    }
    vector<int> ans(2);
    ans[0]=x<y?x:y;
    ans[1]=x>y?x:y;
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 2, 1, 4};
    vector<int> ans = singleNumber(a);
    cout<<ans[0]<<" and "<<ans[1]<<" occur exactly once.";
}
