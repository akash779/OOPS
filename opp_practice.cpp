#include <iostream>
#include <conio.h>

using namespace std;

void clearScreen() {
    system("cls");
}

int main() {
    cout << "Press Enter to clear the screen." << endl;

    while (true) {
        char key = cin.get();
        if (key == '\n') { // Check if Enter was pressed
            clearScreen();
            cout << "Screen cleared!" << endl;
            break;
        }
    }

    return 0;
}
