#ifndef animations
#define animations
#include <cstdlib>


namespace animations {

  void animation_rules() {

    clear_console();

    std::string animatedRule[] = {
        "  .________________________________________.    ",
        " / \\                                        \\ ",
        "|   |             Bombed Core               |   ",
        "`.__|                                       |   ",
        "    |                                       |   ",
        "    |      Desenvolvido por:                |   ",
        "    |      > Eduardo Lechinski Ramos        |   ",
        "    |      > Jonatas Regis Hellmann         |   ",
        "    |      > Leonardo De Borba Cardoso      |   ",
        "    |                                       |   ",
        "    |                                       |   ",
        "    |  .---------------------------------------.",
        "    \\_/_______________________________________/"
    };

    for (int i = 0; i < 13; i++) {
      std::cout << animatedRule[i] << std::endl;
<<<<<<< Updated upstream
      usleep(100000);
=======
      Timer::sleep(100);
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
      usleep(300000);
=======
      Timer::sleep(200);
>>>>>>> Stashed changes
    }

    std::cout << std::endl << std::endl;

    pause_console();

  }

  void animation_loser() {

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
<<<<<<< Updated upstream
      usleep(200000);
=======
      Timer::sleep(200);
>>>>>>> Stashed changes
    }

    std::cout << std::endl << std::endl;

    pause_console();

  }

  void animation_thanksforplay() {
    system("cls");
    string animation_thanksforplay[] = {
    "        _____  _            _                    _                        ",
    "       |  _  || |          (_)                  | |                       ",
    "       | | | || |__   _ __  _   __ _   __ _   __| |  ___                  ",
    "       | | | || '_ \\ | '__|| | / _` | / _` | / _` | / _ \\               ",
    "       \\ \\_/ /| |_) || |   | || (_| || (_| || (_| || (_) |              ",
    "        \\___/ |_.__/ |_|   |_| \\__, | \\__,_| \\__,_| \\___/            ",    
    "                                __/ |                                     ",
    "                               |___/                                      ",
    "                            ___                             _             ",
    "                           |_  |                           | |            ",
    "     _ __    ___   _ __      | |  ___    __ _   __ _  _ __ | |            ",
    "    | '_ \\  / _ \\ | '__|     | | / _ \\  / _` | / _` || '__|| |         ",
    "    | |_) || (_) || |    /\\__/ /| (_) || (_| || (_| || |   |_|           ",
    "    | .__/  \\___/ |_|    \\____/  \\___/  \\__, | \\__,_||_|   (_)       ",
    "    | |                                  __/ |                            ",
    "    |_|                                 |___/                             "   
    };

    for(int i = 0; i < 16; i++){
        cout << animation_thanksforplay[i] << endl;
        Sleep(200);
    }
    cout << endl << endl;
}

}


#endif