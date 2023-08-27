#include <iostream>
#include <windows.h>
#include "animations.h"
#include "services/console_helpers.h"

namespace menu {

    int choiceMenu, choiceMap;

    void displayMenu(){

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
    }

    void startMenu(){

        while (true) {

            hide_cursor();

            displayMenu();

            switch (choiceMenu) {
                case 1:

                    animation::animationSelectMap(choiceMap);
                    //switch escolha do mapa
                    //system cls
                    //game::run_game

                case 2:

                    animation::animationRules();

                case 3:
                    // animação de saída
                    break;
                default:
                    std::cout << "[ERROR]" << std::endl;
                    system("pause");
                
            }
        }

    }


}