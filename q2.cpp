#include <iostream>
using namespace std;

class Temperature {
private:
    double kelvin;
    double celsius;
    double fahrenheit;

    // Helper function to update Celsius and Fahrenheit based on Kelvin
    void updateCelsiusAndFahrenheit() {
        celsius = kelvin - 273.15;
        fahrenheit = (celsius * 9.0 / 5) + 32;
    }

public:
    // Mutator for Kelvin, updates Celsius and Fahrenheit accordingly
    void setKelvin(double k) {
        kelvin = k;
        updateCelsiusAndFahrenheit();
    }

    // Mutator for Celsius, updates Kelvin and Fahrenheit accordingly
    void setCelsius(double c) {
        celsius = c;
        kelvin = c + 273.15;
        fahrenheit = (c * 9.0 / 5) + 32;
    }

    // Mutator for Fahrenheit, updates Kelvin and Celsius accordingly
    void setFahrenheit(double f) {
        fahrenheit = f;
        celsius = (5.0 / 9) * (f - 32);
        kelvin = celsius + 273.15;
    }

    // Accessors
    double getKelvin() const {
        return kelvin;
    }

    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return fahrenheit;
    }
};

int main() {
    Temperature temp;
    double kelvinInput;

    cout << "Enter a temperature in Kelvin: ";
    cin >> kelvinInput;

    // Set the temperature in Kelvin and update Celsius and Fahrenheit
    temp.setKelvin(kelvinInput);

    // Display results
    cout << "Temperature in Kelvin: " << temp.getKelvin() << endl;
    cout << "Temperature in Celsius: " << temp.getCelsius() << endl;
    cout << "Temperature in Fahrenheit: " << temp.getFahrenheit() << endl;

    return 0;
}
