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
    void increase_tick() {
        if (ticks_to_explode <= MAX_TICKS_TO_EXPLODE){
            ticks_to_explode++;
        }
    }
    bool enabled_to_explode(){
        return ticks_to_explode == MAX_TICKS_TO_EXPLODE;
    }
    bool explode(){
        if (enabled_to_explode()){
            ticks_to_explode = 0;
            return enabled_to_explode();
        }
        return false;
    }

    void activate(int x, int y) {
        coordinate.X = x;
        coordinate.Y = y;
        is_active = true;
    }
    bool active(){
        return is_active;
    }

    void set_coord(Coord new_coord){
        coordinate = new_coord;
    }

    Coord get_coord(){
        return coordinate;
    }
private:
    Coord coordinate;
    bool is_active=false;
    int ticks_to_explode;
};


#endif //BOMBEDCORE_BOMB_H
