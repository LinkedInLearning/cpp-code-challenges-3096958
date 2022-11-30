// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;

    // Write your code here

    return moves;
}

// Main function
int main(){
    std::string knight;
    std::vector<std::string> moves1, moves2;

    knight = "d5";
    moves1 = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : moves1)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;

    knight = "h7";
    moves2 = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : moves2)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;

    return 0;
}
