/*
        ---Matrix problem---
The game of Sudoku quickly spread all over the world, 
becoming today the most popular pastime on the entire planet.
Many people, however, fill the matrix incorrectly, 
disregarding the game's restrictions.
Your task in this problem is to write a program that checks
whether or not a filled array is a solution to the problem.
The game matrix is ​​a matrix of 9 x 9 integers. To be a solution to the problem, 
each row and column must contain all the numbers from 1 to 9. Also, if we divide
the matrix into 9 3 x 3 regions each. of these regions must also contain the numbers 1 to 9.
The example below shows an array that is a solution to the problem.
1 3 2 | 5 7 9 | 4 6 8
4 9 8 | 2 6 1 | 3 7 5
7 5 6 | 3 8 4 | 2 1 9
------+-------+------
6 4 3 | 1 5 8 | 7 9 2
5 2 1 | 7 9 3 | 8 4 6
9 8 7 | 4 2 6 | 5 3 1
------+-------+------
2 1 4 | 9 3 5 | 6 8 7
3 6 5 | 8 1 7 | 9 2 4
8 7 9 | 6 4 2 | 1 5 3

---INPUT ESPECIFICATION---
Multiple instances are given.
The first data is the number n > 0 of matrices in the input.
In the following lines the n matrices are given. Each matrix is ​​given in 9 rows,
where each row contains 9 integers.

---OUTPUT ESPECIFICATION---
For each instance your program should print a line saying Instance k,
where k is the current instance number. On the second line,
your program should print YES if the matrix is ​​the solution to a Sudoku problem,
and NO otherwise. Print a blank line after each instance.
*/


#include <iostream>
using namespace std;

int main(){

int n, mat[9][9]={}, cont=0;

cin>>n;
for(int p=0;p<n;p++){
    cont=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>mat[i][j];
        }
    }
    //compare lines
    for(int k=0;k<9;k++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if((mat[k][i]==mat[k][j])&&i!=j){
                    cont++;
                }
            }
        }
    }
    //comp columns
    for(int k=0;k<9;k++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][k]==mat[j][k]&&i!=j){
                    cont++;
                }
            }
        }
    }
    if(cont>0){
        cout<<endl<<"Instance" <<endl<<"NO"<<endl<<p+1;
    }
    else{
        cout<<endl<<"Instance" <<endl<<"YES"<<endl<<p+1;
    }
}



return 0;
}
/*
---Input example---
2
1 3 2 5 7 9 4 6 8
4 9 8 2 6 1 3 7 5
7 5 6 3 8 4 2 1 9
6 4 3 1 5 8 7 9 2
5 2 1 7 9 3 8 4 6
9 8 7 4 2 6 5 3 1
2 1 4 9 3 5 6 8 7
3 6 5 8 1 7 9 2 4
8 7 9 6 4 2 1 5 3
1 3 2 5 7 9 4 6 8
4 9 8 2 6 1 3 7 5
7 5 6 3 8 4 2 1 9
6 4 3 1 5 8 7 9 2
5 2 1 7 9 3 8 4 6
9 8 7 4 2 6 5 3 1
2 1 4 9 3 5 6 8 7
3 6 5 8 1 7 9 2 4
8 7 9 6 4 2 1 3 5
---Output---
Instance 1
YES
Instance 2
NO
*/