#include "Weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon() {
	weaponName = "Sword";
	weaponDescription = "X";
	weaponType = WeaponType::Sword;
	weaponWeight = 1;
	weaponDamages = 1;
	weaponCosts = 1;
	weaponDurability = 1;
}

Weapon::Weapon(std::string name, std::string description, WeaponType type, int weight, int damages, int cost, float durability) {
	weaponName = name;
	weaponDescription = description;
	weaponType = type;
	weaponWeight = weight;
	weaponDamages = damages;
	weaponCosts = cost;
	weaponDurability = durability;
}

Weapon::~Weapon() {}

std::string Weapon::setNameWeapon() {
	return(weaponName);
}

WeaponType Weapon::setWeaponType() {
	return(weaponType);
}
int Weapon::setWeaponWeight() {
	return(weaponWeight);
}
int Weapon::setWeaponDamages() {
	return(weaponDamages);
}
int Weapon::setWeaponCost() {
	return(weaponCosts);
}

float Weapon::getWeaponDurability() {
	return(weaponDurability);
}

void Weapon::setWeaponDurability(float durability) {
	weaponDurability = durability;
}
void Weapon::setCost() {
	weaponCosts = (weaponCosts * weaponDurability);
}