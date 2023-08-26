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
    bomb::destroy_bomb_on_map(map_mock);

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

namespace player_tests {
  void move_test() {
    string Map[arena_height][arena_width];
    helpers::make_empty_map(Map);

    int original_player_x = player::player_x;
    int original_player_y = player::player_y;

    player::move(1, 0, Map);

    assert(player::player_x != original_player_x);
    assert(player::player_y == original_player_y);
  }

  void player_should_walk_in_empty_map() {
    string Map[arena_height][arena_width];
    helpers::make_empty_map(Map);

    assert(player::can_move(3, 3, Map));
  }
  void run_tests() {
    move_test();
  }
}

int main() {
  arena_tests::run_tests();
  bomb_tests::run_tests();
  player_tests::run_tests();
  return 0;
}
