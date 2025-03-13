#include <iostream>
#include <cstring> 

using namespace std;

class Wagon {
private:
    int horsePower;
    char* licensePlate;
    int wheelsCount;

public:

    Wagon(int hp, const char* plate, int wheels) : horsePower(hp), wheelsCount(wheels) {
        licensePlate = new char[strlen(plate) + 1];
        strcpy(licensePlate, plate);
    }

    ~Wagon() {
        delete[] licensePlate;
    }

    int getHorsePower() {
        return horsePower;
    }
    const char* getLicensePlate(){
        return licensePlate; 
    }
    int getWheelsCount(){
        return wheelsCount;
    }

    void setHorsePower(int hp){
        horsePower = hp;
    }

    void setWheelsCount(int wheels) {
        wheelsCount = wheels;
    }
    
    void setLicensePlate(const char* plate) {
        delete[] licensePlate;
        licensePlate = new char[strlen(plate) + 1];
        strcpy(licensePlate, plate);
    }
};

int main() {
    std::cout << "Hello World" << std::endl;
    return 0;
}
