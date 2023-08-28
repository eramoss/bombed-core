#include "game.h"
#include "assets/menu.h"

int main() {
    while (true) {
        hide_cursor();
        int choice_map = menu::get_choice_menu();
        int map;

        switch (choice_map) {
            case 1:
                map = menu::select_map();
                game::run_game(map);
                break;
            case 2:
                animations::animation_rules();
                break;
            case 3:
                exit(0);
                break;
            default:
                std::cout << "[ERROR]" << std::endl;
                pause_console();
                clear_console();
                break;
        }
    }
    return 0;
}
