#include <iostream>
#include <windows.h>
using namespace std;

void setConsolePosition(){
    short int cX = 0;
    short int cY = 0;
    COORD coord;
    coord.X = cX;
    coord.Y = cY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//setConsolePosition();

void hide_cursor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void animation1(){
    string animatedRule1[] = {
        "  ._________________________________________________.",
        " / \\                                                 \\",
        "|   |                    Regras                      |",
        "`.__|                                                |",
        "    |                                                |",
        "    |    > Movimento automatico, pressione WASD      |",
        "    |          para mover o seu personagem.          |",
        "    |                                                |",
        "    |    > Pressione ENTER para soltar uma bomba     |",
        "    |        no local onde esta seu personagem.      |",
        "    |                                                |",
        "    |    > Apos o jogador andar 3 vezes, a bomba     |",
        "    |         ira detonar em formato de cruz.        |",
        "    |                                                |",
        "    |    > Bombas podem destruir paredes frageis,    |",
        "    |           matar inimigos e o jogador.          |",
        "    |                                                |",
        "    |    > O jogador ganha quando acabar com todos   |",
        "    |               os inimigos do mapa.             |",
        "    |                                                |",
        "    |  .------------------------------------------------.",
        "    \\_/________________________________________________/"
    };

    for(int i = 0; i < 22; i++){
        cout << animatedRule1[i] << endl;
        Sleep(200);
    }
    cout << endl << endl;
}

void animation2(){

   char block1 = char(176), block3 = char(219);
   //char block2 = char(177);

    string linha1 = string(1, block3) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1);

    string linha2 = string(1, block1) + string(1, block3) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1);

    string linha3 = string(1, block1) + string(1, block1) + string(1, block3) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1);

    string linha4 = string(1, block1) + string(1, block1) + string(1, block1) + string(1, block3) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1);

    string linha5 = string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block3) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1);

    string linha6 = string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block3) + string(1, block1) + string(1, block1) + string(1, block1);

    string linha7 = string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block3) + string(1, block1) + string(1, block1);

    string linha8 = string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block3) + string(1, block1);

    string linha9 = string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block1) + string(1, block3);

    string frames[] = {
    linha1,
    linha2,
    linha3,
    linha4,
    linha5,
    linha6,
    linha7,
    linha8,
    linha9
    };

    for (int j = 0; j < 15; j++)
    {
        for(int i = 0; i < 9; i++){
            setConsolePosition();
            cout << frames[i];
            Sleep(100);
        }
    }
    setConsolePosition();
    cout << frames[0];
    cout << endl << endl;
}

// Vou fazer algo aqui depois
void animation3(){
    int frame[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };



    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            if (i == j - i) {
                cout << char(219);
                Sleep(10);
            } else {
                cout << "*";
                Sleep(10);
            }

        }
        cout << endl;
    }

}

void animation4(){
    char player_symbol = char(2);
    for(int i = 0; i < 4; i++){
        player_symbol = char(2);
        setConsolePosition();
        cout << "                " << player_symbol;
        
        //Arena::print_map();
        Sleep(300);
        
        player_symbol = char(120);
        setConsolePosition();
        cout << "                " <<player_symbol;
        
        //Arena::print_map()
        Sleep(300);
    }
    cout << endl << endl;
    
}

int main() {
    while (true) {
        hide_cursor();
        system("cls");
        //animation1();
        //animation2();
        //animation3();
        //animation4();
        system("pause");
    }
    return 0;
}