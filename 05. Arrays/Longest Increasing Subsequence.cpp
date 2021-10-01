#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;
 
// Function to find the length of the longest increasing subsequence in a given array
int findLISLength(vector<int> const &input)
{
    // base case
    if (input.size() == 0) {
        return 0;
    }
 
    // create an empty ordered set `s`. The i'th element in `s` is defined as the
    // smallest integer that ends an increasing sequence of length `i`
    set<int> s;
 
    // process every element one by one
    for (int i = 0; i < input.size(); i++)
    {
        // ignore the current element if it is already present in the set
        if (s.find(input[i]) != s.end()) {
            continue;
        }
 
        // insert the current element into the set
        auto ret = s.insert(input[i]);
 
        // get an iterator to the inserted item
        set<int>::iterator it;
        if (ret.second) {
            it = ret.first;
        }
 
        // if the element is not inserted at the end, then delete the next
        // greater element from the set
        if (++it != s.end()) {
            s.erase(it);
        }
    }
 
    // length of LIS is the total number of elements in the set
    return s.size();
}
 
int main()
{
    vector<int> input = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
 
    cout << "The length of the LIS is " << findLISLength(input);
 
    return 0;
}



