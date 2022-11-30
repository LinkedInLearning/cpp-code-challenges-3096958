#ifndef COMPLEX_NUM_H
#define COMPLEX_NUM_H

#include <iostream>

class complex_num{
    
    // Write your code here

    public:
         complex_num(double = 0.0, double = 0.0);
         complex_num operator +(complex_num);
         complex_num operator -(complex_num);
         complex_num operator *(complex_num);
         complex_num operator /(complex_num);
         void print(std::ostream &os);
};

#endif /* COMPLEX_NUM_H */
