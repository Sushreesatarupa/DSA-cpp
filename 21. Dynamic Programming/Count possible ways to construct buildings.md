## Question Link : https://practice.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1#

## Video Link : <br>

> Logic : https://www.youtube.com/watch?v=0nF-BMYy7tc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=19 <br>
> Code : (self coming soon)

### SOLUTION : (ACCEPTED) 
Issues which can come : use mod wisely

```
class Solution{
	public:
	int TotalWays(int N)
	{
	   long n = N;
	   long ocz = 1;
	   long oco = 1;
	   
	   for(long long i=2;i<=n;i++){
	       long ncz = oco%1000000007;
	       long nco = ocz%1000000007 + oco%1000000007;
	       
	       
	       ocz = ncz;
	       oco = nco;
	   }
	   
	   long long total = ocz%1000000007 + oco%1000000007;
	   total = total*total;
	    
	    
	   return total%1000000007;
    	    
	}
};
```
