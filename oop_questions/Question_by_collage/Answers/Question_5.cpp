/*5) Assume that a bank maintains two kinds of accounts for customers, one called as savings
and the other as current account. The savings account provides compound interest and
withdrawal facilities but no cheque book facility. The current account provides cheque
book facility but no interest. Current account holders should also maintain a minimum
balance and if the balance falls below this level a service charge is imposed. Create a
class account that stores customer name, account number and type of account. From this
derive the classes cur_acct and sav_acct to make them more specific to their
requirements. Include necessary member functions in order to achieve the following
tasks:
(a) Accept the deposit from a customer and update the balance.
(b) Display the balance.
(c) Compute and deposit interest.
(d) Permit withdrawal and update the balance.
(e) Check for the minimum balance, impose penalty, necessary and update the balance.\*/
#include<iostream>
using namespace std;

class Account {
protected:
  string customerName;
  int accountNumber;
  float balance;

public:
  Account(string name, int accNumber, float initialBalance) : customerName(name), accountNumber(accNumber), balance(initialBalance) {}

  void deposit(float amount) {
    balance += amount;
    cout << "Deposit successful. Current balance: " << balance << endl;
  }

  void displayBalance() {
    cout << "Account Balance: " << balance << endl;
  }

  virtual void computeInterest() {
    cout << "No interest for this account type." << endl;
  }

  virtual void withdraw(float amount) {
    if (amount <= balance) {
      balance -= amount;
      cout << "Withdrawal successful. Current balance: " << balance << endl;
    } else {
      cout << "Insufficient funds for withdrawal." << endl;
    }
  }

  virtual void checkMinimumBalance() {
    cout << "No minimum balance check for this account type." << endl;
  }
};

class SavingsAccount : public Account {
  float interestRate;

public:
  SavingsAccount(string name, int accNumber, float initialBalance, float rate) : Account(name, accNumber, initialBalance), interestRate(rate) {}

  void computeInterest() override {
    float interest = balance * interestRate / 100;
    balance += interest;
    cout << "Interest computed and deposited. Current balance: " << balance << endl;
  }
};

class CurrentAccount : public Account {
  float minimumBalance;
  float serviceCharge;

public:
  CurrentAccount(string name, int accNumber, float initialBalance, float minBalance, float charge) : Account(name, accNumber, initialBalance), minimumBalance(minBalance), serviceCharge(charge) {}

  void withdraw(float amount) override {
    if (amount <= balance) {
      balance -= amount;
      cout << "Withdrawal successful. Current balance: " << balance << endl;
    } else {
      cout << "Insufficient funds for withdrawal." << endl;
      checkMinimumBalance();
    }
  }

  void checkMinimumBalance() override {
    if (balance < minimumBalance) {
      balance -= serviceCharge;
      cout << "Minimum balance charge applied. Current balance: " << balance << endl;
    }
  }
};

int main() {
  string name;
  int accNumber;
  float initialBalance;
  float interestRate;
  float minimumBalance;
  float serviceCharge;

  cout << "Enter customer name: ";
  getline(cin, name);

  cout << "Enter account number: ";
  cin >> accNumber;

  cout << "Enter initial balance: ";
  cin >> initialBalance;

  int accountType;
  cout << "Select account type (1 for Savings, 2 for Current): ";
  cin >> accountType;

  Account* accPtr;

  if (accountType == 1) {
    cout << "Enter interest rate for savings account: ";
    cin >> interestRate;
    accPtr = new SavingsAccount(name, accNumber, initialBalance, interestRate);
  } else if (accountType == 2) {
    cout << "Enter minimum balance for current account: ";
    cin >> minimumBalance;
    cout << "Enter service charge for current account: ";
    cin >> serviceCharge;
    accPtr = new CurrentAccount(name, accNumber, initialBalance, minimumBalance, serviceCharge);
  } else {
    cerr << "Invalid account type selected." << endl;
    return 1;
  }

  int choice;

  do {
    cout << "\nSelect operation:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Compute Interest\n";
    cout << "4. Display Balance\n";
    cout << "5. Check Minimum Balance\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        float depositAmount;
        cout << "Enter deposit amount: ";
        cin >> depositAmount;
        accPtr->deposit(depositAmount);
        break;

      case 2:
        float withdrawAmount;
        cout << "Enter withdrawal amount: ";
        cin >> withdrawAmount;
        accPtr->withdraw(withdrawAmount);
        break;

      case 3:
        accPtr->computeInterest();
        break;

      case 4:
        accPtr->displayBalance();
        break;

      case 5:
        accPtr->checkMinimumBalance();
        break;

      case 0:
        cout << "Exiting program.\n";
        break;

      default:
        cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);

  delete accPtr;

  return 0;
}

