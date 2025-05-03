#include <iostream>
using namespace std;

class Account
{
// private:
protected:
    double* withdraws;
    int numberOfWithdraws;
    double* deposits;
    int numberOfDeposits;
    static int numberOfActiveAccounts;

public:
    Account() {
        withdraws = new double[1];
        deposits = new double[1];
        numberOfWithdraws = 0;
        numberOfDeposits = 0;
        numberOfActiveAccounts++;
    }

    Account(double balance, double *withdraws, size_t numberOfWithdraws, double *deposits, size_t numberOfDeposits) {
        this->withdraws = new double[numberOfWithdraws];

        for (size_t i = 0; i < numberOfWithdraws; i++) {
            this->withdraws[i] = withdraws[i];  
        }

        this->numberOfWithdraws = numberOfWithdraws;

        this->deposits = new double[numberOfDeposits];

        for (size_t i = 0; i < numberOfDeposits; i++) {
            this->deposits[i] = deposits[i];
        }

        this->numberOfDeposits = numberOfDeposits;
        numberOfActiveAccounts++;
    }

    Account(const Account &other) {
        this->withdraws = new double[other.numberOfWithdraws];

        for (int i = 0; i < other.numberOfWithdraws; i++) {
            this->withdraws[i] = other.withdraws[i];
        }
        this->numberOfWithdraws = other.numberOfWithdraws;
        this->deposits = new double[other.numberOfDeposits];

        for (int i = 0; i < other.numberOfDeposits; i++) {
            this->deposits[i] = other.deposits[i];
        }
        this->numberOfDeposits = other.numberOfDeposits;
        
        numberOfActiveAccounts++;
    }

    Account &operator=(const Account &other) {
        if (this!= &other) {
            
            delete[] withdraws;
            delete[] deposits;

            this->withdraws = new double[other.numberOfWithdraws];

            for (int i = 0; i < other.numberOfWithdraws; i++) {
                this->withdraws[i] = other.withdraws[i];
            }
            this->numberOfWithdraws = other.numberOfWithdraws;
            this->deposits = new double[other.numberOfDeposits];

            for (int i = 0; i < other.numberOfDeposits; i++) {
                this->deposits[i] = other.deposits[i];
            }
            this->numberOfDeposits = other.numberOfDeposits;
            
            // numberOfActiveAccount++;
        }
        return *this;
    }

    double getBalance() const {
        double balance= 0;

        for (int i = 0; i < numberOfDeposits; i++) {
            balance += deposits[i];
        }

        for (int i = 0; i < numberOfWithdraws; i++) {
            balance -= withdraws[i];
        }
        return balance;
    }
    
    void printAccountInformation() const {
        //  <balance> <numberOfDeposits> <numberOfWithdraws>
        cout << getBalance() << " " << numberOfDeposits << " " << numberOfWithdraws << endl;
    }


    // !!
    static int getActiveAccounts() {
        return numberOfActiveAccounts;
    }

    
    int getNumberOfDeposits() const {
        return numberOfDeposits;
    }
    int getNumberOfWithdraws() const {
        return numberOfWithdraws;
    }


    ~Account() {
        delete[] withdraws;
        delete[] deposits;
        numberOfActiveAccounts--;
    }
};

class BankAccount : public Account
{
private:
    string IBAN;
    string accountHolder;

public:
    BankAccount(const string &IBAN, const string &accountHolder) : Account() {
        this->IBAN = IBAN;
        this->accountHolder = accountHolder;
    }

    BankAccount(const BankAccount &other) : Account(other) {
        this->IBAN = other.IBAN;
        this->accountHolder = other.accountHolder;
    }

    BankAccount &operator=(const BankAccount &other) {
        if (this != &other) {

            this->IBAN = other.IBAN;
            this->accountHolder = other.accountHolder;
        }
        return *this;
    }

    void printAccountInformation() const {
        // <IBAN> <accountHolder> <balance> <numberOfDeposits> <numberOfWithdraws> - 
        cout << IBAN << " " << accountHolder << " " << getBalance() << " " << getNumberOfDeposits() << " " << getNumberOfWithdraws() << endl;
    }
};
