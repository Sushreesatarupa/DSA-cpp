#include <iostream>
using namespace std;

void printIntersection(int *array1, int size1, int *array2, int size2) {
  int index1 = 0, index2 = 0;
  /* This loop will continue untill one 
  of the array traversal completes */
  while(index1 < size1 && index2 < size2) {
    if (array1[index1] < array2[index2])
    /*array1[index1]is smaller, increment index1 */
      index1++;
    else if (array2[index2] < array1[index1])
    /*array2[index2]is smaller, increment index2 */
      index2++;
    else {
    /* Both equal, print anyone and increment both indexes */
      printf("%d ", array2[index2]);
      index1++;
      index2++;
    }
  }
}
 
int main(){
    int array1[10] = {1, 3, 5, 6, 8, 10, 11, 14, 15, 20};
    int array2[6] = {2, 3, 5, 7, 9, 10}; 
 
    printIntersection(array1, 10, array2, 6);
 
    return 0;
}
