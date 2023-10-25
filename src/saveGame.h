//
// Created by eramoss on 24/10/23.
//

#ifndef BOMBEDCORE_SAVEGAME_H
#define BOMBEDCORE_SAVEGAME_H
#include "Characters/Player.h"
#include "Characters/EnemyMirror.h"
#include "Characters/EnemyRandom.h"
#include "Power.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void save_positions(Player& player, EnemyMirror& enemyM, EnemyRandom& enemyR,Power power,  Timer timer) {

    std::ofstream outFile("options.txt");

    // pega a coordenada de geral
    Coord player_coord = player.get_coord();
    Coord bomb_coord = player.get_bomb().get_coord();
    Coord enemyM_coord = enemyM.get_coord();
    Coord enemyR_coord = enemyR.get_coord();

    // escreve as coordenadas respectivas no arquivo
    outFile << "Player," << player_coord.X << "," << player_coord.Y << std::endl;
    outFile << "Bomb," << bomb_coord.X << "," << bomb_coord.Y << std::endl;
    outFile << "EnemyMirror," << enemyM_coord.X << "," << enemyM_coord.Y << std::endl;
    outFile << "EnemyRandom," << enemyR_coord.X << "," << enemyR_coord.Y << std::endl;
    outFile << "Power," << power.coord.X << "," << power.coord.Y << std::endl;
    outFile << "Timer," << timer.elapsed() << ",";

    outFile.close();
}

void load_positions(Player& player, EnemyMirror& enemyM, EnemyRandom& enemyR,Power& power,Bomb& bomb, double& timer) {

    std::ifstream inFile("options.txt");
    std::string line;

    while (std::getline(inFile, line)) {

        std::istringstream ss(line);

        std::string typeName;
        std::getline(ss, typeName, ',');

        int x, y;
        ss >> x;        //
        ss.ignore();    //  lê as coordenadas
        ss >> y;        //


        // da a coordenada respectiva de cada um
        if (typeName == "Player") {
            player.move(x - player.get_coord().X, y - player.get_coord().Y);
        } else if (typeName == "Bomb") {
            bomb.set_coord({x, y});
            if (x != 0 && y != 0) bomb.activate(x,y);
        } else if (typeName == "EnemyMirror") {
            enemyM.move(x - enemyM.get_coord().X, y - enemyM.get_coord().Y);
        } else if (typeName == "EnemyRandom") {
            enemyR.move(x - enemyR.get_coord().X, y - enemyR.get_coord().Y);
        } else if (typeName == "Timer") {
            timer = x;
        } else if (typeName == "Power") {
            power.coord.X = x;
            power.coord.Y = y;
        }
    }

    inFile.close();
}

#endif //BOMBEDCORE_SAVEGAME_H
