//
// Created by eramoss on 28/09/23.
//

#ifndef BOMBEDCORE_COORD_H
#define BOMBEDCORE_COORD_H
struct Coord{
    int X;
    int Y;

    bool operator==(Coord rhs){
        return this->X == rhs.X && this->Y == rhs.Y;
    };

    bool operator!=(Coord rhs){
        return this->X != rhs.X && this->Y != rhs.Y;
    };
};

#endif //BOMBEDCORE_COORD_H
