#include <iostream>
#include <string>
#include <cstring>
#include "dlist.h"

bool IsValidAction(std::string input_line) {
    if (input_line == "n" || input_line == "d" || input_line == "r" || input_line == "p" || input_line == "c" || input_line == "a") {
        return true;
    }
    else {
        return false;
    }
}

bool IsValidOperator(std::string input_line) {
    if (input_line == "+" || input_line == "-" || input_line == "*" || input_line == "/") {
        return true;
    }
    else {
        return false;
    }
}

bool IsValidOperand(std::string input_line) {
    int last_index = input_line.size() - 1;

    if (input_line < "0" || input_line > "9") {
        return false;
    }
    else {
        return true;
    }
}

void AddFunc(Dlist<double>& stack) {
    try {
        double operand_one = stack.RemoveFront();
        if (stack.IsEmpty()) {
            std::cout << "Not enough operands" << "\n";
            stack.InsertFront(operand_one);
        }
        else {
            double operand_two = stack.RemoveFront();
            double result = operand_one + operand_two;
            stack.InsertFront(result);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands" << "\n";
    }
}

void SubFunc(Dlist<double>& stack) {
    try {
        double operand_one = stack.RemoveFront();
        if (stack.IsEmpty()) {
            std::cout << "Not enough operands" << "\n";
            stack.InsertFront(operand_one);
        }
        else {
            double operand_two = stack.RemoveFront();
            double result = operand_two - operand_one;
            stack.InsertFront(result);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands" << "\n";
    }
}

void MultFunc(Dlist<double>& stack) {
    try {
        double operand_one = stack.RemoveFront();
        if (stack.IsEmpty()) {
            std::cout << "Not enough operands" << "\n";
            stack.InsertFront(operand_one);
        }
        else {
            double operand_two = stack.RemoveFront();
            double result = operand_one * operand_two;
            stack.InsertFront(result);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands" << "\n";
    }
}

void DivFunc(Dlist<double>& stack) {
    try {
        double operand_one = stack.RemoveFront();
        if (operand_one == 0) {
            std::cout << "Divide by zero\n";
        }
        else if (stack.IsEmpty()) {
            std::cout << "Not enough operands\n";
            stack.InsertFront(operand_one);
        }else {
            double operand_two = stack.RemoveFront();
            double result = operand_two / operand_one;
            stack.InsertFront(result);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands\n";
    }
}

void Negate(Dlist<double>& stack) {
    try {
        double operand_one = stack.RemoveFront();
        double operand_two = -1;
        double result = operand_one * operand_two;
        stack.InsertFront(result);
    }
    catch (emptyList err) {
        std::cout << "Not enough operands\n";
    }
}

void Duplicate(Dlist<double>& stack) {
    try {
        double operand_one = stack.RemoveFront();
        stack.InsertFront(operand_one);
        stack.InsertFront(operand_one);
    }
    catch (emptyList err) {
        
        std::cout << "Not enough operands\n";
    }
}

void Reverse(Dlist<double>& stack) {
    try {
        double operand_one = stack.RemoveFront();
        if (stack.IsEmpty()) {
            std::cout << "Not enough operands\n";
            stack.InsertFront(operand_one);
        }
        else{
            double operand_two = stack.RemoveFront();
            stack.InsertFront(operand_two);
            stack.InsertFront(operand_one);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands\n";
    }
}

void Print(Dlist<double>& stack) {
    try {
        int operand_one = stack.RemoveFront();
        std::cout << operand_one << "\n";
        stack.InsertFront(operand_one);
    }
    catch (emptyList err) {
        std::cout << "Not enough operands\n";
    }
}

void ClearFunc(Dlist<double>& stack) {
    while (!stack.IsEmpty()) {
        stack.RemoveFront();
    }
}

void PrintAll(Dlist<double>& stack) {
    Dlist<double> temp_list = stack;

    while (!temp_list.IsEmpty()) {
        int operand = temp_list.RemoveFront();
        std::cout << operand;

        if (!temp_list.IsEmpty()) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

void CalcDriver() {
    Dlist<double> stack;
    std::string input_line;
    std::cin >> input_line;

    while (input_line != "q") {
        if (IsValidOperand(input_line)) {
            stack.InsertFront(stod(input_line));
        }
        else if(IsValidOperator(input_line)){
            if (input_line == "+") {
                AddFunc(stack);
            }else if(input_line == "-"){
                SubFunc(stack);
            }
            else if (input_line == "*") {
                MultFunc(stack);
            }
            else if (input_line == "/") {
                DivFunc(stack);
            }
        }
        else if (IsValidAction(input_line)) {
            if (input_line == "n") {
                Negate(stack);
            }else if (input_line == "d") {
                Duplicate(stack);
            }
            else if (input_line == "r") {
                Reverse(stack);
            }
            else if (input_line == "p") {
                Print(stack);
            }
            else if (input_line == "c") {
                ClearFunc(stack);
            }
            else if (input_line == "a") {
                PrintAll(stack);
            }
        }
        else {
            std::cout << "Bad Input\n";
        }
        std::cin >> input_line;
    }
}

int main() {
    CalcDriver();
    return 0;
}
