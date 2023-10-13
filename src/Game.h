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
    Game() : player(Coord{1, 1}), enemyR(Coord{9, 9}), enemyM(Coord{5, 5}),
             map("../map.txt"), game_over(false) {}

    void run() {
        std::thread([&]() {
            while (!game_over) {
                display_timer();
            }
        }).detach();
        translate_map();
        char input;
        while (!game_over) {
            clear_console(true);
            display_map();

            input = get_input_without_enter();
            processInput(input);
            check_bomb_explode();
            check_player_death();
        }
        clear_console(true);
        display_map();
    }

private:
    Timer timer;
    Player player;
    EnemyMirror enemyM;
    EnemyRandom enemyR;
    MapFromFile map;
    bool game_over;

    bool character_can_move(Character &character, int dx, int dy) {
        Coord move = character.get_coord() + Coord{dx, dy};
        if (move == enemyR.get_coord()) return false;
        if (move == enemyM.get_coord()) return false;
        if (move == player.get_bomb().get_coord()) return false;
        if (map.map[move.Y][move.X] == empty_symbol) {
            return true;
        }
        return false;
    }

    void display_timer();

    void display_map() {
        for (int i = 0; i < map.height; i++) {
            for (int j = 0; j < map.width; j++) {
                if (enemyR.get_coord() == Coord{j, i}) {
                    std::cout << enemy_symbol;
                } else if (enemyM.get_coord() == Coord{j, i}) {
                    std::cout << enemy_symbol;
                } else if (player.get_bomb().get_coord() == Coord{j, i}) {
                    std::cout << bomb_character;
                } else if (player.get_coord() == Coord{j, i}) {
                    std::cout << player_symbol;
                } else {
                    std::cout << map.map[i][j];
                }
            }
            std::cout << std::endl;
        }
    }

    Coord random_move;

    void processInput(char input) {
        switch (input) {
            case 'w':
                move(0, -1);
                break;
            case 's':
                move(0, 1);
                break;
            case 'a':
                move(-1, 0);
                break;
            case 'd':
                move(1, 0);
                break;
            case 'b':
                player.put_bomb();
                break;
            case 'q':
                game_over = true;
                break;
            default:
                break;
        }
    }

    void move(int dx, int dy) {
        if (character_can_move(player, dx, dy)) {
            player.move(dx, dy);
        }

        if (character_can_move(enemyM, dx * -1, dy * -1)) {
            enemyM.move(dx * -1, dy * -1);
        }

        random_move = enemyR.generate_random_move();
        while (!character_can_move(enemyR, random_move.X, random_move.Y)) {
            random_move = enemyR.generate_random_move();
        }
        enemyR.move(random_move.X, random_move.Y);
    }


    void translate_map() const {
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

    void check_player_death() {
        if (player.get_coord() == enemyR.get_coord() || player.get_coord() == enemyM.get_coord()) {
            game_over = true;
        }
    }

    void check_bomb_explode() {
        Bomb& bomb = player.get_bomb();
        if (bomb.is_active()) {
            bomb.inactivate();
            Timer::async_time_out([&]() {
                explode_bomb();
            }, 3000);
        }
    }

    void explode_bomb() {
        Bomb& bomb = player.get_bomb();
        for (const std::string& sprite : bomb.sprite_animations) {
            clear_console(true);
            animate_bomb(sprite);
            display_map();
            Timer::sleep(75);
        }

        for (const std::string& sprite : bomb.sprite_animations) {
            clear_console(true);
            animate_bomb(sprite);
            display_map();
            Timer::sleep(75);
        }

        bomb.set_coord(Coord{-1, -1});
        clear_console(true);
        display_map();
    }

    void animate_bomb(const std::string& sprite) {
        Bomb& bomb = player.get_bomb();
        int x = bomb.get_coord().X;
        int y = bomb.get_coord().Y;

        const auto& Map = map.map;

        if (Map[y + 1][x] != strong_wall_symbol)
            Map[y + 1][x] = sprite;

        if (Map[y - 1][x] != strong_wall_symbol)
            Map[y - 1][x] = sprite;

        if (Map[y][x - 1] != strong_wall_symbol)
            Map[y][x - 1] = sprite;

        if (Map[y][x + 1] != strong_wall_symbol)
            Map[y][x + 1] = sprite;

        if (Map[y][x] != strong_wall_symbol)
            Map[y][x] = sprite;
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
