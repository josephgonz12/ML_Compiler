#include "../include/matrix.h"
#include <iostream>

int main() {
    std::cout << "--- Testing Matrix Initialization ---\n";
    
    Matrix testMat(2, 3);
    
    // TODO: 2. Use your overloaded operator() to assign float values to a few specific indices
    testMat(1,1) = 0.2f;
    testMat(1,2) = 0.4f;
    
    // TODO: 3. Call your print() method to verify the matrix prints out correctly to the console
    testMat.print();
    
    std::cout << "\nBasic setup works!\n";
    return 0;
}