#include <iostream>
#include <string>
#include "WeaponType.h"

using namespace std;

#pragma once

class Weapon
{
private:
	std::string weaponName;
	std::string weaponDescription;
	WeaponType weaponType;
	int weaponWeight, weaponDamages, weaponCosts;
	float weaponDurability;

public:
	Weapon();
	~Weapon();
	Weapon(std::string name, std::string description, WeaponType type, int weight, int damages, int cost, float durability);


	std::string setNameWeapon();
	WeaponType setWeaponType();
	int setWeaponWeight();
	int setWeaponDamages();
	int setWeaponCost();
	float getWeaponDurability();
	void setWeaponDurability(float durability);
	void setCost();

};


