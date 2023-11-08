#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(SpellBook const &other) {
	size_t i = spells.size();
	while (i-- > 0) delete spells[i];
	spells.clear();
	i = 0;
	while (i++ < other.spells.size()) spells.push_back(other.spells[i]->clone());
}
SpellBook &SpellBook::operator=(SpellBook const &other) {
	if (this != &other) {
		size_t i = spells.size();
		while (i-- > 0) delete spells[i];
		spells.clear();
		i = 0;
		while (i++ < other.spells.size()) spells.push_back(other.spells[i]->clone());
	}
	return *this;
}

SpellBook::~SpellBook() {
	size_t i = spells.size();
	while (i-- > 0) delete spells[i];
	spells.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
	size_t i = spells.size();
	while (i-- > 0)
		if (spells[i]->getName() == spell->getName()) return;
	spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const &spell) {
	size_t i = spells.size();
	while (i-- > 0) {
		if (spells[i]->getName() == spell) {
			delete spells[i];
			spells.erase(spells.begin() + i);
			return;
		}
	}
}

ASpell *SpellBook::createSpell(std::string const &spell) {
	size_t i = spells.size();
	while (i-- > 0)
		if (spells[i]->getName() == spell) return spells[i]->clone();
	return NULL;
}