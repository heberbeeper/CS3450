#include "weaponBehavior.h"
#include "character.h"
using namespace std;

int main() {
	KnifeBehavior knife;
	BowAndArrowBehavior bow;
	AxeBehavior axe;
	SwordBehavior sword;

	Queen queen(make_unique<KnifeBehavior>());
	King king(make_unique<BowAndArrowBehavior>());
	Troll troll(make_unique<AxeBehavior>());
	Knight knight(make_unique<SwordBehavior>());

	// Queen queen(knife);
	// King king(bow);
	// Troll troll(axe);
	// Knight knight(sword);

	queen.fight();
	cout << "\n";
	king.fight();
	cout << "\n";
	troll.fight();
	cout << "\n";
	knight.fight();
	cout << "\n";
	// A character can change strategies at runtime.
	knight.setWeapon(make_unique<BowAndArrowBehavior>());
	knight.fight();
	cout << "\n";

	return 0;
}
