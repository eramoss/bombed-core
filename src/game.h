#include "arena.h"

namespace game {

  // functions interface*

  void run_game();

  void check_bomb_ticks_to_destroy();
  void destroy_bomb();
  void animate_bomb();
  void destroy_bomb();

  void check_player_death();
  void check_enemy_deaths();

  void game_over();


  void run_game() {
    hide_cursor();
    Arena::initialize_map();

    char input;

    while (true) {
      Arena::print_map();

      input = get_input_without_enter(); // Get a character from the keyboard

      switch (input) {
        case 'w':
          Arena::make_movement(0, -1);
          break;
        case 's':
          Arena::make_movement(0, 1);
          break;
        case 'a':
          Arena::make_movement(-1, 0);
          break;
        case 'd':
          Arena::make_movement(1, 0);
          break;
        case 'b':
          player::put_bomb();
          break;
        default:
          break;
      }
      check_bomb_ticks_to_destroy();
      check_player_death();
      check_enemy_deaths();
    }
  }

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
    animate_bomb();
    bomb::destroy_bomb(Arena::Map);
  }

  void animate_bomb() {
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
  }


  void check_player_death() {
    if (Arena::Map[player::player_y][player::player_x] != player_symbol) {
      game_over();
    }
  }

  void check_enemy_deaths() {
    if (Arena::Map[enemy_mirror::enemy_y][enemy_mirror::enemy_x] != enemy_symbol) {
      game_over();
    }
  }

  void game_over() {
    Arena::print_map();
    sleep(1);
    exit(0);
  }
}