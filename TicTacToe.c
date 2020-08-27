#include<stdio.h>
#include<math.h>
char board[3][3];

// human move
int human_move(int pos)
{
        if(pos == 1 && board[0][0]=='_'){
            board[0][0]='X';
            return 1;
        }
        else if(pos == 2 && board[0][1]=='_'){
            board[0][1]='X';
            return 1;
        }
        else if(pos == 3 && board[0][2]=='_'){
            board[0][2]='X';
            return 1;
        }
        else if(pos == 4 && board[1][0]=='_'){
            board[1][0]='X';
            return 1;
        }
        else if(pos == 5 && board[1][1]=='_'){
            board[1][1]='X';
            return 1;
        }
        else if(pos == 6 && board[1][2]=='_'){
            board[1][2]='X';
            return 1;
        }
        else if(pos == 7 && board[2][0]=='_'){
            board[2][0]='X';
            return 1;
        }
        else if(pos == 8 && board[2][1]=='_'){
            board[2][1]='X';
            return 1;
        }
        else if(pos == 9 && board[2][2]=='_'){
            board[2][2]='X';
            return 1;
        }
        else{
            printf("Invalid position \n");
            return 0;
        }

}

void printCurrent(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int isWinner(){
    int i,j;
    //horizontal
    for(i=0;i<3;i++){
        if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X')        return -10;
        else if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O')        return 10;
    }
    //vertical
    for(i=0;i<3;i++){
        if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X')        return -10;
        else if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O')        return 10;
    }
    //diagonal
    if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')        return -10;
    if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')        return -10;
    if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')        return  10;
    if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')        return  10;
    // if no match found
    return 0;
}

int anyMoveLeft(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j]=='_')    return 1;
        }
    }
    return 0;
}

int minmax(int depth,int currentmove){
    int res = isWinner();
    if(res==10) return 10;
    if(res==-10) return -10;
    if(!anyMoveLeft()) return 0;

    if(currentmove){
        int bestscore=-100000;
        int score;
        int i,j;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(board[i][j]=='_'){
                    board[i][j]='O';
                    score = minmax(depth+1,0);
                    board[i][j]='_';
                    if(score>=bestscore)
                        bestscore =score;
                }
            }
        }
        return bestscore;
    }
    else{
        int bestscore =100000;
        int score;
        int i,j;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(board[i][j]=='_'){
                    board[i][j]='X';
                    score = minmax(depth+1,1);
                    board[i][j]='_';
                    if(score<=bestscore)
                        bestscore =score;
                }
            }
        }
        return bestscore;
    }
}

void bestMove(){
    int i,j;
    int bestscore = -10000;
    int move[2];
    int score;
    move[0]=-1;
    move[1]=-1;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j]=='_'){
                board[i][j]='O';
                score = minmax(0,0);
                board[i][j]='_';
                if(score>bestscore){
                    bestscore = score;
                    move[0]=i;
                    move[1]=j;
                }

            }
        }
    }

    board[move[0]][move[1]] = 'O';

}

void main()
{
    int i,j,win;
    //empty board
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            board[i][j]='_';
        }
    }

    while(1){
        int pos,hmove;
        printf("your move \n");
        scanf("%d",&pos);
        hmove = human_move(pos);

        if (!hmove)
            continue;

        printCurrent();
        win = isWinner();

        if(!anyMoveLeft() && win==0){
            printf("TIE\n");
            break;
        }

        bestMove();
        win = isWinner();

        printf("computer moved \n");
        printCurrent();

        if(win ==10){
            printf("You lose\n");
            break;
        }
    }
}
