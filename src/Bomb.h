//
// Created by eramoss on 27/09/23.
//

#ifndef BOMBEDCORE_BOMB_H
#define BOMBEDCORE_BOMB_H

#define MAX_TICKS_TO_EXPLODE 3
#define AMOUNT_OF_SPRITES 4

#include "services/consts.h"
#include "Coord.h"

class Bomb {
public:
    const char* sprite_animations[AMOUNT_OF_SPRITES] = { explosion, great_explosion, greater_explosion, empty_symbol };

    Bomb()=default;
    ~Bomb() = default;

    void activate(int x, int y) {
        coordinate.X = x;
        coordinate.Y = y;
        active = true;
    }
    bool is_active(){
        return active;
    }

    void inactivate(){
        active = false;
    }

    void set_coord(Coord new_coord){
        coordinate = new_coord;
    }

    Coord get_coord(){
        return coordinate;
    }
private:
    Coord coordinate = Coord {-1,-1};
    bool active=false;
};


#endif //BOMBEDCORE_BOMB_H
