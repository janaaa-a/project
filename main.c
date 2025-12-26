#include <stdio.h>
#include <string.h>
#include "board.h"
#include "move.h"
#include "validation.h"
#include <stdlib.h>
#include <ctype.h>
#include "saveload.h"
#include "undoredo.h"
int main(){
    
    piece board[8][8]; char input[20]; char move[6]; int a[4]; int currentPlayer=0;int count=0;piece disp[32];
    initilize(board);
    printBoard(board);
    saveToHistory(board, disp, count, currentPlayer);
    while(1){
     printf(" Player %d turn \n", currentPlayer + 1);
    printf("Enter move or (save/load/quit/undo/redo): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        for (int i = 0; i<4 ; i++) {
            input[i] = toupper(input[i]);
        }
        
        if (strcmp(input, "SAVE") == 0) {
            saveGame(board, currentPlayer, count, disp);
            continue;
        }
        else if (strcmp(input, "LOAD") == 0) {
            loadGame(board, &currentPlayer, &count, disp);
            clearHistory();  
            saveToHistory(board, disp, count, currentPlayer);  
            printBoard(board);
            printDisplay(&count, disp);
            continue;
        }
        else if (strcmp(input, "QUIT") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
         if (strcmp(input, "UNDO") == 0) {
        if (undo(board, disp, &count, &currentPlayer)) {
            printBoard(board);
            printDisplay(&count, disp);
        }
        continue;
        }
        if (strcmp(input, "REDO") == 0) {
            if (redo(board, disp, &count, &currentPlayer)) {
            printBoard(board);
            printDisplay(&count, disp);
        }
        continue;
    }
        
        if (!isValidInputFormat(input)) {
        continue;  
        }
        strcpy(move, input);  
        change(move,a);
        if (isValidMove(board, a, currentPlayer,move)) {
            char placedpiece=placePiece(board,a,move);
            moving(board,a,placedpiece,&count,disp);
            currentPlayer = 1 - currentPlayer; // Switching between players
            saveToHistory(board, disp, count, currentPlayer);
            printBoard(board);
            printDisplay(&count, disp);
        }
        else {
            printf("Invalid move, try again.\n");
        }
        if(isCheckmate(board,currentPlayer)){
            printf("checkmate! Player %d wins!", 2 - currentPlayer);
            break;
        }
        if(isdraw(board,currentPlayer)){
            printf("draw!");
            break;
        }
    }
    printf("game over");
    return 0;
}