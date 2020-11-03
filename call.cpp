#include <iostream>
#include <string>
#include "dlist.h"

void CallDriver(){
    std::string input;
    for (int i = 0; i < 20; i++) {
        std::cin >> input;
        std::cout << input << std::endl;
    }
}

int main() {
    CallDriver();
    return 0;
}