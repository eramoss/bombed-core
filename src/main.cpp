#include <iostream>
#include <ctime>
#include "arena.h"
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
                Arena::move_player(0, -1);
                break;
            case 's':
                Arena::move_player(0, 1);
                break;
            case 'a':
                Arena::move_player(-1, 0);
                break;
            case 'd':
                Arena::move_player(1, 0);
                break;
            case 'b':
                player::put_bomb();
                break;
            default:
                break;
        }
        if (bomb::bomb_enabled) {
            bomb::ticks_to_explode++;
        }
    }

    return 0;
}
