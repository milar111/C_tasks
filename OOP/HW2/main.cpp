#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class EmployeeSalaries {
private:
    double* salaries;
    size_t size;
    size_t capacity;
    string employeeName;

    void resize() {
        capacity *= 2;
        double* newSalaries = new double[capacity];
        
        for (int i = 0; i < size; i++) newSalaries[i] = salaries[i];
        
        delete[] salaries;
        salaries = newSalaries;
    }

    bool isValidSalary(double salary) const { return salary >= 910.00 && salary <= 2500.00; }

public:
    EmployeeSalaries() : size(1), capacity(10) {
        salaries = new double[capacity];
        salaries[0] = 910.00;
        employeeName = "";
    }

    EmployeeSalaries(double* salaries, size_t size, size_t capacity, const string& employeeName) {
        if (size > capacity) throw invalid_argument("size > capacity");

        this->capacity = capacity;
        this->size = size;
        this->employeeName = employeeName;
        this->salaries = new double[capacity];

        for (int i = 0; i < size; i++) {
            if (!isValidSalary(salaries[i])) {
                delete[] this->salaries;
                throw invalid_argument("salary error");
            }
            this->salaries[i] = salaries[i];
        }
    }

    EmployeeSalaries(const EmployeeSalaries& other) : size(other.size), capacity(other.capacity) {
        salaries = new double[capacity];
        for (size_t i = 0; i < size; i++) salaries[i] = other.salaries[i];
        employeeName = other.employeeName;
    }

    EmployeeSalaries& operator=(const EmployeeSalaries& other) {
        if (this != &other) {
            delete[] salaries;
            size = other.size;
            capacity = other.capacity;
            salaries = new double[capacity];
            for (size_t i = 0; i < size; i++) salaries[i] = other.salaries[i];
            employeeName = other.employeeName;
        }
        return *this;
    }

    ~EmployeeSalaries() {
        delete[] salaries;
    }

    double* getSalaries() const { return salaries; }
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    string getEmployeeName() const { return employeeName; }

    void addSalary(double salary) {
        if (!isValidSalary(salary)) throw invalid_argument("salary error");
        if (size >= capacity) {
            capacity *= 2;
            double* newSalaries = new double[capacity];
            for (size_t i = 0; i < size; i++) newSalaries[i] = salaries[i];
            delete[] salaries;
            salaries = newSalaries;
        }
        salaries[size++] = salary;
    }

    void setEmployeeName(const string& name) {
        employeeName = name;
    }
};

class Person {
protected:
    string name;
    int age;
    static int totalPeople;

public:
    Person(const string& name, int age) {
        if (!isValidName(name)) throw invalid_argument("name error");
        if (!isValidAge(age)) throw invalid_argument("age error");
        this->name = name;
        this->age = age;
        totalPeople++;
    }

    Person(const Person& other) {
        name = other.name;
        age = other.age;
        totalPeople++;
    }

    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    virtual ~Person() = default;

    string getName() const { return name; }
    int getAge() const { return age; }
    static int getTotalPeople() { return totalPeople; }
    static bool isValidName(const string& name) {return !name.empty();}
    static bool isValidAge(int age) {return age >= 0 && age <= 65;}
};

int Person::totalPeople = 0;

class Employee : public Person {
private:
    string position;
    int experience;
    EmployeeSalaries salaries;

public:
    Employee() : Person("Employee", 18), position("developer"), experience(1) {
        salaries = EmployeeSalaries();  
    }

    Employee(const string& name, int age, const string& position, int experience): Person(name, age) {
        if (!isValidPosition(position)) throw invalid_argument("position error");
        if (!isValidExperience(experience)) throw invalid_argument("experience error");

        this->position = position;
        this->experience = experience;
        salaries = EmployeeSalaries(); 
    }

    Employee(const Employee& other): Person(other), position(other.position), experience(other.experience), salaries(other.salaries) {}

    Employee& operator=(const Employee& other) {
        if (this != &other) {
            Person::operator=(other);
            position = other.position;
            experience = other.experience;
            salaries = other.salaries;
        }
        return *this;
    }

    string getPosition() const { return position; }
    int getExperience() const { return experience; }
    EmployeeSalaries& getSalaries() { return salaries; } 
    const EmployeeSalaries& getSalaries() const { return salaries; } 

    double calculateAverageSalary() const {
        double* salaryArray = salaries.getSalaries();
        size_t size = salaries.getSize();
        if (size == 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < size; i++) sum += salaryArray[i];
        return sum / size;
    }

