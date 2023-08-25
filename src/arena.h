#include <iostream>
#include "services/console_helpers.h"
#include "player.h"
#include "enemy_mirror.h"

#define ENTROPY_MAP_GENERATOR (y % 2 == 0 && x % 2 == 0) || rand() % 9 == 2
using namespace std;

namespace Arena {

  //functions interface *
  void print_map();
  void initialize_map();
  void create_map_borders();
  void create_map_layout_random();
  void place_wall(string Map[arena_height][arena_width], int x, int y);
  void init_player();
  void move_player(int dx, int dy);
  bool is_bomb_on(int x, int y);
  bool is_player_on(int x, int y);


  // arena layout
  string Map[arena_height][arena_width];


  void initialize_map() {
    create_map_borders();
    create_map_layout_random();
    init_player();
  }

  void move_player(int dx, int dy) {
    player::move(dx, dy, Map);
    enemy_mirror::move(dx, dy, Map);
  }

  void init_player() {
    Map[1][1] = player_symbol;
    Map[arena_height - 3][arena_width - 3] = enemy_symbol;
  }

  void print_map() {
    clear_console(true);

    for (int y = 0; y < arena_height; ++y) {
      for (int x = 0; x < arena_width; ++x) {
        if (!is_bomb_on(x, y) || is_player_on(x, y)) {
          cout << Map[y][x];
        }
        else {
          cout << bomb_character;
        }

      }
      cout << endl;
    }
  }

  void create_map_borders() {
    for (int y = 0; y < arena_height; ++y) {
      Map[y][0] = strong_wall_symbol;
      Map[y][arena_width - 1] = strong_wall_symbol;
    }
    for (int x = 0; x < arena_width; ++x) {
      Map[0][x] = strong_wall_symbol;
      Map[arena_height - 1][x] = strong_wall_symbol;
    }
  }

  void create_map_layout_random() {
    srand(time(NULL));

    for (int y = 1; y < arena_height - 1; ++y) {
      for (int x = 1; x < arena_width - 1; ++x) {
        if (ENTROPY_MAP_GENERATOR) {
          place_wall(Map, x, y);
        }
        else {
          Map[y][x] = empty_symbol;
        }
      }
    }
  }

  void place_wall(string Map[arena_height][arena_width], int x, int y) {
    const double strong_wall_probability = 0.9;
    if (static_cast<double>(rand()) / RAND_MAX < strong_wall_probability) {
      Map[y][x] = strong_wall_symbol;
    }
    else {
      Map[y][x] = weak_wall_symbol;
    }
  }

  bool is_bomb_on(int x, int y) {
    return bomb::bomb_x == x && bomb::bomb_y == y;
  }
  bool is_player_on(int x, int y) {
    return player::player_x == x && player::player_y == y && enemy_mirror::enemy_x == x && enemy_mirror::enemy_y == y;
  }

}