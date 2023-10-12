#include "Merchant.h"
#include "Weapon.h"
#include <iostream>


using namespace std;

Merchant::Merchant() {
	merchantName = "";
	merchantShopName = "";
	merchantDescription = "";
	merchantCatchphrase = "";
	merchantMoney = 1;
	for (int i = 0; i < 4; i++) {
		mWeapon[i] = Weapon();
	}
}

Merchant::Merchant(std::string name, std::string shopName, std::string description, std::string catchPhrase, int money, Weapon weapon[1]) {
	merchantName = name;
	merchantShopName = shopName;
	merchantDescription = description;
	merchantCatchphrase = catchPhrase;
	merchantMoney = money;
	for (int i = 0; i < 4; i++) {
		mWeapon[i] = weapon[0];
	}
}

Merchant::~Merchant() {

}

void Merchant::Introduction() {
	cout << "Hi, I am" << merchantName << endl;
	cout << merchantDescription << endl;
	cout << merchantCatchphrase << endl;
	cout << "My shop name is" << merchantShopName << endl;
	cout << "I have" << merchantMoney << "Golds" << endl;
	cout << endl;
}

Weapon Merchant::setWeaponType(int number) {
	return(mWeapon[number]);
}

int Merchant::getMoney() {
	return(merchantMoney);
}

void Merchant::setMoney(int money) {
	merchantMoney = money;
}

