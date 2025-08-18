#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount() { balance = 0; }
    BankAccount(double balance) { this->balance = balance; }
    BankAccount(const BankAccount &acc) { balance = acc.balance; }
    friend ostream &operator<<(ostream &out, BankAccount &acc);
    void deduct(double amount)
    {
        if (amount > 0 && amount < balance)
            this->balance -= amount;
    }
};
ostream &operator<<(ostream &out, BankAccount &acc)
{
    out << acc.balance << "$ ";
    return out;
}

int main()
{
    BankAccount acc1;
    cout << "Account 1: " << acc1 << endl;
    BankAccount acc2(1000);
    cout << "Account 2: " << acc2 << endl;
    BankAccount acc3(acc2);
    cout << "Account 3: " << acc3 << endl;
    acc3.deduct(200);
    cout << "After Deducting 200$" << endl;
    cout << "Account 3: " << acc3 << endl;
    cout << "Account 2: " << acc2 << endl;
    return 0;
}