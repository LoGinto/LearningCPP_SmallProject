#include <iostream>
#include <ctime>
#include <cstdlib>
#include<limits>
#include "Character.h"
#include "Game.h"


int main() {
    // Seed random number generator once at program start
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // sf::RenderWindow window(sf::VideoMode({800u, 600u}), "Luck Dungeons");
    // sf::Texture playerTexture;
    // if(!playerTexture.loadFromFile("Assets/player.png")){
    //     std::cout<<"Failed to load player texture!"<<std::endl;
    //     return -1;
    // }
    // sf::Sprite playerSprite(playerTexture);
    // playerSprite.setPosition(sf::Vector2f(100.f, 400.f));
    std::cout << "Welcome to luck dungeons! For now we only have 1 game: Coin Toss" << std::endl;
    std::cout << "First opponent:" << std::endl << std::endl;

    // Create characters
    Character* player = new Character("Hero", 3, 1);
    Character* enemy  = new Character("Goblin", 3, 1);

    // Show initial stats
    std::cout << "Player stats\n";
    player->showStats();

    std::cout << "\nEnemy stats\n";
    enemy->showStats();

    // Start game
    Game game(player, enemy);
    game.start();

    // Clean up
    delete player;
    delete enemy;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer
    std::cout<<"\nPress Enter to exit..."<<std::endl;
    std::cin.get();//wait for user input before closing
    std::cin.get();//wait for user input before closing
    return 0;
}
