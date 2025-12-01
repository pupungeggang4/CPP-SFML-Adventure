#include "render.hpp"

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