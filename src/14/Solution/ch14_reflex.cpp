// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);
    std::srand((unsigned)(time(0)));
    std::rand();
    do{
        std::string word;

        int i = std::rand()%10;
        std::chrono::seconds delay(4 + std::rand() % 7);
        
        auto start = std::chrono::steady_clock::now();
        auto end = start + delay;
        
        std::cout << "\n\n             Wait for it.........                         " << std::flush;
        
        do{
            // Wait for the random delay to catch the player off guard.
        }while(end > std::chrono::steady_clock::now());
        
        std::cout << "\n\t\t\t\t\t Type in the word " << words[i] << ": " << std::flush;

        start = std::chrono::steady_clock::now();
        std::getline(std::cin, word);
        end = std::chrono::steady_clock::now();
        std::transform(word.begin(), word.end(), word.begin(), toupper);
        double elapsed_seconds = (end-start).count()/1e9;
        std::cout << "\n";
        
        if(elapsed_seconds > 2.0)
            if(word.compare(words[i]) == 0)
                std::cout << "You typed in the right word, but you took too long to react! Try again, you can do better than " << elapsed_seconds << " seconds.\n\n";
            else
                std::cout << "You took too long to react and typed in the wrong word! Try again. For the record, it took you " << elapsed_seconds << " seconds.\n\n";
        else
            if(word.compare(words[i]) == 0)
                std::cout << "Well done! It took you " << elapsed_seconds << " seconds.\n\n";
            else
                std::cout << "It took you " << elapsed_seconds << " seconds, but you typed in the wrong word! Try again.\n\n";
        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
