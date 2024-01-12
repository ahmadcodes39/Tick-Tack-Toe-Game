#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void display_board()
{
    cout << "\n-------------\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n-------------\n";
    }
}

bool check_winner(char c)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
        {
            return true;
        }
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
        {
            return true;
        }
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
    {
        return true;
    }
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
    {
        return true;
    }
    return false;
}

bool is_board_full()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void play_game()
{
    char player = 'X';
    int row, col;
    bool play_again = true;

    while (play_again)
    {
       
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }

        while (true)
        {
            display_board();

          
            cout << "Player " << player << ", enter row and column (1-3): ";
            cin >> row >> col;

           
            row--;
            col--;

           
            if (row < 0 || row > 2 || col < 0 || col > 2)
            {
                cout << "Invalid input, try again\n";
                continue;
            }
            if (board[row][col] != ' ')
            {
                cout << "That spot is already taken, try again\n";
                continue;
            }

           
            board[row][col] = player;
            if (check_winner(player))
            {
                display_board();
                cout << "Player " << player << " wins!\n";
                break;
            }

           
            if (is_board_full())
            {
                display_board();
                cout << "The game is a tie!\n";
                break;
            }
           
            
            player = (player == 'X') ? 'O' : 'X';
        }

       
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            play_again = true;
        }
        else
        {
            play_again = false;
        }
    }
}

int main()
{
    play_game();
    return 0;
}