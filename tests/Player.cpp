//
// Created by eramoss on 29/09/23.
//
#include "../src/Characters/Player.h"
#include "iostream"
#include <cassert>

void create_bomb_as_active() {
    auto * player = new Player(Coord{1,1});
    player->put_bomb();
    Bomb bomb = player->get_bomb();
    assert(bomb.active());
    std::cout << "Create bomb activate passed." << std::endl;
}
void create_bomb_in_player_place() {
    auto * player = new Player(Coord{1,1});
    player->put_bomb();
    Bomb bomb = player->get_bomb();

    assert(player->get_coord() == bomb.get_coord());
    std::cout << "Create in position passed." << std::endl;
}
 int main(){
    create_bomb_as_active();
    create_bomb_in_player_place();
}