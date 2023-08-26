#include "bomb.h"
#include "services/consts.h"
namespace player {
  using namespace std;

  // Player position
  int player_x = 1;
  int player_y = 1;

  int movements_with_bomb_in_map = 0;

  // functions interface*
  bool can_move(int x, int y, string Map[arena_height][arena_width]);
  void move(int dx, int dy, string Map[arena_height][arena_width]);
  void put_bomb();
  bool bomb_was_placed();



  bool can_move(int x, int y, string Map[arena_height][arena_width]) {
    if (x < 0 || y < 0 || x >= arena_width || y >= arena_height) return false;
    return Map[y][x] == empty_symbol;
  }

  void move(int dx, int dy, string Map[arena_height][arena_width]) {
    int newX = player_x + dx;
    int newY = player_y + dy;

    if (can_move(newX, newY, Map)) {
      Map[player_y][player_x] = empty_symbol;
      player_x = newX;
      player_y = newY;
      Map[player_y][player_x] = player_symbol;
    }

    if (bomb_was_placed()) {
      movements_with_bomb_in_map++;
    }
  }

  void put_bomb() {
    if (!bomb_was_placed()) {
      bomb::activate_bomb(player_x, player_y);
    }
  }
  bool bomb_was_placed() {
    return bomb::bomb_x != -1 && bomb::bomb_y != -1;
  }



}
