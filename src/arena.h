#include <iostream>
#include "services/console_helpers.h"

using namespace std;

namespace Arena {
  // arena dimensions
  const int arena_width = 40;
  const int arena_height = 20;

  // arena symbols
  const char* wall_symbol = "\u2588";
  const char* player_symbol = "\U0001FBC7";
  const char* empty_symbol = " ";


  //functions interface *
  void print_map();


  // arena layout
  string Map[arena_height][arena_width];

  void initialize_map() {
    srand(time(NULL));
    // Initialize the Map borders
    for (int y = 0; y < arena_height; ++y) {
      Map[y][0] = wall_symbol;
      Map[y][arena_width - 1] = wall_symbol;
    }
    for (int x = 0; x < arena_width; ++x) {
      Map[0][x] = wall_symbol;
      Map[arena_height - 1][x] = wall_symbol;
    }

    // Create the Map layout
    for (int y = 1; y < arena_height - 1; ++y) {
      for (int x = 1; x < arena_width - 1; ++x) {
        if ((y % 2 == 0 && x % 2 == 0) || rand() % 9 == 2) {
          Map[y][x] = wall_symbol;
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