#include "Renderer.h"
#include <iostream>

Renderer::Renderer()
    : window(sf::VideoMode({800u, 600u}), "Luck Dungeons"),
      playerSprite(playerTexture),
      enemySprite(enemyTexture),
      coinSprite(coinHeadsTexture)
{
    if (!playerTexture.loadFromFile("Assets/player.png"))
        std::cerr << "Failed to load player texture\n";

    if (!enemyTexture.loadFromFile("Assets/enemy.png"))
        std::cerr << "Failed to load enemy texture\n";

    if (!coinHeadsTexture.loadFromFile("Assets/coin_heads.png"))
        std::cerr << "Failed to load coin heads texture\n";

    if (!coinTailsTexture.loadFromFile("Assets/coin_tails.png"))
        std::cerr << "Failed to load coin tails texture\n";
}