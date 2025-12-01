#pragma once
#include "general.hpp"

class Render {
    public:
        static void renderText(sf::RenderTarget&, sf::Text&, std::vector<float>, sf::String);
        static void renderRect(sf::RenderTarget&, sf::RectangleShape&, std::vector<float>, float);
};