// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions.
// Rules
// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
// Any live cell with two or three live neighbours lives on to the next generation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


#include <iostream>
#include <string>
#include <algorithm>

int live_neighbors(char game[][11],int i, int j){
    int neighbors = 0;
    i+=10;
    j+=10;
    if(game[(i+1)%10][(j+1)%10]=='X')
        neighbors++;
    if(game[(i+1)%10][j%10]=='X')
        neighbors++;
    if(game[(i+1)%10][(j-1)%10]=='X')
        neighbors++;
    if(game[i%10][(j+1)%10]=='X')
        neighbors++;
    if(game[i%10][(j-1)%10]=='X')
        neighbors++;
    if(game[(i-1)%10][(j+1)%10]=='X')
        neighbors++;
    if(game[(i-1)%10][j%10]=='X')
        neighbors++;
    if(game[(i-1)%10][(j-1)%10]=='X')
        neighbors++;
    return neighbors;
}


// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
 
int main(){    
    char game[10][11] = {"-----X----",
                         "------X---",
                         "----XXX---",
                         "----------",
                         "----------",
                         "----------",
                         "----------",
                         "----------",
                         "----------",
                         "----------"};
    char new_game[10][11];
    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        memcpy(new_game,game,110);
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                int n = live_neighbors(game,i,j);
                
                // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
                if(game[i][j]=='X' && n<2)
                    new_game[i][j]='-';
                // Any live cell with two or three live neighbours lives on to the next generation.
                //if(game[i][j]=='X' && (n==2 || n==3))
                //    new_game[i][j]='X';
                // Any live cell with more than three live neighbours dies, as if by overpopulation.
                if(game[i][j]=='X' && n>3)
                    new_game[i][j]='-';
                // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
                if(game[i][j]=='-' && n==3)
                    new_game[i][j]='X';
            }
        }
        memcpy(game,new_game,110);

        std::cout << "Press Enter for the next generation, or type \"Exit\": ";
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n";
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
 


