#pragma once
#include "general.hpp"
#include "res.hpp"

class Scene;
class Game : public std::enable_shared_from_this<Game> {
    public:
        shared_ptr<Game> self;
        shared_ptr<Scene> scene;
        sf::RenderWindow window;
        sf::View viewUI;
        sf::RectangleShape rRect; sf::Font rFont; sf::Text rText = sf::Text(rFont, "", 32);
        Game();

        void init();
        void run();
        void handleScene();
        void handleInput();
};
