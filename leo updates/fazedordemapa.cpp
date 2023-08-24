#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Numero da matriz: ";
    cin >> n;
for(int i = 1; i < 4; i++){
    cout << "int map"<<i<<"[" << n << "][" << n << "] = {" << endl;
    for (int i = 0; i < n; i++) {
        cout << "{";
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                cout << "1";
            } else {
                cout << "0";
            }
            
            if (j != n - 1) { 
                cout << ", ";
            }
        }
        cout << "}";
        if (i != n - 1) {
            cout << ",";
        }
        cout << endl;
    }
    cout << "};" << endl;
}
    return 0;
}