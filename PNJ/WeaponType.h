#pragma once
#include <iostream>

using namespace std;

enum class WeaponType{
	Bow,
	Dagger,
	Staff,
	Sword,
	Default,
};

static string WeaponToStr(WeaponType weapon) {
	switch (weapon) {
	case WeaponType::Bow:
		return "Bow";
	case WeaponType::Dagger:
		return "Dagger";
	case WeaponType::Staff:
		return "Staff";
	case WeaponType::Sword:
		return "Sword";
	default:
		return "Default";
	}

}
