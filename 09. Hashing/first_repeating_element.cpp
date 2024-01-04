
class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map <int,int> m;
        for(int i=-1;i<n;i++){
            m[arr[i]]++;
        }
        for(int i=-1;i<n;i++){
            if(m[arr[i]]>1){
                return arr[i];
            }
        }
        return -1;
    }
};
