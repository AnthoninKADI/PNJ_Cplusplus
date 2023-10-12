#pragma once
#include <iostream>

using namespace std;

enum class Race {
	Default,
	Elf,
	Orc,
	Gobelin,
	Human,
};

static string RaceToStr(Race race) {
	switch (race) {
	default:
		return "Default";
	case Race::Elf:
		return "Elf";
	case Race::Orc:
		return "Orc";
	case Race::Gobelin:
		return "Gobelin";
	case Race::Human:
		return "Human";
	}
}