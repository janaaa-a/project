#include <stdio.h>
#include <string.h>
#include "undoredo.h"
#include "board.h"
#include "validation.h"
#include "move.h"

#define MAX_HISTORY 100
static piece boardHistory[MAX_HISTORY][8][8];
static piece dispHistory[MAX_HISTORY][32];
static int countHistory[MAX_HISTORY];
static int playerHistory[MAX_HISTORY];
static int historySize = 0;
static int currentPosition = -1;

void saveToHistory(piece board[8][8], piece disp[32], int count, int currentPlayer) {
    
    if (currentPosition < historySize - 1) {
        historySize = currentPosition + 1;
    }

    currentPosition++;

    if (currentPosition >= MAX_HISTORY) {
        printf("Warning: Move history is full!\n");
        currentPosition = MAX_HISTORY - 1;
        return;
    }

    memcpy(boardHistory[currentPosition], board, sizeof(piece) * 8 * 8);
    memcpy(dispHistory[currentPosition], disp, sizeof(piece) * 32);
    countHistory[currentPosition] = count;
    playerHistory[currentPosition] = currentPlayer;
 
    historySize = currentPosition + 1;
}

int undo(piece board[8][8], piece disp[32], int *count, int *currentPlayer) {
    if (currentPosition <= 0) {
        printf("Nothing to undo!\n");
        return 0;
    }
    currentPosition--;

    memcpy(board, boardHistory[currentPosition], sizeof(piece) * 8 * 8);
    memcpy(disp, dispHistory[currentPosition], sizeof(piece) * 32);
    *count = countHistory[currentPosition];
    *currentPlayer = playerHistory[currentPosition];
    
    printf("Move undone!\n");
    return 1;
}

int redo(piece board[8][8], piece disp[32], int *count, int *currentPlayer) {
    if (currentPosition >= historySize - 1) {
        printf("Nothing to redo!\n");
        return 0;
    }

    currentPosition++;

    memcpy(board, boardHistory[currentPosition], sizeof(piece) * 8 * 8);
    memcpy(disp, dispHistory[currentPosition], sizeof(piece) * 32);
    *count = countHistory[currentPosition];
    *currentPlayer = playerHistory[currentPosition];
    
    printf("Move redone!\n");
    return 1;
}

void clearHistory() {
    historySize = 0;
    currentPosition = -1;
    printf("History cleared.\n");
}
  
   