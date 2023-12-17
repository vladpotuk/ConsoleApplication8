#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Abonent.h"
#include<iostream>

class PhoneBook {
private:
    static const int MAX_ABONENTS = 100; 
    Abonent* abonents[MAX_ABONENTS]; 
    int count; 

public:
    PhoneBook();
    ~PhoneBook();
    void addAbonent(const char* name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& additional);
    Abonent* findAbonent(const char* name) const;
    void removeAbonent(const char* name);
    void showAllAbonents() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif 

