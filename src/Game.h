//
// Created by eramoss on 13/10/23.
//

#ifndef BOMBEDCORE_GAME_H
#define BOMBEDCORE_GAME_H

#include "iostream"
#include "assets/animations.h"
#include "assets/menu.h"
#include "Characters/EnemyMirror.h"
#include "Characters/EnemyRandom.h"
#include "Characters/Player.h"
#include "Characters/Character.h"
#include "Map.h"
#include <iomanip>


class Game {
public:
    Game() : player(Coord{1, 1}), map("../map.txt"), game_over(false) {}

    void run() {
//        std::thread([&]() {
//            while (!game_over) {
//                display_timer();
//            }
//        }).detach();
        translate_map();
        char input;
        while (!game_over) {
            clear_console(true);
            display_map();

            input = get_input_without_enter();
            processInput(input);
        }
    }

private:
    Timer timer;
    Player player;
    MapFromFile map;
    bool game_over;

    bool character_can_move(Character & character, int dx, int dy) const{
        Coord move = character.get_coord() + Coord{dx,dy};
        if (map.map[move.Y][move.X] == empty_symbol) {
            return true;
        }
        return false;
    }

    void display_timer();

    void display_map() {
        for (int i = 0; i < map.height; i++) {
            for (int j = 0; j < map.width; j++) {
                if (player.get_coord() == Coord{j, i}) {
                    std::cout << player_symbol;
                } else {
                    std::cout << map.map[i][j];
                }
            }
            std::cout << std::endl;
        }
    }


    void processInput(char input) {
        switch (input) {
            case 'w':
                if (character_can_move(player,0, -1))
                player.move(0, -1);
                break;
            case 's':
                if (character_can_move(player,0, 1))
                player.move(0, 1);
                break;
            case 'a':
                if (character_can_move(player,-1, 0))
                player.move(-1, 0);
                break;
            case 'd':
                if (character_can_move(player,1, 0))
                player.move(1, 0);
                break;
            case 'q':
                game_over = true;
                break;
            default:
                break;
        }
    }
    void translate_map() const{
        for (int i = 0; i < map.height; i++) {
            for (int j = 0; j < map.width; j++) {
                if (map.map[i][j] == "#") {
                    map.map[i][j] = strong_wall_symbol;
                } else if ((map.map[i][j] == "@")) {
                    map.map[i][j] = weak_wall_symbol;
                } else {
                    map.map[i][j] = empty_symbol;
                }
            }
        }
    }

};

#ifdef WIN_32
void Game::display_timer() {
    std::ostringstream ss;
    ss << "time: " << std::fixed << std::setprecision(2) << timer.elapsed() / 1000;
    std::string result = ss.str();

    COORD coord;
    coord.X = 0;  // Set X coordinate to 0
    coord.Y = 0;  // Set Y coordinate to 0

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);

    // Fill the line with spaces to clear any previous content
    DWORD dwWritten;
    FillConsoleOutputCharacterA(console, ' ', csbi.dwSize.X, coord, &dwWritten);
    SetConsoleCursorPosition(console, coord);

    std::cout << result << '\r';
}
#else
void Game::display_timer() {
    std::string command = "printf \"time: \"";
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << timer.elapsed() / 1000;
    std::string result = ss.str();
    command.append(result);
    command.append("\033[0K\r");
    system(command.c_str());
}

#endif // WIN_32


#endif //BOMBEDCORE_GAME_H
