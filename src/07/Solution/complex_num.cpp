#include "complex_num.h"

complex_num::complex_num(double r, double i){
    real = r;
    imaginary = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.real = real + w.real;
    z.imaginary = imaginary + w.imaginary;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.real = real - w.real;
    z.imaginary = imaginary - w.imaginary;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.real = (real * w.real) - (imaginary * w.imaginary);
    z.imaginary = (real * w.imaginary) + (imaginary * w.real);
    return z;
}

complex_num complex_num::operator /(complex_num w){
    double div = (w.real * w.real) + (w.imaginary * w.imaginary);
    complex_num z;
    z.real = (real * w.real) + (imaginary * w.imaginary);
    z.real /= div;
    z.imaginary = (imaginary * w.real) - (real * w.imaginary);
    z.imaginary /= div;
    return z;
}

void complex_num::print(std::ostream &os){
    if(imaginary >= 0.0)
        os << real << " + " << imaginary << "i";
    else
        os << real << " - " << imaginary * -1 << "i";
    os << std::flush;
}