#include "utils/asserts_utils.h"

namespace arena_tests {
  void init_map_test() {
    Arena::initialize_map();
    assertions_arena::assert_arena_has_only_valid_blocks();
  }

  void run_tests() {
    init_map_test();
  }
}

namespace bomb_tests {
  void destroy_bomb_should_be_return_bomb_to_origin() {
    bomb::bomb_x = 1;
    bomb::bomb_y = 1;
    string map_mock[arena_height][arena_width];
    bomb::destroy_bomb(map_mock);

    assert(bomb::bomb_x == -1 && bomb::bomb_y == -1);
  }

  void activate_bomb_test() {
    bomb::activate_bomb(1, 2);

    assert(bomb::bomb_x == 1 && bomb::bomb_y == 2);
    assert(bomb::bomb_enabled);
  }

  void run_tests() {
    destroy_bomb_should_be_return_bomb_to_origin();
    activate_bomb_test();
  }
}

int main() {
  arena_tests::run_tests();
  bomb_tests::run_tests();
  return 0;
}
