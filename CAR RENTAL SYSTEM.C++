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
// Rental.cpp
#include "Rental.h"
#include <iostream>

Rental::Rental(std::string customerName) : customerName(customerName) {}

void Rental::addCarToInventory(const Car& car) {
    cars.push_back(car);
}

void Rental::rentCar(int carIndex) {
    if (cars[carIndex].getAvailability()) {
        cars[carIndex].setAvailability(false);
        std::cout << "Car rented successfully!" << std::endl;
    } else {
        std::cout << "Car is not available for rent!" << std::endl;
    }
}

void Rental::returnCar(int carIndex) {
    if (!cars[carIndex].getAvailability()) {
        cars[carIndex].setAvailability(true);
        std::cout << "Car returned successfully!" << std::endl;
    } else {
        std::cout << "This car was not rented!" << std::endl;
    }
}

void Rental::listAvailableCars() const {
    std::cout << "Available cars: " << std::endl;
    for (size_t i = 0; i < cars.size(); i++) {
        if (cars[i].getAvailability()) {
            std::cout << i + 1 << ". " << cars[i].getMake() << " " 
                      << cars[i].getModel() << " (" 
                      << cars[i].getYear() << ")" << std::endl;
        }
    }
}
// main.cpp
#include <iostream>
#include "Car.h"
#include "Rental.h"

int main() {
    Rental rental("John Doe");

    Car car1("Toyota", "Corolla", 2020);
    Car car2("Honda", "Civic", 2021);

    rental.addCarToInventory(car1);
    rental.addCarToInventory(car2);

    rental.listAvailableCars();

    return 0;
}
// main.cpp
#include <iostream>
#include "Car.h"
#include "Rental.h"

int main() {
    Rental rental("John Doe");

    Car car1("Toyota", "Corolla", 2020);
    Car car2("Honda", "Civic", 2021);

    rental.addCarToInventory(car1);
    rental.addCarToInventory(car2);

    rental.listAvailableCars();

    int carToRent;
    std::cout << "Enter the car number to rent: ";
    std::cin >> carToRent;
    rental.rentCar(carToRent - 1);

    rental.listAvailableCars();

    return 0;
}
// main.cpp
#include <iostream>
#include "Car.h"
#include "Rental.h"

int main() {
    Rental rental("John Doe");

    Car car1("Toyota", "Corolla", 2020);
    Car car2("Honda", "Civic", 2021);

    rental.addCarToInventory(car1);
    rental.addCarToInventory(car2);

    rental.listAvailableCars();

    int carToRent;
    std::cout << "Enter the car number to rent: ";
    std::cin >> carToRent;
    rental.rentCar(carToRent - 1);

    rental.listAvailableCars();

    int carToReturn;
    std::cout << "Enter the car number to return: ";
    std::cin >> carToReturn;
    rental.returnCar(carToReturn - 1);

    rental.listAvailableCars();

    return 0;
}








