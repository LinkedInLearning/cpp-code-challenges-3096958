// C++ Code Challenges, LinkedIn Learning

// Challenge #9: Fixing Faulty Code
// Fix the bugs in the provided code.
// The application is supposed to ask the user for a string, and count the vowels in it.


#include <iostream>
//                       error
#include <string>
#include <algorithm>


int vowel_count(const std::string str){
    int count=0;
//    for(int i; i<str.length(); i++)   error
    for(int i=0; i<str.length(); i++)
        switch(str[i]){
            /*case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':*/   //error
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            count++;
        }
    return count;
}

// Faulty code, main()
// Summary: This application simulates the game described in the Monty Hall problem a large number of times to reveal the probability of winning by always choosing to switch the choice for a door.


//void main(){    error
int main(){    
    std::string input; 
    std::cout << "Enter some text: ";
    //std::cin >> input;  error  
    std::getline(std::cin,input);
    std::transform(input.begin(), input.end(), input.begin(), toupper);
    std::cout << "\nThe text you entered contains " << vowel_count(input) << " vowels.\n\n";
}
 