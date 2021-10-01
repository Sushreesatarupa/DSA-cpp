#include <iostream>
using namespace std;

    // function to display the chess board with moves
void display(int chess[5][5])
{
    for(int rowIdx = 0 ; rowIdx < 5 ; rowIdx++)
    {
        for(int colIdx = 0 ; colIdx < 5 ; colIdx++)
        {
            cout << chess[rowIdx][colIdx] << " " ;
        }   
        cout << "\n" ;
    }
    
    cout << "\n" ;
}

    // function to move all possible paths recursively and display correct ones
void knightsTour(int chess[5][5], int row, int col, int move)
{
        // if current index is out of bound
    if(row < 0 || col < 0 || row >= 5 || col >= 5 || chess[row][col] > 0)
    {
        return ;
    }
        // if (move == 25) then display the chess board
    else if(move == 25)
    {
        chess[row][col] = move ;
        display(chess) ;
        chess[row][col] = 0 ;
        return ;
    }
    
    chess[row][col] = move ;
    
            // checking all possible paths
        knightsTour(chess, row-2, col+1, move+1) ;
        knightsTour(chess, row-1, col+2, move+1) ;
        knightsTour(chess, row+1, col+2, move+1) ;
        knightsTour(chess, row+2, col+1, move+1) ;
        knightsTour(chess, row+2, col-1, move+1) ;
        knightsTour(chess, row+1, col-2, move+1) ;
        knightsTour(chess, row-1, col-2, move+1) ;
        knightsTour(chess, row-2, col-1, move+1) ;
    
    // backtracking
    chess[row][col] = 0 ;
}

int main() 
{
	int row, col ;
	
	cin >> row >> col ;
	
	int chess[5][5] ;
	
	    // calling knightsTour() function for given row and col index
	knightsTour(chess, row, col, 1) ;
	
	return 0;
}
