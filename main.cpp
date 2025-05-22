#include "game.h"
#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    Game game;
    int row, col;

    std::cout << "Welcome to Tic Tac Toe!\n";
    std::cout << "Player X starts.\n";

    while (true) {
        game.displayBoard();
        std::cout << "Player " << game.getCurrentPlayerSymbol() 
                  << ", enter your move (row and column, e.g., 1 2): ";

        if (!(std::cin >> row >> col)) {
            std::cout << "Invalid input: Please enter numbers only.\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            continue; // Ask for input again
        }

        // game.makeMove already handles out-of-bounds for 0-2 and occupied cells
        // and prints its own messages.
        if (game.makeMove(row, col)) {
            char winner = game.checkWin();
            if (winner != EMPTY_CELL) {
                game.displayBoard(); // Show final board
                std::cout << "Player " << winner << " wins!\n";
                break;
            }

            if (game.checkDraw()) {
                game.displayBoard(); // Show final board
                std::cout << "It's a draw!\n";
                break;
            }

            game.switchPlayer();
        }
        // If makeMove returned false, it already printed an error message.
        // The loop will continue, and the same player will be prompted again.
    }

    std::cout << "Game Over!\n";
    return 0;
}
