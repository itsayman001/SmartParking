#include <iostream>
#include <vector>
#include <string>
#include <ctime>  

using namespace std;

class Vehicle {
public:
        string licensePlate;
            time_t entryTime;
    Vehicle(string plate) : licensePlate(plate), entryTime(time(NULL)) {}
};

class ParkingSystem {
private:
    vector<Vehicle*> spots;  
    int totalSpots;

public:
    ParkingSystem(int numSpots) : totalSpots(numSpots) {
        spots.resize(numSpots, nullptr);  
    }

    bool parkVehicle(string licensePlate) {
        for (int i = 0; i < totalSpots; ++i) {
            if (spots[i] == nullptr) {
                spots[i] = new Vehicle(licensePlate);
                cout << "Vehicle " << licensePlate << " parked in spot " << i + 1 << endl;
                return true;
            }
        }
        cout << "No available spots!" << endl;
        return false;
    }

   
    bool removeVehicle(string licensePlate) {
        for (int i = 0; i < totalSpots; ++i) {
            if (spots[i] != nullptr && spots[i]->licensePlate == licensePlate) {
                time_t exitTime = time(nullptr);
                double hours = difftime(exitTime, spots[i]->entryTime) / 3600.0;
                double fee = hours * 5.0;  // $5 per hour
                cout << "Vehicle " << licensePlate << " removed from spot " << i + 1 << ". Fee: $" << fee << endl;
                delete spots[i];
                spots[i] = nullptr;
                return true;
            }
        }
        cout << "Vehicle not found!" << endl;
        return false;
    }

  
    void displayStatus() {
        cout << "Parking Status:" << endl;
        for (int i = 0; i < totalSpots; ++i) {
            if (spots[i] != nullptr) {
                cout << "Spot " << i + 1 << ": " << spots[i]->licensePlate << endl;
            } else {
                cout << "Spot " << i + 1 << ": Empty" << endl;
            }
        }
    }

    ~ParkingSystem() {
        for (auto spot : spots) {
            if (spot != nullptr) delete spot;
        }
    }
};

int main() {
    ParkingSystem parking(10);  
    int choice;
    string plate;

    while (true) {
        cout << "\n1. Park Vehicle\n2. Remove Vehicle\n3. Display Status\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter license plate: ";
                cin >> plate;
                parking.parkVehicle(plate);
                break;
            case 2:
                cout << "Enter license plate: ";
                cin >> plate;
                parking.removeVehicle(plate);
                break;
            case 3:
                parking.displayStatus();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

