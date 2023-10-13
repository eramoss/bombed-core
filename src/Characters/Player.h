//
// Created by eramoss on 27/09/23.
//

#ifndef BOMBEDCORE_PLAYER_H
#define BOMBEDCORE_PLAYER_H

#include "Character.h"
#include "../Bomb.h"

class Player: public Character {
public:
    explicit Player(Coord coord) : Character(coord), bomb() {
    };
    ~Player() = default;

    bool put_bomb(){
        if(bomb.is_active()){
            return false;
        }
        bomb.activate(coordinate.X, coordinate.Y);
        return true;
    }
    Bomb & get_bomb() {
        return bomb;
    }
private:
    Bomb bomb;
};

#endif //BOMBEDCORE_PLAYER_H
