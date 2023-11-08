#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <vector>

#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
   private:
	std::string name;
	std::string title;
	SpellBook spellBook;
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
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spell);
	void launchSpell(std::string spell, ATarget const &target);
};

#endif