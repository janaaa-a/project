#ifndef MOVE_H
#define MOVE_H
#include "board.h"

void change(char move[6],int a[4]);
void moving(piece board[8][8],int a[4],char placedpiece,int *count,piece disp[32]);
void applymovesim(piece temp[8][8],int b[4],char placedpiece);

#endif /* MOVE_H */