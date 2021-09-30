## Question Link : https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1#
### Video Link : <br>
> Logic : https://www.youtube.com/watch?v=IV9pbZsi5cc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=21<br>
> Code walkthrough : (SELF)


### SOLUTION : (ACCEPTED)
Possible Issues : Use mod wisely and use long insted of int when declaring a,ab,abc
```
class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        long a = 0;
        long ab = 0;
        long abc = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a'){
                a = (2*a + 1)%1000000007;
            }else if(s[i] == 'b'){
                ab = (2*ab + a)%1000000007;
            }else if(s[i] == 'c'){
                abc = (2*abc + ab)%1000000007;
            }
        }
    
        return abc%1000000007;
    }
    
};

```
