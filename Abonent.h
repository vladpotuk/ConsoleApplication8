#include <string>

class Abonent {
public:
    Abonent(const char* name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& additional);

    const char* getFullName() const;
    const std::string& getHomePhone() const;
    const std::string& getWorkPhone() const;
    const std::string& getMobilePhone() const;
    const std::string& getAdditionalInfo() const;

private:
    char name[256];
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string additionalInfo;
};
