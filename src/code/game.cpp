#include "game.hpp"
#include "scene.hpp"

// Loading game system.
Game::Game() {
    window = sf::RenderWindow(sf::VideoMode({1280, 720}), "Adventure Game");
    window.setFramerateLimit(60);
}

// Loading game state
void Game::init() {
    self = shared_from_this();
    scene = make_shared<Scene>(self);
}

void Game::run() {
    while (window.isOpen()) {
        handleScene();
        handleInput();
        window.clear();
        window.display();
    }
}

void Game::handleScene() {
    scene->loop(self);
}

void Game::handleInput() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
            
        }
    }
}
