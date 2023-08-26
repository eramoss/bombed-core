#include <iostream>
#include <windows.h>

using namespace std;

void animationLoser(){
    string loseFrames[] = {
        "     _____                           _____                    ",
        "    |  __ \\                         |  _  |                   ",
        "    | |  \\/  __ _  _ __ ___    ___  | | | |__   __  ___  _ __ ",
        "    | | __  / _` || '_ ` _ \\  / _ \\ | | | |\\ \\ / / / _ \\| '__|",
        "    | |_\\ \\| (_| || | | | | ||  __/ \\ \\_/ / \\ V / |  __/| |   ",
        "     \\____/ \\__,_||_| |_| |_| \\___|  \\___/   \\_/   \\___||_|   "
    };

    for(int i = 0; i < 6; i ++){
        cout << loseFrames[i] << endl;
        Sleep(300);
    }

    cout << endl << endl;
}

void animationWinner(){
    system("cls");
    string winFrames[] = {
        "    __   __                _    _  _         _ ",
        "    \\ \\ / /               | |  | |(_)       | |",
        "     \\ V /   ___   _   _  | |  | | _  _ __  | |",
        "      \\ /   / _ \\ | | | | | |/\\| || || '_ \\ | |",
        "      | |  | (_) || |_| | \\  /\\  /| || | | ||_|",
        "      \\_/   \\___/  \\__,_|  \\/  \\/ |_||_| |_|(_)"
    };


    for(int i = 0; i < 6; i ++){
        cout << winFrames[i] << endl;
        Sleep(300);
    }
    
    cout << endl << endl;
}


int main() {
    int escolha;
    while (true) {
        system("cls");
        cout << " 1- Ganhar  2 - Perder  ? - Bipolar\n";
        cout << " Escolha: "; cin >> escolha;
        system("cls");
        if (escolha == 1){
            animationWinner();
        } else if (escolha == 2) {
            animationLoser();
        } else {
            animationWinner();
            animationLoser();
        }
        system("pause");
    }
    return 0;
}