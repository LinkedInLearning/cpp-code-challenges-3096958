// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Use the algorithm of your choice.
// Don't use a sorting function.

#include <iostream>

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.

bool sort_array(int *arr, int n) {
    if (arr == NULL)
        return false;
    if (n < 2)
        return true;

    // Bubble sort algorithm
    bool sorted = false;
    int temp;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = false;
            }
    }
    return true;
}

// Main function
int main() {
    const int len = 3;
    int array[5] = {1, 4, 3, 5, 2};

    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    sort_array(array, len);

    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";

    return 0;
}
