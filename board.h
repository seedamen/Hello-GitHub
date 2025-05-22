#ifndef BOARD_H
#define BOARD_H

#include <vector>

// Define representations for cell states
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY_CELL = ' ';

// Define the game board class
class Board {
public:
    // Constructor to initialize an empty board
    Board() : grid(3, std::vector<char>(3, EMPTY_CELL)) {}

    // (Optional) A helper function to get the board (maybe useful for display or testing)
    const std::vector<std::vector<char>>& getGrid() const {
        return grid;
    }

    // (Optional) A function to set a cell (useful for making a move)
    // Basic version without error checking for now
    void setCell(int row, int col, char player) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            grid[row][col] = player;
        }
    }

private:
    std::vector<std::vector<char>> grid;
};

#endif // BOARD_H
