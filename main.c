#include <stdio.h>
#include<stdlib.h>
#include "board.h"
#include "move.h"
#include "validation.h"

int main(){
    
    char board[10][10];char move[6]; int a[4]; int currentPlayer=0;
    initilize(board);
    printBoard(board);
    while(1){
        printf("player %d turn: ",currentPlayer+1);
        scanf("%s",move);
        change(move,a);
        if (isValidMove(board, a, currentPlayer)) {
            currentPlayer = 1 - currentPlayer; // Switching between players
            moving(board,a);
            printBoard(board);}
        else {
            printf("Invalid move, try again.\n");
        }
    }
    return 0;

}