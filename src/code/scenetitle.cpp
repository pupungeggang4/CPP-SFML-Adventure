#include "scene.hpp"
#include "game.hpp"

SceneTitle::SceneTitle(shared_ptr<Game> game) : Scene(game) {

}

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rText.setFillColor(sf::Color::Black);
    game->rText.setCharacterSize(32);
    game->rText.setPosition({20, 20});
    game->rText.setString("Adventure Game");
    game->window.draw(game->rText);
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2i pos, int button) {

}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {

}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}