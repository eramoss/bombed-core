#include <iostream>
#include "services/console_helpers.h"

using namespace std;

namespace Arena {
  // arena dimensions
  const int arena_width = 40;
  const int arena_height = 20;

  // arena symbols
  const char* wall_symbol = "\u2588";
  const char* player_symbol = "A";
  const char* empty_symbol = " ";


  //functions interface *
  void print_map();


  // arena layout
  string Map[arena_height][arena_width];


  void print_map() {
    clear_console();

    for (int y = 0; y < arena_width; ++y) {
      for (int x = 0; x < arena_height; ++x) {
        cout << Map[y][x];
      }
      cout << endl;
    }
  }

}