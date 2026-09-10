#pragma once
#include "weaponBehavior.h"

class Character {
public:
	explicit Character(WeaponBehavior& weapon) : weapon(&weapon) {}
	virtual ~Character() = default;

	void setWeapon(WeaponBehavior& newWeapon) {
		weapon = &newWeapon;
	}

	virtual void fight() const = 0;

protected:
	void useWeapon() const {
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
		cout << "The queen fights: ";
		useWeapon();
	}
};

class King : public Character {
public:
	using Character::Character;

	void fight() const override {
		cout << "The king fights: ";
		useWeapon();
	}
};

class Troll : public Character {
public:
	using Character::Character;

	void fight() const override {
		cout << "The troll fights: ";
		useWeapon();
	}
};

class Knight : public Character {
public:
	using Character::Character;

	void fight() const override {
		cout << "The knight fights: ";
		useWeapon();
	}
};