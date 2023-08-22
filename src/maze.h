#include <iostream>
#include "services/console_helpers.h"

using namespace std;

namespace maze {
  // Maze dimensions
  const int maze_width = 40;
  const int maze_height = 20;

  // Maze symbols
  const char* wall_symbol = "\u2588";
  const char* player_A_symbol = "A";
  const char* empty_symbol = " ";


  //functions interface *
  void create_walls();
  void create_random_inside_map();
  void init_map();
  bool is_wall(int y_coord, int x_coord);
  void print_maze();




  // Maze layout
  string Map[maze_height][maze_width];

  void init_map() {
    create_walls();
    create_random_inside_map();
  }

  void create_walls() {
    for (int i = 0; i < maze_height; i++) {
      for (int j = 0; j < maze_width; j++) {
        if (is_wall(i, j)) {
          Map[i][j] = wall_symbol;
        }
      }
    }
  }

  void create_random_inside_map() {
    for (int i = 0; i < maze_height; i++) {
      for (int j = 0; j < maze_width; j++) {
        if (!is_wall(i, j)) {
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

  bool is_wall(int y_coord, int x_coord) {
    return y_coord == 0 || x_coord == maze_height - 1 || y_coord == 0 || y_coord == maze_width - 1;
  }

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