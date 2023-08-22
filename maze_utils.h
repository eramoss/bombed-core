#include <iostream>
#include "./console_helpers.h"

using namespace std;

namespace maze {
  // Maze dimensions
  const int maze_width = 30;
  const int maze_height = 30;

  // Maze symbols
  const char* wall_symbol = "\u2588";
  const char* player_A_symbol = "A";
  const char* player_B_symbol = "B";
  const char* empty_symbol = " ";


  // Maze layout
  string Map[maze_width][maze_height] = {
      {wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol},
      {wall_symbol, empty_symbol, empty_symbol, empty_symbol, wall_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, wall_symbol},
      {wall_symbol, empty_symbol, wall_symbol, empty_symbol, wall_symbol, empty_symbol, wall_symbol, wall_symbol, empty_symbol, wall_symbol},
      {wall_symbol, empty_symbol, wall_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, wall_symbol},
      {wall_symbol, empty_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, empty_symbol, wall_symbol},
      {wall_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, wall_symbol, empty_symbol, wall_symbol},
      {wall_symbol, empty_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, empty_symbol, wall_symbol, empty_symbol, wall_symbol},
      {wall_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, wall_symbol, empty_symbol, empty_symbol, empty_symbol, wall_symbol},
      {wall_symbol, wall_symbol, wall_symbol, wall_symbol, empty_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol, wall_symbol},
      {wall_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, empty_symbol, player_B_symbol}
  };


  void print_maze() {
    clear_console();

    for (int y = 0; y < maze_height; ++y) {
      for (int x = 0; x < maze_width; ++x) {
        cout << Map[y][x];
      }
      cout << endl;
    }
  }

}