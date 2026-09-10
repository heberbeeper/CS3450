#pragma once
#include <iostream>

class WeaponBehavior {
public:
	virtual ~WeaponBehavior() = default;
	virtual const char* getName() const = 0;
	virtual void useWeapon() const = 0;
};

class KnifeBehavior : public WeaponBehavior {
public:
	const char* getName() const override {
		return "Knife";
	}

	void useWeapon() const override {
		std::cout << "cutting with a knife\n";
	}
};

class BowAndArrowBehavior : public WeaponBehavior {
public:
	const char* getName() const override {
		return "Bow and Arrow";
	}
	void useWeapon() const override {
		std::cout << "shooting an arrow with a bow\n";
	}
};

class AxeBehavior : public WeaponBehavior {
public:
	const char* getName() const override {
		return "Axe";
	}
	void useWeapon() const override {
		std::cout << "chopping with an axe\n";
	}
};

class SwordBehavior : public WeaponBehavior {
public:
	const char* getName() const override {
		return "Sword";
	}
	void useWeapon() const override {
		std::cout << "swinging a sword\n";
	}
};