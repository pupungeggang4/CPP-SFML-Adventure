#include <scene.hpp>
#include <game.hpp>

SceneField::SceneField(shared_ptr<Game> game) : Scene(game) {
    game->menu = false;
}

void SceneField::loop(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rText.setFillColor(sf::Color::Black);
    game->rText.setCharacterSize(32);
    game->rRect.setOutlineColor(sf::Color::Black);
}

void SceneField::render(shared_ptr<Game> game) {

}

void SceneField::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {

}

void SceneField::keyDown(shared_ptr<Game> game, int key) {

}

void SceneField::keyUp(shared_ptr<Game> game, int key) {

}
