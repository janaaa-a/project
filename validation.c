#include<stdio.h>
#include <stdlib.h>
#include "board.h"
#include "move.h"
#include <string.h>
int isPromotion(int a[4], piece board[8][8], char move[6])
{
    char piece = board[a[1]][a[0]].type;
    int r2 = a[3];
    if ((piece == 'p' && r2 == 0) || (piece == 'P' && r2 == 7))
    {
        if (piece == 'p' && (move[4] == 'q' || move[4] == 'n' || move[4] == 'r' || move[4] == 'b'))
            return 1;
        else if (piece == 'P' && (move[4] == 'Q' || move[4] == 'N' || move[4] == 'R' || move[4] == 'B'))
            return 1;
    }
    return 0;
}
char placePiece(piece board[8][8], int a[4], char move[6])
{
    char mypiece = board[a[1]][a[0]].type;
    if (isPromotion(a, board, move))
        return move[4];
    else
        return mypiece;
}

int isPathClear(piece board[8][8], int a[4])
{
    // a[0]//Coulumn start
    // a[1]//row start
    // a[2]//colomn end
    // a[3]//row end
    int dirR = 0;
    int dirC = 0;
    if (a[1] == a[3])
    {
        dirR = 0;
        if (a[2] > a[0])
            dirC = 1;
        else
            dirC = -1;
    }
    else if (a[0] == a[2])
    {
        dirC = 0;
        if (a[3] > a[1])
            dirR = 1;
        else
            dirR = -1;
    }
    else if (abs(a[3] - a[1]) == abs(a[2] - a[0]))
    {
        if (a[2] > a[0])
            dirC = 1;
        else
            dirC = -1;
        if (a[3] > a[1])
            dirR = 1;
        else
            dirR = -1;
    }

    int x = dirR + a[1];
    int y = dirC + a[0];
    while ((x != a[3]) || y != a[2])
    {
        if ((board[x][y].type != '.') && (board[x][y].type != '-'))
        {
            return 0;
        }
        x += dirR;
        y += dirC;
    }
    return 1;
}

int isValidBishopMove( int a[4],piece board[8][8])
{

    int rowDiff = abs(a[3] - a[1]);
    int colDiff = abs(a[2] - a[0]);
    if (rowDiff != colDiff)
    {
        return 0;
    }
    return 1;
}

int isValidQueenMove( int a[4],piece board[8][8])
{
    int rowDiff = abs(a[3] - a[1]);
    int colDiff = abs(a[2] - a[0]);

    if (rowDiff == colDiff || a[1] == a[3] || a[0] == a[2])
    {
        return 1;
    }
    return 0;
}
int isValidKingMove(piece board[8][8], int a[4])
{
    int rowdiff = abs(a[1] - a[3]);
    int coldiff = abs(a[0] - a[2]);
    if (rowdiff > 1 || coldiff > 1)
        return 0;
    return 1;
    // TODO: Add check detection
}
int isValidPawnMove(piece board[8][8], int a[4], char piece)
{
    int rowDiff = a[3] - a[1];
    int colDiff = abs(a[2] - a[0]);
    char destpiece = board[a[3]][a[2]].type;

    if (piece == 'p')
    { // white pawn

        if (rowDiff == -1 && colDiff == 0 && (destpiece == '-' || destpiece == '.'))
        {
            return 1; // 1 square
        }

        if (rowDiff == -2 && colDiff == 0 && a[1] == 6 &&
            (board[a[1] - 1][a[0]].type == '.' || board[a[1] - 1][a[0]].type == '-') && (destpiece == '-' || destpiece == '.'))
        {
            return 1; // 2 squares from the start
        }
        if (abs(rowDiff) == abs(colDiff) && rowDiff == -1 && destpiece != '-' && destpiece != '.')
        {
            return 1;
        }
    }
    else
    { // BLACK pawn

        if (rowDiff == 1 && colDiff == 0 && (destpiece == '-' || destpiece == '.'))
        {
            return 1; // 1 square
        }

        if (rowDiff == 2 && colDiff == 0 && a[1] == 1 &&
            (board[a[1] + 1][a[0]].type == '.' || board[a[1] + 1][a[0]].type == '-') && (destpiece == '-' || destpiece == '.'))
        {
            return 1; // 2 squares from the start
        }

        if (abs(rowDiff) == abs(colDiff) && rowDiff == 1 && destpiece != '-' && destpiece != '.')
        {
            return 1;
        }
    }

    return 0;
}
int isValidRookMove(int a[4], piece board[8][8])
{
    if ((a[0] == a[2]) && (a[1] != a[3]))
        return 1;
    else if ((a[0] != a[2]) && (a[1] == a[3]))
        return 1;
    else
        return 0;
}

int isValidKnightMove(int a[4], piece board[8][8])
{
    int rowDiff = abs(a[3] - a[1]);
    int colDiff = abs(a[2] - a[0]);
    if ((rowDiff == 2) && (colDiff == 1))
        return 1;
    else if ((rowDiff == 1) && (colDiff == 2))
        return 1;
    else
        return 0;
}

