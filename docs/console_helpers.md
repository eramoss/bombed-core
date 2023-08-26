# Documentação das Funções e Constantes de Apoio ao Console

## Funções de Limpeza e Controle de Console

### `clear_console(bool is_to_print_map = false)`

Limpa o console. Se `is_to_print_map` for `true`, reposiciona o cursor para a posição inicial no console.

- Parâmetros:
  - `is_to_print_map`: Define se é para reposicionar o cursor (padrão é `false`)

### `hide_cursor()`

Oculta o cursor no console.

### `get_input_without_enter()`

Obtém um caractere de entrada do teclado, ignorando a tecla Enter.

## Constantes de Suporte a Diferentes Sistemas

### `_WIN32`

Constante que indica que o sistema operacional é Windows.

### `STD_OUTPUT_HANDLE`

Identificador do console de saída no Windows.

### `COORD`

Estrutura que define as coordenadas do cursor no Windows.

### `clear_console` (Windows)

Função para limpar o console no Windows.

### `hide_cursor` (Windows)

Função para ocultar o cursor no Windows.

### `get_input_without_enter` (Windows)

Função para obter uma entrada do teclado sem capturar a tecla Enter no Windows.

### `clear_console` (Linux)

Função para limpar o console no Linux.

### `hide_cursor` (Linux)

Função para ocultar o cursor no Linux.

### `get_input_without_enter` (Linux)

Função para obter uma entrada do teclado sem capturar a tecla Enter no Linux.
