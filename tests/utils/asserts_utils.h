#include "../../src/game.h"
#include <assert.h>

namespace assertions_arena {
  using namespace Arena;
  void assert_arena_has_only_valid_blocks() {
    for (int i = 0; i < arena_height; i++) {
      for (int j = 0; j < arena_width; j++) {
        assert(Map[i][j] == empty_symbol || Map[i][j] == strong_wall_symbol || Map[i][j] == weak_wall_symbol || Map[i][j] == player_symbol || Map[i][j] == enemy_symbol);
      }
    }
  }

}

namespace helpers {
  void make_empty_map(string Map[arena_height][arena_width]) {
    for (int i = 0; i < arena_height; i++) {
      for (int j = 0; j < arena_width; j++) {
        Map[i][j] = empty_symbol;
      }
    }
  }
}