#ifndef VALIDATION_H
#define VALIDATION_H
#include "board.h"

int isPromotion(int a[4],piece board[8][8],char move[6]);
int isValidBishopMove(piece board[8][8], int a[4]);
int isValidQueenMove(piece board[8][8], int a[4]);
int isValidKingMove(piece board[8][8], int a[4]);
int isValidPawnMove(piece board[8][8], int a[4], char piece);
int isValidRookMove(int a[4],piece board[8][8]);
int isValidKnightMove(int a[4],piece board[8][8]);
int isPathClear(piece board[8][8],int a[4]);

int isCheck(piece temp[8][8],int currentPlayer);
char placePiece(piece board[8][8],int a[4],char move[6]);

int isValidMove(piece board[8][8], int a[4], int currentplayer,char move[6]);
#endif /* VALIDATION_H */