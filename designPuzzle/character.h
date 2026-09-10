#pragma once
#include "weaponBehavior.h"

class Character {
public:
	explicit Character(WeaponBehavior& weapon) : weapon(&weapon) {}
	virtual ~Character() = default;

	void setWeapon(WeaponBehavior& newWeapon) {
		std::cout << "Changing weapon...\n";
		weapon = &newWeapon;
	}

	virtual void fight() const = 0;

protected:
	void useWeapon() const {
		std::cout << "Using weapon: " << weapon->getName() << "\n";
		if (weapon != nullptr) {
			weapon->useWeapon();
		}
	}

private:
	WeaponBehavior* weapon;
};

class Queen : public Character {
public:
	using Character::Character;

	void fight() const override {
		std::cout << "The queen fights: \n";
		useWeapon();
	}
};

class King : public Character {
public:
	using Character::Character;

	void fight() const override {
		std::cout << "The king fights: \n";
		useWeapon();
	}
};

class Troll : public Character {
public:
	using Character::Character;

	void fight() const override {
		std::cout << "The troll fights: \n";
		useWeapon();
	}
};

class Knight : public Character {
public:
	using Character::Character;

	void fight() const override {
		std::cout << "The knight fights: \n";
		useWeapon();
	}
};