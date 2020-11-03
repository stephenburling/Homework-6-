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
        double operand1 = stack.RemoveFront();
        if (stack.IsEmpty()) {
            std::cout << "Not enough operands" << "\n";
            stack.InsertFront(operand1);
        }
        else {
            double operand2 = stack.RemoveFront();
            double result = operand1 + operand2;
            stack.InsertFront(result);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands" << "\n";
    }
}

void SubFunc(Dlist<double>& stack) {
    try {
        double operand1 = stack.RemoveFront();
        if (stack.IsEmpty()) {
            std::cout << "Not enough operands" << "\n";
            stack.InsertFront(operand1);
        }
        else {
            double operand2 = stack.RemoveFront();
            double result = operand2 - operand1;
            stack.InsertFront(result);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands" << "\n";
    }
}

void MultFunc(Dlist<double>& stack) {
    try {
        double operand1 = stack.RemoveFront();
        if (stack.IsEmpty()) {
            std::cout << "Not enough operands" << "\n";
            stack.InsertFront(operand1);
        }
        else {
            double operand2 = stack.RemoveFront();
            double result = operand1 * operand2;
            stack.InsertFront(result);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands" << "\n";
    }
}

void DivFunc(Dlist<double>& stack) {
    try {
        double operand1 = stack.RemoveFront();
        if (operand1 == 0) {
            std::cout << "Divide by zero\n";
        }
        else if (stack.IsEmpty()) {
            std::cout << "Not enough operands\n";
            stack.InsertFront(operand1);
        }else {
            double operand2 = stack.RemoveFront();
            double result = operand2 / operand1;
            stack.InsertFront(result);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands\n";
    }
}

void Negate(Dlist<double>& stack) {
    try {
        double operand1 = stack.RemoveFront();
        double operand2 = -1;
        double result = operand1 * operand2;
        stack.InsertFront(result);
    }
    catch (emptyList err) {
        std::cout << "Not enough operands\n";
    }
}

void Duplicate(Dlist<double>& stack) {
    try {
        double operand1 = stack.RemoveFront();
        stack.InsertFront(operand1);
        stack.InsertFront(operand1);
    }
    catch (emptyList err) {
        
        std::cout << "Not enough operands\n";
    }
}

void Reverse(Dlist<double>& stack) {
    try {
        double operand1 = stack.RemoveFront();
        if (stack.IsEmpty()) {
            std::cout << "Not enough operands\n";
            stack.InsertFront(operand1);
        }
        else{
            double operand2 = stack.RemoveFront();
            stack.InsertFront(operand2);
            stack.InsertFront(operand1);
        }
    }
    catch (emptyList err) {
        std::cout << "Not enough operands\n";
    }
}

void Print(Dlist<double>& stack) {
    try {
        int operand1 = stack.RemoveFront();
        std::cout << operand1 << " called print\n";
        stack.InsertFront(operand1);
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
        std::cout << operand << " ";
    }
    std::cout << "called print all\n";
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
        // check for bad input
        std::cin >> input_line;
    }
}

int main() {
    CalcDriver();
    return 0;
}