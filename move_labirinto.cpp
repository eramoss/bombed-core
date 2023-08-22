#include <iostream>
#include <vector>
#include <ctime>

#include "./maze_utils.h"

using namespace std;


// Player position
int player_x = 1;
int player_y = 1;

enum PlayerType {
    A = 'A',
    B = 'B',
};

bool can_move(int x, int y) {
    if (x < 0 || y < 0 || x >= maze::maze_width || y >= maze::maze_height) return false;
    return maze::Map[y][x] == maze::empty_symbol;
}

void move_player(int dx, int dy, PlayerType player) {
    int newX = player_x + dx;
    int newY = player_y + dy;

    if (can_move(newX, newY)) {
        maze::Map[player_y][player_x] = maze::empty_symbol;
        player_x = newX;
        player_y = newY;
        player == 'A' ? maze::Map[player_y][player_x] = maze::player_A_symbol : maze::Map[player_y][player_x] = maze::player_B_symbol;
    }
}


int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator
    maze::Map[player_y][player_x] = maze::player_A_symbol;

    char input;

    while (true) {
        maze::print_maze();

        input = get_input_without_enter(); // Get a character from the keyboard

        switch (input) {
            case 'w':
                move_player(0, -1, PlayerType::A);
                break;
            case 's':
                move_player(0, 1, PlayerType::A);
                break;
            case 'a':
                move_player(-1, 0, PlayerType::A);
                break;
            case 'd':
                move_player(1, 0, PlayerType::A);
                break;
            default:
                break;
        }
    }

    return 0;
}
