#ifndef SAVELOAD_H
#define SAVELOAD_H
#include "board.h"

void saveGame(piece board[8][8], int currentPlayer, int count, piece disp[32]);
void loadGame(piece board[8][8], int *currentPlayer, int *count, piece disp[32]);

#endif /* SAVELOAD_H */