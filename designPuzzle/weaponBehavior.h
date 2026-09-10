#pragma once

#include <iostream>
using namespace std;

class WeaponBehavior {
public:
	virtual ~WeaponBehavior() = default;
	virtual void useWeapon() const = 0;
};

class KnifeBehavior : public WeaponBehavior {
public:
	void useWeapon() const override {
		cout << "cutting with a knife\n";
	}
};

class BowAndArrowBehavior : public WeaponBehavior {
public:
	void useWeapon() const override {
		cout << "shooting an arrow with a bow\n";
	}
};

class AxeBehavior : public WeaponBehavior {
public:
	void useWeapon() const override {
		cout << "chopping with an axe\n";
	}
};

class SwordBehavior : public WeaponBehavior {
public:
	void useWeapon() const override {
		cout << "swinging a sword\n";
	}
};