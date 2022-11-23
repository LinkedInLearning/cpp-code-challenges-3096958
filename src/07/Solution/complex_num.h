#include <iostream>

class complex_num{
    private:
       double real;        // Real Part
       double imaginary;  //  Imaginary Part

    public:
         complex_num(double = 0.0, double = 0.0);
         complex_num operator +(complex_num);
         complex_num operator -(complex_num);
         complex_num operator *(complex_num);
         complex_num operator /(complex_num);
         void set_number(double, double);
         double get_real();
         double get_imaginary();
         void print(std::ostream &os);
};

