#include <bits/stdc++.h>
using namespace std;
class BankAccount
{
private:
    long long accountNumber;
    string ownerName;
    vector<Transaction> transactions;
protected:
    double balance;

    void addTransaction(double amount, string type)
    {
        transactions.push_back(Transaction(amount, type));
    }
public:
    BankAccount(long long acc, string ow, double b) : accountNumber(acc), ownerName(ow), balance(b) {}
    string getOwnerName()
    {
        return ownerName;
    }
    long long getAccountNumber()
    {
        return accountNumber;
    }
    double getBalance()
    {
        return balance;
    }
    virtual bool withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
           addTransaction(amount, "Withdrawal");
            return true;
        }
        return false;
    }
    bool deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        addTransaction(amount, "deposit");
            return true;
        }
        return false;
    }
    virtual void displayInfo()
    {
        cout << "Name: " << getOwnerName() << endl
             << "number of your account: " << getAccountNumber() << endl
             << "balance: " << getBalance() << endl;
    }
    void displayTransactions() const
    {
            cout << "\n===== Transaction History =====\n";

            if (transactions.empty())
            {
                cout << "No transactions yet.\n";
                return;
            }

            for (const Transaction& transaction : transactions)
            {
                transaction.display();
                cout << "----------------------\n";
            }
    }
    bool operator==(const BankAccount &other) const 
    {
        return accountNumber == other.accountNumber;
    }
    void operator+=(double amount)
    {
        deposit(amount);
    }
    void operator-=(double amount)
    {
        withdraw(amount);
    }
    friend ostream &operator<<(ostream &out , const BankAccount&account);
    virtual ~BankAccount() = default;
};
ostream& operator<<(ostream& out, const BankAccount& account)
{
    out << "Account Number: "
        << account.accountNumber << endl;

    out << "Owner: "
        << account.ownerName << endl;

    out << "Balance: "
        << account.balance << endl;

    return out;
}
class Bank
{
private:
    vector<BankAccount> accounts;
public:
    void addAccount(long long accountNumber, string ownerName, double balance)
    {
        BankAccount account(accountNumber, ownerName, balance);
        accounts.push_back(account);
    }
    void displayAccounts()
    {
        for (BankAccount &account : accounts)
        {
            account.displayInfo();
        }
    }
    BankAccount *findAccount(long long accountNumber)
    {
        {
            for (int i = 0; i < accounts.size(); ++i)
            {
                if (accounts[i].getAccountNumber() == accountNumber)
                {

                    return &accounts[i];
                }
            }
            return nullptr;
        }
    }
    bool deposit(long long accountNumber, double amount)
    {
        BankAccount *account = findAccount(accountNumber);
        if (account != nullptr)
        {
            return account->deposit(amount);
        }
        return false;
    }
     bool  withdraw(long long accountNumber, double amount)
    {
        BankAccount *account = findAccount(accountNumber);
        if (account != nullptr)
        {
            return account->withdraw(amount);
        }
        return false;
    }
    bool transfer(long long formAccount, long long toAccount, double amount)
    {
        BankAccount *sender = findAccount(formAccount);
        BankAccount *receiver = findAccount(toAccount);
        if (sender == nullptr || receiver == nullptr)
            return false;
        else if (formAccount == toAccount)
            return false;
        else if (sender->withdraw(amount) == false)
            return false;
        receiver->deposit(amount);
        return true;
    }
    bool deleteAccount(long long accountNumber)
    {
        for (int i = 0; i < accounts.size(); ++i)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                accounts.erase(accounts.begin() + i);
                return true;
            }
        }
        return false;
    }
};
class SavingsAccount : public BankAccount
{
private:
    double interestRate;
public:
    SavingsAccount(long long accountNumber, string ownerName, double balance, double interestRate) : BankAccount(accountNumber, ownerName, balance), interestRate(interestRate) {}
    double calculateInterest()
    {
        return getBalance() * interestRate;
    }
    void displayInfo() override
    {
        cout << "AccountNumber: " << getAccountNumber() << endl
             << "Owner: " << getOwnerName() << endl
             << "Balance: " << getBalance() << endl
             << "AccountType: Savings" << endl
             << "interestRate: " << interestRate * 100 << "%" << endl;
    }
};
class CurrentAccount : public BankAccount
{
private:
    double overdraftLimit;
public:
    CurrentAccount(long long accountNumber, string ownerName, double balance, double overdraftLimit) : BankAccount(accountNumber, ownerName, balance), overdraftLimit(overdraftLimit) {}
    bool withdraw(double amount) override
    {
        if (amount <= 0)
            return false;
        if (amount <= getBalance() + overdraftLimit)
        {
            balance -= amount;
            addTransaction(amount, "withdraw");
            return true;
        }
        return false;
    }
    void displayInfo() override
    {
        cout << "AccountNumber: " << getAccountNumber() << endl
             << "Owner: " << getOwnerName() << endl
             << "Balance: " << getBalance() << endl
             << "AccountType: Current" << endl
             << "overdraftLimit: " << overdraftLimit << endl;
    }
};
class Transaction 
{
private:
    double amount;
    string type;
public:
    Transaction(double a , string t) : amount(a) , type(t){}
    double getAmount() const
    {
        return amount;
    }
    string getType() const 
    {
        return type;
    }
    void display() const 
    {
        cout<<"Type: "<<type<<endl
        <<"Amount: "<<amount<<endl;
    }
};

