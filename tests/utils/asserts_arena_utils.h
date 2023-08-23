#include "../../src/arena.h"
#include <assert.h>

namespace asserts {
  using namespace Arena;
  void assert_arena_has_only_valid_blocks() {
    for (int i = 0; i < arena_height; i++) {
      for (int j = 0; j < arena_width; j++) {
        assert(Map[i][j] == empty_symbol || Map[i][j] == wall_symbol);
      }
    }
  }
}
