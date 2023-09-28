//
// Created by eramoss on 27/09/23.
//

#ifndef BOMBEDCORE_ENEMYMIRROR_H
#define BOMBEDCORE_ENEMYMIRROR_H

#include "Character.h"

class EnemyMirror: public Character{
public:
    void mirroring(int dx_player_move, int dy_player_move) {
        move(dx_player_move,dy_player_move);
    }
};


#endif //BOMBEDCORE_ENEMYMIRROR_H
