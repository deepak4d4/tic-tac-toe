import numpy

#board = numpy.array([["_"]*3]*3)

#for i in range(3):
#    for j in range(3):
#        print(board[i][j],end=" ")
#    print()

def ismoveleft(board):
    #global board
    for i in range(3):
        for j in range(3):
            if board[i][j]=="_":
                return True
    return False
def iswinner(board):
    for i in range(3):
        if board[i][0]==board[i][1]==board[i][2]=="X":
            return -10
        elif board[i][0]==board[i][1]==board[i][2]=="O":
            return 10
    
    #vertical
    for i in range(3):
        if board[0][i]==board[1][i]==board[2][i]=="X":
            return -10
        elif board[0][i]==board[1][i]==board[2][i]=="O":
            return 10
    
    #digonals
    if board[0][0]==board[1][1]==board[2][2]=="X":
        return -10
    if board[0][0]==board[1][1]==board[2][2]=="O":
        return 10
    if board[0][2]==board[1][1]==board[2][0]=="X":
        return -10
    if board[0][2]==board[1][1]==board[2][0]=="O":
        return 10
    
    return 0
    
def minmax(board,depth,ismx):
    result = iswinner(board)
    if result==10 or result ==-10:
        return result
    if ismoveleft(board)==False:
        return 0
    if ismx:
        bestscore =-10**9
        for i in range(3):
            for j in range(3):
                if board[i][j]=="_":
                    board[i][j]="O"
                    score =minmax(board,depth+1,False)
                    bestscore=max(score,bestscore)
                    board[i][j]="_"
        return bestscore
    else:
        bestscore =10**9
        for i in range(3):
            for j in range(3):
                if board[i][j]=="_":
                    board[i][j]="X"
                    score =minmax(board,depth+1,True)
                    bestscore=min(score,bestscore)
                    board[i][j]="_"
        return bestscore

def bestmove(board):
    bestscore=-10**9
    move=[-1,-1]        
    for i in range(3):
        for j in range(3):
            if board[i][j]=="_":
                board[i][j]="O"
                score = minmax(board,0,False)
                board[i][j]="_"
                if score>bestscore:
                    bestscore = score
                    move[0]=i
                    move[1]=j
                    #print("min",move)
    board[move[0]][move[1]]="O"

        
if __name__=="__main__":
    board = numpy.array([["_"]*3]*3)
    for i in range(9):
        human =int(input())
        if human<3:
            board[0][human]="X"
        elif 3<=human<6:
            board[1][human%3]="X"
        elif 6<=human<9:
            board[2][human%3]="X"
        for j in range(3):
            for k in range(3):
               print(board[j][k],end=" ")
            print()
        print()
        win = iswinner(board)
        if ismoveleft(board)==False and win==0:
            print("tie")
            break
        bestmove(board);    
        for j in range(3):
            for k in range(3):
                print(board[j][k],end=" ")
            print()
        if win==10:
            print("O wins")
            break
        elif win==-10:
            print("x wins")
            break
        
