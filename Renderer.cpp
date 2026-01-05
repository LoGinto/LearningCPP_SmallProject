#include "Renderer.h"
#include <iostream>


sf::Texture Renderer::loadTexture(const std::string& path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Failed to load texture: " << path << "\n";
    }
    return texture;
}
Renderer::Renderer()
    : window(sf::VideoMode({800u, 600u}), "Luck Dungeons"),
      playerTexture(loadTexture("Assets/player.png")),
      enemyTexture(loadTexture("Assets/enemy.png")),
      coinHeadsTexture(loadTexture("Assets/coin_heads.png")),
      coinTailsTexture(loadTexture("Assets/coin_tails.png")),
      playerSprite(playerTexture),  
      enemySprite(enemyTexture),
      coinSprite(coinHeadsTexture)
{
    // Now load the textures (order is safe because textures are constructed before sprites)
    if (!playerTexture.loadFromFile("Assets/player.png")) {
        std::cerr << "Failed to load player texture!\n";
    }
    if (!enemyTexture.loadFromFile("Assets/enemy.png")) {
        std::cerr << "Failed to load enemy texture!\n";
    }
    if (!coinHeadsTexture.loadFromFile("Assets/coin_heads.png")) {
        std::cerr << "Failed to load coin heads texture!\n";
    }
    if (!coinTailsTexture.loadFromFile("Assets/coin_tails.png")) {
        std::cerr << "Failed to load coin tails texture!\n";
    }

    // Set initial positions (using braced Vector2f, same as you wanted)
    playerSprite.setPosition({150.f, 450.f});
    enemySprite.setPosition({650.f, 450.f});
    coinSprite.setPosition({450.f, 250.f});
}

bool Renderer::isOpen() const{
    return window.isOpen();
}

void Renderer::processEvents() {
    // Use std::optional directly in the loop condition
    while (const std::optional<sf::Event> optionalEvent = window.pollEvent()) {
        const sf::Event& event = *optionalEvent;  // Dereference the optional

        if (event.is<sf::Event::Closed>()) {
            window.close();
        }
        // Handle other events here if needed, e.g.:
        // else if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        //     if (keyPressed->scancode == sf::Keyboard::Escape) { ... }
        // }
    }
}
void Renderer::clear() {
    window.clear(sf::Color::Black);
}

void Renderer::draw(sf::Vector2f playerPosition,sf::Vector2f enemyPosition){
    playerSprite.setPosition(playerPosition);
    enemySprite.setPosition(enemyPosition);
    window.draw(playerSprite);
    window.draw(enemySprite);
    window.draw(coinSprite);

    window.display();
}

void Renderer::showCoinFlip(bool isHeads){
    if(isHeads){
        coinSprite.setTexture(coinHeadsTexture);
    } else {
        coinSprite.setTexture(coinTailsTexture);    
    }

    coinSprite.setPosition({350.f, 250.f});
    window.draw(coinSprite);
    window.display();
}