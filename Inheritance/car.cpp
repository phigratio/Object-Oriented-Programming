// Task 2:
// Create a Car class which consists of seats, wheels, engine, doors.
// Car Class also has the attribute the maximum_acceleration,
// fuel_capacity.
// Class Seat stores the information of comfortability (Pleasant,
// Comfy) and presence of seat warmer.
// The class Wheel stores the information of circumference.
// The class Engine stores information about the Maximum Fuel
// Consumption Rate, Maximum Energy Production Rate, Average RPM.
// The class door stores the information of opening mode (sideways ,
// upward ways).
// Create necessary access and mutator functions for each class. Make
// a display function in the Car class which displays the
// specification (info about all components as well as attributes).

#include <bits/stdc++.h>
using namespace std;
class seat
{
private:
    string comfortability;
    bool seatWarmer;

public:
    seat(string comfort, bool warmer) : comfortability(comfort), seatWarmer(warmer) {}
    string getComfortability() const
    {
        return comfortability;
    }
    bool hasSeatWarmer() const
    {
        return seatWarmer;
    }
};

class Wheel
{
private:
    double circumference;

public:
    Wheel(double circum) : circumference(circum) {}
    double getCircumference() const
    {
        return circumference;
    }
};
class Engine
{
private:
    double maxFuelConsumptionRate;
    double maxEnergyProductionRate;
    double averageRPM;

public:
    Engine(double fuelRate, double energyRate, double rpm)
        : maxFuelConsumptionRate(fuelRate), maxEnergyProductionRate(energyRate), averageRPM(rpm) {}

    double getMaxFuelConsumptionRate() const { return maxFuelConsumptionRate; }
    double getMaxEnergyProductionRate() const { return maxEnergyProductionRate; }
    double getAverageRPM() const { return averageRPM; }
};
class Door
{
private:
    string openingMode;

public:
    Door(string mode) : openingMode(mode) {}

    string getOpeningMode() const { return openingMode; }
};
class Car
{
private:
    int seats;
    int wheels;
    int doors;
    Engine engine;
    double maxAcceleration;
    double fuelCapacity;

public:
    Car(int numSeats, int numWheels, int numDoors, const Engine &carEngine,
        double acceleration, double capacity)
        : seats(numSeats), wheels(numWheels), doors(numDoors), engine(carEngine),
          maxAcceleration(acceleration), fuelCapacity(capacity) {}

    int getSeats() const { return seats; }
    int getWheels() const { return wheels; }
    int getDoors() const { return doors; }
    Engine getEngine() const { return engine; }
    double getMaxAcceleration() const { return maxAcceleration; }
    double getFuelCapacity() const { return fuelCapacity; }

    void display() const
    {
        cout << "Car Specifications:" << endl;
        cout << "Seats: " << seats << endl;
        cout << "Wheels: " << wheels << endl;
        cout << "Doors: " << doors << endl;
        cout << "Engine Max Fuel Consumption Rate: " << engine.getMaxFuelConsumptionRate() << endl;
        cout << "Engine Max Energy Production Rate: " << engine.getMaxEnergyProductionRate() << endl;
        cout << "Engine Average RPM: " << engine.getAverageRPM() << endl;
        cout << "Maximum Acceleration: " << maxAcceleration << endl;
        cout << "Fuel Capacity: " << fuelCapacity << endl;
    }
};

int main()
{

    seat carSeat("Pleasant", true);
    Wheel carWheel(18.0);
    Engine carEngine(8.0, 300.0, 2500.0);
    Door carDoor("sideways");

    Car myCar(5, 4, 4, carEngine, 10.0, 60.0);

    myCar.display();

    return 0;
}