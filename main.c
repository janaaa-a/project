#include <stdio.h>
#include "board.h"
#include "move.h"
#include "validation.h"
#include <stdlib.h>

int main(){
    
    piece board[8][8];char move[6]; int a[4]; int currentPlayer=0;int count=0;char disp[32];
    initilize(board);
    printBoard(board);
    while(1){
        printf("player %d turn: ",currentPlayer+1);
        scanf("%s",move);
        change(move,a);
        if (isValidMove(board, a, currentPlayer,move)) {
            currentPlayer = 1 - currentPlayer; // Switching between players
            char placedpiece=placePiece(board,a,move);
            moving(board,a,placedpiece);
            printBoard(board);}
        else {
            printf("Invalid move, try again.\n");
        }
    }
    return 0;

}