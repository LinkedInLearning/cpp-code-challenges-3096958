// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_number()
// Summary: This function receives a string and returns true if the string is a decimal number, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for decimal numbers, false otherwise.
bool is_number(const std::string &str){
    if(str.empty())
        return false;
    if(str.find_first_not_of("[0123456789]") == std::string::npos)
        return true;
    return false;
}
 
// get_tokens()
// Summary: This function receives a string with tokens separated by dots, and returns a vector with the tokens.
// Arguments:
//           str: The string to analyze.
// Returns: A vector of strings containing the tokens.
std::vector<std::string> get_tokens(const std::string &str){
    size_t i = 0;
    int dot = -1;
    std::vector<std::string> tokens;

    do{
        dot = str.find('.', dot + 1);
        tokens.push_back(str.substr(i, dot - i));
        i = dot + 1;
    }while(dot != std::string::npos);

    return tokens;
}
  
// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){
    std::vector<std::string> tokens = get_tokens(ip);
 
    if (tokens.size() != 4)
        return false;
 
    for(std::string token: tokens)
        if(is_number(token)){
            int num = stoi(token);
            if(num < 0 || num > 255)
                return false;
        }
        else
            return false;

    return true;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
