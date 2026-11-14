#include <iostream>

using namespace std;

void clearScreen() {
    // \033[2J clears the entire screen
    // \033[H moves the cursor to the top-left position (row 1, column 1)
    std::cout << "\033[2J\033[H";
    std::cout.flush(); // Forces the output to display immediately
}
