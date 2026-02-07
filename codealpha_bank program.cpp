#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Transaction {
    string type;
    double amount;
};


class Account {
public:
    int accNum;
    double balance;
    vector<Transaction> history; 

    Account(int n, double b) : accNum(n), balance(b) {}

    void deposit(double amt) {
        balance += amt;
        history.push_back({"Deposit", amt}); 
    }

    void withdraw(double amt) {
        if (amt <= balance) {
            balance -= amt;
            history.push_back({"Withdraw", amt});
        } else {
            cout << "Error: Not enough money!" << endl;
        }
    }

    void showStatus() {
        cout << "Account: " << accNum << " | Balance: $" << balance << endl;
        cout << "History:" << endl;
        for (auto t : history) {
            cout << " - " << t.type << ": " << t.amount << endl;
        }
    }
};


class Customer {
public:
    string name;
    Account myAcc;

    Customer(string n, int id, double start) : name(n), myAcc(id, start) {}

    void sendMoney(double amt, Customer &receiver) {
        if (myAcc.balance >= amt) {
            myAcc.withdraw(amt);
            receiver.myAcc.deposit(amt);
            cout << "Sent $" << amt << " from " << name << " to " << receiver.name << endl;
        }
    }
};

int main() {
    Customer c1("Mohnish", 101, 500);
    Customer c2("Arjun", 102, 200);

    c1.myAcc.deposit(100);
    c1.sendMoney(250, c2); 

    cout << "\n--- Mohnish's Info ---" << endl;
    c1.myAcc.showStatus();

    cout << "\n--- Arjun's Info ---" << endl;
    c2.myAcc.showStatus();

    return 0;
}