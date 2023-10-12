#include <iostream>
#include "Weapon.h"
#include "WeaponType.h"
#include "Race.h"
#include "Work.h"
#include "Character.h"


using namespace std;

Character::Character() {
	characterFirstName = "";
	characterLastName = "";
	characterCatchPhrase = "";
	characterMoney = 0;
	characterLifePoint = 1;
	for (int i = 0; i < 3; i++) {
		mWeapon[i] = Weapon();
	}
	characterRace = Race::Default;
	characterWork = Work::Default;
}

Character::Character(std::string firstname, std::string lastname, std::string catchphrase, int money, int lifepoints, Weapon weapon[1], Race race, Work work) {
	characterFirstName = firstname;
	characterLastName = lastname;
	characterCatchPhrase = catchphrase;
	characterMoney = money;
	characterLifePoint = lifepoints;
	for (int i = 0; i < 3; i++) {
		mWeapon[i] = weapon[i];
	}
	characterRace = race;
	characterWork = work;
}

Character::~Character() {}

std::string Character::setName() {
	return characterFirstName + " - " + characterLastName;
}

int Character::setMoney() {
	return characterMoney;
}

WeaponType Character::setWeaponType() {
	return mWeapon[0].setWeaponType();
}

int Character::getHP() {
	return characterLifePoint;
}

void Character::setHP(int hp) {
	characterLifePoint = hp;
}

void Character::Introduction() {
	cout << "Hi, I am " << characterFirstName << " " << characterLastName << endl; cout << characterCatchPhrase << endl; cout << "Health - " << characterLifePoint << " HP" << endl; cout << "Money - " << characterMoney << " Golds" << endl;
	cout << "Work - " << WorkToStr(characterWork) << endl << endl; 	cout << "Race - " << RaceToStr(characterRace) << endl;
}

void Character::addInventory(Weapon weapon) {
	bool InventoryAdd = false;
	for (int i = 0; i < 3; i++)
	{
		if (mWeapon[i].setWeaponType() == WeaponType::Sword) {
			mWeapon[i] = weapon;
			cout << "You obtain - " << WeaponToStr(weapon.setWeaponType()) << endl; cout << " Cost - " << weapon.setWeaponCost() << endl; cout << " Damages - " << weapon.setWeaponDamages() << endl; cout << " durability - " << weapon.getWeaponDurability() << endl;
			InventoryAdd = true;
			return;
		}
	}
}

Weapon Character::getMainWeapon()
{
	return mWeapon[0];
}

void Character::showInventory() {
	for (int i = 0; i < 3; i++)
	{
		if (mWeapon[i].setWeaponType() != WeaponType::Sword) {
			cout << "Weapon : " << i + 1 << " : " << WeaponToStr(mWeapon[i].setWeaponType()) << endl; cout << " Cost - " << mWeapon[i].setWeaponCost() << endl; cout << " Damages - " << mWeapon[i].setWeaponDamages() << endl; cout << " durability - " << mWeapon[i].getWeaponDurability() << endl;
		}
	}
}


void Character::removeInInventory(int number) {
	mWeapon[number] = Weapon();
}

void Character::Buy(Merchant merchant, int number) {
	Weapon merchantWeapon = merchant.setWeaponType(number);
	if (characterMoney >= merchantWeapon.setWeaponCost()) {
		characterMoney -= merchantWeapon.setWeaponCost();
		cout << "You got - " << merchantWeapon.setNameWeapon() << endl;
		cout << "Your money - " << characterMoney << " Golds." << endl << endl;
		addInventory(merchantWeapon);
	}
	else {
		cout << "You don't have enough money" << endl;
	}
}

void Character::Sell(Merchant merchant, int number) {
	Weapon SellWeapon = mWeapon[number];
	if (SellWeapon.setWeaponType() == WeaponType::Sword) {
		cout << "You can't sell this" << endl;
		return;
	}

	if (merchant.getMoney() < SellWeapon.setWeaponCost()) {
		cout << "Your weapon is too expensive for me, i don't have enough money." << endl;
		return;
	}
	else if (merchant.getMoney() >= SellWeapon.setWeaponCost()) {
		removeInInventory(number);
		merchant.setMoney(merchant.getMoney() - SellWeapon.setWeaponCost());
		characterMoney += SellWeapon.setWeaponCost();
		cout << "Thank you. your balance - " << characterMoney << " golds." << endl;
		return;
	}
}

void Character::Attack(Character& character, int number) {
	Weapon& attackWeapon = mWeapon[number];
	if (attackWeapon.setWeaponType() == WeaponType::Default) {
		cout << "You can't attack with this weapon" << endl;
		return;
	}

	character.setHP(character.getHP() - attackWeapon.setWeaponDamages());
	if (character.getHP() < 0) {
		character.setHP(0);
	}

	attackWeapon.setWeaponDurability(attackWeapon.getWeaponDurability() - 0.1f);
	attackWeapon.setCost();

	if (attackWeapon.getWeaponDurability() <= 0) {
		cout << "You' weapon is broken" << endl;
		attackWeapon = Weapon();
		return;
	}
	cout << attackWeapon.setNameWeapon() << " a inflige "
		<< attackWeapon.setWeaponDamages() << " degats a " << character.setName()
		<< ". Il lui reste " << character.getHP() << " PV."
		<< endl;
}

