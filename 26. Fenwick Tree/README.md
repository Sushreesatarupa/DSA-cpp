# FENWICK TREES or BINARY INDEXED TREES

To update and perform a range query in `O(logN)` which is certainly better than `O(N)`

## Prerequisites 

- To find the rightmost setbit of a number <br/>
Negative of a number => (2s complement) <br />
Negative of a number => (1s complement + 1) <br/>
2s complement of a number can be divided into 3 parts -> left(all bits flipped) + middle(rightmost setbit) + right(all zeroes) <br/>

  **Result :** For number x , `(x & -x)` gives the rightmost setbit of x

<br />

## Some Observations 

- In a Fenwick tree, for a number num, the parent of num is the number obatainer after removing its rightmost bit.
So 1,2,4,8,16 have a parent 0.
- As we increase level, the number of setbits in the elements increases
- An edge (from parent to a child) contains the result of range [parent+1, child]
- Every node is storing the results of left child of its parent node including itself

<br />

## Advantages 
- Complexity - O(number of set bits)
- For length N, space needed - O(N) (whereas in segment tree it is 4xN)
- Code smaller in Length

<br />

## Disadvantages 
- It will not work for the functions whose inverse does not exist. So it will not work for the functions like `max & min`. However, `add, mul, div, sub` still works because of existence of inverse functions.

<br />

## Resources

- Watch Video Explanation <a href = "https://www.youtube.com/watch?v=DxN5-Y8Ld4c"> Click Here</a><br />

- Read Article <a href = "https://leetcode.com/discuss/general-discussion/1093346/Introduction-to-Fenwick-TreeBinary-Indexed-Tree(BIT)"> Click Here</a><br />
