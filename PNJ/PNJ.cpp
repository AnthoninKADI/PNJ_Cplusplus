#include "Weapon.h"
#include "Character.h"
#include "Merchant.h"
#include <iostream>

using namespace std;

Weapon Bow = Weapon("Bow", "", WeaponType::Bow, 5, 15, 50, 1);
Weapon Dagger = Weapon("Dagger", "", WeaponType::Dagger, 2, 8, 20, 1);
Weapon Staff = Weapon("Staff", "", WeaponType::Staff, 10, 10, 75, 1);
Weapon Sword = Weapon("Sword", "", WeaponType::Sword, 25, 50, 250, 1);
Weapon NPCEnemySword = Weapon("Diamond_Sword", "", WeaponType::Sword, 25, 50, 250, 1);

Weapon merchantInventory[4] = { Bow, Dagger, Staff, Sword };
Weapon PlayerInventory[2] = { Dagger, Weapon() };
Weapon NPCEnemyInventory[1] = { NPCEnemySword };

Character Player;
Character NPCEnemy;

Merchant merchant = Merchant(
    "NPC Merchant", "Capital store", "Welcome to the Capital store", "You can Buy & Sell", 100, merchantInventory
);

void StartGame();
void ShopBuy();
void Fight();
void ShopSell();


int main()
{
    StartGame();
    ShopBuy();
    Fight();
    ShopSell();
    return 0;
}

void StartGame() {
    cout << "-- Create your Character --" << endl;
    cout << "Choose a first name for your character" << endl;
    string firstname;
    cin >> firstname;
    cout << "Choose a last name for your character" << endl;
    string lastname;
    cin >> lastname;
    cout << "Choose a introudction for your character" << endl;
    string PlayerIntro;
    cin >> PlayerIntro;
    Player = Character(firstname, lastname, PlayerIntro, 2000, 2000, PlayerInventory, Race::Orc, Work::Paladin);
}

void ShopBuy() {
    cout << " Choose which weapon you want to buy. Write the number : 1 - Bow, 2 - Dagger, 3 - Staff, 4 - Sword" << endl;
    cout << " you have" << Player.SetMoney() << "Golds" << endl;
    int number;
    cin >> number;
    if (number == 1) {
        Player.Buy(merchant, number - 1);
    }

    else if (number == 2) {
        Player.Buy(merchant, number - 1);
    }

    else if (number == 3) {
        Player.Buy(merchant, number - 1);
    }

    else if (number == 4) {
        Player.Buy(merchant, number - 1);
    }
}

void Fight() {
    Character NPCEnemy = Character("Gobe", "Lin", "Gobelin je suis", 100, 100, NPCEnemyInventory, Race::Gobelin, Work::Warrior);
    NPCEnemy.Introduction();
    NPCEnemyInventory[1] = NPCEnemySword;
    cout << "You are gonna attack the Gobelin, choose with which weapon you are gonna attack him" << endl;
    Player.ShowInventory();
    int number;
    cin >> number;
    if (number == 1) {
        Player.Attack(NPCEnemy, number - 1);
    }
    else if (number == 2) {
        Player.Attack(NPCEnemy, number - 1);
    }
    if (NPCEnemy.GetHP() <= 0) {
        cout << "You kill your enemy" << endl;
        Player.AddInventory(NPCEnemy.SetWeaponType());
        Player.ShowInventory();
    }
    else if (Player.GetHP() <= 0) {
        cout << "YOU DIE" << endl;
    }
    else {
        NPCEnemy.Attack(Player, 0);
    }
    while (NPCEnemy.GetHP() > 0 && Player.GetHP() > 0);
}

void ShopSell() {
    cout << " Choose which weapon you want to sell. Write the number" << endl;
    Player.ShowInventory();
    int number;
    cin >> number;
    if (number == 1) {
        Player.Sell(merchant, number - 1);
    }
    else if (number == 2) {
        Player.Sell(merchant, number - 1);
    }
    else if (number == 3) {
        Player.Sell(merchant, number - 1);
    }
}
