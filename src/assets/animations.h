#ifndef animations
#define animations
#include <cstdlib>
#include "../services/console.h"
#include "../services/Timer.h"

namespace animations {
    void animation_rules() {
        clear_console();
        std::string animatedRule[] = {
                "  ._________________________________________________.    ",
                " / \\                                                 \\ ",
                "|   |                    Regras                      |   ",
                "`.__|                                                |   ",
                "    |                                                |   ",
                "    |    > Use WASD para mover o seu personagem.     |   ",
                "    |                                                |   ",
                "    |    > Pressione B para usar a bomba.            |   ",
                "    |      Ela explodirá após 3 segundos.            |   ",
                "    |                                                |   ",
                "    |    > Derrote todos os inimigos para ganhar.    |   ",
                "    |                                                |   ",
                "    |    > Os poderes podem aumentar a bomba ou      |   ",
                "    |      permitir a passagem entre obstáculos.     |   ",
                "    |                                                |   ",
                "    |    > Pressione P para salvar o jogo e Q        |   ",
                "    |      para voltar ao menu inicial.              |   ",
                "    |                                                |   ",
                "    |               Desenvolvido por:                |   ",
                "    |                                                |   ",
                "    |    > Eduardo Ramos Lechinski                   |   ",
                "    |    > Jonatas Regis Hellman                     |   ",
                "    |    > Leonardo de Borba Cardoso                 |   ",
                "    |                                                |   ",
                "    |                                                |   ",
                "    |  .------------------------------------------------.",
                "    \\_/________________________________________________/"
        };

        for (int i = 0; i < 27; i++) {
            std::cout << animatedRule[i] << std::endl;
            Timer::sleep(300);
        }
        std::cout << std::endl << std::endl;
        pause_console();
    }

    void animation_winner() {

        clear_console();

        std::string animated_win[] = {
                "__   __                _    _  _         _ ",
                "\\ \\ / /               | |  | |(_)       | |",
                " \\ V /   ___   _   _  | |  | | _  _ __  | |",
                "  \\ /   / _ \\ | | | | | |/\\| || || '_ \\ | |",
                "  | |  | (_) || |_| | \\  /\\  /| || | | ||_|",
                "  \\_/   \\___/  \\__,_|  \\/  \\/ |_||_| |_|(_)"
        };

        for (int i = 0; i < 6; i++) {
            std::cout << animated_win[i] << std::endl;
            Timer::sleep(300);
        }

        std::cout << std::endl << std::endl;

        pause_console();

    }

    void animations_loser() {

        clear_console();

        std::string animated_lose[] = {
                "     _____                           _____                    ",
                "    |  __ \\                         |  _  |                   ",
                "    | |  \\/  __ _  _ __ ___    ___  | | | |__   __  ___  _ __ ",
                "    | | __  / _` || '_ ` _ \\  / _ \\ | | | |\\ \\ / / / _ \\| '__|",
                "    | |_\\ \\| (_| || | | | | ||  __/ \\ \\_/ / \\ V / |  __/| |   ",
                "     \\____/ \\__,_||_| |_| |_| \\___|  \\___/   \\_/   \\___||_|   "
        };

        for (int i = 0; i < 6; i++) {
            std::cout << animated_lose[i] << std::endl;
            Timer::sleep(300);
        }

        std::cout << std::endl << std::endl;

        pause_console();

    }

}


#endif