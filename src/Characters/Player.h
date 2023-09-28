//
// Created by eramoss on 27/09/23.
//

#ifndef BOMBEDCORE_PLAYER_H
#define BOMBEDCORE_PLAYER_H

#include "Character.h"
#include "../Bomb.h"

class Player: public Character {
public:
    Player(int x, int y){
        coordinate = Coord {
            x,y
        };
    };
    ~Player() = default;

    bool put_bomb(){
        if(bomb.active()){
            return false;
        }
        bomb.activate(coordinate.X, coordinate.Y);
        return true;
    }
private:
    Bomb bomb;
};

#endif //BOMBEDCORE_PLAYER_H
