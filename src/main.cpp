#include "Game.h"

//#include "assets/menu.h"
//
//void start_menu() {
//    while (true) {
//        hide_cursor();
//        int choice_menu = menu::get_choice_menu();
//        int map;
//
//        switch (choice_menu) {
//            case 1:
//                map = menu::select_map();
//                game::run_game(map);
//                break;
//            case 2:
//                animations::animation_rules();
//                break;
//            case 3:
//                exit(0);
//                break;
//            default:
//                std::cout << "[ERROR]" << std::endl;
//                pause_console();
//                clear_console();
//                break;
//        }
//    }
//}
//
int main() {
    int select;

    Player player(Coord {1,1});
    EnemyRandom enemyRandom(Coord{7,7});
    EnemyMirror enemyMirror(Coord{5,5});
    Timer timer;
    Power power(Coord{18,26});

    while (true) {

        clear_console();

        std::cout << "______                    _                _   _____\n"
                     "| ___ \\                  | |              | | /  __ \\\n"
                     "| |_/ /  ___   _ __ ___  | |__    ___   __| | | /  \\/  ___   _ __   ___ \n"
                     "| ___ \\ / _ \\ | '_ ` _ \\ | '_ \\  / _ \\ / _` | | |     / _ \\ | '__| / _ \\\n"
                     "| |_/ /| (_) || | | | | || |_) ||  __/| (_| | | \\__/\\| (_) || |   |  __/\n"
                     "\\____/  \\___/ |_| |_| |_||_.__/  \\___| \\__,_|  \\____/ \\___/ |_|    \\___|\n\n"
                     "     1 - Jogar     2 - Continuar     3 - Creditos     4 - Sair\n\n"
                     "                          Escolha:";
        std::cin >> select;

        switch (select) {
            case 1: {
                clear_console();
                hide_cursor();
                Game* game = new Game();
                game->run();
                break;
            }
            case 2: {
                clear_console();
                hide_cursor();
                double ms_timer;
                load_positions(player,enemyMirror,enemyRandom,power,player.get_bomb(),ms_timer);
                Game *game = new Game(player,enemyMirror,enemyRandom,power,"mape_saved.txt",ms_timer);
                game->run();
                break;
            }
            case 3:
                animation_rules();
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }

    return 0;
}
