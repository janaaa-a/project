#include<stdlib.h>
int isPathClear(char board[10][10], int sr, int sc, int er, int ec) {
    
}
int isValidBishopMove(char board[10][10], int a[4], char piece) {
    
    int rowDiff = abs(a[3] - a[1]);  
    int colDiff = abs(a[2] - a[0]); 
    if (rowDiff != colDiff) {
        return 0; 
    }
        if (!isPathClear(board, a[1], a[0], a[3], a[2])) {
        return 0;  
    }
    
    return 1;
}

int isValidQueenMove(char board[10][10], int a[4], char piece) {
    int rowDiff = abs(a[3] - a[1]);
    int colDiff = abs(a[2] - a[0]);
    
    if (rowDiff == colDiff || a[1] == a[3] || a[0] == a[2]) {
        if (!isPathClear(board, a[1], a[0], a[3], a[2])) {
            return 0;  
        }
        return 1;
    }
    return 0; 
}
int isValidKingMove(char board[10][10], int a[4], char piece){
    int rowdiff= abs(a[1]-a[3]);
    int coldiff = abs(a[0]-a[2]);
    if(rowdiff > 1 || coldiff > 1 )
        return 0;
    return 1;
    // TODO: Add check detection
}
int isValidPawnMove(char board[10][10], int a[4], char piece) {
    int rowDiff = a[3] - a[1];  
    int colDiff = abs(a[2] - a[0]);
    char destpiece = board[a[3]][a[2]];
    
    if (piece == 'p') {  // white pawn 
        
        if( rowDiff == -1 && colDiff == 0 && (destpiece == '-' || destpiece == '.')) {
            return 1;  // 1 square
        }
        
         if( rowDiff == -2 && colDiff == 0 && a[1] == 7 && 
           ( board[a[1] - 1][a[0]] == '.' || board[a[1] - 1][a[0]] == '-')
            && (destpiece == '-' || destpiece == '.')) {
            return 1;  // 2 squares from the start
        }
        if(abs(rowDiff)==abs(colDiff) && rowDiff==-1 && destpiece != '-' && destpiece != '.') {
        return 1;
        }
        
    } else {  // BLACK pawn 
        
         if( rowDiff == 1 && colDiff == 0 && (destpiece == '-' || destpiece == '.')) {
            return 1;  // 1 square
        }
        
       if( rowDiff == 2 && colDiff == 0 && a[1] == 2 && 
           ( board[a[1] + 1][a[0]] =='.' || board[a[1] + 1][a[0]] == '-')
           && (destpiece == '-' || destpiece == '.')) {
            return 1;  // 2 squares from the start
        }
        
        if(abs(rowDiff)==abs(colDiff) && rowDiff==1 &&destpiece != '-' && destpiece != '.') {
        return 1;
        }
    }
    
    return 0;  
}


int isValidMove(char board[10][10], int a[4], int currentPlayer) {
    char piece = board[a[1]][a[0]];  
    char distpiece = board[a[3]][a[2]];

    if (currentPlayer == 0){
        if (piece < 'a' || piece > 'z') {
            return 0; 
        }
        if (distpiece >= 'a' && distpiece <= 'z') {
            return 0; 
        }
    } else {
        if (piece < 'A' || piece > 'Z') {
            return 0; 
        }
        if (distpiece >= 'A' && distpiece <= 'Z') {
            return 0; 
        }
    }

    if (piece == 'p' || piece == 'P') {
        return isValidPawnMove(board, a, piece);
    }
    else if (piece == 'b' || piece == 'B') {
        return isValidBishopMove(board, a, piece);
    }
    else if (piece == 'q' || piece == 'Q') {
        return isValidQueenMove(board, a, piece);
    }
    else if (piece == 'k' || piece == 'K') {
        return isValidKingMove(board, a, piece);
    }
    else {
        return 0; 
    }
}
