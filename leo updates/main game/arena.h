#include <iostream>
#include "services/console_helpers.h"
#define ENTROPY_MAP_GENERATOR (y % 2 == 0 && x % 2 == 0) || rand() % 9 == 2
using namespace std;

namespace Arena {
  // arena dimensions
  const int arena_width = 40;
  const int arena_height = 20;

  // arena symbols
  char wall_symbol = char(219);
  char player_symbol = char(2);
  char weak_wall = char(177);
  const char* empty_symbol = " ";


  //functions interface *
  void print_map();
  void initialize_map();
  void create_map_borders();
  void create_map_layout_random();


  // arena layout
  string Map[arena_height][arena_width];

  void initialize_map() {
    create_map_borders();
    create_map_layout_random();
  }

  void create_map_borders() {
    for (int y = 0; y < arena_height; ++y) {
      Map[y][0] = wall_symbol;
      Map[y][arena_width - 1] = wall_symbol;
    }
    for (int x = 0; x < arena_width; ++x) {
      Map[0][x] = wall_symbol;
      Map[arena_height - 1][x] = wall_symbol;
    }
  }

  void create_map_layout_random() {
    srand(time(NULL));

    for (int y = 1; y < arena_height - 1; ++y) {
      for (int x = 1; x < arena_width - 1; ++x) {
        if (ENTROPY_MAP_GENERATOR) {
          int teste = 1 + rand() % 2;
          if (teste % 2 == 0){
            Map[y][x] = wall_symbol;
          } else {
            Map[y][x] = weak_wall;
          }
        }
        else {
          Map[y][x] = empty_symbol;
        }
      }
    }
  }


  void print_map() {
    clear_console();

    for (int y = 0; y < arena_height; ++y) {
      for (int x = 0; x < arena_width; ++x) {
        cout << Map[y][x];
      }
      cout << endl;
    }
  }

}