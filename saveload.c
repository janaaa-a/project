#include <stdio.h>
#include <string.h>
#include "saveload.h"
#include "board.h"

void saveGame(piece board[8][8], int currentPlayer, int count, piece disp[32]) {
    FILE *file = fopen("chessgame.txt", "w");
    
    if (file == NULL) {
        printf("Error: Could not create save file!\n");
        return;
    }
    
    fprintf(file, "%d\n", currentPlayer);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fprintf(file, "%c ", board[i][j].type);
            
            fprintf(file, "%d ", board[i][j].state);
            
            fprintf(file, "%d %d ", board[i][j].currentPos[0], board[i][j].currentPos[1]);
            
            fprintf(file, "%d %d ", board[i][j].initialPos[0], board[i][j].initialPos[1]);
            
            fprintf(file, "%d %d", board[i][j].previousPos[0], board[i][j].previousPos[1]);
            
        }
         fprintf(file, "\n"); 
    }
    
    fprintf(file, "%d\n", count);

    for (int i = 0; i < count; i++) {
        fprintf(file, "%c %d %d %d %d %d %d %d\n", 
                disp[i].type,
                disp[i].state,
                disp[i].currentPos[0], disp[i].currentPos[1],
                disp[i].initialPos[0], disp[i].initialPos[1],
                disp[i].previousPos[0], disp[i].previousPos[1]);
    }
    
    fclose(file);
    printf("Game saved successfully to chessgame.txt!\n");
}

void loadGame(piece board[8][8], int *currentPlayer, int *count, piece disp[32]) {
    FILE *file = fopen("chessgame.txt", "r");

    if (file == NULL) {
        printf("Error: No save file found! Start a new game.\n");
        return;
    }

    fscanf(file, "%d\n", currentPlayer);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fscanf(file, " %c", &board[i][j].type); 

            fscanf(file, "%d", &board[i][j].state);

            fscanf(file, "%d %d", &board[i][j].currentPos[0], &board[i][j].currentPos[1]);

            fscanf(file, "%d %d", &board[i][j].initialPos[0], &board[i][j].initialPos[1]);

            fscanf(file, "%d %d", &board[i][j].previousPos[0], &board[i][j].previousPos[1]);
        }
    }
    
    fscanf(file, "%d\n", count);
    
    for (int i = 0; i < *count; i++) {
        fscanf(file, " %c %d %d %d %d %d %d %d\n",
               &disp[i].type,
               &disp[i].state,
               &disp[i].currentPos[0], &disp[i].currentPos[1],
               &disp[i].initialPos[0], &disp[i].initialPos[1],
               &disp[i].previousPos[0], &disp[i].previousPos[1]);
    }
    
    fclose(file);
    printf(" Game loaded successfully from chessgame.txt!\n");
}