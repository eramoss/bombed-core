#include <fstream>
#include <iostream>
#include "saveGame.h"

class MapFromFile {
public:
    MapFromFile(const std::string &filename) {
        std::ifstream file(filename);
        std::string line;
        height = 0;
        width = 0;

        if (getline(file, line)) { // lê a primeira linha
            width = line.size(); // define a largura do mapa pela quantidade de char da linha
            ++height; // conta +1 para a altura da linha que foi lida
            while (getline(file, line)) {
                ++height; // conta a altura até acabar as linhas
            }
        }

        map = new std::string *[height]; // alocação dinâmica para a altura

        for (int i = 0; i < height; i++) {
            map[i] = new std::string [width]; // alocação dinâmica para a largura
        }

        file.clear();
        file.seekg(0, std::ios::beg); // volta pra primeira linha ??
        for (int i = 0; i < height && getline(file, line); i++) {
            for (int j = 0; j < width; j++) {
                map[i][j] = line[j]; // loop para preencher a matriz
            }
        }
        file.close();
    }

    ~MapFromFile() { // destruct do gamemap ??
        for (int i = 0; i < height; i++) {
            delete[] map[i];
        }
        delete[] map;
    }

    void print() { // mostrar o mapa
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << map[i][j];
            }
            std::cout << std::endl;
        }
    }

    int height;
    int width;
    std::string **map;
};
