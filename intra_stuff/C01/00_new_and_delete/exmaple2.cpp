#include <iostream>
#include <string>

class Student
{
	private:
	std::string _login;

	public:
	Student() :_login("l_default")
	{
		std::cout << "Sttudent " << this->_login << "is born " << std::endl;
	}

	~Student() {
		std::cout << "Student " << this->_login << " died" << std::endl;
	}


};

int main () {
	Student* students = new Student[42];
	//do some stuff
	delete [] students;
	return 0;
}
