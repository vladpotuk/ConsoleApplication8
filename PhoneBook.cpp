#include "PhoneBook.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

PhoneBook::PhoneBook() : count(0) {}

PhoneBook::~PhoneBook() {
    for (int i = 0; i < count; ++i) {
        delete abonents[i];
    }
}

void PhoneBook::addAbonent(const char* name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& additional) {
    if (count < MAX_ABONENTS) {
        abonents[count++] = new Abonent(name, home, work, mobile, additional);
    }
    else {
        std::cerr << "PhoneBook is full. Cannot add more abonents.\n";
    }
}

Abonent* PhoneBook::findAbonent(const char* name) const {
    for (int i = 0; i < count; ++i) {
        if (std::strcmp(abonents[i]->getFullName(), name) == 0) {
            return abonents[i];
        }
    }
    return nullptr;
}

void PhoneBook::removeAbonent(const char* name) {
    for (int i = 0; i < count; ++i) {
        if (std::strcmp(abonents[i]->getFullName(), name) == 0) {
            delete abonents[i];
            abonents[i] = abonents[--count];
            return;
        }
    }
}

void PhoneBook::showAllAbonents() const {
    for (int i = 0; i < count; ++i) {
        std::cout << "Name: " << abonents[i]->getFullName() << "\n"
            << "Home Phone: " << abonents[i]->getHomePhone() << "\n"
            << "Work Phone: " << abonents[i]->getWorkPhone() << "\n"
            << "Mobile Phone: " << abonents[i]->getMobilePhone() << "\n"
            << "Additional Info: " << abonents[i]->getAdditionalInfo() << "\n\n";
    }
}

void PhoneBook::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < count; ++i) {
            file << abonents[i]->getFullName() << ","
                << abonents[i]->getHomePhone() << ","
                << abonents[i]->getWorkPhone() << ","
                << abonents[i]->getMobilePhone() << ","
                << abonents[i]->getAdditionalInfo() << "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file for writing.\n";
    }
}

void PhoneBook::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < count; ++i) {
            delete abonents[i];
        }
        count = 0;

        std::string line;
        while (std::getline(file, line) && count < MAX_ABONENTS) {
            char name[256], home[20], work[20], mobile[20], additional[256];
            if (sscanf_s(line.c_str(), "%[^,],%19[^,],%19[^,],%19[^,],%255[^\n]", name, sizeof(name), home, sizeof(home), work, sizeof(work), mobile, sizeof(mobile), additional, sizeof(additional)) == 5) {
                addAbonent(name, home, work, mobile, additional);
            }
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file for reading.\n";
    }
}
