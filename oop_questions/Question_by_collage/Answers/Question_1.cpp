/* 1) Define a class to represent a bank account. Include the following members:
Data members: 1. Name of the depositor. 2. Account number. 3. Type of account. 4.
Balance amount in the account.
Member functions: 1. To assign initial values. 2. To deposit an amount. 3. To withdraw an
amount after checking the balance. 4. To display the name and balance.
Write a main program to test the program. */

#include <iostream> //boiler plate for input output stream
// #include <stdlib.h>//boiler plate for use clear command ((1.) 'cin.get()' -clear screen by pressing any key  (2.)'system("CLS")' -clear screen without pressing any key )
#include <string.h>  //boiler plate for use string
#include <conio.h>   //boiler plate for use _getch() function
#include <windows.h> //boiler plate help to create line on console by providing width of console.
using namespace std;

class bank_account // create a class
{
private: // access specifier for data members
    // declare data members
    string accname; // name of account holder
    int accnum;     // account number
    string acct;    // account type
    int accbal;     // account balance
    string pwd;     // account password

public: // access specifier for data function
    // declare data function
    void acc_det(int acc_num);
    void depo();
    void bal();
    void wdr();

    // function to access private data members
    void set_acc_det(string acc_name, int acc_num, char acc_t, int acc_bal, string pwd_)
    {
        accname = acc_name;
        cout << "acc name success" << endl;
        accnum = acc_num;
        cout << "acc num success" << endl;
        accbal = acc_bal;
        cout << "acc bal success" << endl;
        acct = acc_t;
        cout << "acc t success" << endl;
        pwd = pwd_;
        cout << "acc pwd success" << endl;
    }
    void set_depo(int amount_depo) { accbal = accbal + amount_depo; }

    int set_wdr(string user, string pass, int wdrammount)
    {
        int balance;
        if (user == accname && pass == pwd)
        {
            if (accbal > wdrammount)
            {
                balance = accbal - wdrammount;
                accbal = balance;
                cout << "Amount: " << wdrammount << "Withdraw Successfully.";
                cout << endl
                     << "Remaning Balance" << balance;
            }
            else
            {
                cout << "Insufficent Fund";
            }
        }

        return balance;
    }

    int get_bal(string user, string pass)
    {
        int balance;
        if (user == accname && pass == pwd)
        {
            balance = accbal;
        }
        cout << "code is here" << balance;
        return balance;
    }
};
// function to clear screen when press enter
void enter_clr()
{
    cout << "Press Enter TO Save...";
    while (true)
    {
        char key = cin.get();
        if (key == '\n')
        { // Check if Enter was pressed
            system("cls");

            break;
        }
    }
} // function to clear screen after user

// function to create line on console
void line()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    int consoleWidth = consoleInfo.dwSize.X;

    for (int i = 0; i < consoleWidth; i++)
    {
        cout << '*';
    }

    cout << endl;
}

// function to enter password and show * on console when enter password
string pw()
{
    int i;
    char ch; // integer i for loop and character ch for enter password
    i = 0;
    char password[10];
    cout << endl
         << "Password At Least Have 4 Characters: ";
    while (1)
    {
        ch = _getch(); // input single character
        if (ch == 13)
        {
            break;
        } // 8 is ascii value of backspace
        else if (i > 8)
        {
            cout << " ";
        }
        if (ch == 8 || i > 8)
        {
            if (i > 0)
            {
                cout << "\b \b";
                i--;
            }
        } //"\b\b" is used to delete one printed value on console
        else
        {
            password[i] = ch;
            cout << "*";
            i++;
        }
    }
    password[i] = '\0';
    return string(password);
}

// defination of data function
void bank_account::acc_det(int acc_num)
{
    acc_num = acc_num + 1; //+1 in account number for 1 base indexing
    cout << "Enter Name Of Account Holder: ";
    string acc_name;
    cin >> acc_name;
    enter_clr();

    cout << endl
         << "Type Of Acc... " << endl
         << "Enter 's' For saving & 'c' For Current Account: " << endl;
    char acc_t;
    cin >> acc_t;
    enter_clr();

    cout << endl
         << "Name Of Acc. Holder: " << acc_name << endl
         << "Acc. Number: " << acc_num << endl;
    cout << "Enter Balance Amount: ";
    int acc_bal;
    cin >> acc_bal;
    cout << "Initial Amount Deposited: ";
    enter_clr();

    cout << endl
         << "Account Created Successfully....";

    cout << endl
         << endl
         << "Set Password For Acc: ";
    string acc_pwd = pw();

    set_acc_det(acc_name, acc_num, acc_t, acc_bal, acc_pwd); // data send using function then it stored to class data member because private data members can not accessable from outside of class in which they created

    cout << endl
         << endl
         << endl
         << "Press Enter Save Data.....";
    enter_clr();
}

void bank_account::depo()
{
    cout << endl
         << "Enter Deposit Amount: ";
    int amount_depo;
    cin >> amount_depo;
    set_depo(amount_depo);
}

void bank_account::bal()
{
    cout << "Enter Account Holder Name Or Account Number:  ";
    string user;
    cin >> user;
    cout << endl
         << "Enter Password: ";
    string pass;
    cin >> pass;

    // call get_bal function from class to show balance
    cout << "Balance: " << get_bal(user, pass);
}

void bank_account::wdr()
{

    cout << "Enter Account Holder Name Or Account Number:  ";
    string user;
    cin >> user;
    cout << endl
         << "Enter Password: ";
    string pass;
    cin >> pass;
    cout << "Enter Withdrawl Amount: ";
    int wdramount;
    cin >> wdramount;
    set_wdr(user, pass, wdramount);
}
int main()
{
    cout << "Welcome To Apna Bank";
    bank_account accounts[10];
    int noa = 0; // number of accounts
    int option;
    while (option != 27) //'\e' is character to represent escape button
    {
        cout << endl
             << "Press 1 For Create A New Account";
        cout << endl
             << "press 2 For Check Balance";
        cout << endl
             << "Press 3 For Deposite Amount";
        cout << endl
             << "Press 4 For Withdraw Amount";
        cout << endl
             << endl
             << endl
             << endl;
        line();
        cout << endl
             << "Press Escape to Clear Screen";
        cin >> option;
        system("cls");
        if (option == 1)
        {
            accounts[noa].acc_det(noa);
            noa++;
        }
        else if (option == 2)
        {
            int acc_num;
            cout << "Enter Your Account Number: ";
            cin >> acc_num;
            accounts[acc_num].bal();
        }
        else if (option == 3)
        {
            int acc_num;
            cout << "Enter Your Account Number: ";
            cin >> acc_num;
            accounts[acc_num].depo();
        }
        else if (option == 4)
        {
            int acc_num;
            cout << "Enter Your Account Number: ";
            cin >> acc_num;
            accounts[acc_num].wdr();
        }
    }

    return 0;
}
