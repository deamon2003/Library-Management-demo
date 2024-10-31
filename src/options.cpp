#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "../include/options.h"
#include "../include/menu.h"

void insertBook(std::vector<UserData>& data) {
    UserData user;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n[+] Enter author name: ";
    std::getline(std::cin, user.author);
    // std::cin.sync();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "[+] Enter Book name: ";
    std::getline(std::cin, user.book_name);
    // std::cin.sync();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "[+] Enter Pages: ";
    std::cin >> user.pages;
    std::cin.sync();
    
    std::cout << "[+] Enter prices: ";
    std::cin >> user.price;
    std::cin.sync();
    
    data.push_back(user); // store the new user data  in the vector
    // std::cout << "[*] User data added succesfully!\n";
    return;
}

void saveBookstoFile(const std::vector<UserData>& data, const std::string& filename) {
    std::ofstream outFile(filename);
    if(outFile.is_open()) {
        for (const auto& book : data) {
            outFile << book.book_name << "\n"
                    << book.author << "\n"
                    << book.pages << "\n"
                    << book.price << "\n";
        }
        outFile.close();
        std::cout << "[=] Books saved successfully.\n";
    } else {
        std::cerr << "[!] Error: Could not open file for  writing.\n";
    }
}

std::vector<UserData> loadBooksFromFile(const std::string& filename) {
    std::vector<UserData> data;
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "\n[!] Error: Could not open file for reading.\n";
        throw std::runtime_error("[!] File cannot be opened.");
    }

    UserData book;
    while (std::getline(inFile, book.book_name) &&
           std::getline(inFile, book.author) &&
           (inFile >> book.pages)&&
           (inFile >> book.price)) {
    
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        data.push_back(book);
    }

    inFile.close();
    std::cout << "\n[=] Books loaded from file successfully.\n\n";
    return data;
}

void displayBookInfo(std::vector<UserData>& data) {

    try {
        std::vector<UserData> loadBooks = loadBooksFromFile(filename);
        for(const auto& book : loadBooks) {
            std::cout << "Title: " << book.book_name << "\n"
                      << "Author: " << book.author << "\n"
                      << "Pages: " << book.pages << "\n"
                      << "Price: " << book.price << "\n\n";
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}

void displayBooksByAuthor(const std::vector<UserData>& data) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string author;
    std::cout << "\n[+] Enter the author name: ";
    std::getline(std::cin, author);

    bool found = false;
    for(const auto& book : data) {
        if (author.compare(book.author) == 0) {
            std::cout << "\nTitle: " << book.book_name << "\n"
                      << "Author: " << book.author << "\n"
                      << "Pages: " << book.pages << "\n"
                      << "Price: " << book.price << "\n\n";
            found = true;
        }
    }

    if (!found) 
        std::cout << "[!] No books found by author: " << author << "\n";
}

int countBooksInFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "\n[!] Error: Unable to open file " << filename << std::endl;
        return -1;
    }

    int bookCount = 0;
    std::string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            bookCount++;
        }
    }

    file.close();
    
    if(bookCount != -1) {
        std::cout << "\n[+] Total number of books in file: " << bookCount << std::endl;
    }
    return 0;
}
