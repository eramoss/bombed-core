#include <iostream>
#include <ctime>
#include "player.h"
using namespace std;




int main() {
    hide_cursor();
    Arena::initialize_map();
    player::init_player();

    char input;

    while (true) {
        Arena::print_map();

        input = get_input_without_enter(); // Get a character from the keyboard

        switch (input) {
            case 'w':
                player::move_player(0, -1);
                break;
            case 's':
                player::move_player(0, 1);
                break;
            case 'a':
                player::move_player(-1, 0);
                break;
            case 'd':
                player::move_player(1, 0);
                break;
            default:
                break;
        }
    }

    return 0;
}
