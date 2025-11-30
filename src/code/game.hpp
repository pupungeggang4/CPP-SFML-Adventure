#pragma once
#include "general.hpp"
#include "res.hpp"

class Scene;
class Field;

class Game : public std::enable_shared_from_this<Game> {
    public:
        shared_ptr<Game> self;
        shared_ptr<Scene> scene;
        sf::RenderWindow window;
        sf::View viewUI;
        sf::RectangleShape rRect; sf::Font rFont; sf::Text rText = sf::Text(rFont, "", 32);
        float frameCurrent = 0, framePrevious = 0, delta = 0; sf::Clock clock;
        std::unordered_map<std::string, bool> keyPressed = {};

        std::string state; bool menu;
        shared_ptr<Field> field;
        int selectedTitle = 0, selectedMenuField = 0, selectedMenuBattle = 0;
        Game();

        void init();
        void run();
        void handleScene();
        void handleInput();
};
