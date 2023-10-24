//
// Created by jonat on 22/10/2023.
//
#include "iostream"

using namespace std;

class Makefilemap {
    void add_synbols ()
    {
        for (int i = 0; i < map.height; i++) {
            for (int j = 0; j < map.width; j++) {
                std::cout << map[i][j];
            }
            std::cout << "\n";
        };
    }

};

int main ()
{
    Makefilemap save_map;
    ofstream new_map;
    new_map.open ("mape_saved.txt");
    new_map << save_map.add_synbols();
    new_map.close ();
    return 0;
}