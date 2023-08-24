#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>

// Mapas
int map1[11][11] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 3, 3, 3, 3, 3, 3, 3, 0, 1},
{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int map2[11][11] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int map3[11][11] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int maps[3] = {map1[11][11], map2[11][11], map3[11][11]}; // Pra escolher o mapa
int map[11][11]; // Define o tamanho do mapa
int player[2] = {1, 1}; // Spawna o jogador A na esquerda em cima
int poder[2] = {1, 2}; // Teste poder
int special[2] = {-1, -1}; // Usar para teste de bomba depois
int bomb[2] = {-2, -1}; // Spawna a bomba fora do mapa
int ticks = 0; // Seta os ticks para zero
int ticksExplosao = 3; // Define a quantidade de ticks para a explosao
bool activeBomb = false; // Define a bomba como inativa
int radiusBomb = 2;
int choiceMenu, choiceMap; // Variávieis do menu
bool superBomb = false;
int superPower = 3;

// Mover os jogadores/especial
void movePlayer(int player[], char move, bool isSpecial = false) {
    switch (move) {
        case 'w': 
            if ((isSpecial && player[0] - 1 > 0) || map[player[0]-1][player[1]] == 0 || map[player[0]-1][player[1]] == 4) player[0]--; 
            break;
        case 's': 
            if ((isSpecial && player[0] + 1 < 11 - 1) || map[player[0]+1][player[1]] == 0 || map[player[0]+1][player[1]] == 4) player[0]++; 
            break;
        case 'a': 
            if ((isSpecial && player[1] - 1 > 0) || map[player[0]][player[1]-1] == 0 || map[player[0]][player[1]-1] == 4) player[1]--; 
            break;
        case 'd': 
            if ((isSpecial && player[1] + 1 < 11 - 1) || map[player[0]][player[1]+1] == 0 || map[player[0]][player[1]+1] == 4) player[1]++; 
            break;
    }

    if (map[player[0]][player[1]] == 4){
        map[player[0]][player[1]] = 0;
        superBomb = true;
    }

    if (activeBomb) {
        ticks++; // VER activateBomb()
    }
}

// Construir o mapa
void buildMap(int chosenMap[11][11]) { 
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {

            // Copia a matriz escolhida para a matriz do jogo
            map[i][j] = chosenMap[i][j];

        }
    }
}

void spawnPower() {

    srand(time(0)); // Aleatoriedade

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (map[i][j] == 4) { // Confere quantos poderes já tem no mapa
                superPower--;     // Diminui da quantidade total de poderes
            }
        }
    }

    while (superPower > 0) {
        int randomMapX = rand() % 11; // Pega um X aleatório
        int randomMapY = rand() % 11; // Pega um Y aleatório

        if (map[randomMapX][randomMapY] == 0) { // Confere se é um espaço vazio
            map[randomMapX][randomMapY] = 4;    // Insere o poderzinho
            superPower--; // Repete até ter 3 poderes no mapa
        }
    }
}

// Cout do mapa e os jogadores
void displayMap() { 
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (i == player[0] && j == player[1]) {            // 
                std::cout << 'A';                              //
            } else if (i == special[0] && j == special[1]) {   // Entendível
                std::cout << 'X';                              //
            } else if (i == bomb[0] && j == bomb[1]) {         //
                std::cout << 'B';
            } 
            else {   
                    // Define cada coisa da matriz
                    // (Do jeito q o eduardo queria, nn ta por cima)
                    switch (map[i][j])
                    {
                    case 0:
                        std::cout << " ";
                        break; // caminho
                    case 1:
                        std::cout << char(219); // strong wall
                        break; 
                    case 3:
                        std::cout << char(254); // weak wall
                        break;
                    case 4:
                        std::cout << char(43); // +
                        break;
                    case 7:
                        std::cout << char(176); // weak explosion
                        break;
                    case 8:
                        std::cout << char(177); // medium explosion
                        break;
                    case 9:
                        std::cout << char(178); // strong explosion
                        break;
                    } 
            }
        }
        std::cout << std::endl;
    }
    spawnPower();
}

