#include <iostream>
#include <cstdlib> // For system clear
#include <algorithm>
#include <cctype>
#include <locale>
#include "../include/menu.h"

void displayMenu() {
    std::cout << "[*] Please chose a option from below [*]" << std::endl;
    std::cout << "\n[1] Add book information." << std::endl;
    std::cout << "[2] Display book information." << std::endl;
    std::cout << "[3] To list all books of an author." << std::endl;
    std::cout << "[4] To list the count of books in db." << std::endl;
    std::cout << "[5] For Exit" << std::endl;
}

void clearScreen() {
    system("clear");
}

