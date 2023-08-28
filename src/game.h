#include "arena.h"
#include "assets/animations.h"
#define WIN true
#define LOSE false

namespace game {
  bool over = false;

  void run_game();
  void check_bomb_ticks_to_destroy();
  void destroy_bomb_on_map();
  void animate_bomb_on_map();
  void check_player_death();
  void check_enemy_deaths();
  void game_over(bool is_win);


  /**
   * Executa o jogo, controlando os eventos de movimento, bombas e condições de derrota.
   */
  void run_game(int map) {
    clear_console();
    hide_cursor();
    Arena::initialize_map();

    char input;

    while (true) {
      Arena::print_map();

      input = get_input_without_enter(); // Obter um caractere do teclado

      switch (input) {
        case 'w':
          Arena::make_movement(0, -1);
          break;
        case 's':
          Arena::make_movement(0, 1);
          break;
        case 'a':
          Arena::make_movement(-1, 0);
          break;
        case 'd':
          Arena::make_movement(1, 0);
          break;
        case 'b':
          player::put_bomb();
          break;
        default:
          break;
      }
      check_bomb_ticks_to_destroy();
      check_player_death();
      check_enemy_deaths();
      if (over) return;
    }
  }

  /**
   * Verifica se a contagem de ticks da bomba excede o limite e destrói a bomba, se necessário.
   */
  void check_bomb_ticks_to_destroy() {
    if (bomb::bomb_enabled) {
      bomb::ticks_to_explode = player::movements_with_bomb_in_map;
      if (bomb::ticks_to_explode >= MAX_TICKS_TO_EXPLODE) {
        destroy_bomb_on_map();
        player::movements_with_bomb_in_map = 0;
      }
    }
  }

  /**
   * Destroi a bomba ativada, executando a animação correspondente.
   */
  void destroy_bomb_on_map() {
    animate_bomb_on_map();
    bomb::destroy_bomb_on_map(Arena::Map);
  }

  /**
   * Anima a explosão da bomba no mapa.
   */
  void animate_bomb_on_map() {
    for (int sprite_index = 0; sprite_index < AMOUNT_OF_SPRITES; sprite_index++) {
      bomb::create_sprite_animation(bomb::bomb_x, bomb::bomb_y, Arena::Map, bomb::sprite_animations[sprite_index]);
      Arena::print_map();
      usleep(50000);
    }
    for (int sprite_index = 0; sprite_index < AMOUNT_OF_SPRITES; sprite_index++) {
      bomb::create_sprite_animation(bomb::bomb_x, bomb::bomb_y, Arena::Map, bomb::sprite_animations[sprite_index]);
      Arena::print_map();
      usleep(50000);
    }
  }

  /**
   * Verifica se o jogador foi derrotado e encerra o jogo, se necessário.
   */
  void check_player_death() {
    if (Arena::Map[player::player_y][player::player_x] != player_symbol) {
      game_over(LOSE);
    }
  }

  /**
   * Verifica se o inimigo espelho foi derrotado e encerra o jogo, se necessário.
   */
  void check_enemy_deaths() {
    if (enemy_mirror::defeated(Arena::Map) && enemy_move_randow::defeated(Arena::Map)) {
      game_over(WIN);
    }
  }

  /**
   * Encerra o jogo, exibindo a tela de game over.
   */
  void game_over(bool is_win) {
    Arena::print_map();
    usleep(500000);
    if (is_win) animations::animation_winner();
    else animations::animations_loser();
    over = true;
  }
}