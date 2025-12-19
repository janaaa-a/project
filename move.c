
#include "validation.h"

void change(char move[6],int a[4]){
    a[0]=move[0]-'A'+1;//Coulumn
    a[1]='9'-move[1]; //row
    a[2]=move[2]-'A'+1;
    a[3]='9'-move[3];}

    void moving(char board[10][10],int a[4],char placedpiece){
      char piece= placedpiece;
    board [a[3]][a[2]]=piece;
    board[a[1]][a[0]]=((a[1]+a[0])%2==0)?'-':'.';
    }
    

