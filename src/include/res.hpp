#pragma once
#include <general.hpp>

class Res {
    public:
        static void loadTexture();
        static void loadSprite();
        static shared_ptr<sf::Font> neodgm;
        static shared_ptr<std::unordered_map<std::string, sf::Texture>> texture;
        static shared_ptr<std::unordered_map<std::string, sf::Sprite>> sprite;
};
