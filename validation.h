#ifndef VALIDATION_H
#define VALIDATION_H


int isValidBishopMove(char board[10][10], int a[4]);
int isValidQueenMove(char board[10][10], int a[4]);
int isValidKingMove(char board[10][10], int a[4]);
int isValidPawnMove(char board[10][10], int a[4], char piece);
int isValidRookMove(int a[4],char board[10][10]);
int isValidKnightMove(int a[4],char board[10][10]);
int isPathClear(char board[10][10],int a[4]);
int isPromotion(int a[4],char board[10][10],char move[6]);
int isCheck(char temp[10][10],int currentPlayer);
char placePiece(char board[10][10],int a[4],char move[6]);

int isValidMove(char board[10][10], int a[4], int currentplayer,char move[6]);
#endif /* VALIDATION_H */