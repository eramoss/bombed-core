#include "maze.h"

// Player position
int player_A_x = 1;
int player_A_y = 1;

enum PlayerType {
  A = 'A',
  B = 'B',
};

bool can_move(int x, int y) {
  if (x < 0 || y < 0 || x >= maze::maze_width || y >= maze::maze_height) return false;
  return maze::Map[y][x] == maze::empty_symbol;
}

void move_player(int dx, int dy) {
  int newX = player_A_x + dx;
  int newY = player_A_y + dy;

  if (can_move(newX, newY)) {
    maze::Map[player_A_y][player_A_x] = maze::empty_symbol;
    player_A_x = newX;
    player_A_y = newY;
    maze::Map[player_A_y][player_A_x] = maze::player_A_symbol;
  }
}
