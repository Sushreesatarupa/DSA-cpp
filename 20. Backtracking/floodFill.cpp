#include<iostream>
#include<vector>

using namespace std;

void floodFill(vector<vector<int>> maze , int currentRow , int currentColumn , string ans) {
    if(currentColumn < 0 || currentRow < 0 || currentColumn == maze[0].size() || currentRow == maze.size() || maze[currentRow][currentColumn]==1)
        return ;
    
    if(currentRow == maze.size() - 1 && currentColumn == maze[0].size() - 1)
    {
        cout << ans << " " ;
        return ;
    }
    
        // top == row - 1
        // down == row + 1
        // left == col - 1
        // right == col + 1
        
    maze[currentRow][currentColumn] = 1;
    
    floodFill(maze , currentRow-1 , currentColumn , ans + 't') ;
    floodFill(maze , currentRow+1 , currentColumn , ans + 'd') ;
    floodFill(maze , currentRow , currentColumn-1 , ans + 'l') ;
    floodFill(maze , currentRow , currentColumn+1 , ans + 'r') ;
    
    maze[currentRow][currentColumn] = 0;
}

int main() 
{
    int rows, columns ;

    cin >> rows >> columns;

    vector <vector<int>> arr(rows, vector<int> (columns));

    for (int idx = 0; idx < rows; idx++)
    { 
        for (int innneridx = 0; innneridx < columns; innneridx++)
            cin >> arr[idx][innneridx];
    }

    floodFill(arr,0,0,"");
    
    return 0 ;
}