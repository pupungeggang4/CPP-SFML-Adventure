#include "game.hpp"

Game::Game() {
    window = sf::RenderWindow(sf::VideoMode({1280, 720}), "SFML works!");
}

void Game::init() {

}

void Game::run() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
}