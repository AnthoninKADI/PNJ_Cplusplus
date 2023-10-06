#include <string>
#include "Weapon.h"
using namespace std;

#pragma once

class Merchant
{
private:
	std::string merchantName;
	std::string merchantShopName;
	std::string merchantDescription;
	std::string merchantCatchphrase;
	int merchantMoney;
	Weapon mWeapon[1];

public:
	Merchant();
	~Merchant();
	Merchant(std::string name, std::string shopname, std::string description, std::string catchphrase, int money, Weapon weapon[1]);
	void Introduction();
	Weapon setWeaponType(int number);
	int getMoney();
	void setMoney(int money);
};

