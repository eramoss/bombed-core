#include <string>
#include "services/consts.h"
#define MAX_TICKS_TO_EXPLODE 3
#define AMOUNT_OF_SPRITES 4

namespace bomb {
  using namespace std;

  int bomb_x = -1;
  int bomb_y = -1;

  bool bomb_enabled = false;
  int ticks_to_explode;

  const char* sprite_animations[AMOUNT_OF_SPRITES] = { explosion, great_explosion, greater_explosion, empty_symbol };

  //functions interface *
  void create_sprite_animation(int x, int y, string map[arena_height][arena_width], const char* sprite);
  void activate_bomb(int x, int y);
  void destroy_bomb_on_map(string map[arena_height][arena_width]);


  /**
 * Cria uma animação de sprite em torno da posição (x, y) no mapa, se não houver parede forte.
 *
 * @param x Coordenada X onde a animação será criada
 * @param y Coordenada Y onde a animação será criada
 * @param map Mapa do cenário representado como uma matriz de strings
 * @param sprite O sprite que será colocado
 */
  void create_sprite_animation(int x, int y, string map[arena_height][arena_width], const char* sprite) {
    if (map[y + 1][x] != strong_wall_symbol) map[y + 1][x] = sprite;
    if (map[y - 1][x] != strong_wall_symbol) map[y - 1][x] = sprite;
    if (map[y][x - 1] != strong_wall_symbol) map[y][x - 1] = sprite;
    if (map[y][x + 1] != strong_wall_symbol) map[y][x + 1] = sprite;
    if (map[y][x] != strong_wall_symbol) map[y][x] = sprite;
  }

  /**
   * Ativa uma bomba na posição (x, y) no mapa.
   *
   * @param x Coordenada X da posição da bomba
   * @param y Coordenada Y da posição da bomba
   */
  void activate_bomb(int x, int y) {
    bomb_x = x;
    bomb_y = y;
    ticks_to_explode = 0;
    bomb_enabled = true;
  }

  /**
   * Destroi a bomba ativada, criando animações de sprite ao redor da posição da bomba.
   *
   * @param map Mapa do cenário representado como uma matriz de strings
   */
  void destroy_bomb_on_map(string map[arena_height][arena_width]) {
    for (int sprite_index = 0; sprite_index < AMOUNT_OF_SPRITES; sprite_index++) {
      create_sprite_animation(bomb_x, bomb_y, map, sprite_animations[sprite_index]);
    }
    bomb_x = -1;
    bomb_y = -1;
  }

}