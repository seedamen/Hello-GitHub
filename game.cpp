#include "game.h"
#include "board.h" // Included via game.h, but good for clarity
#include <iostream>
#include <vector> // Included via board.h

// Constructor
Game::Game() : currentPlayer(1) {
    // gameBoard is initialized by its default constructor
}

// Displays the current game board
void Game::displayBoard() const {
    const std::vector<std::vector<char>>& grid = gameBoard.getGrid();
    std::cout << "\n  0 1 2\n"; // Column numbers
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " "; // Row numbers
        for (int j = 0; j < 3; ++j) {
            std::cout << grid[i][j] << (j < 2 ? "|" : "");
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "  -+-+-\n";
        }
    }
    std::cout << std::endl;
}

// Attempts to make a move for the current player
bool Game::makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        std::cout << "Invalid input: Row and column must be between 0 and 2.\n";
        return false; // Out of bounds
    }

    const std::vector<std::vector<char>>& grid = gameBoard.getGrid();
    if (grid[row][col] != EMPTY_CELL) {
        std::cout << "Invalid move: Cell (" << row << ", " << col << ") is already occupied.\n";
        return false; // Cell not empty
    }

    char playerSymbol = getCurrentPlayerSymbol();
    gameBoard.setCell(row, col, playerSymbol); // setCell in Board class handles actual update
    return true;
}

// Checks if there is a winner
char Game::checkWin() const {
    const std::vector<std::vector<char>>& grid = gameBoard.getGrid();

    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] != EMPTY_CELL && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return grid[i][0]; // Winner
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (grid[0][j] != EMPTY_CELL && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            return grid[0][j]; // Winner
        }
    }

    // Check diagonals
    if (grid[0][0] != EMPTY_CELL && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return grid[0][0]; // Winner
    }
    if (grid[0][2] != EMPTY_CELL && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return grid[0][2]; // Winner
    }

    return EMPTY_CELL; // No winner
}

// Checks if the game is a draw
bool Game::checkDraw() const {
    if (checkWin() != EMPTY_CELL) {
        return false; // There's a winner, so not a draw
    }

    const std::vector<std::vector<char>>& grid = gameBoard.getGrid();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == EMPTY_CELL) {
                return false; // Found an empty cell, game is not over yet
            }
        }
    }
    return true; // All cells are filled, and no winner
}

// Switches the current player
void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

// Gets the current player symbol
char Game::getCurrentPlayerSymbol() const {
    return (currentPlayer == 1) ? PLAYER_X : PLAYER_O;
}

// Gets the current conceptual player (1 for X, 2 for O)
int Game::getCurrentPlayer() const {
    return currentPlayer;
}
