#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(ASpell const &other) {
	name = other.name;
	effects = other.effects;
}

ASpell &ASpell::operator=(ASpell const &other) {
	if (this != &other) {
		name = other.name;
		effects = other.effects;
	}
	return *this;
}

ASpell::~ASpell() {}

ASpell::ASpell(std::string const &n, std::string const &e) : name(n), effects(e) {}

std::string const &ASpell::getName() const { return name; }

std::string const &ASpell::getEffects() const { return effects; }

void ASpell::launch(ATarget const &target) const { target.getHitBySpell(*this); }