#pragma once
#include "general.hpp"

class Game;
class Field;
class FieldPlayer;
class FieldEntity;

class Field {
    public:
        sf::View view;
        shared_ptr<FieldPlayer> player;

        Field();
        void render(shared_ptr<Game>);
};

class FieldPlayer {
    public:
        sf::FloatRect rect;
        sf::Sprite sprite;

        FieldPlayer();
        void render(shared_ptr<Game>);
};

class FieldEntity {
    public:
        FieldEntity();
};
