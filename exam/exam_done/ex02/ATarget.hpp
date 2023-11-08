#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget {
   protected:
	std::string type;
	ATarget();
	ATarget(ATarget const &other);
	ATarget &operator=(ATarget const &other);

   public:
	virtual ~ATarget();
	ATarget(std::string const &t);
	std::string const &getType() const;
	virtual ATarget *clone() const = 0;
	void getHitBySpell(ASpell const &spell) const;
};

#endif
