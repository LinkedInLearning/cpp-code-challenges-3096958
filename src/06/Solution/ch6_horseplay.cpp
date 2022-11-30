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
    int x, y;
    x = knight[0] - 'a' + 1;
    y = knight[1] - '0';
    const int delta1[2] = {-1, 1};
    const int delta2[2] = {-2, 2};
    
    int new_x;
    int new_y;
    std::string new_loc = "  ";

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
            new_x = x + delta1[i];
            new_y = y + delta2[j];
            
            if(new_x > 0 && new_x < 9 && new_y > 0 && new_y < 9 ){
                new_loc[0] = new_x + 'a' - 1;
                new_loc[1] = new_y + '0';
                moves.push_back(new_loc);
            }

            new_x = x + delta2[i];
            new_y = y + delta1[j];
            
            if(new_x > 0 && new_x < 9 && new_y > 0 && new_y < 9 ){
                new_loc[0] = new_x + 'a' - 1;
                new_loc[1] = new_y + '0';
                moves.push_back(new_loc);
            }
        }
    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
