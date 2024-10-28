#include <iostream>
#include <iomanip>  // For setting precision on output

class GasPump {
private:
    double costPerGallon;
    double amountDispensed; // in gallons
    double totalCharge;

public:
    // Constructor
    GasPump() : costPerGallon(0.0), amountDispensed(0.0), totalCharge(0.0) {}

    // Method to set the cost per gallon of gas
    void setCostPerGallon(double cost) {
        costPerGallon = cost;
    }

    // Method to get the cost per gallon of gas
    double getCostPerGallon() const {
        return costPerGallon;
    }

    // Method to dispense gas based on time in seconds
    void dispenseGas(int seconds) {
        amountDispensed = seconds * 0.10;  // 0.10 gallons per second
        totalCharge = amountDispensed * costPerGallon;
    }

    // Method to display the amount of gas dispensed
    double getAmountDispensed() const {
        return amountDispensed;
    }

    // Method to display the total charge for the gas dispensed
    double getTotalCharge() const {
        return totalCharge;
    }

    // Method to reset the pump for a new usage
    void reset() {
        amountDispensed = 0.0;
        totalCharge = 0.0;
    }
};

int main() {
    GasPump pump;
    double costPerGallon;
    int seconds;

    // Prompt user to enter cost per gallon and time to pump gas
    std::cout << "Enter the cost per gallon of gas: $";
    std::cin >> costPerGallon;

    std::cout << "Enter the number of seconds to pump gas: ";
    std::cin >> seconds;

    // Set the cost per gallon
    pump.setCostPerGallon(costPerGallon);

    // Dispense gas for the given number of seconds
    pump.dispenseGas(seconds);

    // Display the results
    std::cout << std::fixed << std::setprecision(2);  // Format output to 2 decimal places
    std::cout << "\nGallons of gas pumped: " << pump.getAmountDispensed() << " gallons" << std::endl;
    std::cout << "Cost per gallon of gas: $" << pump.getCostPerGallon() << std::endl;
    std::cout << "Total cost: $" << pump.getTotalCharge() << std::endl;

    return 0;
}
