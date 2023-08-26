#include <iostream>
#include <ctime>
#include "game.h"
using namespace std;


int main() {
    hide_cursor();
    Arena::initialize_map();

    char input;

    while (true) {
        Arena::print_map();

        input = get_input_without_enter(); // Get a character from the keyboard

        switch (input) {
            case 'w':
                Arena::make_movement(0, -1);
                break;
            case 's':
                Arena::make_movement(0, 1);
                break;
            case 'a':
                Arena::make_movement(-1, 0);
                break;
            case 'd':
                Arena::make_movement(1, 0);
                break;
            case 'b':
                player::put_bomb();
                break;
            default:
                break;
        }
        game::check_bomb_ticks_to_destroy();
        game::check_player_death();
    }

    return 0;
}
