#ifndef Game_H
#define Game_H

#include "Character.h"

class Game{
private:
    Character* player;
    Character* enemy;
    char coinToss();

public:
  Game(Character* p,Character* e);
  void BattleRound();
  void start();
};

#endif