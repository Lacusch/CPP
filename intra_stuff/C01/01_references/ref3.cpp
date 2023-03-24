#include <iostream>
#include <string>
#include <string_view>

class Student {
    private:
        std::string _login;
    public:
       Student(std::string const & login): _login(login) {};
    std::string & getLoginRef() {
        return this->_login;
    }
    std::string const & getConstLoginRef() const {
        return this->_login;
    }

    std::string* getLoginPtr() {
        return &(this->_login);
    }
    std::string const * getConstLoginPtr() const {
        return &(this->_login);
    }
};

int main() {
    Student bob          = Student("bfuber");
    Student const jim    = Student("jfubar");

    std::cout << bob.getConstLoginRef() << " " << jim.getConstLoginRef() << std::endl;
    std::cout << *(bob.getConstLoginPtr()) << " " << *(jim.getConstLoginPtr()) << std::endl;

    bob.getLoginRef() = "bobfubar";
    std::cout << bob.getConstLoginRef() << std::endl;

    *(bob.getLoginPtr()) = "bobbyfubar";
    std::cout << bob.getConstLoginRef() << std::endl;

    return 0;
}
