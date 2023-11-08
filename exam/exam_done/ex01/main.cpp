#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

// #https://github.com/c-bertran/42-exam-shell/tree/main
int main(void) {
	Warlock richard("Richard", "the Titled");

	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);
	richard.learnSpell(fwoosh);

	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);

	delete fwoosh;
	return 0;
}
