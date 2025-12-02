#include <res.hpp>

shared_ptr<sf::Font> Res::neodgm = make_shared<sf::Font>("font/neodgm.ttf");
shared_ptr<std::unordered_map<std::string, sf::Texture>> Res::texture = make_shared<std::unordered_map<std::string, sf::Texture>>();
shared_ptr<std::unordered_map<std::string, sf::Sprite>> Res::sprite = make_shared<std::unordered_map<std::string, sf::Sprite>>();

void Res::loadTexture() {
    texture->emplace("arrow", sf::Texture("image/arrow.png"));
}

void Res::loadSprite() {
    sprite->emplace("arrow", Res::texture->at("arrow"));
}
