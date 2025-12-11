#include <res.hpp>

shared_ptr<sf::Font> Res::neodgm = make_shared<sf::Font>("font/neodgm.ttf");
shared_ptr<std::unordered_map<std::string, sf::Texture>> Res::texture = make_shared<std::unordered_map<std::string, sf::Texture>>();
shared_ptr<std::unordered_map<std::string, sf::Sprite>> Res::sprite = make_shared<std::unordered_map<std::string, sf::Sprite>>();

void Res::loadTexture() {
    texture->emplace("arrow", sf::Texture("image/arrow.png"));
    texture->emplace("player", sf::Texture("image/player.png"));
}

void Res::loadSprite() {
    sprite->emplace("arrow", sf::Sprite(Res::texture->at("arrow")));
    sprite->emplace("player", sf::Sprite(Res::texture->at("player")));
}
