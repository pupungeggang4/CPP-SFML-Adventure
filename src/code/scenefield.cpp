#include <scene.hpp>
#include <ui.hpp>
#include <func.hpp>
#include <render.hpp>
#include <game.hpp>

SceneField::SceneField(shared_ptr<Game> game) {
    game->menu = false;
    game->selectedMenuField = 0;
}

void SceneField::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneField::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->rText.setFillColor(sf::Color::Black);
    game->rText.setCharacterSize(32);
    game->rRect.setOutlineColor(sf::Color::Black);

    Render::renderRect(game->window, game->rRect, UI::UIField["button_menu"], 2);

    if (game->menu == true) {
        Render::renderMenuField(game->window, game);
    }
}

void SceneField::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {
    if (button == 0) {
        if (game->menu == false) {
            if (Func::pointInsideRectUI(pos, UI::UIField["button_menu"])) {
                game->menu = true;
            }
        } else if (game->menu == true) {
            if (Func::pointInsideRectUI(pos, UI::UIField["button_menu"])) {
                game->menu = false;
            } else if (Func::pointInsideRectUI(pos, UI::UIMenuField["button_resume"])) {
                game->menu = false;
            } else if (Func::pointInsideRectUI(pos, UI::UIMenuField["button_exit"])) {
                game->scene = make_shared<SceneTitle>(game);
            } else if (Func::pointInsideRectUI(pos, UI::UIMenuField["button_quit"])) {
                game->running = false;
            }
        }
    }
}

void SceneField::keyDown(shared_ptr<Game> game, int key) {
    char alpha = key + 97;
    
    if (game->menu == false) {
        if (key == K_ESCAPE) {
            game->menu = true;
            game->selectedMenuField = 0;
        }
    } else {
        if (key == K_ESCAPE) {
            game->menu = false;
        } else if (key == K_ENTER) {
            if (game->selectedMenuField == 0) {
                game->menu = false;
            } else if (game->selectedMenuField == 1) {
                game->scene = make_shared<SceneTitle>(game);
            } else if (game->selectedMenuField == 2) {
                game->running = false;
            }
        } else if (key == K_UP) {
            game->selectedMenuField = (game->selectedMenuField + 2) % 3;
        } else if (key == K_DOWN) {
            game->selectedMenuField = (game->selectedMenuField + 1) % 3;
        }
    }
}

void SceneField::keyUp(shared_ptr<Game> game, int key) {

}
