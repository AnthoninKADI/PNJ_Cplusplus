#pragma once
#include <iostream>

using namespace std;

enum class Work {
	Default,
	Archer,
	Warrior,
	Priest,
	Paladin,
};

static string WorkToStr(Work work) {
	switch (work) {
	default:
		return "Default";
	case Work::Archer:
		return "Archer";
	case Work::Warrior:
		return "Warrior";
	case Work::Priest:
		return "Priest";
	case Work::Paladin:
		return "Paladin";
	}
}


