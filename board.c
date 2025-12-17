#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"
void initilize(piece board[8][8])
{

    memset(board, 0, 8 * 8 * sizeof(piece));
    piece pTemp;
    for (int i = 0; i < 8; i++)
    {
        pTemp.type = 'p';
        pTemp.currentPos[0] = 6;
        pTemp.currentPos[1] = i;
        pTemp.initialPos[0] = 6;
        pTemp.initialPos[1] = i;
        pTemp.state = 1;
        board[6][i] = pTemp;
    }
    for (int i = 0; i < 8; i++)
    {
        pTemp.type = 'P';
        pTemp.currentPos[0] = 1;
        pTemp.currentPos[1] = i;
        pTemp.initialPos[0] = 1;
        pTemp.initialPos[1] = i;
        pTemp.state = 1;
        board[1][i] = pTemp;
    }

    pTemp.type = 'r';
    pTemp.currentPos[0] = 7;
    pTemp.currentPos[1] = 0;
    pTemp.initialPos[0] = 7;
    pTemp.initialPos[1] = 0;
    pTemp.state = 1;
    board[7][0] = pTemp;
    pTemp.type = 'r';
    pTemp.currentPos[0] = 7;
    pTemp.currentPos[1] = 7;
    pTemp.initialPos[0] = 7;
    pTemp.initialPos[1] = 7;
    pTemp.state = 1;
    board[7][7] = pTemp;

    pTemp.type = 'n';
    pTemp.currentPos[0] = 7;
    pTemp.currentPos[1] = 1;
    pTemp.initialPos[0] = 7;
    pTemp.initialPos[1] = 1;
    pTemp.state = 1;
    board[7][1] = pTemp;

    pTemp.type = 'n';
    pTemp.currentPos[0] = 7;
    pTemp.currentPos[1] = 6;
    pTemp.initialPos[0] = 7;
    pTemp.initialPos[1] = 6;
    pTemp.state = 1;
    board[7][6] = pTemp;

    pTemp.type = 'b';
    pTemp.currentPos[0] = 7;
    pTemp.currentPos[1] = 2;
    pTemp.initialPos[0] = 7;
    pTemp.initialPos[1] = 2;
    pTemp.state = 1;
    board[7][2] = pTemp;

    pTemp.type = 'b';
    pTemp.currentPos[0] = 7;
    pTemp.currentPos[1] = 5;
    pTemp.initialPos[0] = 7;
    pTemp.initialPos[1] = 5;
    pTemp.state = 1;
    board[7][5] = pTemp;
    pTemp.type = 'q';
    pTemp.currentPos[0] = 7;
    pTemp.currentPos[1] = 4;
    pTemp.initialPos[0] = 7;
    pTemp.initialPos[1] = 4;
    pTemp.state = 1;
    board[7][4] = pTemp;
    pTemp.type = 'k';
    pTemp.currentPos[0] = 7;
    pTemp.currentPos[1] = 3;
    pTemp.initialPos[0] = 7;
    pTemp.initialPos[1] = 3;
    pTemp.state = 1;
    board[7][3] = pTemp;

    pTemp.type = 'K';
    pTemp.currentPos[0] = 0;
    pTemp.currentPos[1] = 3;
    pTemp.initialPos[0] = 0;
    pTemp.initialPos[1] = 3;
    pTemp.state = 1;
    board[0][3] = pTemp;
    pTemp.type = 'Q';
    pTemp.currentPos[0] = 0;
    pTemp.currentPos[1] = 4;
    pTemp.initialPos[0] = 0;
    pTemp.initialPos[1] = 4;
    pTemp.state = 1;
    board[0][4] = pTemp;

    pTemp.type = 'B';
    pTemp.currentPos[0] = 0;
    pTemp.currentPos[1] = 5;
    pTemp.initialPos[0] = 0;
    pTemp.initialPos[1] = 5;
    pTemp.state = 1;
    board[0][5] = pTemp;
    pTemp.type = 'B';
    pTemp.currentPos[0] = 0;
    pTemp.currentPos[1] = 2;
    pTemp.initialPos[0] = 0;
    pTemp.initialPos[1] = 2;
    pTemp.state = 1;
    board[0][2] = pTemp;

    pTemp.type = 'N';
    pTemp.currentPos[0] = 0;
    pTemp.currentPos[1] = 1;
    pTemp.initialPos[0] = 0;
    pTemp.initialPos[1] = 1;
    pTemp.state = 1;
    board[0][1] = pTemp;

    pTemp.type = 'N';
    pTemp.currentPos[0] = 0;
    pTemp.currentPos[1] = 6;
    pTemp.initialPos[0] = 0;
    pTemp.initialPos[1] = 6;
    pTemp.state = 1;
    board[0][6] = pTemp;

    pTemp.type = 'R';
    pTemp.currentPos[0] = 0;
    pTemp.currentPos[1] = 0;
    pTemp.initialPos[0] = 0;
    pTemp.initialPos[1] = 0;
    pTemp.state = 1;
    board[0][0] = pTemp;

    pTemp.type = 'R';
    pTemp.currentPos[0] = 0;
    pTemp.currentPos[1] = 7;
    pTemp.initialPos[0] = 0;
    pTemp.initialPos[1] = 7;
    pTemp.state = 1;
    board[0][7] = pTemp;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!((board[i][j].type >= 'A' && board[i][j].type <= 'Z') || (board[i][j].type >= 'a' && board[i][j].type <= 'z')))

            {
                board[i][j].type = ((i + j) % 2 == 0) ? '-' : '.';
            }
        }
    }

    //-------------old -------------//
}
void printBoard(piece board[8][8])
{

    printf("  A   B   C   D   E   F   G   H  ");
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", 8 - i);
        for (int j = 0; j < 8; j++)
        {

            printf(" %c  ", board[i][j].type);
        }
        printf("%d", 8 - i);
        printf("\n");
    }
    printf("  A   B   C   D   E   F   G   H  ");
    printf("\n");
}

void display(piece board[8][8], int a[4], int *count, char disp[32])
{
    char dist = board[a[3]][a[2]].type;
    if ((board[a[3]][a[2]].type >= 'A' && board[a[3]][a[2]].type <= 'Z') || (board[a[3]][a[2]].type >= 'a' && board[a[3]][a[2]].type <= 'z'))
    {
        disp[*count] = dist;
        *count += 1;
    }
}

void printDisplay(int *count, char disp[32])
{
    printf("taken out pieces:{");
    if ((*count) != 0)
    {
        for (int i = 0; i < (*count); i++)
        {
            printf("%c ,", disp[i]);
        }
    }
    printf("}\n");
}

void copyboard(piece board[8][8], piece temp[8][8])
{
    memset(temp, 0, 8 * 8 * sizeof(piece));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!((board[i][j].type >= 'A' && board[i][j].type <= 'Z') || (board[i][j].type >= 'a' && board[i][j].type <= 'z')))

            {
                temp[i][j].type = ((i + j) % 2 == 0) ? '-' : '.';
            }
            else
            {
                temp[i][j].type = board[i][j].type;
            }
        }
    }
}
