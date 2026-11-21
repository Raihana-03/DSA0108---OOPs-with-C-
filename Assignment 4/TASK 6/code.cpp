#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string registration;
    double dailyRate;
    bool rented = false;
public:
    Vehicle(string reg, double rate) : registration(reg), dailyRate(rate) {}
    virtual double rentalCharge(int days) const = 0;
    virtual string type() const = 0;
    virtual void rent() { rented = true; }
    virtual double returnVehicle(int daysLate) {
        rented = false;
        return daysLate > 0 ? daysLate * 100.0 : 0.0;
    }
    virtual void display() const {
        cout << type() << " | " << registration << " | Rs."
             << dailyRate << " per day | "
             << (rented ? "Rented" : "Available") << '\n';
    }
    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(string reg, double rate) : Vehicle(reg, rate) {}
    double rentalCharge(int days) const override { return dailyRate * days; }
    string type() const override { return "Bicycle"; }
};

class TwoWheeler : public Vehicle {
protected:
    double fuelLevel;
    string serviceDue;
public:
    TwoWheeler(string reg, double rate, double fuel, string due)
        : Vehicle(reg, rate), fuelLevel(fuel), serviceDue(due) {}
    double rentalCharge(int days) const override { return dailyRate * days + 30; }
    string type() const override { return "TwoWheeler"; }
};

class Car : public Vehicle {
protected:
    int seats;
    double fuelLevel;
    string serviceDue;
public:
    Car(string reg, double rate, int s, double fuel, string due)
        : Vehicle(reg, rate), seats(s), fuelLevel(fuel), serviceDue(due) {}
    double rentalCharge(int days) const override { return dailyRate * days + 100; }
    string type() const override { return "Car"; }
};

class ElectricCar : public Car {
    double batteryKwh;
    double chargePerKwh;
public:
    ElectricCar(string reg, double rate, int s, double battery, double price)
        : Car(reg, rate, s, 100, "N/A"), batteryKwh(battery), chargePerKwh(price) {}
    double rentalCharge(int days) const override {
        return dailyRate * days + batteryKwh * chargePerKwh;
    }
    string type() const override { return "ElectricCar"; }
};

// New type added without changing Vehicle or the existing vehicle classes.
class ElectricBus : public Vehicle {
    int seats;
public:
    ElectricBus(string reg, double rate, int s) : Vehicle(reg, rate), seats(s) {}
    double rentalCharge(int days) const override { return dailyRate * days + seats * 5.0; }
    string type() const override { return "ElectricBus"; }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;
    fleet.push_back(make_unique<Bicycle>("TN01-BI-101", 80));
    fleet.push_back(make_unique<TwoWheeler>("TN01-TW-202", 150, 5, "2026-12-01"));
    fleet.push_back(make_unique<Car>("TN01-CA-303", 1200, 5, 20, "2026-12-10"));
    fleet.push_back(make_unique<ElectricCar>("TN01-EC-404", 1600, 5, 45, 8));
    fleet.push_back(make_unique<ElectricBus>("TN01-EB-505", 2500, 30));

    cout << "Fleet listing:\n";
    for (const auto& v : fleet) v->display();

    cout << "\nRental charges for 2 days:\n";
    for (const auto& v : fleet)
        cout << v->type() << ": Rs." << v->rentalCharge(2) << '\n';

    fleet[2]->rent();
    cout << "\nAfter renting car:\n";
    fleet[2]->display();
    cout << "Late return charge: Rs." << fleet[2]->returnVehicle(2) << '\n';
    fleet[2]->display();
}
