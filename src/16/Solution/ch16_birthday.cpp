// C++ Code Challenges, LinkedIn Learning

// Challenge #16: The Birthday Problem
// The birthday problem consists in finding the probability of having at least two people with the same birthday in a group of n people.
// Create an application that simulates the Birthday Problem 1 million times, with the number of people specified by the user.
// Use this application to prove (empirically) that the probability of having at least 2 people with the same birthday is approximately 0.5 for a group of 23 people. 
// https://en.wikipedia.org/wiki/Birthday_problem 

#include <iostream>
#include <chrono>

// The Birthday Problem, main()
// Summary: This application simulates the birthday problem a large number of times to reveal the probability of a birthday match in a groupd of a given number of people.
int main(){    
    const int total = 1000000;
    int n, i, j, k, matches;
    int b_days[366];
    bool match = false;

    std::cout << "Enter the number of people in the group: " << std::flush;
    std::cin >> n;

    if(n > 366)
        matches = total;
    else{
        std::srand((unsigned)time(0)); 
        std::rand();
        matches=0;

        for(k=0; k<total; k++){ 
            for(i=0; i<n; i++) // Generate random birthdays
                if(i%4 == 0)
                    b_days[i] = std::rand() % 366;
                else
                    b_days[i] = std::rand() % 365;

            match = false;
            for(i=0; i<n-1; i++){ // Compare birthdays
                for(j=i+1; j<n; j++)
                    if(b_days[i]==b_days[j]){
                        match=true;
                        break;
                    }
                if(match)
                    break;
            }
            if(match)
                matches++;
        }
    }

    std::cout << "The probability of a birthday match is " << (double)matches/total << "\n\n" << std::flush;  

    return 0;
}
