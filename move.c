
#include "validation.h"
#include "board.h"

void change(char move[6], int a[4])
{
  a[0] = move[0] - 'A'; // Coulumn
  a[1] = '8' - move[1];   // row
  a[2] = move[2] - 'A';
  a[3] = '8' - move[3];
}

void moving(piece board[8][8], int a[4], char placedpiece,int *count,piece disp[32])
{
  char mypiece = placedpiece;
  piece *moved=&board[a[1]][a[0]];
  piece *dst= &board[a[3]][a[2]];
  if (dst->type != '-' && dst->type != '.')
    {
        dst->state = 0;
        disp[(*count)] = *dst;
        (*count)++;
    }
  moved->currentPos[0] =a[3];
  moved->currentPos[1] =a[2];
  moved->previousPos[0] =a[1];
  moved->previousPos[1] =a[0];
  moved->type = mypiece;
  board[a[3]][a[2]]= *moved;
  board[a[1]][a[0]].type = ((a[1] + a[0]) % 2 == 0) ? '-' : '.';
  board[a[1]][a[0]].state=0;
}


void applymovesim(piece temp[8][8],int b[4],char placedpiece){
  char mypiece=placedpiece;
  piece move=temp[b[1]][b[0]];

  move.type=mypiece;
  move.currentPos[0]=b[3];
  move.currentPos[1]=b[2];
  temp[b[3]][b[2]]=move;
   temp[b[1]][b[0]].type = ((b[1] + b[0]) % 2 == 0) ? '-' : '.';

}
