#include <string>
#include "Weapon.h"
#include "WeaponType.h"
#include "Race.h"
#include "Work.h"
#include "Merchant.h"

using namespace std;
#pragma once

class Character 
{
private:
	std::string characterFirstName;
	std::string characterLastName;
	std::string characterCatchPhrase;
	int characterMoney, characterLifePoint;
	Weapon mWeapon[1];
	Race characterRace;
	Work characterWork;

public:
	Character();
	~Character();
	Character(std::string firstname, std::string lastname, std::string catchphrase, int money, int lifepoints, Weapon weapon[1], Race race, Work work);

	std::string setName();
	WeaponType setWeaponType();
	int setMoney();
	int getHP();
	int setHP(int hp);
	void Introduction();
	void addInventory(Weapon weapon);
	void showInventory();
	void removeInInventory(int number);
	void Buy(Merchant merchant, int number);
	void Sell(Merchant merchant, int number);
	void Attack(Character& character, int number);
};



