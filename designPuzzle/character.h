#pragma once
#include "weaponBehavior.h"

class Character {
public:
	explicit Character(std::unique_ptr<WeaponBehavior> weapon) : weapon(std::move(weapon)) {};
	virtual ~Character() = default;

	void setWeapon(std::unique_ptr<WeaponBehavior> newWeapon) {
		std::cout << "Changing weapon...\n";
		weapon = std::move(newWeapon);
	}

	virtual void fight() const = 0;

protected:
	void useWeapon() const {
		if (weapon != nullptr) {
			std::cout << "Using weapon: " << weapon->getName() << "\n";
			weapon->useWeapon();
		}
	}

private:
	std::unique_ptr<WeaponBehavior> weapon;
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