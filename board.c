#include<stdio.h>
void initilize(char board[10][10]){
     char a[10][10]={{' ','A','B','C','D','E','F','G','H',' '},
    {'8','R','N','B','K','Q','B','N','R','8'},{'7','P','P','P','P','P','P','P','P','7'},
    {'\0'},{'\0'},{'\0'},{'\0'},
{'2','p','p','p','p','p','p','p','p','2'},{'1','r','n','b','k','q','b','n','r','1'},
{' ','A','B','C','D','E','F','G','H',' '}};
for(int i=1;i<=8;i++){
    a[i][0]='9'-i;
    a[i][9]='9'-i;
}
for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]=='\0')
            a[i][j]=((i+j)%2==0)?'-':'.';}}
for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            board[i][j]=a[i][j];
        
        }}}
void printBoard(char board[10][10]){
for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
    printf("%c  ",board[i][j]);
}printf("\n");

}}