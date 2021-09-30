def initialise(n):
    for key in ['queen','row','col','nw','sw']:
        board[key] = {}
    for i in range(n):
        board['queen'][i] = -1
        board['row'][i] = 0
        board['col'][i] = 0
    
    for i in range(-(n-1),n):
        board['nw'][i] = 0;
        board['sw'][i+n-1] = 0;
        
def free(i,j):
    if(board['row'][i]==0 and board['col'][j]==0 and board['nw'][j-i]==0 and board['sw'][j+i]==0):
        return True
    return False
        
def addQueen(i,j):
    board['queen'][i] = j
    board['row'][i] = 1
    board['col'][j] = 1
    board['nw'][j-i] = 1
    board['sw'][j+i] = 1
    
def undoQueen(i,j):
    board['queen'][i] = -1
    board['row'][i] = 0
    board['col'][j] = 0
    board['nw'][j-i] = 0
    board['sw'][j+i] = 0
    
def placeQueen(i):
    n = len(board['queen'].keys())
    for j in range(n):
        if(free(i,j)):
            addQueen(i,j)
            if i==n-1:
                return True
            else:
                extendSoln = placeQueen(i+1)
            
            if(extendSoln):
                return True
            else:
                undoQueen(i,j)
    else:
        return False
        
board = {}
n = int(input())
initialise(n)

if(placeQueen(0)):
    for row in board['queen'].keys():
        print((row, board['queen'][row]))
        