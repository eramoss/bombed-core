#include "arena.h"

namespace game {

  // functions interface*
  void check_bomb_ticks_to_destroy();
  void destroy_bomb();

  void check_bomb_ticks_to_destroy() {
    if (bomb::bomb_enabled) {
      bomb::ticks_to_explode = player::movements_with_bomb_in_map;
      if (bomb::ticks_to_explode >= MAX_TICKS_TO_EXPLODE) {
        destroy_bomb();
        player::movements_with_bomb_in_map = 0;
      }
    }
  }

  void destroy_bomb() {
    for (int sprite_index = 0; sprite_index < AMOUNT_OF_SPRITES; sprite_index++) {
      bomb::create_sprite_animation(bomb::bomb_x, bomb::bomb_y, Arena::Map, bomb::sprite_animations[sprite_index]);
      Arena::print_map();
      usleep(50000);
    }
    for (int sprite_index = 0; sprite_index < AMOUNT_OF_SPRITES; sprite_index++) {
      bomb::create_sprite_animation(bomb::bomb_x, bomb::bomb_y, Arena::Map, bomb::sprite_animations[sprite_index]);
      Arena::print_map();
      usleep(50000);
    }
    bomb::destroy_bomb(Arena::Map);
  }

  void game_over() {
    exit(0);
  }
  void check_player_death() {
    if (Arena::Map[player::player_y][player::player_x] != player_symbol) {
      game_over();
    }
    if ((enemy_mirror::enemy_x == player::player_x && enemy_mirror::enemy_y == player::player_y) && !enemy_mirror::defeated(Arena::Map)) game_over();
  }

}