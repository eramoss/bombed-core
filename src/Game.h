//
// Created by eramoss on 13/10/23.
//// game.h

#ifndef BOMBEDCORE_GAME_H
#define BOMBEDCORE_GAME_H


#pragma once

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
    Game();

    void run();

private:
    Timer timer;
    Player player;
    EnemyMirror enemyM;
    EnemyRandom enemyR;
    MapFromFile map;
    bool game_over;

    void displayTimer();

    bool characterCanMove(Character &character, int dx, int dy);

    void displayMap();

    void processInput(char input);

    void move(int dx, int dy);

    void translateMap() const;

    void checkPlayerDeath();

    void checkBombExplode();

    void explodeBomb();

    void animateBomb(const std::string &sprite);

    void killCharacterInBombRadius(Character &character, Bomb &bomb);

    bool hasWall(int x, int y) const;
};


Game::Game() : player(Coord{1, 1}), enemyR(Coord{9, 9}), enemyM(Coord{5, 5}),
               map("../map.txt"), game_over(false) {}

void Game::run() {
    std::thread([&]() {
        while (!game_over) {
            displayTimer();
        }
    }).detach();
    translateMap();
    char input;
    while (!game_over) {
        clear_console(true);
        displayMap();

        input = get_input_without_enter();
        processInput(input);
        checkBombExplode();
        checkPlayerDeath();
    }
    clear_console(true);
    displayMap();
}


bool Game::characterCanMove(Character &character, int dx, int dy) {
    Coord move = character.get_coord() + Coord{dx, dy};
    if (move.X > map.width - 1 || move.Y > map.height - 1 || move.X < 0 || move.Y < 0) return false;
    if (character.defeated()) return false;

    if (move == enemyR.get_coord()) return false;
    if (move == enemyM.get_coord()) return false;
    if (move == player.get_bomb().get_coord()) return false;
    if (map.map[move.Y][move.X] == empty_symbol) {
        return true;
    }
    return false;
}


void Game::displayMap() {
    for (int i = 0; i < map.height; i++) {
        for (int j = 0; j < map.width; j++) {
            std::string symbol = map.map[i][j];
            if (symbol == strong_wall_symbol || symbol == explosion || symbol == great_explosion ||
                symbol == greater_explosion) {
                std::cout << symbol;
            } else if ((enemyR.get_coord() == Coord{j, i} && !enemyR.defeated()) ||
                       (enemyM.get_coord() == Coord{j, i} && !enemyM.defeated())) {
                std::cout << enemy_symbol;
            } else if (player.get_bomb().get_coord() == Coord{j, i}) {
                std::cout << bomb_character;
            } else if (player.get_coord() == Coord{j, i} && !player.defeated()) {
                std::cout << player_symbol;
            } else {
                std::cout << symbol;
            }
        }
        std::cout << std::endl;
    }
}


void Game::processInput(char input) {
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

void Game::move(int dx, int dy) {
    Coord random_move{};
    if (characterCanMove(player, dx, dy)) {
        player.move(dx, dy);
    }

    if (characterCanMove(enemyM, dx * -1, dy * -1)) {
        enemyM.move(dx * -1, dy * -1);
    }

    random_move = enemyR.generate_random_move();
    while (!characterCanMove(enemyR, random_move.X, random_move.Y)) {
        random_move = enemyR.generate_random_move();
    }
    enemyR.move(random_move.X, random_move.Y);
}


void Game::translateMap() const {
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

void Game::checkPlayerDeath() {
    if (player.get_coord() == enemyR.get_coord() || player.get_coord() == enemyM.get_coord()) {
        game_over = true;
    }
}

void Game::checkBombExplode() {
    Bomb &bomb = player.get_bomb();
    if (bomb.is_active()) {
        bomb.inactivate();
        Timer::async_time_out([&]() {
            explodeBomb();
        }, 3000);
    }
}

void Game::explodeBomb() {
    Bomb &bomb = player.get_bomb();
    killCharacterInBombRadius(player, bomb);
    killCharacterInBombRadius(enemyR, bomb);
    killCharacterInBombRadius(enemyM, bomb);
    for (const std::string &sprite: bomb.sprite_animations) {
        clear_console(true);
        animateBomb(sprite);
        displayMap();
        Timer::sleep(75);
    }

    for (const std::string &sprite: bomb.sprite_animations) {
        clear_console(true);
        animateBomb(sprite);
        displayMap();
        Timer::sleep(75);
    }

    bomb.set_coord(Coord{-1, -1});
    clear_console(true);
    displayMap();
}

void Game::animateBomb(const std::string &sprite) {
    Bomb &bomb = player.get_bomb();
    int x = bomb.get_coord().X;
    int y = bomb.get_coord().Y;
    static bool stop = false;
    static int directionXToStop = 2;
    static int directionYToStop = 2;
    auto &Map = map.map;
    const int radius = bomb.get_blast_radius();

    auto updateMap = [&](int dx, int dy) {
        for (int i = 0; i <= radius; i++) {
            if (stop && directionXToStop == dx && directionYToStop == dy) break;
            int new_x = x + dx * i;
            int new_y = y + dy * i;

            if (new_x < 0 || new_x >= map.width || new_y < 0 || new_y >= map.height)
                continue;

            if (Map[new_y][new_x] == strong_wall_symbol)
                break;

            if (Map[new_y][new_x] == weak_wall_symbol) {
                Map[new_y][new_x] = explosion;
                Map[new_y][new_x] = empty_symbol;
                directionXToStop = dx;
                directionYToStop = dy;
                stop = true;
                break;
            }
            Map[new_y][new_x] = sprite;

        }
    };

    updateMap(1, 0);  // Right
    updateMap(-1, 0); // Left
    updateMap(0, -1); // Up
    updateMap(0, 1);  // Down

    if (Map[y][x] != strong_wall_symbol)
        Map[y][x] = sprite;
}


void Game::killCharacterInBombRadius(Character &character, Bomb &bomb) {
    Coord bombCoord = bomb.get_coord();
    Coord characterCoord = character.get_coord();

    int bombX = bombCoord.X;
    int bombY = bombCoord.Y;
    int characterX = characterCoord.X;
    int characterY = characterCoord.Y;

    int blastRadius = bomb.get_blast_radius();

    int dx = characterX - bombX;
    int dy = characterY - bombY;

    int distance = abs(dx) + abs(dy);

    if (distance <= blastRadius) {
        bool hasLineOfSight = true;

        for (int step = 0; step < distance; step++) {
            int x = bombX + step * dx / distance;
            int y = bombY + step * dy / distance;

            if (hasWall(x, y)) {
                hasLineOfSight = false;
                break;
            }
        }

        if (hasLineOfSight && (characterX == bombX || characterY == bombY)) {
            character.kill();
        }
    }
}

bool Game::hasWall(int x, int y) const {
    return map.map[y][x] != empty_symbol;
}


#ifdef WIN_32
void Game::displayTimer() {
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

void Game::displayTimer() {
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
