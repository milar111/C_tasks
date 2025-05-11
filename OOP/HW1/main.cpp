#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

class Operation {
protected:
    string name;
    string symbol;

public:
    Operation(const string& name, const string& symbol) {
        if (name.empty() || symbol.empty()) throw invalid_argument("empty str");
        this->name = name;
        this->symbol = symbol;
    }

    Operation(const Operation& other): Operation(other.name, other.symbol) {}

    Operation& operator=(const Operation& other) {
        if (this != &other) {
            this->name = other.name;
            this->symbol = other.symbol;
        }
        return *this;
    }

    virtual ~Operation() = default;
    virtual double execute(const double n1, const double n2) = 0;

    string getName() const { return name; }
    string getSymbol() const { return symbol; }
    void setName(const string& name) {
        if (name.empty()) throw invalid_argument("empty name");
        this->name = name;
    }
    void setSymbol(const string& symbol) {
        if (symbol.empty()) throw invalid_argument("empty symbol");
        this->symbol = symbol;
    }
};

class AddOperation : public Operation {
public:
    AddOperation(const string& name) : Operation(name, "+") {}
    AddOperation(const AddOperation& other) : Operation(other) {}
    AddOperation& operator=(const AddOperation& other) {
        if (this != &other) Operation::operator=(other);
        return *this;
    }

    double execute(const double n1, const double n2) override {
        return n1 + n2;
    }
};

class SubtractOperation : public Operation {
public:
    SubtractOperation(const string& name) : Operation(name, "-") {}
    SubtractOperation(const SubtractOperation& other) : Operation(other) {}
    SubtractOperation& operator=(const SubtractOperation& other) {
        if (this != &other) Operation::operator=(other);
        return *this;
    }

    double execute(const double n1, const double n2) override {
        return n1 - n2;
    }
};

class MultiplyOperation : public Operation {
public:
    MultiplyOperation(const string& name) : Operation(name, "*") {}
    MultiplyOperation(const MultiplyOperation& other) : Operation(other) {}
    MultiplyOperation& operator=(const MultiplyOperation& other) {
        if (this != &other) Operation::operator=(other);
        return *this;
    }

    double execute(const double n1, const double n2) override {
        return n1 * n2;
    }
};

class DivideOperation : public Operation {
public:
    DivideOperation(const string& name) : Operation(name, "/") {}
    DivideOperation(const DivideOperation& other) : Operation(other) {}
    DivideOperation& operator=(const DivideOperation& other) {
        if (this != &other) Operation::operator=(other);
        return *this;
    }

    double execute(const double n1, const double n2) override {
        if (n2 == 0) {
            throw invalid_argument("error");
        }
        return n1 / n2;
    }
};

class PowerOperation : public Operation {
public:
    PowerOperation(const string& name) : Operation(name, "**") {}
    PowerOperation(const PowerOperation& other) : Operation(other) {}
    PowerOperation& operator=(const PowerOperation& other) {
        if (this != &other) Operation::operator=(other);
        return *this;
    }

    double execute(const double n1, const double n2) override {
        return pow(n1, n2);
    }
};

class RootOperation : public Operation {
public:
    RootOperation(const string& name) : Operation(name, "V") {}
    RootOperation(const RootOperation& other) : Operation(other) {}
    RootOperation& operator=(const RootOperation& other) {
        if (this != &other) Operation::operator=(other);
        return *this;
    }

    double execute(const double n1, const double n2) override {
        if (n1 < 0 || n2 <= 0) throw invalid_argument("error");
        return pow(n1, 1. / n2);
    }
};

class Calculator {
private:
    const char* name;
    size_t numberOfSupportedOperations;
    size_t capacityForOperations;
    Operation** operations;
    static double numberOfSuccessfulCalculations;

public:
    Calculator() {
        name = new char[1];
        ((char*)name)[0] = '\0';
        numberOfSupportedOperations = 0;
        capacityForOperations = 2;
        operations = new Operation*[capacityForOperations];
    }

    Calculator(const char* name, size_t n, Operation** ops) {
        if (!name || strlen(name) == 0) throw invalid_argument("calc name empty");
        if (n <= 0) throw invalid_argument("opp > 0");

        this->name = new char[strlen(name) + 1];
        strcpy((char*)this->name, name);
        numberOfSupportedOperations = n;
        capacityForOperations = n;
        operations = new Operation*[capacityForOperations];
        
        for (int i = 0; i < n; i++) operations[i] = ops[i];
    }

