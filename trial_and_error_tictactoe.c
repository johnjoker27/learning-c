/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>*/

/*char board[3][3];//created the 3x3 board with this.

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
}*/

/*int board[25] = {
    :,:,:,:,:
    :,-,-,-,:,
    :,-,-,-,:,
    :,-,-,-,:,
}*/

/*#include <stdio.h>

enum CellState {
    EMPTY = 0,
    NOUGHTS,
    CROSSES,
    BORDER
};

enum {HUMANWIN,COMPWIN,DRAW};

const int convertTo25[9] = {
    6,7,8,
    11,12,13,
    16,17,18
};

void InitialiseBoard(enum CellState *board){
    for(int index = 0; index < 25; ++index){
        board[index] = BORDER;
    }
    for(int index = 0; index < 9; ++index){
        board[convertTo25[index]] = EMPTY;
    }
}

void printBoard(const enum CellState *board){
    printf("\nBoard:\n");
    for(int index = 0; index < 25; ++index) {
        if (index != 0 && index % 5 == 0){
            printf("\n");
        }
        printf("%d ", board[index]);
    }
    printf("\n");
}

void RunGame(){


}

int main(){
    enum CellState board[25];

    InitialiseBoard(board);
    printBoard(board);

    return 0;
}*/


/*#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    PLAYER_X,
    PLAYER_O
} player;

void print_grid();
void swap_player();
bool check_tie();
bool check_rows();
bool check_columns();
bool check_diagonals();
bool check_winner();
void computer_move();

char GRID[3][3] =
{
    {'-','-','-'},
    {'-','-','-'},
    {'-','-','-'}
};

player CURRENT_PLAYER = PLAYER_X;
bool vs_computer = false;

int main()
{
    srand(time(NULL));


    int mode = 1;
    printf("Choose mode:\n1. Player vs Player\n2. Player vs Computer\n");
    scanf("%d", &mode);
    if(mode == 2)
    {
        vs_computer = true;
    }


    bool game_running = true;

int row, column;

// loop until a valid move is entered
while(true)
{
    printf("\nPlayer: %c\nPlease enter row column (1-3): ",
           CURRENT_PLAYER == PLAYER_X ? 'X' : 'O');

    if(scanf("%d %d", &row, &column) != 2)
    {
        int c;
        while((c = getchar()) != '\n' && c != EOF);  // flush buffer correctly
        printf("Invalid input! Please enter numbers between 1 and 3.\n");
        continue;
    }

    if(row < 1 || row > 3 || column < 1 || column > 3)
    {
        printf("Invalid input! Row and column must be 1, 2, or 3.\n");
        continue;
    }

    if(GRID[row-1][column-1] != '-')
    {
        printf("That space is already taken. Try again.\n");
        continue;
    }

    // valid move entered, break the loop
    break;
}

// apply the move
GRID[row-1][column-1] = CURRENT_PLAYER == PLAYER_X ? 'X' : 'O';

    return 0;
}

void print_grid()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            printf("%c ", GRID[i][j]);
        printf("\n");
    }
}

void swap_player()
{
    CURRENT_PLAYER = (CURRENT_PLAYER == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

bool check_tie()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(GRID[i][j] == '-')
                return false;
    return true;
}

bool check_rows()
{
    for(int i = 0; i < 3; i++)
        if(GRID[i][0] != '-' && GRID[i][0] == GRID[i][1] && GRID[i][1] == GRID[i][2])
            return true;
    return false;
}

bool check_columns()
{
    for(int i = 0; i < 3; i++)
        if(GRID[0][i] != '-' && GRID[0][i] == GRID[1][i] && GRID[1][i] == GRID[2][i])
            return true;
    return false;
}

bool check_diagonals()
{
    if(GRID[0][0] != '-' && GRID[0][0] == GRID[1][1] && GRID[1][1] == GRID[2][2])
        return true;
    if(GRID[0][2] != '-' && GRID[0][2] == GRID[1][1] && GRID[1][1] == GRID[2][0])
        return true;
    return false;
}

bool check_winner()
{
    return check_rows() || check_columns() || check_diagonals();
}

void computer_move()
{
    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while(GRID[row][col] != '-');

    GRID[row][col] = 'O';
    printf("Computer chooses: %d %d\n", row + 1, col + 1);
}
*/









#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    PLAYER_X,
    PLAYER_O
} player;

char GRID[3][3];
player CURRENT_PLAYER = PLAYER_X;
bool vs_computer = false;


void init_grid();
void print_grid();
void swap_player();
bool check_tie();
bool check_rows();
bool check_columns();
bool check_diagonals();
bool check_winner();
void computer_move();
void player_move();

