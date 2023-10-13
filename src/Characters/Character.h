//
// Created by eramoss on 27/09/23.
//

#ifndef BOMBEDCORE_CHARACTER_H
#define BOMBEDCORE_CHARACTER_H
#include "../Coord.h"

class Character {
public:
    Character(Coord coord){coordinate = coord;};
    ~Character() = default;

    void move(int dx,int dy) {
        int newX = coordinate.X + dx;
        int newY = coordinate.Y + dy;

        coordinate.X = newX;
        coordinate.Y = newY;
    };

    Coord get_coord() const {
        return coordinate;
    };
    [[nodiscard]] bool defeated() const{
        return is_defeated;
    }
    void kill(){
        is_defeated = true;
    }
protected:
    Coord coordinate{};
    bool is_defeated = false;
};


#endif //BOMBEDCORE_CHARACTER_H