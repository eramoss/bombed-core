#ifndef animes
#define animes

#include <iostream>
#include <windows.h>

namespace animation {

    void animationLoser(){

        system("cls");

        std::string animatedLose[] = { 
        "     _____                           _____                    ",
        "    |  __ \\                         |  _  |                   ",
        "    | |  \\/  __ _  _ __ ___    ___  | | | |__   __  ___  _ __ ",
        "    | | __  / _` || '_ ` _ \\  / _ \\ | | | |\\ \\ / / / _ \\| '__|",
        "    | |_\\ \\| (_| || | | | | ||  __/ \\ \\_/ / \\ V / |  __/| |   ",
        "     \\____/ \\__,_||_| |_| |_| \\___|  \\___/   \\_/   \\___||_|   "
        };

        for(int i = 0; i < 6; i ++){
            std::cout << animatedLose[i] << std::endl;
            Sleep(200);
        }

        std::cout << std::endl << std::endl;

        system("pause");

    }

    void animationWinner(){

        system("cls");

        std::string animatedWin[] = {
        "__   __                _    _  _         _ ",
        "\\ \\ / /               | |  | |(_)       | |",
        " \\ V /   ___   _   _  | |  | | _  _ __  | |",
        "  \\ /   / _ \\ | | | | | |/\\| || || '_ \\ | |",
        "  | |  | (_) || |_| | \\  /\\  /| || | | ||_|",
        "  \\_/   \\___/  \\__,_|  \\/  \\/ |_||_| |_|(_)"
        };

        for(int i = 0; i < 6; i ++){
            std::cout << animatedWin[i] << std::endl;
            Sleep(300);
        }
        
        std::cout << std::endl << std::endl;

        system("pause");

    }

    void animationRules(){ 
        system("cls");
        std::string animatedRule[] = {
            "  ._________________________________________________.    ",
            " / \\                                                 \\ ",
            "|   |                    Regras                      |   ",
            "`.__|                                                |   ",
            "    |                                                |   ",
            "    |    > Movimento automatico, pressione WASD      |   ",
            "    |          para mover o seu personagem.          |   ",
            "    |                                                |   ",
            "    |    > Pressione ENTER para soltar uma bomba     |   ",
            "    |        no local onde esta seu personagem.      |   ",
            "    |                                                |   ",
            "    |    > Apos o jogador andar 3 vezes, a bomba     |   ",
            "    |         ira detonar em formato de cruz.        |   ",
            "    |                                                |   ",
            "    |    > Bombas podem destruir paredes frageis,    |   ",
            "    |           matar inimigos e o jogador.          |   ",
            "    |                                                |   ",
            "    |    > O jogador ganha quando acabar com todos   |   ",
            "    |               os inimigos do mapa.             |   ",
            "    |                                                |   ",
            "    |  .------------------------------------------------.",
            "    \\_/________________________________________________/"
        };

        for(int i = 0; i < 22; i++){
            std::cout << animatedRule[i] << std::endl;
            Sleep(100);
        }
        std::cout << std::endl << std::endl;
        system("pause");
    }

    void animationSelectMap(int &choiceMap){
        system("cls");
        std::cout << "+-------------------------------------------------------------------------------------+\n"
                    "|                                                                                      |\n"
                    "|                                Escolha o seu mapa:                                   |\n"
                    "|                                                                                      |\n"
                    "|                                                                                      |\n"
                    "|            Mapa 1                     Mapa 2                      Mapa 3             |\n"
                    "|     +--------------------+      +-------------------+      +-------------------+     |\n"
                    "|     |                    |      |                   |      |                   |     |\n"
                    "|     |  o  o  o  o  o  o  |      |                   |      |                   |     |\n"
                    "|     |                    |      |                   |      |                   |     |\n"
                    "|     |  o  o  o  o  o  o  |      |                   |      |                   |     |\n"
                    "|     |                    |      |                   |      |                   |     |\n"
                    "|     |  o  o  o  o  o  o  |      |                   |      |                   |     |\n"
                    "|     |                    |      |                   |      |                   |     |\n"
                    "|     |  o  o  o  o  o  o  |      |                   |      |                   |     |\n"
                    "|     |                    |      |                   |      |                   |     |\n"
                    "|     +--------------------+      +-------------------+      +-------------------+     |\n"
                    "|                                                                                      |\n"
                    "|       Dificuldade: 1/11          Dificuldade: 5/11          Dificuldade: 11/11       |\n"
                    "|                                                                                      |\n"
                    "|      Um guerreiro covarde        Um guerreiro justo         Para o verdadeiro        |\n"
                    "|        morre mil mortes,         nunca anda sozinho,        guerreiro, o maior       |\n"
                    "|      o valente apenas uma        a honra o acompanha        desafio e o chamado      |\n"
                    "|                                                                                      |\n"
                    "|                                                                                      |\n"
                    "+-------------------------------------------------------------------------------------+\n\n";

        std::cin >> choiceMap;
    }

}

#endif