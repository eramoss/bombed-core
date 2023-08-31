#include <iostream>
#include "animations.h"
#include "../services/console_helpers.h"

namespace menu {

  int get_choice_menu() {
    int choice_menu;
    clear_console();

    std::cout << "______                    _                _ \n"
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
      " \\____/ \\___/ |_|    \\___|       Escolha: "; std::cin >> choice_menu;

    std::cout << std::endl << std::endl << std::endl;

    return choice_menu;
  }


  int select_map() {
    int choice_menu;
    do {
      clear_console();
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

      std::cin >> choice_menu;
    } while (choice_menu != 1 && choice_menu != 2 && choice_menu != 3);
    return choice_menu;
  }

}