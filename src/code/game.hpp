#pragma once
#include "general.hpp"

class Scene;
class Game : public std::enable_shared_from_this<Game> {
    public:
        shared_ptr<Game> self;
        shared_ptr<Scene> scene;
        sf::RenderWindow window;
        Game();

        void init();
        void run();
        void handleScene();
        void handleInput();
};
