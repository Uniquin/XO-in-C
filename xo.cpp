#include "stdio.h"
#include "conio.h"

void main(){
     int i = 0;
     int player = 0;
     int go = 0;
     int row = 0;
     int column = 0;
     int line = 0;
     int winner = 0;
     char board[3][3] = {
         {'1','2','3'},
         {'4','5','6'},
         {'7','8','9'}
       };
     for( i = 0; i<9 && winner==0; i++)
     {
     clrscr();
     printf("\n\n");
     printf("\t\t\t\t %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
     printf("\t\t\t\t---+---+---\n");
     printf("\t\t\t\t %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
     printf("\t\t\t\t---+---+---\n");
     printf("\t\t\t\t %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
     player = i%2 + 1;

     do{
          printf("\n\t\tPlayer %d, please enter the number [your] %c: ", player,(player==1)?'X':'O');
          scanf("%d", &go);
     row = --go/3;
     column = go%3;
     }while(go<0 || go>9 || board[row][column]>'9');
     board[row][column] = (player == 1) ? 'X' : 'O';

     if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
          (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
          winner = player;
     else
     for(line = 0; line <= 2; line ++)
     if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||
          (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
          winner = player;
      }
     clrscr();
     printf("\n\n");
     printf("\t\t\t\t %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
     printf("\t\t\t\t---+---+---\n");
     printf("\t\t\t\t %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
     printf("\t\t\t\t---+---+---\n");
     printf("\t\t\t\t %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
     if(winner == 0)
     printf("\n\t\t\tHow boring, it is a draw\n");
     else
          printf("\n\t\tCongratulations, player %d, YOU ARE THE WINNER!\n", winner);
}
