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

        // Center the origins of all sprites using SFML 3 syntax
    playerSprite.setOrigin({playerSprite.getLocalBounds().size.x / 2.f,
                            playerSprite.getLocalBounds().size.y / 2.f});
    enemySprite.setOrigin({enemySprite.getLocalBounds().size.x / 2.f,
                           enemySprite.getLocalBounds().size.y / 2.f});
    coinSprite.setOrigin({coinSprite.getLocalBounds().size.x / 2.f,
                          coinSprite.getLocalBounds().size.y / 2.f});

    // Scales for Fear & Hunger atmosphere
    playerSprite.setScale({0.85f, 0.85f});
    enemySprite.setScale({1.25f, 1.25f});
    coinSprite.setScale({0.5f, 0.5f});

    // Positions - now perfectly aligned thanks to centered origins
    playerSprite.setPosition({300.f, 450.f});   // Foreground, your preferred player spot
    enemySprite.setPosition({400.f, 250.f});    // Back, dead center of the 800x600 window
    coinSprite.setPosition({400.f, 300.f});     // Centered for flip animation
    
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

void Renderer::draw(sf::Vector2f playerPosition,sf::Vector2f enemyPosition,bool drawCoin){
    playerSprite.setPosition(playerPosition);
    enemySprite.setPosition(enemyPosition);
    window.draw(playerSprite);
    window.draw(enemySprite);
    if(drawCoin){
        window.draw(coinSprite);
    }
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