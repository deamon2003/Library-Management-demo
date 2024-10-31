#ifndef OPTIONS_H
#define OPTIONS_H

#include <vector>
#include <string>

struct UserData {
    std::string author;
    std::string book_name;
    int pages;
    float price;
};

const std::string filename = "userData.txt";

void insertBook(std::vector<UserData>& data);
void displayBookInfo(std::vector<UserData>& data);
void saveBookstoFile(const std::vector<UserData>& data, const std::string& filename);
std::vector<UserData> loadBooksFromFile(const std::string& filename);
void displayBooksByAuthor(const std::vector<UserData>& data);
int countBooksInFile(const std::string& filename);

#endif