#ifndef UNDOREDO_H
#define UNDOREDO_H
#include "board.h"

#define MAX_HISTORY 100

void saveToHistory(piece board[8][8], piece disp[32], int count, int currentPlayer);
int undo(piece board[8][8], piece disp[32], int *count, int *currentPlayer);
int redo(piece board[8][8], piece disp[32], int *count, int *currentPlayer);
void clearHistory();

#endif