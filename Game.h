#ifndef Game_H
#define Game_H

#include "Character.h"
#include "Renderer.h"

class Game{
private:
    Character* player;
    Character* enemy;
    Renderer renderer;
    bool  showCoin;
    char coinToss();

public:
  Game(Character* p,Character* e);
  void BattleRound();
  void start();
};

#endif