#ifndef BOARD_H
#define BOARD_H

typedef struct{
char type;
int initialPos[2];
int previousPos[2];
int currentPos[2];
int desiredPos[2];
int state; //0 -> dead, 1->alive
}piece; 

void initilize(piece board[8][8]);
void printBoard(piece board[8][8]);
void printDisplay(int *count,piece disp[32]);
void copyboard(piece board[8][8],piece temp[8][8]);
#endif /* BOARD_H */