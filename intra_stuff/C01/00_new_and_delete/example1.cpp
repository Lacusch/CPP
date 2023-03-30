#include <iostream>
#include <string>

class Student
{
	private:
		std::string _login;
	
	public:
		Student(std::string login) : _login(login)
		{
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}

		~Student() {
			std::cout << "Student " << this->_login << " died" << std::endl;
		}
};

int main()
{
	Student	bob = Student("bfubar");
	Student* jim = new Student("jfubar");
	//stuff over here
	delete jim; //delete jim
	return (0); //bob deletes itself
}
