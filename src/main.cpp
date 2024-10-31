#include <iostream>
#include <limits>
#include <vector>
#include "../include/menu.h"
#include "../include/options.h"

int main() {
    std::vector<UserData> userData;
    int choice;

   do {
        clearScreen();

        std::cout << R"(.____     .__ ___.                                      _____                                                                     __      _________                 __                    )" << std::endl; 
        std::cout << R"(|    |    |__|\_ |__ _______ _____  _______  ___.__.   /     \  _____     ____  _____     ____    ____    _____    ____    ____ _/  |_   /   _____/___.__.  _______/  |_   ____    _____  )" << std::endl; 
        std::cout << R"(|    |    |  | | __ \\_  __ \\__  \ \_  __ \<   |  |  /  \ /  \ \__  \   /    \ \__  \   / ___\ _/ __ \  /     \ _/ __ \  /    \\   __\  \_____  \<   |  | /  ___/\   __\_/ __ \  /     \ )" << std::endl; 
        std::cout << R"(|    |___ |  | | \_\ \|  | \/ / __ \_|  | \/ \___  | /    Y    \ / __ \_|   |  \ / __ \_/ /_/  >\  ___/ |  Y Y  \\  ___/ |   |  \|  |    /        \\___  | \___ \  |  |  \  ___/ |  Y Y  \)" << std::endl; 
        std::cout << R"(|_______ \|__| |___  /|__|   (____  /|__|    / ____| \____|__  /(____  /|___|  /(____  /\___  /  \___  >|__|_|  / \___  >|___|  /|__|   /_______  // ____|/____  > |__|   \___  >|__|_|  /)" << std::endl; 
        std::cout << R"(        \/         \/             \/         \/              \/      \/      \/      \//_____/       \/       \/      \/      \/                \/ \/          \/             \/       \/ )" << std::endl; 

        std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        
        displayMenu(); 
        std::cout << "\n[+] Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "[+] You selecte Option 1: ";
                insertBook(userData);
                saveBookstoFile(userData,filename);
                break;
            case 2:
                std::cout << "[+] You selecte Option 2: ";
                displayBookInfo(userData);
                break;
            case 3:
                std::cout << "[+] You selecte Option 3: ";
                displayBooksByAuthor(userData);
                break;
            case 4:
                std::cout << "[+] You selecte Option 4: ";
                countBooksInFile(filename);
                break;
            case 5:
                std::cout << "Exiting...";
                exit(1);
            default:
                std::cout << "[!] Invalid option. PLease try again.\n";
        }

        std::cout << "\n[-]Press Enter to continue...";
        std::cin.get();
        std::cin.ignore();

   } while(choice != 5);
   return 0;
}


