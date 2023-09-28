//
// Created by eramoss on 27/09/23.
//

#ifndef BOMBEDCORE_CHARACTER_H
#define BOMBEDCORE_CHARACTER_H
struct Coord{
    int X;
    int Y;
};


class Character {
public:
    Character() = default;
    ~Character() = default;

    void move(int dx,int dy) {
        int newX = coordinate.X - dx;
        int newY = coordinate.Y - dy;

        coordinate.X = newX;
        coordinate.Y = newY;
    };

    Coord get_coord(){
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