//
// Created by eramoss on 28/09/23.
//

#include "../src/Characters/Character.h"
#include "assert.h"

class CharacterTestUtils {
public:
    CharacterTestUtils(){};
    void move(){
        Character * character_mock = new Character(Coord{1,1});
        character_mock->move(1,0);
        character_mock->move(0,1);

        assert(character_mock->get_coord().X == 2);
        assert(character_mock->get_coord().Y == 2);
    }

    void kill(){
        Character * character_mock = new Character(Coord{1,1});
        character_mock->kill();
        assert(character_mock->defeated());
    }

    void run_tests(){
        move();
        kill();
    }
};

int main() {
    CharacterTestUtils * tests = new CharacterTestUtils();
    tests->run_tests();
}