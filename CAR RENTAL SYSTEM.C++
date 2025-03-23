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
// main.cpp
#include <iostream>
#include "Car.h"
#include "Rental.h"

void displayMenu() {
    std::cout << "\nCar Rental System\n";
    std::cout << "1. List available cars\n";
    std::cout << "2. Rent a car\n";
    std::cout << "3. Return a car\n";
    std::cout << "4. Exit\n";
}

int main() {
    Rental rental("John Doe");

    Car car1("Toyota", "Corolla", 2020);
    Car car2("Honda", "Civic", 2021);

    rental.addCarToInventory(car1);
    rental.addCarToInventory(car2);

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                rental.listAvailableCars();
                break;
            case 2: {
                int carToRent;
                std::cout << "Enter the car number to rent: ";
                std::cin >> carToRent;
                rental.rentCar(carToRent - 1);
                break;
            }
            case 3: {
                int carToReturn;
                std::cout << "Enter the car number to return: ";
                std::cin >> carToReturn;
                rental.returnCar(carToReturn - 1);
                break;
            }
            case 4:
                std::cout << "Exiting system...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
// Rental.cpp
#include "Rental.h"
#include <iostream>

void Rental::rentCar(int carIndex) {
    if (carIndex < 0 || carIndex >= cars.size()) {
        std::cout << "Invalid car number!" << std::endl;
        return;
    }
    if (cars[carIndex].getAvailability()) {
        cars[carIndex].setAvailability(false);
        std::cout << "Car rented successfully!" << std::endl;
    } else {
        std::cout << "Car is not available for rent!" << std::endl;
    }
}

void Rental::returnCar(int carIndex) {
    if (carIndex < 0 || carIndex >= cars.size()) {
        std::cout << "Invalid car number!" << std::endl;
        return;
    }
    if (!cars[carIndex].getAvailability()) {
        cars[carIndex].setAvailability(true);
        std::cout << "Car returned successfully!" << std::endl;
    } else {
        std::cout << "This car was not rented!" << std::endl;
    }
}
// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h"
#include <string>
#include <vector>

class Rental {
private:
    std::vector<Car> cars;
    std::string customerName;
    double rentalRatePerDay; // Rate per day for car rental

public:
    Rental(std::string customerName, double rentalRatePerDay);
    void addCarToInventory(const Car& car);
    void rentCar(int carIndex, int rentalDays);
    void returnCar(int carIndex);
    void listAvailableCars() const;
    double calculateRentalCost(int rentalDays) const;
};

#endif
// Rental.cpp
#include "Rental.h"
#include <iostream>

Rental::Rental(std::string customerName, double rentalRatePerDay) 
    : customerName(customerName), rentalRatePerDay(rentalRatePerDay) {}

void Rental::rentCar(int carIndex, int rentalDays) {
    if (carIndex < 0 || carIndex >= cars.size()) {
        std::cout << "Invalid car number!" << std::endl;
        return;
    }
    if (cars[carIndex].getAvailability()) {
        cars[carIndex].setAvailability(false);
        std::cout << "Car rented for " << rentalDays << " days.\n";
        std::cout << "Total rental cost: $" << calculateRentalCost(rentalDays) << std::endl;
    } else {
        std::cout << "Car is not available for rent!" << std::endl;
    }
}

double Rental::calculateRentalCost(int rentalDays) const {
    return rentalDays * rentalRatePerDay;
}
// main.cpp
#include <iostream>
#include "Car.h"
#include "Rental.h"

void displayMenu() {
    std::cout << "\nCar Rental System\n";
    std::cout << "1. List available cars\n";
    std::cout << "2. Rent a car\n";
    std::cout << "3. Return a car\n";
    std::cout << "4. Exit\n";
}

int main() {
    Rental rental("John Doe", 20.0); // $20 per day rental rate

    Car car1("Toyota", "Corolla", 2020);
    Car car2("Honda", "Civic", 2021);

    rental.addCarToInventory(car1);
    rental.addCarToInventory(car2);

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                rental.listAvailableCars();
                break;
            case 2: {
                int carToRent, rentalDays;
                std::cout << "Enter the car number to rent: ";
                std::cin >> carToRent;
                std::cout << "Enter rental days: ";
                std::cin >> rentalDays;
                rental.rentCar(carToRent - 1, rentalDays);
                break;
            }
            case 3: {
                int carToReturn;
                std::cout << "Enter the car number to return: ";
                std::cin >> carToReturn;
                rental.returnCar(carToReturn - 1);
                break;
            }
            case 4:
                std::cout << "Exiting system...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
// Rental.cpp
#include "Rental.h"
#include <iostream>

void Rental::listAvailableCars() const {
    std::cout << "Available cars:\n";
    bool availableCarsFound = false;
    for (size_t i = 0; i < cars.size(); i++) {
        if (cars[i].getAvailability()) {
            std::cout << "Car #" << i + 1 << ": " 
                      << cars[i].getMake() << " " 
                      << cars[i].getModel() << " (" 
                      << cars[i].getYear() << ")\n";
            availableCarsFound = true;
        }
    }
    if (!availableCarsFound) {
        std::cout << "No available cars at the moment.\n";
    }
}
// main.cpp
#include <iostream>
#include "Car.h"
#include "Rental.h"

void displayMenu() {
    std::cout << "\nCar Rental System\n";
    std::cout << "1. List available cars\n";
    std::cout << "2. Rent a car\n";
    std::cout << "3. Return a car\n";
    std::cout << "4. Exit\n";
}

int main() {
    Rental rental("John Doe", 20.0);

    Car car1("Toyota", "Corolla", 2020);
    Car car2("Honda", "Civic", 2021);

    rental.addCarToInventory(car1);
    rental.addCarToInventory(car2);

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid input
            std::cout << "Invalid input! Please enter a valid option.\n";
            continue;
        }

        switch(choice) {
            case 1:
                rental.listAvailableCars();
                break;
            case 2: {
                int carToRent, rentalDays;
                std::cout << "Enter the car number to rent: ";
                std::cin >> carToRent;
                std::cout << "Enter rental days: ";
                std::cin >> rentalDays;

                if (rentalDays <= 0) {
                    std::cout << "Rental days must be a positive number.\n";
                    break;
                }
                rental.rentCar(carToRent - 1, rentalDays);
                break;
            }
            case 3: {
                int carToReturn;
                std::cout << "Enter the car number to return: ";
                std::cin >> carToReturn;
                rental.returnCar(carToReturn - 1);
                break;
            }
            case 4:
                std::cout << "Exiting system...\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option (1-4).\n";
        }
    } while (choice != 4);

    return 0;
}
// Rental.cpp
#include "Rental.h"
#include <iostream>

