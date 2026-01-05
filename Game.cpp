#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


Game::Game(Character* p,Character* e){
    player = p;
    enemy = e;
}
char Game::coinToss(){
    return (rand()%2==0)?'H':'T';
}
void Game::BattleRound(){
    char playerBet;
    std::cout << "Choose your bet (H/T): ";
    std::cin >> playerBet;
    playerBet = toupper(playerBet);
    if(playerBet != 'H' && playerBet != 'T'){
        std::cout << "Invalid choice! Please choose H or T." << std::endl;
        return;
    }
    std::cout<<"Tossing the coin..."<<std::endl;
    std::cout.flush();
    PlaySound(TEXT("coin.wav"), NULL, SND_FILENAME | SND_ASYNC);
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    char result = coinToss();
    if(playerBet == result){
        std::cout << "You won this round! Enemy takes 1 damage." << std::endl;
        enemy->takeDamage(1);
    } else {
        std::cout << "You lost this round! You take 1 damage." << std::endl;
        player->takeDamage(1);
    }
    std::cout<<"\nPlayer stats\n";
    player->showStats();
    std::cout<<"\nEnemy stats\n";
    enemy->showStats();
}
void Game::start(){
    while(renderer.isOpen()&&player->isAlive() && enemy->isAlive()){
        renderer.processEvents();
        renderer.clear();
        renderer.draw({100.f, 400.f}, {600.f, 300.f});
        BattleRound();
    }
    if(player->isAlive()){
        std::cout << "Congratulations! You have defeated the enemy!" << std::endl;
    } else {
        std::cout << "You have been defeated. Game Over." << std::endl;
    }
}