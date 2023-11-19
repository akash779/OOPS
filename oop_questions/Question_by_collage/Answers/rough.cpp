// //programe for clear screen
// #include <iostream>
// #include <conio.h>
// 
// using namespace std;
// 
// void clearScreen() {
//     system("cls");
//     
// }
// 
// int main() {
//     cout << "Press Enter to clear the screen." << endl;
// 
//     while (true) {
//         char key = cin.get();
//         if (key == '\n') { // Check if Enter was pressed
//             clearScreen();
//             cout << "Screen cleared!" << endl;
//             break;
//         }
//     }
// 
//     return 0;
// }



//programe to print the * line upto to the width of screen
// #include <iostream>
// #include <windows.h>
// 
// using namespace std;
// 
// int main() {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
//     GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
//     int consoleWidth = consoleInfo.dwSize.X;
// 
//     for (int i = 0; i < consoleWidth; i++) {
//         cout << '*';
//     }
// 
//     cout << endl;
// 
//     return 0;
// }


// //programe for find the ascii value of character
// #include<iostream>
// #include<conio.h>
// using namespace std;
// int main(){
// 
//     char ch;
//     ch=_getch();
//     int a=ch;
//     cout<<endl<<endl<<a;
//     return 0;
// }



#include <iostream>
#include <conio.h>
using namespace std;

string pw() {
    int i = 0;
    char ch;
    char password[11]; // Allow for a 10-character password plus the null terminator

    cout << "Password: ";
    while (1) {
        ch = _getch();

        if (ch == 13) { // Enter key
            break;
        } else if (ch == 8) { // Backspace key
            if (i > 0) {
                cout << "\b \b"; // Erase the last character on the screen
                i--;
            }
        } else {
            if (i < 10) { // Check if the password length limit is reached
                password[i] = ch;
                cout << '*'; // Display an asterisk to mask the input
                i++;
            }
        }
    }

    password[i] = '\0'; // Null-terminate the password string
    cout << endl; // Move to a new line

    return string(password);
}

int main() {
    string password = pw();
    cout << "You entered the password: " << password << endl;
    return 0;
}
