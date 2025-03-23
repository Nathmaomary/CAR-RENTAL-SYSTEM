// main.cpp
#include <iostream>

int main() {
    std::cout << "Welcome to the Car Rental System" << std::endl;
    return 0;
}

// Car.h
#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;
    bool isAvailable;

public:
    Car(std::string make, std::string model, int year);
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    bool getAvailability() const;
    void setAvailability(bool availability);
};

#endif

