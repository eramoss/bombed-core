#include <iostream>
#include "console_helpers.h"

using namespace std;

namespace maze {
  // Maze dimensions
  const int maze_width = 20;
  const int maze_height = 40;

  // Maze symbols
  const char* wall_symbol = "\u2588";
  const char* player_A_symbol = "A";
  const char* player_B_symbol = "B";
  const char* empty_symbol = " ";


  // Maze layout
  string Map[maze_width][maze_height];

  void init_map() {
    for (int i = 0; i < maze_width; i++) {
      for (int j = 0; j < maze_height; j++) {
        if (i == 0 || i == maze_width - 1 || j == 0 || j == maze_height - 1) {
          Map[i][j] = wall_symbol;
        }
        else {
          int random = rand() % 100;
          if (random < 80) {
            Map[i][j] = empty_symbol;
          }
          else {
            Map[i][j] = wall_symbol;
          }
        }
      }
    }
  }


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