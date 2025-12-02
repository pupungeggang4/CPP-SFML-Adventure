#pragma once
#include <general.hpp>

class Game;

class Scene {
    public:
        Scene(shared_ptr<Game>);
        virtual void loop(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void mouseUp(shared_ptr<Game>, sf::Vector2f, int);
        virtual void keyDown(shared_ptr<Game>, int);
        virtual void keyUp(shared_ptr<Game>, int);
};

class SceneTitle : public Scene {
    public:
        int selectedTitle = 0;
        SceneTitle(shared_ptr<Game>);
        void loop(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
        void keyDown(shared_ptr<Game>, int) override;
        void keyUp(shared_ptr<Game>, int) override;
};

class SceneField : public Scene {
    public:
        SceneField(shared_ptr<Game>);
        void loop(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
        void keyDown(shared_ptr<Game>, int) override;
        void keyUp(shared_ptr<Game>, int) override;
};

class SceneBattle : public Scene {
    public:
        SceneBattle(shared_ptr<Game>);
        void loop(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
        void keyDown(shared_ptr<Game>, int) override;
        void keyUp(shared_ptr<Game>, int) override;
};
