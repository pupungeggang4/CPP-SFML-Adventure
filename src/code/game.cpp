#include "game.hpp"
#include "scene.hpp"

// Loading game system.
Game::Game() {
    unsigned int mWidth = sf::VideoMode::getDesktopMode().size.x;
    if (mWidth > 2560) {
        window = sf::RenderWindow(sf::VideoMode({2560, 1440}), "Adventure Game");
    } else if (mWidth > 1920) {
        window = sf::RenderWindow(sf::VideoMode({1920, 1080}), "Adventure Game");
    } else {
        window = sf::RenderWindow(sf::VideoMode({1280, 720}), "Adventure Game");
    }
    window.setFramerateLimit(60);
}

// Loading game state
void Game::init() {
    self = shared_from_this();
    scene = make_shared<Scene>(self);
}

// Game main loop
void Game::run() {
    while (window.isOpen()) {
        handleScene();
        handleInput();
        window.clear();
        window.display();
    }
}

// Handling scene
void Game::handleScene() {
    scene->loop(self);
}


// Handling input (mouse, keyboard)
void Game::handleInput() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
            
        }
    }
}
