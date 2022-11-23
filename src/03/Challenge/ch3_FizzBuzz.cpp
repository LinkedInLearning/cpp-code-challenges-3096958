// C++ Code Challenges, LinkedIn Learning

// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>

// FizzBuzz, main()
// Summary: This application runs on the main function.

int main() {
    int n;
    bool m3, m5;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        m3 = (i % 3) == 0;
        m5 = (i % 5) == 0;

        if (!m3 && !m5)
            std::cout << i;
        else {
            if (m3)
                std::cout << "Fizz";
            if (m5)
                std::cout << "Buzz";
        }
        std::cout << std::endl;
    }
    return 0;
}
