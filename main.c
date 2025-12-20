#include <stdio.h>
#include <string.h>
#include "board.h"
#include "move.h"
#include "validation.h"
#include <stdlib.h>
#include <ctype.h>
#include "saveload.h"

int main(){
    
    piece board[8][8]; char input[20]; char move[6]; int a[4]; int currentPlayer=0;int count=0;piece disp[32];
    initilize(board);
    printBoard(board);

    while(1){
     printf(" Player %d turn \n", currentPlayer + 1);
    printf("Enter move or (save/load/quit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        for (int i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }
        
        if (strcmp(input, "save") == 0) {
            saveGame(board, currentPlayer, count, disp);
            continue;
        }
        else if (strcmp(input, "load") == 0) {
            loadGame(board, &currentPlayer, &count, disp);
            printBoard(board);
            printDisplay(&count, disp);
            continue;
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        
        if (strlen(input) < 4 || strlen(input) > 5) {
            printf("Invalid move format! Use format like E2E4 or E7E8q\n");
            continue;
        }
         for (int i = 0; input[i]; i++) {
            input[i] = toupper(input[i]);
        }
        if (!isValidInputFormat(input)) {
        continue;  
        }
        strcpy(move, input);  
        change(move,a);
        if (isValidMove(board, a, currentPlayer,move)) {
            currentPlayer = 1 - currentPlayer; // Switching between players
            char placedpiece=placePiece(board,a,move);
            moving(board,a,placedpiece,&count,disp);
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