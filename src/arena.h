#include <iostream>
#include "services/console_helpers.h"
#include "services/consts.h"
#include <time.h>

#include "player.h"
#include "enemy_mirror.h"
#include "enemy_move_random.h"

#define ENTROPY_MAP_GENERATOR (y % 2 == 0 && x % 2 == 0) || rand() % 11 == 2
using namespace std;

namespace Arena {
  double map_difficulty;

  void print_map();
  void initialize_map(int map_chosse);
  void create_map_borders();
  void create_map_layout_random();
  void place_wall(string Map[arena_height][arena_width], int x, int y);
  void init_characters();
  void make_movement(int dx, int dy);
  bool is_bomb_on(int x, int y);
  bool is_character_on(int x, int y);


  // arena layout
  string Map[arena_height][arena_width];


  /**
 * Inicializa o mapa, criando as bordas, o layout e posicionando o jogador e inimigo.
 *
 * @param map_choose O mapa escolhido pelo jogador para gerar a dificuldade do mapa
 */
  void initialize_map(int map_choose) {
    map_difficulty = map_choose;
    create_map_borders();
    create_map_layout_random();
    init_characters();
  }

  /**
   * Imprime o mapa no console, mostrando os caracteres do cenário, bombas e personagens.
   */
  void print_map() {
    clear_console(true);

    for (int y = 0; y < arena_height; ++y) {
      for (int x = 0; x < arena_width; ++x) {
        if (!is_bomb_on(x, y) || is_character_on(x, y)) {
          cout << Map[y][x];
        }
        else {
          cout << bomb_character;
        }
      }
      cout << endl;
    }
  }

  /**
   * Cria as bordas do mapa com paredes fortes.
   */
  void create_map_borders() {
    for (int y = 0; y < arena_height; ++y) {
      Map[y][0] = strong_wall_symbol;
      Map[y][arena_width - 1] = strong_wall_symbol;
    }
    for (int x = 0; x < arena_width; ++x) {
      Map[0][x] = strong_wall_symbol;
      Map[arena_height - 1][x] = strong_wall_symbol;
    }
  }

  /**
   * Cria o layout do mapa de forma aleatória.
   */
  void create_map_layout_random() {
    srand(time(NULL));

    for (int y = 1; y < arena_height - 1; ++y) {
      for (int x = 1; x < arena_width - 1; ++x) {
        if (ENTROPY_MAP_GENERATOR) {
          place_wall(Map, x, y);
        }
        else {
          Map[y][x] = empty_symbol;
        }
      }
    }
  }

  /**
   * Coloca uma parede no mapa na posição (x, y) com base em uma probabilidade.
   *
   * @param Map Mapa do cenário representado como uma matriz de strings
   * @param x Coordenada X da posição
   * @param y Coordenada Y da posição
   */
  void place_wall(string Map[arena_height][arena_width], int x, int y) {
    const double strong_wall_probability = map_difficulty * map_difficulty / 15 + 0.3; 
    if (static_cast<double>(rand()) / RAND_MAX < strong_wall_probability) {
      Map[y][x] = strong_wall_symbol;
    }
    else {
      Map[y][x] = weak_wall_symbol;
    }
  }


  /**
 * Realiza o movimento do jogador e do inimigo espelho na direção (dx, dy).
 *
 * @param dx Mudança na coordenada X
 * @param dy Mudança na coordenada Y
 */
  void make_movement(int dx, int dy) {
    player::move(dx, dy, Map);
    enemy_mirror::move(dx, dy, Map);
    enemy_move_randow::move_random(Map);
  }


  /**
   * Verifica se há uma bomba na posição (x, y) do mapa.
   *
   * @param x Coordenada X da posição
   * @param y Coordenada Y da posição
   * @return true se houver uma bomba na posição, false caso contrário
   */
  bool is_bomb_on(int x, int y) {
    return bomb::bomb_x == x && bomb::bomb_y == y;
  }

  /**
   * Verifica se há um personagem na posição (x, y) do mapa.
   *
   * @param x Coordenada X da posição
   * @param y Coordenada Y da posição
   * @return true se houver um personagem na posição, false caso contrário
   */
  bool is_character_on(int x, int y) {
    return (player::player_x == x && player::player_y == y) || (enemy_mirror::enemy_x == x && enemy_mirror::enemy_y == y);
  }


  /**
   * Inicializa a posição do jogador e inimigo no mapa.
   */
  void init_characters() {
    Map[1][1] = player_symbol;
    Map[arena_height - 3][arena_width - 3] = enemy_symbol;
    Map[1][arena_width - 3] = enemy_symbol;
  }

}