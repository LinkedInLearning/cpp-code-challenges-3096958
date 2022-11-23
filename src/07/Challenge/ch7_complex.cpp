// C++ Code Challenges, LinkedIn Learning

// Challenge #7: Creating a Class
// Create a class to perform complex number calculations.
// A complex number contains a real part and an imaginary part.
// a+ib
// a and b are real numbers.
// i is the square root of -1.
//
// Overload the +, -, *, and / operators:
//
// z+w = (a+ib)+(c+id) = (a+c) + i(b+d)
// z-w = (a+ib)-(c+id) = (a-c) + i(b-d)
// z*w = (a+ib)*(c+id) = (ac-bd) + i(ad+bc)
// z/w = (a+ib)/(c+id) = ((ac+bd)/(c^2+d^2)) + i((bc-ad)/(c^2+d^2))

#include <iostream>
#include "complex_num.h"

// Main function
int main() {
    complex_num z(10.0,5.0);  // Calls Constructor
    complex_num w(-2.0,-3.0);         // Calls Constructor
    std::cout << "    z = ";
    z.print(std::cout);
    std::cout << std::endl;
    std::cout << "    w = ";
    w.print(std::cout);
    std::cout << std::endl << std::endl;

    complex_num v;
    std::cout << "z + w = ";
    v = z + w;   
    v.print(std::cout);
    std::cout << std::endl;

    std::cout << "z - w = ";
    v = z - w;   
    v.print(std::cout);
    std::cout << std::endl;
    
    std::cout << "z * w = ";
    v = z * w;   
    v.print(std::cout);
    std::cout << std::endl;
    
    std::cout << "z / w = ";
    v = z / w;   
    v.print(std::cout);

    std::cout << std::endl << std::endl;
    return 0;
}
