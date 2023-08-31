#include "bomb.h"
#include "services/consts.h"
namespace player {
  using namespace std;

  // Player position
  int player_x = 1;
  int player_y = 1;

  int movements_with_bomb_in_map = 0;

  bool can_move(int x, int y, string Map[arena_height][arena_width]);
  void move(int dx, int dy, string Map[arena_height][arena_width]);
  void put_bomb();
  bool bomb_was_placed();

  /**
   * Verifica se é possível mover para a posição (x, y) no mapa.
   *
   * @param x Coordenada X de destino
   * @param y Coordenada Y de destino
   * @param Map Mapa do cenário representado como uma matriz de strings
   * @return true se é possível mover, false caso contrário
   */
  bool can_move(int x, int y, string Map[arena_height][arena_width]) {
    if (x < 0 || y < 0 || x >= arena_width || y >= arena_height) return false;
    if (bomb::bomb_x == x && bomb::bomb_y == y) return false;
    return Map[y][x] == empty_symbol;
  }

  /**
   * Move o jogador na direção (dx, dy) se possível.
   *
   * @param dx Mudança na coordenada X
   * @param dy Mudança na coordenada Y
   * @param Map Mapa do cenário representado como uma matriz de strings
   */
  void move(int dx, int dy, string Map[arena_height][arena_width]) {
    int newX = player_x + dx;
    int newY = player_y + dy;

    if (can_move(newX, newY, Map)) {
      Map[player_y][player_x] = empty_symbol;
      player_x = newX;
      player_y = newY;
      Map[player_y][player_x] = player_symbol;
    }

    if (bomb_was_placed()) { // para controlar a explosão da bomba
      movements_with_bomb_in_map++;
    }
  }

  /**
   * Coloca uma bomba no local atual do jogador, se nenhuma bomba já foi colocada.
   */
  void put_bomb() {
    if (!bomb_was_placed()) {
      bomb::activate_bomb(player_x, player_y);
    }
  }

  /**
   * Verifica se uma bomba foi colocada no mapa.
   *
   * @return true se uma bomba foi colocada, false caso contrário
   */
  bool bomb_was_placed() {
    return bomb::bomb_x != -1 && bomb::bomb_y != -1;
  }
}






