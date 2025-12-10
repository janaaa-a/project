#ifndef VALIDATION_H
#define VALIDATION_H

int isPathClear(char board[10][10], int startRow, int startCol, int endRow, int endCol);


int isValidBishopMove(char board[10][10], int a[4], char piece);
int isValidQueenMove(char board[10][10], int a[4], char piece);
int isValidKingMove(char board[10][10], int a[4], char piece);
int isValidPawnMove(char board[10][10], int a[4], char piece);

int isValidMove(char board[10][10], int a[4], int currentplayer );
#endif /* VALIDATION_H */