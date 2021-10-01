#include<iostream>
using namespace std;

int mat[9][9] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

bool checkRow(int r, int num){
    // cout << "Checking Row\n\n";
    for(int i = 0; i < 9; i++){
        if(mat[r][i] == num)
            return true;
    }
    return false;
}

bool checkCol(int c, int num){
    // cout << "Checking Column\n\n";
    for(int i = 0; i < 9; i++){
        if(mat[i][c] == num)
            return true;
    }
    return false;
}

bool checkBox(int rowInd, int colInd, int num){
    // cout << "Checking Box\n\n";
    rowInd = rowInd / 3;
    colInd = colInd / 3;
    int row = 3 + rowInd * 3, col = 3 + colInd * 3, i = 3 * rowInd, j = 3 * colInd;
    for(i; i < row; i++){
        for(j; j < col; j++){
            if(mat[i][j] == num)
                return true;
        }
    }
    return false;
}

bool isVacant(int &row, int &col){
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(mat[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isValidLocation(int row, int col, int num){
    // cout << row <<"  " << col <<"  " << num << endl;
    if(!(checkRow(row, num)) && !(checkCol(col, num)) && !(checkBox(row, col, num))){
        return true;
    }
    else
        return false;
}

bool isSolved(){
    int rowTofind, colTofind;
    if(!isVacant(rowTofind, colTofind)){
        return true;
    }
    // cout << "Not solved\n\n";
    for(int num = 1; num <= 9; num++){
        if(isValidLocation(rowTofind, colTofind, num)){
            // cout << "We found a valid location\n\n";
            mat[rowTofind][colTofind] = num;
            if(isSolved())
                return true;
            mat[rowTofind][colTofind] = 0;
        }
    }
    return false;
}

void print(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    if(isSolved()){
        print();
    }
    else
        cout << "Error in sudoku!\n";
    return 0;

}