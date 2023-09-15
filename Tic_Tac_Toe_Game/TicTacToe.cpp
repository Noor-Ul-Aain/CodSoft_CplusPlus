#include <iostream>
#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
    gameOver = false;
    movesCount = 0;
}

TicTacToe::~TicTacToe()
{
}

void TicTacToe::printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
             cout << board[i][j];

            if (j < 2)
                 cout << " | ";
        }
         cout <<  endl;

        if (i < 2)
             cout << "---------" <<  endl;
    }
     cout <<  endl;
}

bool TicTacToe::isGameOver()
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i)
    {
        // Rows
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;

        // Columns
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }

    // Diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool TicTacToe::isDraw()
{
    if (movesCount >= 7)
        return true; // After 7 moves, it's possible for no player to win

    return false;
}

void TicTacToe::play()
{
    bool printWelcome = true;

    while (!gameOver)
    {
        system("CLS");

        if (printWelcome)
        {
             cout << "_____________________Welcome to Tic-Tac-Toe Game_____________________\n";
            printWelcome = false;
        }

        // Print the current board
        printBoard();

        // Get the player's move
        int row, col;

         cout << "Player " << currentPlayer << ", enter your move (row [0 - 2] and column [0 - 2] ): ";
         cin >> row >> col;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;
            movesCount++;

            // Check if the current player has won
            if (isGameOver())
            {
                printBoard();

                cout << "Congatulations!!!\nPlayer " << currentPlayer << " wins!!!\n";
                gameOver = true;
            }

            // Check for a draw
            else if (isDraw())
            {
                printBoard();

                 cout << "It's a draw!!!\n";
                gameOver = true;
            }

            // Switch to the other player
            else
            {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

                /*if (currentPlayer == 'X')
                {
                currentPlayer = 'O';
                }
                else
                {
                    currentPlayer = 'X';
                }*/
            }

        }

        else
        {
             cout << "\nInvalid move!!!\nTry again!!!\n";

             char temp;
             cout << "Enter any key to continue: ";
             cin >> temp;
        }

    }

    // Ask the user if they want to replay
    char choice;
    cout << "\nDo you want to play again?\nPress 'y' or 'Y' for YES\nPress any key for NO" <<  endl;
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        // Reset the game and play again
        system("CLS");
        resetGame();
        play();
    }
}
void TicTacToe::resetGame()
{
    // Clear the board and reset game state
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
    gameOver = false;
    movesCount = 0;
}
