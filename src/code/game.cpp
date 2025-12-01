#include "game.hpp"
#include "scene.hpp"
#include "res.hpp"
#include "field.hpp"

// Loading game system.
Game::Game() {
    rFont = *(Res::neodgm);
    rFont.setSmooth(false);
    rText = sf::Text(rFont, "", 32);

    unsigned int mWidth = sf::VideoMode::getDesktopMode().size.x;
    if (mWidth > 2560) {
        width = 2560; height = 1440;
    } else if (mWidth > 1920) {
        width = 1920; height = 1080;
    } else {
        width = 1280; height = 720;
    }
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Adventure Game");
    window.setFramerateLimit(60);
    viewUI = sf::View({640, 360}, {1280, 720});
    window.setView(viewUI);

    keyPressed = {{"left", false}, {"right", false}, {"up", false}, {"down", false}};
    clock = sf::Clock();
}

// Loading game state
void Game::init() {
    self = shared_from_this();
    scene = make_shared<SceneTitle>(self);
    field = make_shared<Field>();
    framePrevious = clock.getElapsedTime().asSeconds();
}

// Game main loop
void Game::run() {
    while (running) {
        frameCurrent = clock.getElapsedTime().asSeconds();
        delta = frameCurrent - framePrevious;
        framePrevious = clock.getElapsedTime().asSeconds();
        handleScene();
        handleInput();
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
            int k = int(key->scancode);
            if (k == K_LEFT) {
                keyPressed["left"] = true;
            }
            if (k == K_RIGHT) {
                keyPressed["right"] = true;
            }
            if (k == K_UP) {
                keyPressed["up"] = true;
            }
            if (k == K_DOWN) {
                keyPressed["down"] = true;
            }
            scene->keyDown(self, k);
        }
        if (const auto* key = event->getIf<sf::Event::KeyReleased>()) {
            int k = int(key->scancode);
            if (k == K_LEFT) {
                keyPressed["left"] = false;
            }
            if (k == K_RIGHT) {
                keyPressed["right"] = false;
            }
            if (k == K_UP) {
                keyPressed["up"] = false;
            }
            if (k == K_DOWN) {
                keyPressed["down"] = false;
            }
            scene->keyUp(self, k);
        }
        if (const auto* mouseUp = event->getIf<sf::Event::MouseButtonReleased>()) {
            int button = int(mouseUp->button);
            sf::Vector2f position = {mouseUp->position.x * 1280.0f / width, mouseUp->position.y * 720.0f / height};
            scene->mouseUp(self, position, button);
        }
    }
}
