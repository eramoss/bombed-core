//
// Created by jonat on 22/10/2023.
//

#ifndef BOMBEDCORE_SAVE_GAME_H
#define BOMBEDCORE_SAVE_GAME_H

#endif //BOMBEDCORE_SAVE_GAME_H
#include "Game.h"
// precisa importar o map do "MapFromFile map";



using namespace std;
class Makefilemap {
    Makefilemap() {
        ofstream new_map;
        new_map.open ("mape_saved.txt");
        for (int i = 0; i < map.height; i++) {
            for (int j = 0; j < map.width; j++) {
                new_map << map[i][j];
            }
            new_map << "\n";
        }
        new_map.close ();
    }
private:
    Game map;
};