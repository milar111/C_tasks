#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Account {
protected:
    double* withdraws;
    int numberOfWithdraws;
    double* deposits;
    int numberOfDeposits;
public:
    Account() : withdraws(nullptr), numberOfWithdraws(0), deposits(nullptr), numberOfDeposits(0) {}

    Account(double* withdraws, size_t numberOfWithdraws, double* deposits, size_t numberOfDeposits) {
        this->numberOfWithdraws = numberOfWithdraws;
        this->numberOfDeposits = numberOfDeposits;
        this->withdraws = new double[numberOfWithdraws];
        this->deposits = new double[numberOfDeposits];
        
        for(int i = 0; i < numberOfWithdraws; i++) this->withdraws[i] = withdraws[i];
        for(int i = 0; i < numberOfDeposits; i++) this->deposits[i] = deposits[i];

    }

    Account(const Account &other) {
        numberOfWithdraws = other.numberOfWithdraws;
        numberOfDeposits = other.numberOfDeposits;
        withdraws = new double[numberOfWithdraws];
        deposits = new double[numberOfDeposits];
        
        for(int i = 0; i < numberOfWithdraws; i++) withdraws[i] = other.withdraws[i];
        for(int i = 0; i < numberOfDeposits; i++) deposits[i] = other.deposits[i];
    }

    Account &operator=(const Account &other) {
        if(this != &other) {
            delete[] withdraws;
            delete[] deposits;
            
            numberOfWithdraws = other.numberOfWithdraws;
            numberOfDeposits = other.numberOfDeposits;
            withdraws = new double[numberOfWithdraws];
            deposits = new double[numberOfDeposits];
            
            for(int i = 0; i < numberOfWithdraws; i++) withdraws[i] = other.withdraws[i];
            for(int i = 0; i < numberOfDeposits; i++) deposits[i] = other.deposits[i];
        }
        return *this;
    }

    virtual double getBalance() const = 0;

    ~Account() {
        delete[] withdraws;
        delete[] deposits;
    }
   
    friend ostream& operator<<(ostream& os, const Account& a) {
        os << "Balance: " << a.getBalance();
        return os;
    }
    
    friend istream& operator>>(istream& is, Account& a) {
        is >> a.numberOfWithdraws;
        a.withdraws = new double[a.numberOfWithdraws];
        for(int i = 0; i < a.numberOfWithdraws; i++) is >> a.withdraws[i];
        
        is >> a.numberOfDeposits;
        a.deposits = new double[a.numberOfDeposits];
        for(int i = 0; i < a.numberOfDeposits; i++) is >> a.deposits[i];
        return is;
    }
};

class BankAccount : public Account {
    string iban;
    string accountHolder;

public:
    BankAccount(const string &IBAN, const string &accountHolder) {
        if (IBAN.empty() || accountHolder.empty()) throw invalid_argument("empty str");
        this->iban = IBAN;
        this->accountHolder = accountHolder;
    }

    BankAccount(const BankAccount &other): BankAccount(other.iban, other.accountHolder) {}

    BankAccount &operator=(const BankAccount &other) {
        if(this != &other) {
            Account::operator=(other);
            iban = other.iban;
            accountHolder = other.accountHolder;
        }
        return *this;
    }

    double getBalance() const {
        double totalDeposits = 0;
        double totalWithdraws = 0;
        
        for(int i = 0; i < numberOfDeposits; i++) totalDeposits += deposits[i];
        for(int i = 0; i < numberOfWithdraws; i++) totalWithdraws += withdraws[i];
        return totalDeposits - totalWithdraws;
    }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "error" << endl;
        return 1;
    }
    BankAccount account("BG3213123213", "Daniel Yordanov");

    inputFile >> account;
    outputFile << account << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}
