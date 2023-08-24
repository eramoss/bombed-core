#include "bomb.h"
namespace enemy_mirror {
  using namespace std;

  // enemy position
  int enemy_x = arena_width-3;
  int enemy_y = arena_height-3;

  // functions interface*
  bool can_move(int x, int y, string Map[arena_height][arena_width]);
  void move(int dx, int dy, string Map[arena_height][arena_width]);


  bool can_move(int x, int y, string Map[arena_height][arena_width]) {
    if (x < 0 || y < 0 || x >= arena_width || y >= arena_height) return false;
    return Map[y][x] == empty_symbol;
  }

  void move(int dx, int dy, string Map[arena_height][arena_width]) {
    int newX = enemy_x - dx;
    int newY = enemy_y - dy;

    if (can_move(newX, newY, Map)) {
      Map[enemy_y][enemy_x] = empty_symbol;
      enemy_x = newX;
      enemy_y = newY;
      Map[enemy_y][enemy_x] = enemy_symbol;
    }

}
}
