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

// Car.cpp
#include "Car.h"

Car::Car(std::string make, std::string model, int year) 
    : make(make), model(model), year(year), isAvailable(true) {}

std::string Car::getMake() const {
    return make;
}

std::string Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

bool Car::getAvailability() const {
    return isAvailable;
}

void Car::setAvailability(bool availability) {
    isAvailable = availability;
}