void Rental::rentCar(int carIndex, int rentalDays) {
    if (carIndex < 0 || carIndex >= cars.size()) {
        std::cout << "Invalid car number! Please select a valid car from the list.\n";
        return;
    }
    if (cars[carIndex].getAvailability()) {
        cars[carIndex].setAvailability(false);
        std::cout << "Car rented for " << rentalDays << " days.\n";
        std::cout << "Total rental cost: $" << calculateRentalCost(rentalDays) << std::endl;
    } else {
        std::cout << "Car is not available for rent!\n";
    }
}

void Rental::returnCar(int carIndex) {
    if (carIndex < 0 || carIndex >= cars.size()) {
        std::cout << "Invalid car number! Please select a valid car to return.\n";
        return;
    }
    if (!cars[carIndex].getAvailability()) {
        cars[carIndex].setAvailability(true);
        std::cout << "Car returned successfully!\n";
    } else {
        std::cout << "This car was not rented!\n";
    }
}
// Rental.cpp
#include "Rental.h"
#include <iostream>
#include <iomanip>

double Rental::calculateRentalCost(int rentalDays) const {
    double totalCost = rentalDays * rentalRatePerDay;
    return totalCost;
}

void Rental::rentCar(int carIndex, int rentalDays) {
    if (carIndex < 0 || carIndex >= cars.size()) {
        std::cout << "Invalid car number!\n";
        return;
    }
    if (cars[carIndex].getAvailability()) {
        cars[carIndex].setAvailability(false);
        std::cout << "Car rented for " << rentalDays << " days.\n";
        std::cout << "Total rental cost: $"
                  << std::fixed << std::setprecision(2) 
                  << calculateRentalCost(rentalDays) << std::endl;
    } else {
        std::cout << "Car is not available for rent!\n";
    }
}

















