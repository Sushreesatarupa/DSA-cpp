//Efficient implementation to verify Mountain Array.
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int N = arr.size();
        int i = 0;
        
        // walk up from 1st element to peak element.
        while(i+1<N && arr[i]<arr[i+1]) {
            i++;
        }

        // peak can't be first or last element of the array.
        if(i==0 || i==N-1) {
            return false;            
        }

        // walk down from the peak to the rightmost or last element of the array.
        while(i+1<N && arr[i]>arr[i+1]) {
            i++;            
        }
        
        return i == N-1;
    }
};
