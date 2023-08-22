#include "maze.h"

namespace player {
  // Player position
  int player_x = 1;
  int player_y = 1;

  bool can_move(int x, int y) {
    if (x < 0 || y < 0 || x >= maze::maze_width || y >= maze::maze_height) return false;
    return maze::Map[y][x] == maze::empty_symbol;
  }

  void move_player(int dx, int dy) {
    int newX = player_x + dx;
    int newY = player_y + dy;

    if (can_move(newX, newY)) {
      maze::Map[player_y][player_x] = maze::empty_symbol;
      player_x = newX;
      player_y = newY;
      maze::Map[player_y][player_x] = maze::player_symbol;
    }
  }

  void init_player() {
    maze::Map[player_x][player_y] = maze::player_symbol;
  }
}
