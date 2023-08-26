# Documentação das Funções do Jogo

## player Namespace

### `can_move(int x, int y, string Map[arena_height][arena_width])`

Verifica se é possível mover o jogador para a posição (x, y) no mapa.

- Parâmetros:
  - `x`: Coordenada X de destino
  - `y`: Coordenada Y de destino
  - `Map`: Mapa do cenário representado como uma matriz de strings
- Retorna `true` se é possível mover, `false` caso contrário.

### `move(int dx, int dy, string Map[arena_height][arena_width])`

Move o jogador na direção (dx, dy) se possível, atualizando o mapa.

- Parâmetros:
  - `dx`: Mudança na coordenada X
  - `dy`: Mudança na coordenada Y
  - `Map`: Mapa do cenário representado como uma matriz de strings

### `put_bomb()`

Coloca uma bomba no local atual do jogador, se nenhuma bomba já foi colocada.

### `bomb_was_placed()`

Verifica se uma bomba foi colocada no mapa.

- Retorna `true` se uma bomba foi colocada, `false` caso contrário.

## enemy_mirror Namespace

### `can_move(int x, int y, string Map[arena_height][arena_width])`

Verifica se é possível mover o inimigo espelho para a posição (x, y) no mapa.

- Parâmetros:
  - `x`: Coordenada X de destino
  - `y`: Coordenada Y de destino
  - `Map`: Mapa do cenário representado como uma matriz de strings
- Retorna `true` se é possível mover, `false` caso contrário.

### `move(int dx, int dy, string Map[arena_height][arena_width])`

Move o inimigo espelho na direção (dx, dy) se possível, atualizando o mapa.

- Parâmetros:
  - `dx`: Mudança na coordenada X
  - `dy`: Mudança na coordenada Y
  - `Map`: Mapa do cenário representado como uma matriz de strings

## bomb Namespace

### `create_sprite_animation(int x, int y, string map[arena_height][arena_width], const char* sprite)`

Cria uma animação de sprite ao redor da posição (x, y) no mapa, se não houver parede forte.

- Parâmetros:
  - `x`: Coordenada X onde a animação será criada
  - `y`: Coordenada Y onde a animação será criada
  - `map`: Mapa do cenário representado como uma matriz de strings
  - `sprite`: O sprite que será colocado

### `activate_bomb(int x, int y)`

Ativa uma bomba na posição (x, y) no mapa.

- Parâmetros:
  - `x`: Coordenada X da posição da bomba
  - `y`: Coordenada Y da posição da bomba

### `destroy_bomb(string map[arena_height][arena_width])`

Destroi a bomba ativada, criando animações de sprite ao redor da posição da bomba.

- Parâmetros:
  - `map`: Mapa do cenário representado como uma matriz de strings

## Arena Namespace

### `initialize_map()`

Inicializa o mapa, criando as bordas, o layout e posicionando o jogador e inimigo.

### `make_movement(int dx, int dy)`

Realiza o movimento do jogador e do inimigo espelho na direção (dx, dy).

- Parâmetros:
  - `dx`: Mudança na coordenada X
  - `dy`: Mudança na coordenada Y

### `init_player()`

Inicializa a posição do jogador e inimigo no mapa.

### `print_map()`

Imprime o mapa no console, mostrando os caracteres do cenário, bombas e personagens.

### `create_map_borders()`

Cria as bordas do mapa com paredes fortes.

### `create_map_layout_random()`

Cria o layout do mapa de forma aleatória.

### `place_wall(string Map[arena_height][arena_width], int x, int y)`

Coloca uma parede no mapa na posição (x, y) com base em uma probabilidade.

- Parâmetros:
  - `Map`: Mapa do cenário representado como uma matriz de strings
  - `x`: Coordenada X da posição
  - `y`: Coordenada Y da posição

### `is_bomb_on(int x, int y)`

Verifica se há uma bomba na posição (x, y) do mapa.

- Parâmetros:
  - `x`: Coordenada X da posição
  - `y`: Coordenada Y da posição
- Retorna `true` se houver uma bomba na posição, `false` caso contrário.

### `is_character_on(int x, int y)`

Verifica se há um personagem na posição (x, y) do mapa.

- Parâmetros:
  - `x`: Coordenada X da posição
  - `y`: Coordenada Y da posição
- Retorna `true` se houver um personagem na posição, `false` caso contrário.

## Game namespace

### `run_game()`

Executa o jogo, controlando os eventos de movimento, bombas e condições de derrota.

### `check_bomb_ticks_to_destroy()`

Verifica se a contagem de ticks da bomba excede o limite e destrói a bomba, se necessário.

### `destroy_bomb()`

Destroi a bomba ativada, executando a animação correspondente.

### `animate_bomb()`

Anima a explosão da bomba no mapa.

### `check_player_death()`

Verifica se o jogador foi derrotado e encerra o jogo, se necessário.

### `check_enemy_deaths()`

Verifica se o inimigo espelho foi derrotado e encerra o jogo, se necessário.

### `game_over()`

Encerra o jogo, exibindo a tela de game over.
