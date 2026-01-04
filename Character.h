#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{
    std::string name;
    public:
        int health;
        int luck;
        Character(std::string characterName,int hp,int lk);
        void showStats() const;
        bool isAlive() const;
        void takeDamage(int damage);
};



#endif