int isCheck(piece temp[8][8], int currentPlayer)
{
    int kr = -1;
    int kc = -1;
    char king = (currentPlayer == 0) ? 'k' : 'K';

    for (int i = 0; i <8; i++)
    {
        for (int j = 0; j <8; j++)
        {
            if (temp[i][j].type == king)
            {
                kr = i;
                kc = j;
            }
        }
    }

    for (int r = 0; r <8; r++)
    {
        for (int c = 0; c <8; c++)
        {
            char p = temp[r][c].type;
            if (p == '.' || p == '-')
                continue;

            if (currentPlayer == 0 && p >= 'a' && p <= 'z')
                continue;
            if (currentPlayer == 1 && p >= 'A' && p <= 'Z')
                continue;

            int b[4] = {c, r, kc, kr};
            if (p == 'p' && kr == r - 1 && abs(kc - c) == 1)
                return 1;
            if (p == 'P' && kr == r + 1 && abs(kc - c) == 1)
                return 1;
            if ((p == 'n' || p == 'N') && isValidKnightMove(b, temp))
                return 1;
            if ((p == 'b' || p == 'B') && isValidBishopMove(b, temp) && isPathClear(temp, b))
                return 1;
            if ((p == 'r' || p == 'R') && isValidRookMove(b, temp) && isPathClear(temp, b))
                return 1;
            if ((p == 'q' || p == 'Q') && isValidQueenMove(b, temp) && isPathClear(temp, b))
                return 1;
            if ((p == 'k' || p == 'K') && abs(r - kr) <= 1 && abs(c - kc) <= 1)
                return 1;
        }
    }

    return 0;
}

int isValidMove(piece board[8][8], int a[4], int currentPlayer, char move[6])
{
    piece temp[8][8];
    char piece = board[a[1]][a[0]].type;
    char distpiece = board[a[3]][a[2]].type;
    if (currentPlayer == 0)
    {
        if (piece < 'a' || piece > 'z')
        {
            return 0;
        }
        if (distpiece >= 'a' && distpiece <= 'z')
        {
            return 0;
        }
    }
    else
    {
        if (piece < 'A' || piece > 'Z')
        {
            return 0;
        }
        if (distpiece >= 'A' && distpiece <= 'Z')
        {
            return 0;
        }
    }

    if (piece == 'p' || piece == 'P')
    {
        if (!isValidPawnMove(board, a, piece))
            return 0;
    }
    else if (piece == 'b' || piece == 'B')
    {
        if (!isValidBishopMove(a,board))
            return 0;
        if (!isPathClear(board, a))
            return 0;
    }
    else if (piece == 'q' || piece == 'Q')
    {
        if (!isValidQueenMove(a,board))
            return 0;
        if (!isPathClear(board, a))
            return 0;
    }
    else if (piece == 'k' || piece == 'K')
    {
        if (!isValidKingMove(board, a))
            return 0;
    }
    else if (piece == 'n' || piece == 'N')
    {
        if (!isValidKnightMove(a, board))
            return 0;
    }
    else if (piece == 'r' || piece == 'R')
    {
        if (!isValidRookMove(a, board))
            return 0;
        if (!isPathClear(board, a))
            return 0;
    }
    int r2 = a[3];
    if ((piece == 'p' && r2 == 0) || (piece == 'P' && r2 == 7))
    {
        if (move[4] == '\0')
            return 0;
        if (piece == 'p' && (move[4] != 'q' && move[4] != 'n' && move[4] != 'r' && move[4] != 'b'))
            return 0;
        else if (piece == 'P' && (move[4] != 'Q' && move[4] != 'N' && move[4] != 'R' && move[4] != 'B'))
            return 0;
    }

    char placedpiece = placePiece(board, a, move);
    
    copyboard(board, temp);
    applymovesim(temp, a, placedpiece);

    if (isCheck(temp, currentPlayer))
    {
        return 0;
    }

    return 1;
}

int haslegalmove(piece board[8][8],int currentPlayer){
    char fakemoveW[6]="xxxxq";char fakemoveB[6]="xxxxQ";
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            if(board[r][c].type=='-'||board[r][c].type=='.')
            continue;
            if((currentPlayer==0 &&(board[r][c].type >= 'A' && board[r][c].type <= 'Z'))||(currentPlayer==1 && (board[r][c].type >= 'a' && board[r][c].type <= 'z') ))
            continue;
            for(int tr=0;tr<8;tr++){
                for(int tc=0;tc<8;tc++){
                    int b[4]={c,r,tc,tr};
            if(currentPlayer==0){
                if(isValidMove(board,b,currentPlayer,fakemoveW)){
                    return 1;
                }
            }
            else if(currentPlayer==1){
                if(isValidMove(board,b,currentPlayer,fakemoveB)){
                    return 1;
                }
            } 
                }
            }

        }
    }
    return 0;

}

int isCheckmate(piece board[8][8],int currentPlayer){
    if(!isCheck(board,currentPlayer)){
    return 0;}
    if(haslegalmove(board,currentPlayer)){
    return 0;}
    
    return 1;
}

int isdraw(piece board[8][8],int currentPlayer){
    if(isCheck(board,currentPlayer)){
    return 0;}
    if(haslegalmove(board,currentPlayer)){
    return 0;}

    return 1;

}

int isValidInputFormat(char *input) {
    int len = strlen(input);
    
    if (len < 4 || len > 5) {
        printf("Invalid input! Move format: E2E4 or E7E8q (for promotion)\n");
        return 0;
    }

    if (input[0] < 'A' || input[0] > 'H') {
        printf("Invalid input! Starting column must be A-H\n");
        return 0;
    }
    
    if (input[1] < '1' || input[1] > '8') {
        printf("Invalid input! Starting row must be 1-8\n");
        return 0;
    }
    
    if (input[2] < 'A' || input[2] > 'H') {
        printf("Invalid input! Destination column must be A-H\n");
        return 0;
    }
    
    if (input[3] < '1' || input[3] > '8') {
        printf("Invalid input! Destination row must be 1-8\n");
        return 0;
    }

    if (len == 5) {
        char promo = input[4];
        if (promo != 'q' && promo != 'r' && promo != 'b' && promo != 'n' &&
            promo != 'Q' && promo != 'R' && promo != 'B' && promo != 'N') {
            printf("Invalid promotion! Use q/r/b/n (or Q/R/B/N for black)\n");
            return 0;
        }
    }
    
    return 1; 
}
