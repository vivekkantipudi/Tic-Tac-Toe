#include<stdio.h>
#include<stdbool.h>

//Tic Tac Toe game
char board[3][3];
char currentPlayer='X';
int i,j;
void boardValues()
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j]='1'+j+3*i;
        }
    }
}
void printBoard()
{
    //printing board
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf(" ");
        for(j=0;j<3;j++)
        {
            printf("%c",board[i][j]);
            if(j<2) printf(" | ");
        }
        if(i<2) printf("\n---|---|---\n");
    }
    printf("\n");
}
bool placeMarker(int cell)
{
   int row = (cell-1)/3; 
   int col = (cell-1)%3;

    if(board[row][col] != 'X' && board[row][col] != 'O') // assigning currentplayer to the board
    {
        board[row][col] = currentPlayer;
        return true;
    }
   return false;
}
bool checkWin()
{
    for(i=0;i<3;i++)
    {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) //rows
        {
            return true;
        }
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) //columns
        {
            return true;
        }
    }

    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) //digonal row 
    {
        return true;
    }
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) //other digonal row
    {
        return true;
    }
  
    return false;

}
bool checkDraw()
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O') //Check whether even one block also empty than not draw else draw
            {
                return false;
            }
        }
    }
    return true;
}
void switchPlayer()
{
    if(currentPlayer == 'X') // switching current player
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
    }
}
int main()
{
    
    boardValues();
    printBoard();
    while(1)
    {
        int cell;
        printf("Player %c, Enter Cell Number (1 - 9): ",currentPlayer);
        scanf("%d",&cell);

        if(cell<1 || cell>9 || !placeMarker(cell))
        {
            printf("Invalid Move! Try Agin: \n");
            continue;
        }

        printBoard();
        if(checkWin())
        {
            printf("Player %c Wins!",currentPlayer);
            break;
        }

        if(checkDraw())
        {
            printf("It's is Draw");
            break;
        }

        switchPlayer();

    }
}