#include "code/general.hpp"
#include "code/res.hpp"
#include "code/game.hpp"

int main(int argc, char** argv) {
    sf::err().rdbuf(NULL); 
    shared_ptr<Game> game = make_shared<Game>();
    game->init();
    game->run();
    Res::neodgm.reset();
    return 0;
}