#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {
   private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(Warlock const &other);
	Warlock &operator=(Warlock const &other);

   public:
	~Warlock();
	Warlock(std::string const &n, std::string const &t);
	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &t);
	void introduce() const;
};

#endif