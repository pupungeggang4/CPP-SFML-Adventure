#include <field.hpp>
#include <res.hpp>
#include <game.hpp>

Field::Field() {
    view = sf::View({0, 0}, {1280, 720});
    player = make_shared<FieldPlayer>();
}

void Field::render(shared_ptr<Game> game) {
    game->window.setView(view);
    player->render(game);
}

FieldEntity::FieldEntity() {

}

FieldPlayer::FieldPlayer() : sprite(Res::texture->at("player")) {
    rect = sf::FloatRect({0, 0}, {80, 80});
}

void FieldPlayer::render(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;
    field->view.setCenter(rect.position);
    sprite.setPosition(rect.position - rect.size / 2.0f);
    game->window.draw(sprite);
}
