#ifndef BOARD_H
#define BOARD_H

void initilize(char board[10][10]);
void printBoard(char board[10][10]);
void display(char board[10][10],int a[],int *count,char disp[32]);
void printDisplay(int *count,char disp[32]);
#endif /* BOARD_H */