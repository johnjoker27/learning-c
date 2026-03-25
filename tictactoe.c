#include <stdio.h>
#include <stdlib.h>

char board[3][3];//created the 3x3 board with this.

void initBoard()//Inititializing an empty board
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()//Display the current board state
{
    printf("\n");
    for(int i = 0; i < 3; i++)
    {
        printf("%c | %c | %c", board[i][0], board[i][1], board[i][2]);
        if(i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

void makeMove(char player)//Allowing a player to make a move function
{
    int row, col;

    printf("Player %c, enter row and column (0-2): ", player);
    scanf("%d %d", &row, &col);

    if(board[row][col] == ' ')
    {
        board[row][col] = player;
    }
    else
    {
        printf("Cell already taken! Try again.\n");
        makeMove(player);
    }
}

int checkWinner()//check if a player won
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;

        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

int isDraw()//checking if the game is a draw
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main()
{
    char player = 'X';//starting player

    initBoard();//initialize the board

    while(1)
    {
        printBoard();
        makeMove(player);

        if(checkWinner())
        {
            printBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        if(isDraw())
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