    Calculator(const Calculator& other) : Calculator(other.name, other.numberOfSupportedOperations, other.operations){}

    const Calculator& operator=(const Calculator& other) {
        if (this != &other) {
            delete[] operations;
            delete[] name; 
            
            name = new char[strlen(other.name) + 1];
            strcpy((char*)name, other.name);
            numberOfSupportedOperations = other.numberOfSupportedOperations;
            capacityForOperations = other.capacityForOperations;
            operations = new Operation*[capacityForOperations];
            
            for (int i = 0; i < numberOfSupportedOperations; i++) {
                operations[i] = other.operations[i];
            }
        }
        return *this;
    }

    ~Calculator() {
        delete[] operations;
        delete[] name; 
    }

    void listSupportedOperations() const {
        for (int i = 0; i < numberOfSupportedOperations; i++) {
            cout << operations[i]->getSymbol() << " - " << operations[i]->getName() << endl;
        }
    }

    void listInputFormat() const {
        cout << "<num1>  <symbol>  <num2> ... <numN> = /n" << endl;
    }

    Calculator& addOperation(const Operation* op) {
        if (numberOfSupportedOperations >= capacityForOperations) {
            Operation** newOperations = new Operation*[capacityForOperations * 2];
            for (int i = 0; i < numberOfSupportedOperations; i++) {
                newOperations[i] = operations[i];
            }
            delete[] operations;
            operations = newOperations;
            capacityForOperations *= 2;
        }
        operations[numberOfSupportedOperations++] = (Operation*)op;
        return *this;
    }

    void startCalculation() {
        const int MAX_OPERATIONS = 200;
        double numbers[MAX_OPERATIONS];
        string operators[MAX_OPERATIONS];
        int numCount = 0;
        int opCount = 0;
        
        cin >> numbers[numCount++];
        
        while (1) {
            string symbol;
            cin >> symbol;
            if (symbol == "=") break;
            
            operators[opCount++] = symbol;
            cin >> numbers[numCount++];
        }
        
        double result = numbers[0];
        for (int i = 0; i < opCount; i++) {
            bool opFound = false;
            for (int j = 0; j < numberOfSupportedOperations; j++) {
                if (operations[j]->getSymbol() == operators[i]) {
                    try {
                        result = operations[j]->execute(result, numbers[i + 1]);
                        opFound = true;
                        break;
                    } catch (invalid_argument) {
                        cout << "error" << endl;
                        return;
                    }
                }
            }
            if (!opFound) {
                cout << "error" << endl;
                return;
            }
        }
        cout << result << endl;
        numberOfSuccessfulCalculations++;
    }

    static double getNumberOfSuccessfulCalculations() {
        return numberOfSuccessfulCalculations;
    }
};

double Calculator::numberOfSuccessfulCalculations = 0;

int main() {
    char calculatorName[20];
    cout << "Enter calculator's name: ";
    cin.getline(calculatorName, 20);

    int numOperations;
    cout << "Enter number of operations: ";
    cin >> numOperations;
    
    Operation** operations = new Operation*[numOperations];
    int operationsAdded = 0;
    
    while (true) {
        cout << "Enter operations: " << endl;
        operationsAdded = 0;
        
        for (int i = 0; i < numOperations; i++) {
            string symbol, name, dash;
            cin >> symbol >> dash >> name;
            
            Operation* op = nullptr;
            if (symbol == "+") {
                op = new AddOperation(name);
            } else if (symbol == "-") {
                op = new SubtractOperation(name);
            } else if (symbol == "*") {
                op = new MultiplyOperation(name);
            } else if (symbol == "/") {
                op = new DivideOperation(name);
            } else if (symbol == "**") {
                op = new PowerOperation(name);
            } else if (symbol == "V") {
                op = new RootOperation(name);
            } else {
                cout << "error" << endl;
                for (int j = 0; j < operationsAdded; j++) delete operations[j];
                i = -1;
                continue;
            }
            operations[operationsAdded++] = op;
        }
        break;
    }

    Calculator calculator(calculatorName, operationsAdded, operations);

    while (1) {
        cout << "\n1. List supported Operations" << endl;
        cout << "2. List input format" << endl;
        cout << "3. Start calculation" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                calculator.listSupportedOperations();
                break;
            case 2:
                calculator.listInputFormat();
                break;
            case 3:
                calculator.startCalculation();
                break;
            case 4:
                for (int i = 0; i < operationsAdded; i++) delete operations[i];
                delete[] operations;
                return 0;
            default:
                cout << "error" << endl;
        }
    }

    return 0;
} 