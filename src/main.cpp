#include "iostream"
#include "assets/animations.h"
#include "assets/menu.h"
#include "Characters/EnemyMirror.h"
#include "Characters/EnemyRandom.h"
#include "Characters/Player.h"
#include "Characters/Character.h"
#include "Map.h"
#include <iomanip>

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
    Timer timer;
    Player *player = new Player(Coord{1, 1});
    MapFromFile Map("../map.txt");
    ;
    char input;
    loop {
        clear_console(true);
        for (int i = 0; i < Map.height; i++) {
            for (int j = 0; j < Map.width; j++) {
                if (player->get_coord() == Coord{j, i}) {
                    std::cout << player_symbol;
                    continue;
                }
                if (Map.map[i][j] == "#") std::cout << strong_wall_symbol;
                else std::cout << empty_symbol;
            }
            std::cout << std::endl;
        }
        std::cout << "time: " << std::fixed << std::setprecision(2) << (timer.elapsed() / 1000) << "\n\n";
        input = get_input_without_enter(); // Obter um caractere do teclado
        switch (input) {
            case 'w':
                player->move(0,-1);
                break;
            case 's':
                player->move(0, 1);
                break;
            case 'a':
                player->move(-1, 0);
                break;
            case 'd':
                player->move(1, 0);
                break;
            case 'q':
                return 0;
            default:
                break;
        }

    };
}