// Define o lugar q vai sair a animação da explosão
void explosionAnimation(int x, int y, char sprite, bool superBomb = false) {
    // Baixo
    if (x + 1 < 11 && map[x+1][y] != 1) map[x+1][y] = sprite;
    if (x + 1 < 11 && map[x+1][y] != 1 && (superBomb && x + 2 < 11 && map[x+2][y] != 1)) map[x+2][y] = sprite;

    // Cima
    if (x - 1 >= 0 && map[x-1][y] != 1) map[x-1][y] = sprite;
    if (x - 1 >= 0 && map[x-1][y] != 1 && (superBomb && x - 2 >= 0 && map[x-2][y] != 1)) map[x-2][y] = sprite;

    // Esquerda
    if (y - 1 >= 0 && map[x][y-1] != 1) map[x][y-1] = sprite;
    if (y - 1 >= 0 && map[x][y-1] != 1 && (superBomb && y - 2 >= 0 && map[x][y-2] != 1)) map[x][y-2] = sprite;

    // Direita
    if (y + 1 < 11 && map[x][y+1] != 1) map[x][y+1] = sprite;
    if (y + 1 < 11 && map[x][y+1] != 1 && (superBomb && y + 2 < 11 && map[x][y+2] != 1)) map[x][y+2] = sprite;
}

// Animação da explosão
void animationBomb() { 

    int explosion = 7;            //
    int great_explosion = 8;      //   VER displayMap()
    int greater_explosion = 9;    //

    // Vetor para mudar o 'sprite' da animação
    int animation[4] = {explosion, great_explosion, greater_explosion, 0};

    // Cout da explosão
    for (int i = 0; i < 3; i++){
        for (int ex = 0; ex < 4; ex++) {

            // Manda a localização da bomba e o sprite relativo ao vetor
            explosionAnimation(bomb[0], bomb[1], animation[ex], superBomb);
            system("cls");

            // Escreve a matriz, já com o sprite da explosão
            displayMap();

            // FPS? da explosão
            Sleep(100);
        }   
    }

}

// Ativamento da bomba
void activateBomb() { 

    bomb[0] = player[0]; // Define a posição
    bomb[1] = player[1]; //     da bomba

    ticks = 0; // Reseta os ticks quando a bomba é ativa

    activeBomb = true; // Ativa a bomba

}

// Ticks para a explosão
void ticksBomb(){

        if (ticks >= ticksExplosao) { // Conta os ticks para a explosão
            
            animationBomb(); // Animação da bomba

            superBomb = false;

            std::cout << "\nBomb exploded!\n";

            bomb[0] = -2;         //    Retorna a bomba
            bomb[1] = -1;         //    para o local de
            activeBomb = false;   //    origem e reseta

            system("cls");  // Mostra o mapa depois da bomba explodir,
            displayMap();   // pra bomba sumir antes do jogador andar

        } else {

            // Aviso de que a bomba vai explodir contando os ticks
            std::cout << "\nBomb will explode in " << (ticksExplosao - ticks) << "\n";

        }
        
}

// Vê se a bomba ta ativa (vulgo fora do lugar de origem)
void checkBomb() { 

    if (bomb[0] != -2 && bomb[1] != -1) { // Vê se ta fora do local de origem
        
        ticksBomb(); // Aciona os ticks para a bomba

    }
}

// Robei do eduardo
void hide_cursor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void layoutJogar(int &choiceMap){
    system("cls");
    std::cout << "+-------------------------------------------------------------------------------------+\n"
                 "|                                                                                     |\n"
                 "|                                Escolha o seu mapa:                                  |\n"
                 "|                                                                                     |\n"
                 "|                                                                                     |\n"
                 "|            Mapa 1                     Mapa 2                      Mapa 3            |\n"
                 "|     +-------------------+      +-------------------+      +-------------------+     |\n"
                 "|     |                   |      |                   |      |                   |     |\n"
                 "|     |                   |      |                   |      |                   |     |\n"
                 "|     |                   |      |                   |      |                   |     |\n"
                 "|     |                   |      |                   |      |                   |     |\n"
                 "|     |                   |      |                   |      |                   |     |\n"
                 "|     |                   |      |                   |      |                   |     |\n"
                 "|     |                   |      |                   |      |                   |     |\n"
                 "|     |                   |      |                   |      |                   |     |\n"
                 "|     +-------------------+      +-------------------+      +-------------------+     |\n"
                 "|                                                                                     |\n"
                 "|       Dificuldade: 1/11          Dificuldade: 5/11          Dificuldade: 11/11      |\n"
                 "|                                                                                     |\n"
                 "|      Um guerreiro covarde        Um guerreiro justo         Para o verdadeiro       |\n"
                 "|        morre mil mortes,         nunca anda sozinho,        guerreiro, o maior      |\n"
                 "|      o valente apenas uma        a honra o acompanha        desafio e o chamado     |\n"
                 "|                                                                                     |\n"
                 "|                                                                                     |\n"
                 "+-------------------------------------------------------------------------------------+\n\n";

    std::cin >> choiceMap;
}

