#include <render.hpp>
#include <res.hpp>
#include <ui.hpp>
#include <game.hpp>
#include <scene.hpp>

void Render::renderMenuField(sf::RenderTarget& rt, shared_ptr<Game> game) {
    game->rRect.setFillColor(sf::Color::White);
    renderRect(game->window, game->rRect, UI::UIMenuField["rect"], 0);
    renderRect(game->window, game->rRect, UI::UIMenuField["rect"], 2);
    renderText(game->window, game->rText, UI::UIMenuField["text_paused"], "Paused");
    renderRect(game->window, game->rRect, UI::UIMenuField["button_resume"], 2);
    renderText(game->window, game->rText, UI::UIMenuField["text_resume"], "Resume");
    renderRect(game->window, game->rRect, UI::UIMenuField["button_exit"], 2);
    renderText(game->window, game->rText, UI::UIMenuField["text_exit"], "Exit to title");
    renderRect(game->window, game->rRect, UI::UIMenuField["button_quit"], 2);
    renderText(game->window, game->rText, UI::UIMenuField["text_quit"], "Quit game");
    renderSprite(game->window, Res::sprite->at("arrow"), {UI::UIMenuField["arrow"][game->selectedMenuField * 2], UI::UIMenuField["arrow"][game->selectedMenuField * 2 + 1]});
}

void Render::renderText(sf::RenderTarget& rt, sf::Text& t, std::vector<float> pos, sf::String text) {
    t.setString(text);
    t.setPosition({pos[0], pos[1]});
    rt.draw(t);
}

void Render::renderRect(sf::RenderTarget& rt, sf::RectangleShape& rs, std::vector<float> rect, float thickness) {
    if (thickness > 0) {
        rs.setFillColor(sf::Color::Transparent);
    }
    rs.setOutlineThickness(thickness);
    rs.setPosition({rect[0], rect[1]});
    rs.setSize({rect[2], rect[3]});
    rt.draw(rs);
}

void Render::renderSprite(sf::RenderTarget& rt, sf::Sprite& s, std::vector<float> pos) {
    s.setPosition({pos[0], pos[1]});
    rt.draw(s);
}
