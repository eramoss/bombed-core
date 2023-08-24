#include <string>
#include "services/consts.h"
#define MAX_TICKS_TO_EXPLODE 3
#define AMOUNT_OF_SPRITES 4

namespace bomb {
  using namespace std;

  int bomb_x = -1;
  int bomb_y = -1;

  bool bomb_enabled = false;
  int ticks_to_explode;

  const char* sprite_animations[AMOUNT_OF_SPRITES] = { explosion, great_explosion, greater_explosion, 0 };

  //functions interface *
  void create_sprite_animation(int x, int y, string map[arena_height][arena_width], const char* sprite);
  void activate_bomb(int x, int y);
  void destroy_bomb(string map[arena_height][arena_width]);
  bool bomb_out_of_origin();


  // define o lugar que vai sair a bomba
  void create_sprite_animation(int x, int y, string map[arena_height][arena_width], const char* sprite) {
    if (map[x + 1][y] != strong_wall_symbol) map[x + 1][y] = sprite;
    if (map[x - 1][y] != strong_wall_symbol) map[x - 1][y] = sprite;
    if (map[x][y - 1] != strong_wall_symbol) map[x][y - 1] = sprite;
    if (map[x][y + 1] != strong_wall_symbol) map[x][y + 1] = sprite;
  }

  // Ativamento da bomba
  void activate_bomb(int x, int y) {
    bomb_x = x;
    bomb_y = y;
    ticks_to_explode = 0;
    bomb_enabled = true;
  }


  void destroy_bomb(string map[arena_height][arena_width]) {
    for (int sprite_index = 0; sprite_index < AMOUNT_OF_SPRITES; sprite_index++) {
      create_sprite_animation(bomb_x, bomb_y, map, sprite_animations[sprite_index]);
    }
  }

  bool bomb_out_of_origin() {
    return !bomb_x == 0 && !bomb_y == 0;
  }
}