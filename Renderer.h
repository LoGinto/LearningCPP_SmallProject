#pragma once

#include <SFML/Graphics.hpp>

class Renderer {
private:
    sf::RenderWindow window;

    sf::Texture playerTexture;
    sf::Texture enemyTexture;
    sf::Texture coinHeadsTexture;
    sf::Texture coinTailsTexture;

    sf::Sprite playerSprite;
    sf::Sprite enemySprite;
    sf::Sprite coinSprite;

public:
    Renderer();

    bool isOpen() const;
    void processEvents();

    void clear();
    void draw(
        sf::Vector2f playerPosition,
        sf::Vector2f enemyPosition
    );

    void showCoinFlip(bool isHeads);
};