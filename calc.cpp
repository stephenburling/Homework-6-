#include <iostream>
#include <string>
#include "dlist.h"
/*
bool IsValidAction(std::string input_line)
    if the input line is equal to either n, d, r, p, c, or a
        return true
    else
        return false

bool IsValidOperator(std::string input_line)
    if the input line is equal to either +, -, *, or /
        return true
    else
        return false


bool IsValidOperand(std::string input_line)
    if the input line is between the values of 0 and 9
        return true
    else
        return false


void AddFunc(Dlist<double>& stack)
    try
        set double named operand_one equal to number removed off top of stack
        if stack is empty
            Print "Not enough operands"
            Insert operand_one back on top of stack
        else
            set double named operand_two equal to number removed off top of stack
            set double named result equal to sum of operand_one and operand_two
    catch emptyList instance
        Print "Not enough operands"


void SubFunc(Dlist<double>& stack)
    try
        set double named operand_one equal to number removed off top of stack
        if stack is empty
            Print "Not enough operands"
            Insert operand_one back on top of stack
        else
            set double named operand_two equal to number removed off top of stack
            set double named result equal to difference of operand_one and operand_two
    catch emptyList instance
        Print "Not enough operands"


void MultFunc(Dlist<double>& stack)
    try
        set double named operand_one equal to number removed off top of stack
        if stack is empty
            Print "Not enough operands"
            Insert operand_one back on top of stack
        else
            set double named operand_two equal to number removed off top of stack
            set double named result equal to product of operand_one and operand_two
    catch emptyList instance
        Print "Not enough operands"


void DivFunc(Dlist<double>& stack)
    try
        set double named operand_one equal to number removed off top of stack
        if operand_one is equal to zero
            Print "Divide by zero"
        if stack is empty
            Print "Not enough operands"
            Insert operand_one back on top of stack
        else
            set double named operand_two equal to number removed off top of stack
            set double named result equal to quotient of operand_one and operand_two
    catch emptyList instance
        Print "Not enough operands"


void Negate(Dlist<double>& stack)
    try
        set double named operand_one equal to number removed from top of stack
        set double named operand_two equal to negative one
        set result equal to the product of operand_one and operand_two
        insert result on top of stack
    catch emptyList instance
        Print "Not enough operands"


void Duplicate(Dlist<double>& stack)
    try
        set double named operand_one equal to number removed from top of stack
        insert operand_one on top of stack
        insert operand_one on top of stack
    catch emptyList instance
        Print "Not enough operands"


void Reverse(Dlist<double>& stack)
    try
        set double named operand_one equal to number removed off top of stack
        if stack is empty
            Print "Not enough operands"
            Insert operand_one back on top of stack
        else
            insert operand_one on top of stack
            insert operand_two on top of stack
    catch emptyList instance
        Print "Not enough operands"


void Print(Dlist<double>& stack)
    try
        set double operand_one equal to removed number on top of stack
        Print operand_one followed by endline
    catch emptyList instance
        Print "Not enough operands"


void ClearFunc(Dlist<double>& stack)
    While stack is not empty
        Call RemoveFront on stack


void PrintAll(Dlist<double>& stack)
    Create temporary Dlist called temp_list equal to stack
    While temp_list is not empty
        set double operand equal to top removed number from temp_list
        Print operant
        if temp_list is not empty
            Print a single whitespace
    Print an endline


void CalcDriver()
    Create empty Dlist called stack
    Create string called input_line
    Make input_line equal to user input

    While input_line is not equal to q
        if input_line is a valid operand
            Insert input_line on top of stack as a double
        else if input_line is a valid operator
            if input_line is equal to +
                call AddFunc
            if input_line is equal to -
                call SubFunc
            if input_line is equal to *
                call MultFunc
            if input_line is equal to /
                call DivFunc
        else if input_line is valid action
            if input_line is equal to d
                call Duplicate
            if input_line is equal to r
                call Reverse
            if input_line is equal to p
                call Print
            if input_line is equal to c
                call Clear
            if input_line is equal to a
                call PrintAll
        else
            Print "Bad Input\n"
    Set input_line equal to user input

int main()
    Call CalcDriver
    Return 0

*/
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
        double operand_one = stack.RemoveFront();
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
        double operand = temp_list.RemoveFront();
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