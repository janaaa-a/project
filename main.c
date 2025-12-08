#include <stdio.h>
#include "board.h"
#include "move.h"
#include <stdlib.h>

int main(){
    
    char board[10][10];char move[6]; int a[4];int count=0;char disp[32];
    initilize(board);
    printBoard(board);
    while(1){
    scanf("%s",move);
    change(move,a);
    moving(board,a);
    printBoard(board);}

    


    return 0;

}