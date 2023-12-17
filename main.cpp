#define _CRT_SECURE_NO_WARNINGS  

#include "PhoneBook.h"
#include <iostream>

int main() {
    PhoneBook phoneBook;

    std::cout << "Enter information for Abonent 1:\n";
    char name1[256], home1[20], work1[20], mobile1[20], additional1[256];
    std::cout << "Name: ";
    std::cin.getline(name1, sizeof(name1));
    std::cout << "Home Phone: ";
    std::cin.getline(home1, sizeof(home1));
    std::cout << "Work Phone: ";
    std::cin.getline(work1, sizeof(work1));
    std::cout << "Mobile Phone: ";
    std::cin.getline(mobile1, sizeof(mobile1));
    std::cout << "Additional Info: ";
    std::cin.getline(additional1, sizeof(additional1));
    phoneBook.addAbonent(name1, home1, work1, mobile1, additional1);

    std::cout << "Enter information for Abonent 2:\n";
    char name2[256], home2[20], work2[20], mobile2[20], additional2[256];
    std::cout << "Name: ";
    std::cin.getline(name2, sizeof(name2));
    std::cout << "Home Phone: ";
    std::cin.getline(home2, sizeof(home2));
    std::cout << "Work Phone: ";
    std::cin.getline(work2, sizeof(work2));
    std::cout << "Mobile Phone: ";
    std::cin.getline(mobile2, sizeof(mobile2));
    std::cout << "Additional Info: ";
    std::cin.getline(additional2, sizeof(additional2));
    phoneBook.addAbonent(name2, home2, work2, mobile2, additional2);

    std::cout << "\nAll Abonents:\n";
    phoneBook.showAllAbonents();

    std::cout << "\nEnter the name to search: ";
    char searchName[256];
    std::cin.getline(searchName, sizeof(searchName));
    Abonent* foundAbonent = phoneBook.findAbonent(searchName);
    if (foundAbonent) {
        std::cout << "\nAbonent found:\n";
        std::cout << "Name: " << foundAbonent->getFullName() << "\n"
            << "Home Phone: " << foundAbonent->getHomePhone() << "\n"
            << "Work Phone: " << foundAbonent->getWorkPhone() << "\n"
            << "Mobile Phone: " << foundAbonent->getMobilePhone() << "\n"
            << "Additional Info: " << foundAbonent->getAdditionalInfo() << "\n\n";
    }
    else {
        std::cout << "Abonent not found.\n";
    }

    phoneBook.saveToFile("phonebook.txt");
    phoneBook.loadFromFile("phonebook.txt");

    return 0;
}
