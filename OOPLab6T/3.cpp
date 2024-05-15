#include <iostream>
#include <string>

// Базовий клас "Транспорт"
class Transport {
protected:
    std::string transportType;

public:
    Transport(const std::string& _transportType) : transportType(_transportType) {}
    virtual ~Transport() {}

    virtual void displayInfo() const {
        std::cout << "Transport Type: " << transportType << std::endl;
    }

    virtual void inputInfo() {
        std::cout << "Enter transport type: ";
        std::cin >> transportType;
    }

    friend std::ostream& operator<<(std::ostream& os, const Transport& transport) {
        os << "Transport Type: " << transport.transportType;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Transport& transport) {
        std::cout << "Enter transport type: ";
        is >> transport.transportType;
        return is;
    }
};

// Похідний клас "Корабель"
class Ship : virtual public Transport {
protected:
    std::string shipName;

public:
    Ship(const std::string& _transportType, const std::string& _shipName) : Transport(_transportType), shipName(_shipName) {}
    ~Ship() override {}

    void displayInfo() const override {
        std::cout << "Transport Type: " << transportType << ", Ship Name: " << shipName << std::endl;
    }

    void inputInfo() override {
        Transport::inputInfo();
        std::cout << "Enter ship name: ";
        std::cin >> shipName;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ship& ship) {
        os << static_cast<const Transport&>(ship) << ", Ship Name: " << ship.shipName;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Ship& ship) {
        is >> static_cast<Transport&>(ship);
        std::cout << "Enter ship name: ";
        is >> ship.shipName;
        return is;
    }
};

// Похідний клас "Пасажирський транспорт"
class PassengerTransport : virtual public Transport {
protected:
    int passengerCapacity;

public:
    PassengerTransport(const std::string& _transportType, int _passengerCapacity) : Transport(_transportType), passengerCapacity(_passengerCapacity) {}
    ~PassengerTransport() override {}

    void displayInfo() const override {
        std::cout << "Transport Type: " << transportType << ", Passenger Capacity: " << passengerCapacity << std::endl;
    }

    void inputInfo() override {
        Transport::inputInfo();
        std::cout << "Enter passenger capacity: ";
        std::cin >> passengerCapacity;
    }

    friend std::ostream& operator<<(std::ostream& os, const PassengerTransport& passengerTransport) {
        os << static_cast<const Transport&>(passengerTransport) << ", Passenger Capacity: " << passengerTransport.passengerCapacity;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, PassengerTransport& passengerTransport) {
        is >> static_cast<Transport&>(passengerTransport);
        std::cout << "Enter passenger capacity: ";
        is >> passengerTransport.passengerCapacity;
        return is;
    }
};

// Похідний клас "Пасажирський корабель"
class PassengerShip : public Ship, public PassengerTransport {
public:
    PassengerShip(const std::string& _transportType, const std::string& _shipName, int _passengerCapacity)
        : Transport(_transportType), Ship(_transportType, _shipName), PassengerTransport(_transportType, _passengerCapacity) {}
    ~PassengerShip() override {}

    void displayInfo() const override {
        std::cout << "Transport Type: " << transportType << ", Ship Name: " << shipName << ", Passenger Capacity: " << passengerCapacity << std::endl;
    }

    void inputInfo() override {
        Transport::inputInfo();
        std::cout << "Enter ship name: ";
        std::cin >> shipName;
        std::cout << "Enter passenger capacity: ";
        std::cin >> passengerCapacity;
    }

    friend std::ostream& operator<<(std::ostream& os, const PassengerShip& passengerShip) {
        os << static_cast<const Transport&>(passengerShip) << ", Ship Name: " << passengerShip.shipName << ", Passenger Capacity: " << passengerShip.passengerCapacity;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, PassengerShip& passengerShip) {
        is >> static_cast<Transport&>(passengerShip);
        std::cout << "Enter ship name: ";
        is >> passengerShip.shipName;
        std::cout << "Enter passenger capacity: ";
        is >> passengerShip.passengerCapacity;
        return is;
    }
};

int main() {
    Transport transport("Generic Transport");
    std::cout << "Transport info: " << std::endl;
    transport.displayInfo();

    Ship ship("Ship", "Generic Ship");
    std::cout << "Ship info: " << std::endl;
    ship.displayInfo();

    PassengerTransport passengerTransport("Passenger Transport", 200);
    std::cout << "Passenger Transport info: " << std::endl;
    passengerTransport.displayInfo();

    PassengerShip passengerShip("Passenger Ship", "Titanic", 3000);
    std::cout << "Passenger Ship info: " << std::endl;
    passengerShip.displayInfo();

    return 0;
}