int main() {
    srand(time(NULL));

    char play_again = 'y';



    init_grid();


    int mode = 1;
    printf("Choose mode:\n1. Player vs Player\n2. Player vs Computer\n3.Exit\n");
    if (scanf("%d", &mode) != 1) {
        printf("Invalid input! Defaulting to Player vs Player.\n");
        mode = 1;
    }
    if (mode == 2) {
        vs_computer = true;
    }
    if(mode == 3){
        printf("You choose to leave the game :(  BYE!");
        exit(0);
    }


    bool game_running = true;

    while (game_running) {
        printf("\n***************************\n");
        print_grid();

        if (vs_computer && CURRENT_PLAYER == PLAYER_O) {
            computer_move();
        } else {
            player_move();
        }

        if (check_winner()) {
            print_grid();
            if (vs_computer && CURRENT_PLAYER == PLAYER_O) {
                printf("Winner: Computer (O)\n");
            } else {
                printf("Winner: %c\n", CURRENT_PLAYER == PLAYER_X ? 'X' : 'O');
            }
            break;
        }

        if (check_tie()) {
            print_grid();
            printf("TIE!\n");
            break;
        }

        swap_player();
    }

    printf("Thanks for playing!\n");


    printf("\n Would you want to play again?(y/n): ");
    scanf(" %c",&play_again);

    if (play_again == 'y'){
        srand(time(NULL));

    char play_again = 'y';



    init_grid();


    int mode = 1;
    printf("Choose mode:\n1. Player vs Player\n2. Player vs Computer\n3.Exit\n");
    if (scanf("%d", &mode) != 1) {
        printf("Invalid input! Defaulting to Player vs Player.\n");
        mode = 1;
    }
    if (mode == 2) {
        vs_computer = true;
    }
    if(mode == 3){
        printf("You choose to leave the game :(  BYE!");
        exit(0);
    }


    bool game_running = true;

    while (game_running) {
        printf("\n***************************\n");
        print_grid();

        if (vs_computer && CURRENT_PLAYER == PLAYER_O) {
            computer_move();
        } else {
            player_move();
        }

        if (check_winner()) {
            print_grid();
            if (vs_computer && CURRENT_PLAYER == PLAYER_O) {
                printf("Winner: Computer (O)\n");
            } else {
                printf("Winner: %c\n", CURRENT_PLAYER == PLAYER_X ? 'X' : 'O');
            }
            break;
        }

        if (check_tie()) {
            print_grid();
            printf("TIE!\n");
            break;
        }

        swap_player();
    }

    printf("Thanks for playing!\n");
    }


    return 0;
}


void init_grid() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            GRID[i][j] = '-';
}


void print_grid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%c ", GRID[i][j]);
        printf("\n");
    }
}


void swap_player() {
    CURRENT_PLAYER = (CURRENT_PLAYER == PLAYER_X) ? PLAYER_O : PLAYER_X;
}


bool check_tie() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (GRID[i][j] == '-')
                return false;
    return true;
}


bool check_rows() {
    for (int i = 0; i < 3; i++)
        if (GRID[i][0] != '-' && GRID[i][0] == GRID[i][1] && GRID[i][1] == GRID[i][2])
            return true;
    return false;
}


bool check_columns() {
    for (int i = 0; i < 3; i++)
        if (GRID[0][i] != '-' && GRID[0][i] == GRID[1][i] && GRID[1][i] == GRID[2][i])
            return true;
    return false;
}


bool check_diagonals() {
    if (GRID[0][0] != '-' && GRID[0][0] == GRID[1][1] && GRID[1][1] == GRID[2][2])
        return true;
    if (GRID[0][2] != '-' && GRID[0][2] == GRID[1][1] && GRID[1][1] == GRID[2][0])
        return true;
    return false;
}


bool check_winner() {
    return check_rows() || check_columns() || check_diagonals();
}


void player_move() {
    int row, col;

    while (true) {
        printf("\nPlayer %c, enter row and column (1-3): nb:one value before the other[press enter after each value entered..... ] or enter 0 0 to quit",
               CURRENT_PLAYER == PLAYER_X ? 'X' : 'O');

        if (scanf("%d %d", &row, &col) != 2) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input! Enter numbers between 1 and 3 or 0 0 to quit.\n");
            continue;
        }


        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if(row == 0 && col == 0){
            printf("Player chose to exit the game. Goodbye!\n");
            exit(0);
        }

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input! Row and column must be 1, 2, or 3.\n");
            continue;
        }

        if (GRID[row-1][col-1] != '-') {
            printf("That space is already taken. Try again.\n");
            continue;
        }

        GRID[row-1][col-1] = (CURRENT_PLAYER == PLAYER_X) ? 'X' : 'O';
        break;
    }
}


void computer_move() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (GRID[row][col] != '-');

    GRID[row][col] = 'O';
    printf("Computer chooses: %d %d\n", row+1, col+1);
}
