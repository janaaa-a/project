#ifndef VALIDATION_H
#define VALIDATION_H


int isValidBishopMove(char board[10][10], int a[4], char piece);
int isValidQueenMove(char board[10][10], int a[4], char piece);
int isValidKingMove(char board[10][10], int a[4], char piece);
int isValidPawnMove(char board[10][10], int a[4], char piece);
int isValidRookMove(int a[4],char board[10][10]);
int isValidKnightMove(int a[4],char board[10][10]);
int isPathClear(char board[10][10],int a[4]);


int isValidMove(char board[10][10], int a[4], int currentplayer );
#endif /* VALIDATION_H */