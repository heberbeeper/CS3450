#include "weaponBehavior.h"
#include "character.h"

int main() {
	KnifeBehavior knife;
	BowAndArrowBehavior bow;
	AxeBehavior axe;
	SwordBehavior sword;

	Queen queen(knife);
	King king(bow);
	Troll troll(axe);
	Knight knight(sword);

	queen.fight();
	cout << "\n";
	king.fight();
	cout << "\n";
	troll.fight();
	cout << "\n";
	knight.fight();
	cout << "\n";
	// A character can change strategies at runtime.
	knight.setWeapon(bow);
	knight.fight();

	return 0;
}
