#include <iostream>
#include "services/console_helpers.h"

using namespace std;

namespace maze {
  // Maze dimensions
  const int maze_width = 40;
  const int maze_height = 20;

  // Maze symbols
  const char* wall_symbol = "\u2588";
  const char* player_symbol = "A";
  const char* empty_symbol = " ";


  //functions interface *
  void print_maze();


  // Maze layout
  string Map[maze_height][maze_width];


  void print_maze() {
    clear_console();

    for (int y = 0; y < maze_width; ++y) {
      for (int x = 0; x < maze_height; ++x) {
        cout << Map[y][x];
      }
      cout << endl;
    }
  }

}