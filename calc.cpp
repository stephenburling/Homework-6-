#include <iostream>
#include <string>
#include <cstring>
#include "dlist.h"

bool IsValidNumber(std::string input_line) {

    int last_index = input_line.size() - 1;

    if (input_line[0] == '-' || input_line[last_index] == '.') {
        return false;
    }
    else {
        return true;
    }
}
void AddFunc(Dlist<double>& stack) {

    // Check for two operands 
    try {
        double operand1 = stack.RemoveFront();
        double operand2 = stack.RemoveFront();
        double result = operand1 + operand2;
        std::cout << result;
        stack.InsertFront(result);
    }
    catch (emptyList e) {
        std::cout << "Not enough operands." << std::endl;
    }
}

void CalcDriver(Dlist<double>& stack) {
    std::string input_line;
    std::cin >> input_line;

    while (input_line != "q") {
        if (IsValidNumber(input_line)) {
            stack.InsertFront(stod(input_line));
        }
        else {
            if (input_line == "+") {
                AddFunc(stack);
            }
            // check for symbol
        }
        // check for bad input 
        std::cin >> input_line;
    }
}