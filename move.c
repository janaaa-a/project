
#include "validation.h"
#include "board.h"

void change(char move[6], int a[4])
{
  a[0] = move[0] - 'A'; // Coulumn
  a[1] = '8' - move[1];   // row
  a[2] = move[2] - 'A';
  a[3] = '8' - move[3];
}

void moving(piece board[8][8], int a[4], char placedpiece)
{
  char piece = placedpiece;
  board[a[3]][a[2]].type = piece;
  board[a[1]][a[0]].type = ((a[1] + a[0]) % 2 == 0) ? '-' : '.';
}
