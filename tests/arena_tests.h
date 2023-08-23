#include "utils/asserts_arena_utils.h"
using namespace asserts;

void init_map_test() {
  initialize_map();
  assert_arena_has_only_valid_blocks();
}
