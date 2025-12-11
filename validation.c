#include<stdlib.h>
int isPathClear(char board[10][10],int a[4]){
    // a[0]//Coulumn start
    //a[1]//row start
    //a[2]//colomn end
    //a[3]//row end
    int dirR=0; int dirC=0;
    if(a[1]==a[3]){
        dirR=0;
        if(a[2]>a[0])
        dirC=1;
        else 
        dirC=-1;
    }
    else if(a[0]==a[2]){
        dirC=0;
        if(a[3]>a[1])
        dirR=1;
        else 
        dirR=-1;
    }
    else if(abs(a[3] - a[1])==abs(a[2] - a[0])){
        if(a[2]>a[0])
        dirC=1;
        else 
        dirC=-1;
        if(a[3]>a[1])
        dirR=1;
        else 
        dirR=-1;
    }

    int x=dirR+a[1];
    int y=dirC+a[0];
    while((x!=a[3])||y!=a[2]){
        if((board[x][y]!='.')&&(board[x][y]!='-')){
        return 0;}
        x+=dirR;
        y+=dirC;
    }
    return 1;
}

int isValidBishopMove(char board[10][10], int a[4], char piece) {
    
    int rowDiff = abs(a[3] - a[1]);  
    int colDiff = abs(a[2] - a[0]); 
    if (rowDiff != colDiff) {
        return 0; 
    }
    return 1;
}

int isValidQueenMove(char board[10][10], int a[4], char piece) {
    int rowDiff = abs(a[3] - a[1]);
    int colDiff = abs(a[2] - a[0]);
    
    if (rowDiff == colDiff || a[1] == a[3] || a[0] == a[2]) {
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
int isValidRookMove(int a[4],char board[10][10]){
    if((a[0]==a[2]) && (a[1]!=a[3]))
        return 1;
    else if((a[0]!=a[2]) && (a[1]==a[3]))
        return 1;
    else
    return 0;
}

int isValidKnightMove(int a[4],char board[10][10]){
    int rowDiff = abs(a[3] - a[1]);  
    int colDiff = abs(a[2] - a[0]); 
    if((rowDiff==2) && (colDiff==1))
    return 1;
    else if((rowDiff==1) && (colDiff==2))
    return 1;
    else
    return 0;}



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
        if(!isValidPawnMove(board, a, piece))
        return 0;
    }
    else if (piece == 'b' || piece == 'B') {
        if(!isValidBishopMove(board, a, piece))
        return 0;
        if(!isPathClear(board,a))
            return 0;
    }
    else if (piece == 'q' || piece == 'Q') {
    if(!isValidQueenMove(board, a, piece))
    return 0;
    if(!isPathClear(board,a))
     return 0;
    }
    else if (piece == 'k' || piece == 'K') {
        if(!isValidKingMove(board, a, piece))
        return 0;
    }
    else if(piece == 'n' || piece == 'N'){
        if(!isValidKnightMove(a,board))
        return 0; 
    }
    else if(piece == 'r' || piece == 'R'){
        if(!isValidRookMove(a,board))
        return 0;
        if(!isPathClear(board,a))
        return 0;     
    }

    return 1;
}
