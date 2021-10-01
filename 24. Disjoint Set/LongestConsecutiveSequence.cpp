#include <bits/stdc++.h>
using namespace std;

/* question link ~ https://leetcode.com/problems/longest-consecutive-sequence/

    THIS QUESTION IS A GREAT START TO UNDERSTAND UNION FIND.

    I have used a hashmap for FIND operation, and an array to store to parent of the given index

 */

/* APPROACH: 
    We try to make a connected series of numbers that are consecutive. 

    For eg, array is 1,3,100,5,6,4.

    first add 1, with its parent as itself, parent[0]=0;

    then add 3, we check if (3-1/3+1) number is previously encountered or not, since it is not, we simple add this in a separately
    as parent[1]=1;

    then same with 100, parent[2]=2;
    then same with 5, parent[3]=3;

    now, when we add 6, we see, we have (6-1=5) previously present, hence what we do is, connect 6 to 5,
    with first finding the parent of 5 and then, setting parent of 6 as parent of 5. 

    similarily we continue for 4. . . 
*/
int findParent(unordered_map<int, int>& par, int r) {
    return r == par[r] ? r : findParent(par, par[r]);
}

//main function to find the longest consecutive numbers in an array
int longestConsecutive(vector<int>& nums) {

    //map "par" used to store the parent index of a given element
    unordered_map<int, int> par;
    unordered_map<int, int> groupSize;

    int ans = 0;

    for (int num: nums) {

        //intitally put the number in map simply
        if (par.find(num) == par.end()) {
            par[num] = num;
            groupSize[num] = 1;
        }
        int numParent = findParent(par, num);

        //now check of there ia a number which is +1/-1 of the number
        for (int adj = num - 1; adj <= num + 1; adj += 2) {

            //if we find such number
            if (par.find(adj) != par.end()) {
                //find the parent of that particular number
                int adjParent = findParent(par, adj);
                
                //and hence connect this number an an extension to it
                if (numParent != adjParent) {
                    par[adjParent] = par[numParent];
                    groupSize[numParent] += groupSize[adjParent];   
                }
            }   
        }
            ans = max(ans, groupSize[numParent]);
        }

        return ans;
    }

int main(){

    //take user input
    int n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int ans=largestConsecutive(nums);
    return 0;

}