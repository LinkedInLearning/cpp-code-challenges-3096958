// C++ Code Challenges, LinkedIn Learning

// Challenge #16: The Monty Hall Problem
// Create an application that simulates the Monty Hall Problem as many times as entered by the user, to prove that the probability of winning is approximately 0.6667 (and not 0.5) if you always switch your choice for a door. 
// https://en.wikipedia.org/wiki/Monty_Hall_problem 

#include <iostream>
#include <chrono>
#include <string>

// The Monty Hall Problem, main()
// Summary: This application simulates the game described in the Monty Hall problem a large number of times to reveal the probability of winning by always choosing to switch the choice for a door.
 
int main(){    
    const int total = 100000;
    int wins=0, car=0, pick=0;
    
    std::srand((unsigned)time(0)); 

    for(int i=0; i<total; i++){
        car = std::rand() % 3;
        pick = std::rand() % 3;
        if(car!=pick)
            wins++;
    }
    std::cout << "The probability of winning when switching your choice is " << (double)wins/total;        
        
    return 0;
}
 