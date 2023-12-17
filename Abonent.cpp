#include "Abonent.h"
#include <cstring>

Abonent::Abonent(const char* name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& additional)
    : homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(additional) {
    strcpy_s(this->name, sizeof(this->name), name);
}

const char* Abonent::getFullName() const {
    return name;
}

const std::string& Abonent::getHomePhone() const {
    return homePhone;
}

const std::string& Abonent::getWorkPhone() const {
    return workPhone;
}

const std::string& Abonent::getMobilePhone() const {
    return mobilePhone;
}

const std::string& Abonent::getAdditionalInfo() const {
    return additionalInfo;
}


