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

    Bomb(int blastRadius =2) : active(false), blastRadius(blastRadius) {
    }
    ~Bomb() = default;

    void activate(int x, int y) {
        coordinate.X = x;
        coordinate.Y = y;
        active = true;
    }
    bool is_active() const{
        return active;
    }

    void inactivate(){
        active = false;
    }

    int get_blast_radius() const {
        return blastRadius;
    }

    void set_coord(Coord new_coord){
        coordinate = new_coord;
    }

    Coord get_coord(){
        return coordinate;
    }
private:
    Coord coordinate = Coord {0,0};
    bool active=false;
    int blastRadius;
};


#endif //BOMBEDCORE_BOMB_H
