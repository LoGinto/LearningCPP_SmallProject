#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(string characterName,int hp,int lk){
    name = characterName;
    health = hp;
    luck = lk;
}

void Character::showStats() const{
    cout << "Character: "<<name<<endl;
    cout << "Health: "<<health<<endl;
    cout << "Luck: " << luck << endl;
}
bool Character::isAlive() const{
    return health>0;
}

void Character::takeDamage(int damage){
    health -= damage;

    if(health<0){
        health = 0;
    }
}