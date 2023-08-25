#include "utils/asserts_utils.h"

namespace arena_tests {
  void init_map_test() {
    Arena::initialize_map();
    assertions_arena::assert_arena_has_only_valid_blocks();
  }
}


int main() {
  arena_tests::init_map_test();
  return 0;
}
