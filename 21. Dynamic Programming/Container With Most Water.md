### Question Link : https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1# <br>

### Video Solution : https://www.youtube.com/watch?v=qUDp8IUbZto <br>

SOLUTION : ( ACCEPTED )

> don't use long long in max function, it will not accept

```
#include<algorithm>
long long maxArea(long long height[], int len)
{
    
        int size = len;
        if(size < 2) return 0;
        
        int left = 0;
        int right = size-1;
        int max_trapped =0; 
        
        while(left<right){
            int w = right-left;
            int h = min(height[left] , height[right]);
            
            max_trapped = max(max_trapped,(w*h));
            
            // this is to always start from the lower side
            
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        
       return max_trapped;
};
```