// Layout das Regras
void layoutRegras(){
    system("cls");
    std::cout << "+--------------------------------------+\n"
                 "|                                      |\n"
                 "|                Regras                |\n"
                 "|                                      |\n"
                 "|--------------------------------------|\n"
                 "|                                      |\n"
                 "|  > Movimento automatico, pressione   |\n"
                 "|      WASD para se mover no mapa.     |\n"
                 "|                                      |\n"
                 "|  > Pressione ENTER para soltar uma   |\n"
                 "|     bomba no local do personagem.    |\n"
                 "|                                      |\n"
                 "|  > A bomba detona apos tres ticks    |\n"
                 "|             do jogador.              |\n"
                 "|                                      |\n"
                 "|  > Bombas destroem paredes frageis,  |\n"
                 "|      matam inimigos e o jogador.     |\n"
                 "|                                      |\n"
                 "|  > O jogador ganhara quando matar    |\n"
                 "|          todos os inimigos.          |\n"
                 "|                                      |\n"
                 "+--------------------------------------+\n\n";
    system("pause");
}

// Int MAIN
int main() {

    hide_cursor(); // Esconde o cursor

    // Menuzinho
    system("cls");
    std::cout <<"______                    _                _ \n"
                "| ___ \\                  | |              | |\n"
                "| |_/ /  ___   _ __ ___  | |__    ___   __| |\n"
                "| ___ \\ / _ \\ | '_ ` _ \\ | '_ \\  / _ \\ / _` |\n"
                "| |_/ /| (_) || | | | | || |_) ||  __/| (_| |\n"
                "\\____/  \\___/ |_| |_| |_||_.__/  \\___| \\__,_|\n\n"
                "  _____   \n"                
                " /  __ \\                         1 - Jogar\n"
                "| /  \\/  ___   _ __   ___        2 - Regras\n"
                "| |     / _ \\ | '__| / _ \\       3 - Sair\n"
                "| \\__/\\| (_) || |   |  __/        \n"
                " \\____/ \\___/ |_|    \\___|       Escolha: "; std::cin >> choiceMenu;
    std::cout << std::endl << std::endl << std::endl;



    // Escolha do menu
    switch (choiceMenu) {
        case 1:

            layoutJogar(choiceMap);

            // Escolha do mapa
            switch (choiceMap) { 
                case 1:
                    buildMap(map1);
                    break;
                case 2:
                    buildMap(map2);
                    break;
                case 3:
                    buildMap(map3);
                    break;
                default:
                    std::cout << "Opcao invalida." << std::endl;
                    return 1;
            }
            
            break;
        case 2:

            layoutRegras();

            break;
        case 3:
            break;
        default:
            std::cout << "Opcao invalida." << std::endl;
            // Tem q fazer voltar pras opções
            break;
    }

    // Clear no menu pra começar o jogo
    system("cls");

    while (true) {

        hide_cursor(); // Esconde o cursor

        system("cls"); // Limpa o mapa anterior

        displayMap(); // Mostra o mapa atual

        checkBomb(); // A cada iteração, checa se a bomba está ativa

        char move;        // Pega a tecla
        move = _getch();  // pressionada

        // Envia qual player (n precisa mais) e qual tecla foi pressionada
        movePlayer(player, move); 

        if (move == 13) { // FAZ O L

            activateBomb(); // Ativa a bomba se o Enter é pressionado

        }

    }

    return 0;
}