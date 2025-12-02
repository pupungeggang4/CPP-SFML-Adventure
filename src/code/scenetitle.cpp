#include <scene.hpp>
#include <ui.hpp>
#include <func.hpp>
#include <render.hpp>
#include <game.hpp>

SceneTitle::SceneTitle(shared_ptr<Game> game) : Scene(game) {
    selectedTitle = 0;
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
    Render::renderSprite(game->window, Res::sprite->at("arrow"), {UI::UITitle["arrow"][selectedTitle * 2], UI::UITitle["arrow"][selectedTitle * 2 + 1]});
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {
    if (button == 0) {
        if (Func::pointInsideRectUI(pos, UI::UITitle["button_start"])) {
            game->scene = make_shared<SceneField>(game);
        } else if (Func::pointInsideRectUI(pos, UI::UITitle["button_quit"])) {
            game->running = false;
        }
    }
}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {
    if (key == K_UP) {
        selectedTitle = (selectedTitle + 3) % 4;
    } else if (key == K_DOWN) {
        selectedTitle = (selectedTitle + 1) % 4;
    } else if (key == K_ENTER) {
        if (selectedTitle == 0) {
            game->scene = make_shared<SceneField>(game);
        } else if (selectedTitle == 3) {
            game->running = false;
        }
    }
}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}
