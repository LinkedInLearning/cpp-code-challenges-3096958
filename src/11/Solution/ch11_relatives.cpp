// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::vector<std::vector<std::string>> people;
    std::vector<std::string> person;
    std::string entry, name;
    
    std::fstream file ("names.csv", std::ios::in);
    // Get the CSV file into a vector of vectors.
    if(file.is_open()){
        while(std::getline(file, entry,',')){
            std::stringstream str(entry);
            person.clear();
            while(std::getline(str, name,' '))
                person.push_back(name);
            people.push_back(person);
        }
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }
    
    std::cout<<"People found in the CSV file:\n\n";
    
    for(int i=0; i<people.size(); i++){
        for(int j=0; j<people[i].size(); j++)
            std::cout << people[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";

    for(int i=0; i<people.size()-1; i++){
        for(int j=i+1; j<people.size(); j++)
            if(people[i][1].compare(people[j][1]) == 0){
                std::cout << people[i][0] << " " << people[i][1] << " may be related to " << people[j][0] << " " << people[j][1] << ".\n\n" << std::flush; 
                return 0;
            }
    }
    std::cout << "No relatives found.\n\n" << std::flush;  
    return 0;
}
 