#include <iostream>
#include <vector>
#include <ctime>

#include "player.h"

using namespace std;




int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator

    maze::init_map();
    hide_cursor();
    init_player();

    char input;

    while (true) {
        maze::print_maze();

        input = get_input_without_enter(); // Get a character from the keyboard

        switch (input) {
            case 'w':
                move_player(0, -1);
                break;
            case 's':
                move_player(0, 1);
                break;
            case 'a':
                move_player(-1, 0);
                break;
            case 'd':
                move_player(1, 0);
                break;
            default:
                break;
        }
    }

    return 0;
}
