#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <vector>

#include "ATarget.hpp"

class TargetGenerator {
   private:
	std::vector<ATarget *> targets;
	TargetGenerator(TargetGenerator const &other);
	TargetGenerator &operator=(TargetGenerator const &other);

   public:
	~TargetGenerator();
	TargetGenerator();
	void learnTargetType(ATarget *target);
	void forgetTargetType(std::string const &target);
	ATarget *createTarget(std::string const &target);
};

#endif