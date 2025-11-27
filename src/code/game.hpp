#pragma once
#include "general.hpp"

class Game {
    public:
        sf::RenderWindow window;
        Game();

        void init();
        void run();
};