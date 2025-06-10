
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Drink {
  string name;
  double price;

public:
  Drink() {
    name = "";
    price = 0.0;
  }

  friend istream &operator>>(istream &in, Drink &drink) {
    string name;
    double price;

    in >> name >> price;

    if (name == "" || price < 0) {
      throw invalid_argument("Invlaid drink input");
    }

    drink.name = name;
    drink.price = price;

    return in;
  }

  string getName() const { return name; }

  double getPrice() const { return price; }
};

class Receipt {
  int id;
  double amount;
  vector<Drink> drinks;

public:
  Receipt() {
    id = 1;
    amount = 1.0;
    drinks = vector<Drink>();
    drinks.push_back(Drink());
  }

  virtual ~Receipt() { drinks.clear(); }

  double calculateReceiptAmount() const {
    double total = 0.0;

    for (int i = 0; i < drinks.size(); i++) {
      total +=
          drinks[i].getPrice(); // same as total += drinks.at(i).getPrice();
    }

    return total;
  }

  virtual double calculateTipAmount() const = 0;

  bool hasReceiptBeenPaid() const { return amount >= calculateReceiptAmount(); }

  friend istream &operator>>(istream &in, Receipt *slip) {
    int id;
    double amount;
    vector<Drink> drinks = vector<Drink>();

    in >> id >> amount;

    while (true) {
      string line;
      getline(in, line);

      if (line == "-----------------------") {
        break;
      }

      istringstream ss(line);
      Drink drink;
      ss >> drink;
      drinks.push_back(drink);
    }

    if (id <= 0 || amount < 0 || drinks.size() == 0) {
      throw invalid_argument("Invlaid receipt input");
    }

    slip->id = id;
    slip->amount = amount;
    slip->drinks = drinks;

    return in;
  }

  int getId() const { return id; }

  double getAmount() const { return amount; }

  vector<Drink> getDrinks() const { return drinks; }
};

class PubReceipt : public Receipt {
public:
  double calculateTipAmount() const { return calculateReceiptAmount() * 0.15; }
};

class ClubReceipt : public Receipt {
public:
  double calculateTipAmount() const { return calculateReceiptAmount() * 0.25; }
};

class Client {
  vector<Receipt *> receipts;

public:
  Client(vector<Receipt *> receipts) {
    this->receipts = vector<Receipt *>();
    for (int i = 0; i < receipts.size(); i++) {
      this->receipts.push_back(receipts[i]);
    };
  }

  ~Client() {
    for (int i = 0; i < receipts.size(); i++) {
      delete receipts[i];
    }
  }

  double calculateTotalSuccessfullySpentMoney() const {
    double total = 0.0;

    for (int i = 0; i < receipts.size(); i++) {
      if (receipts[i]->hasReceiptBeenPaid()) {
        total += receipts[i]->calculateReceiptAmount();
        // ? + tipAmount ?
      }
    }

    return total;
  }
};

int main() {
  vector<Receipt *> receipts;
  ifstream file("receipts.txt", ios::in);

  if (!file.is_open()) {
    throw invalid_argument("File not found!");
  }

  while (!file.eof()) {
    string line;
    file >> line;
    if (line == "Pub") {
      PubReceipt *pub = new PubReceipt();
      file >> pub;
      receipts.push_back(pub);
    } else if (line == "Club") {
      ClubReceipt *club = new ClubReceipt();
      file >> club;
      receipts.push_back(club);
    }
  }

  Client client(receipts);

  cout << "Total successfully spent money:"
       << client.calculateTotalSuccessfullySpentMoney() << " BGN" << endl;

  file.close();
  return 0;
}