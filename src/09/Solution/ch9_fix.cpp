// C++ Code Challenges, LinkedIn Learning

// Challenge #9: Fixing Faulty Code
// Fix the bugs in the provided code.
// The application is supposed to ask the user for a string, and print the number of vowels contained in the string.

// For example: 
// "I love my dog" has 4 vowels, "education" has 5 vowels, and "Sly spy by my crypt" has 0 vowels.

#include <string>
//                       error: Missing the iostream header file
#include <iostream>

// vowel_count()
// Summary: This function counts the number of vowels in an incoming string.
// Arguments:
//           str: The string to analyze.
// Returns: An integer with the vowel count.
int vowel_count(const std::string str){
    int count=0;
//    for(int i; i<str.length(); i++)   error: i is uninitialized.
    for(int i=0; i<str.length(); i++)
        switch(str[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            // error: The function makes no assumption about the case.
            //        Either transform the string to lowercase, or include uppercase vowels in the switch.
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
// Summary: This application ask the user for a string, and prints the number of vowels in it.

//void main(){    error: main() should return an int
int main(){    
    std::string input; 
    std::cout << "Enter some text: " << std::flush;

    //std::cin >> input;  error: cin can't read phrases with spaces 
    std::getline(std::cin,input);
    
    std::cout << "\nThe text you entered contains " << vowel_count(input) << " vowels.\n\n";
}
 