#include "arena.h"

namespace player {
  using namespace Arena;
  // Player position
  int player_x = 1;
  int player_y = 1;

  bool can_move(int x, int y) {
    if (x < 0 || y < 0 || x >= arena_width || y >= arena_height) return false;
    return Map[y][x] == empty_symbol;
  }

  void move_player(int dx, int dy) {
    int newX = player_x + dx;
    int newY = player_y + dy;

    if (can_move(newX, newY)) {
      Map[player_y][player_x] = empty_symbol;
      player_x = newX;
      player_y = newY;
      Map[player_y][player_x] = player_symbol;
    }
  }

  void init_player() {
    Map[player_x][player_y] = player_symbol;
  }
}
