#include <scene.hpp>
#include <ui.hpp>
#include <func.hpp>
#include <render.hpp>
#include <game.hpp>

SceneTitle::SceneTitle(shared_ptr<Game> game) : Scene(game) {

}

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rText.setFillColor(sf::Color::Black);
    game->rText.setCharacterSize(32);
    game->rRect.setOutlineColor(sf::Color::Black);
    Render::renderText(game->window, game->rText, UI::UITitle["text_title"], "Adventure Game");
    Render::renderRect(game->window, game->rRect, UI::UITitle["button_start"], 2);
    Render::renderText(game->window, game->rText, UI::UITitle["text_start"], "Start Game");
    Render::renderRect(game->window, game->rRect, UI::UITitle["button_collection"], 2);
    Render::renderText(game->window, game->rText, UI::UITitle["text_collection"], "Collection");
    Render::renderRect(game->window, game->rRect, UI::UITitle["button_erase"], 2);
    Render::renderText(game->window, game->rText, UI::UITitle["text_erase"], "Erase Data");
    Render::renderRect(game->window, game->rRect, UI::UITitle["button_quit"], 2);
    Render::renderText(game->window, game->rText, UI::UITitle["text_quit"], "Quit Game");
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {
    if (button == 0) {
        if (Func::pointInsideRectUI(pos, UI::UITitle["button_quit"])) {
            game->running = false;
        }
    }
}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {

}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}