//
// Created by eramoss on 27/09/23.
//

#ifndef BOMBEDCORE_ENEMYRANDOM_H
#define BOMBEDCORE_ENEMYRANDOM_H

#include "Character.h"
#include "random"

class EnemyRandom: public Character{
public:
    EnemyRandom(int x, int y){
        coordinate = Coord {
                x,y
        };
    };
    ~EnemyRandom() = default;

    Coord generate_random_move(){
        int dx, dy;
        int random_direction = rand() % 4; // Generate a random number from 0 to 3

        switch (random_direction) {
            case 0: // Up
                dx = 0;
                dy = -1;
                break;
            case 1: // Down
                dx = 0;
                dy = 1;
                break;
            case 2: // Left
                dx = -1;
                dy = 0;
                break;
            case 3: // Right
                dx = 1;
                dy = 0;
                break;
        }
        return Coord {
            dx,dy
        };
    }
};


#endif //BOMBEDCORE_ENEMYRANDOM_H
