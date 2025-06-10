#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Bet {
    string name;
    double coefficient;

public:
    Bet() {
        name = "";
        coefficient = 0.0;
    }

    friend istream& operator>>(istream& in, Bet& bet) {
        string name;
        double coefficient;
        in >> name >> coefficient;
        if(name == "" || coefficient < 0) throw invalid_argument("error");
        bet.name = name;
        bet.coefficient = coefficient;

        return in;
    }

    string getName() const { return name; }
    double getCoefficient() const { return coefficient; }
};

class BettingSlip {
protected:
    int id;
    double amount;
    vector<Bet> bets;

public:
    BettingSlip() {
        id = 1;
        amount = 1.0;
        bets = vector<Bet>();
        bets.push_back(Bet());
    }

    virtual ~BettingSlip() { bets.clear(); } //!

    double calculateCoefficient() const {
        double total = 1.0;
        for (int i = 0; i < bets.size(); i++) total *= bets[i].getCoefficient();
        return total;
    }

    double estimateProfitBeforeFee() const {return amount * calculateCoefficient();}

    virtual double calculateFee() const = 0;

    double calculateProfit() const {return estimateProfitBeforeFee() - calculateFee();}

    friend istream& operator>>(istream& in, BettingSlip* slip) {
        int id;
        double amount;
        vector<Bet> bets = vector<Bet>();
        in >> id >> amount;

        while (true) {
            string line;
            getline(in, line);
            istringstream ss(line);
            Bet bet;
            ss >> bet;
            bets.push_back(bet);
        }
        if (id <= 0 || amount < 0 || bets.size() == 0) throw invalid_argument("error with betting");
        slip->id = id;
        slip->amount = amount;
        slip->bets = bets;
        return in;
    }

    int getId() const { return id; }
    double getAmount() const { return amount; }
    vector<Bet> getBets() const { return bets; }
};

class FootballBettingSlip : public BettingSlip {
public:
    double calculateFee() const override {return estimateProfitBeforeFee() * 0.10;}
};

class F1BettingSlip : public BettingSlip {
public:
    double calculateFee() const override {return estimateProfitBeforeFee() * 0.15;}
};



class User {
    vector<BettingSlip*> bets;

public:
    User(vector<BettingSlip*> bets) {
        this->bets = vector<BettingSlip*>();
        for (int i = 0; i < bets.size(); i++) this->bets.push_back(bets[i]);}
    ~User() {for (int i = 0; i < bets.size(); i++) delete bets[i];}

    double calculateTotalProfit() const {
        double total = 0.0;
        for (int i = 0; i < bets.size(); i++) total += bets[i]->calculateProfit();
        return total;
    }
};




int main() {
    vector<BettingSlip*> bets;
    ifstream file("input.txt");
    if(!file.is_open()){
        throw invalid_argument("file error");
    }
    
    while (!file.eof()) {
    string line;
    file >> line;
    if (line == "Football") {
        FootballBettingSlip* football = new FootballBettingSlip();
        file >> football;
        bets.push_back(football);
    } else if (line == "F1") {
        F1BettingSlip* f1 = new F1BettingSlip();
        file >> f1;
        bets.push_back(f1);
        }
    }


    User user(bets);
    cout << "Total income: " << user.calculateTotalProfit() << " BGN" << endl;

    file.close();
    return 0;
}
