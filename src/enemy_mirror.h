#include "services/consts.h"
#include <string>

namespace enemy_mirror {
  using namespace std;

  // enemy position
  int enemy_x = arena_width - 3;
  int enemy_y = arena_height - 3;

  void move(int dx, int dy, string Map[arena_height][arena_width]);
  bool can_move(int x, int y, string Map[arena_height][arena_width]);

  bool defeated(string Map[arena_height][arena_width]);


  /**
 * Move o inimigo na direção (-dx, -dy) se possível, atualizando o mapa.
 *
 * @param dx Mudança na coordenada X (negativa)
 * @param dy Mudança na coordenada Y (negativa)
 * @param Map Mapa do cenário representado como uma matriz de strings
 */
  void move(int dx, int dy, string Map[arena_height][arena_width]) {
    int newX = enemy_x - dx;
    int newY = enemy_y - dy;

    if (can_move(newX, newY, Map)) {
      Map[enemy_y][enemy_x] = empty_symbol;
      enemy_x = newX;
      enemy_y = newY;
      Map[enemy_y][enemy_x] = enemy_symbol;
    }
  }

  /**
   * Verifica se é possível mover para a posição (x, y) no mapa, levando em conta
   * as regras de movimentação do inimigo.
   *
   * @param x Coordenada X de destino
   * @param y Coordenada Y de destino
   * @param Map Mapa do cenário representado como uma matriz de strings
   * @return true se é possível mover, false caso contrário
   */
  bool can_move(int x, int y, string Map[arena_height][arena_width]) {
    if (x < 0 || y < 0 || x >= arena_width || y >= arena_height) return false;
    return (Map[y][x] == empty_symbol || Map[y][x] == player_symbol) && !defeated(Map);
  }



  /**
   * Verifica se o inimigo foi derrotado no mapa.
   *
   * @param Map Mapa do cenário representado como uma matriz de strings
   * @return true se o inimigo foi derrotado, false caso contrário
   */
  bool defeated(string Map[arena_height][arena_width]) {
    return Map[enemy_y][enemy_x] != enemy_symbol;
  }
}
