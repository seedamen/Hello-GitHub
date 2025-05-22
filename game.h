#ifndef GAME_H
#define GAME_H

#include "board.h" // Includes vector and player constants
#include <iostream> // For std::cout, std::endl

class Game {
public:
    // Constructor
    Game();

    // Displays the current game board
    void displayBoard() const;

    // Attempts to make a move for the current player
    // player parameter: 1 for X, 2 for O
    // Returns true if the move was successful, false otherwise
    bool makeMove(int row, int col);

    // Checks if there is a winner
    // Returns PLAYER_X if X wins, PLAYER_O if O wins, EMPTY_CELL otherwise
    char checkWin() const;

    // Checks if the game is a draw
    // Returns true if it's a draw, false otherwise
    bool checkDraw() const;

    // Switches the current player
    void switchPlayer();

    // Gets the current player symbol
    char getCurrentPlayerSymbol() const;

    // Gets the current conceptual player (1 for X, 2 for O)
    int getCurrentPlayer() const;

private:
    Board gameBoard;
    int currentPlayer; // 1 for Player X, 2 for Player O
};

#endif // GAME_H
