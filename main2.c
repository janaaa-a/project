#include <stdio.h>
#include "board.h"
#include "move.h"
#include "validation.h"
#include <stdlib.h>
#include <string.h>

int main()
{

    piece board[8][8];
    initilize(board);
    printBoard(board);
    return 0;
}