    static bool isValidPosition(const string& position) {return !position.empty();}
    static bool isValidExperience(int experience) {return experience >= 1;}
};

class Manager : public Person {
private:
    string department;

public:
    Manager() : Person("Manager", 18), department("delivery") {}

    Manager(const string& name, int age, const string& department): Person(name, age) {
        if (!isValidDepartment(department)) throw invalid_argument("department error");
        this->department = department;
    }

    Manager(const Manager& other): Person(other), department(other.department) {}

    Manager& operator=(const Manager& other) {
        if (this != &other) {
            Person::operator=(other);
            department = other.department;
        }
        return *this;
    }

    string getDepartment() const { return department; }

    void payEmployeeByName(const string& employeeName, vector<Employee>& employees, double salary) const {
        bool found = false;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getName() == employeeName) {
                employees[i].getSalaries().addSalary(salary);
                found = true;
                break;
            }
        }
        if (!found) throw runtime_error("employee error");
    }

    static bool isValidDepartment(const string& department) {
        if (department.empty()) return false;
        return department == "delivery" || department == "marketing" || department == "sales" || department == "human resources";
    }
};




istream& operator>>(istream& in, Employee& emp) {
    string name, surname, position;
    int age, experience;
    
    in >> name >> surname >> age;
    
    position = "";
    string word;
    while (in >> word) {
        if (isdigit(word[0])) {
            experience = stoi(word);
            break;
        }
        if (!position.empty()) position += " ";
        position += word;
    }
    
    name = name + " " + surname;
    emp = Employee(name, age, position, experience);
    emp.getSalaries().setEmployeeName(name);
    return in;
}

ostream& operator<<(ostream& out, const Employee& emp) {
    out << "Name: " << emp.getName() << ", Age: " << emp.getAge() << ", Position: " << emp.getPosition() << ", Experience: " << emp.getExperience() << ", Average Salary: " << emp.calculateAverageSalary();
    return out;
}

istream& operator>>(istream& in, Manager& mgr) {
    string name, surname, department;
    int age;
    
    in >> name >> surname >> age >> department;
    
    name = name + " " + surname;
    mgr = Manager(name, age, department);
    return in;
}

ostream& operator<<(ostream& out, const Manager& mgr) {
    out << "Name: " << mgr.getName() << ", Age: " << mgr.getAge() << ", Department: " << mgr.getDepartment();
    return out;
}

class FileManager {
private:
    const string inputFileName;
    const string outputFileName;

public:
    FileManager(const string& inputFileName, const string& outputFileName): inputFileName(inputFileName), outputFileName(outputFileName) {}
    
    void readFromFile(vector<Employee>& employees, vector<Manager>& managers) {
        ifstream inputFile(inputFileName);
        if (!inputFile.is_open()) throw runtime_error("file error");

        string line;
        while (getline(inputFile, line)) {
            if (line.empty()) continue;

            istringstream iss(line);
            char type;
            iss >> type;

            if (type == 'e') {
                Employee emp;
                iss >> emp;
                employees.push_back(emp);
            }
            else if (type == 'm') {
                Manager mgr;
                string employeeName, employeeSurname;
                double salary;
                
                iss >> mgr >> employeeName >> employeeSurname >> salary;
                
                string fullEmployeeName = employeeName + " " + employeeSurname;
                
                bool managerExists = false;
                for (const auto& existingMgr : managers) {
                    if (existingMgr.getName() == mgr.getName()) {
                        managerExists = true;
                        existingMgr.payEmployeeByName(fullEmployeeName, employees, salary);
                        break;
                    }
                }
                
                if (!managerExists) {
                    mgr.payEmployeeByName(fullEmployeeName, employees, salary);
                    managers.push_back(mgr);
                }
            }
        }
    }

    void writeToFile(const vector<Employee>& employees, const vector<Manager>& managers) {
        ofstream outputFile(outputFileName);
        if (!outputFile.is_open()) throw runtime_error("file error");

        outputFile << "Total number of people: " << Person::getTotalPeople() << "\n\n";
        
        outputFile << "Employees:\n";
        for (const auto& emp : employees) outputFile << emp << "\n";

        outputFile << "\nManagers:\n";
        for (const auto& mgr : managers) outputFile << mgr << "\n";
    }
};

int main() {
    try {
        vector<Employee> employees;
        vector<Manager> managers;
        FileManager fileManager("input.txt", "output.txt");
        
        fileManager.readFromFile(employees, managers);
        fileManager.writeToFile(employees, managers);

    } catch (...) { //ws
        cout << "Error" << endl;
        return 1;
    }

    return 0;
}
