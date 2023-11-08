#include "TargetGenerator.hpp"

#include "ASpell.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(TargetGenerator const &other) {
	size_t i = targets.size();
	while (i-- > 0) delete targets[i];
	targets.clear();
	i = 0;
	while (i++ < other.targets.size()) targets.push_back(other.targets[i]->clone());
}
TargetGenerator &TargetGenerator::operator=(TargetGenerator const &other) {
	if (this != &other) {
		size_t i = targets.size();
		while (i-- > 0) delete targets[i];
		targets.clear();
		i = 0;
		while (i++ < other.targets.size()) targets.push_back(other.targets[i]->clone());
	}
	return *this;
}

TargetGenerator::~TargetGenerator() {
	size_t i = targets.size();
	while (i-- > 0) delete targets[i];
	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target) {
	size_t i = targets.size();
	while (i-- > 0)
		if (targets[i]->getType() == target->getType()) return;
	targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(std::string const &target) {
	size_t i = targets.size();
	while (i-- > 0) {
		if (targets[i]->getType() == target) {
			delete targets[i];
			targets.erase(targets.begin() + i);
			return;
		}
	}
}

ATarget *TargetGenerator::createTarget(std::string const &target) {
	size_t i = targets.size();
	while (i-- > 0)
		if (targets[i]->getType() == target) return targets[i]->clone();
	return NULL;
}