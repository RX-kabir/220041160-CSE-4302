#include <iostream>
#include <string>

using namespace std;

class Temperature {
private:
    double value;
    string unit;

public:
    Temperature() : value(0), unit("Celsius") {}

    void assign(double temp, string unit) {

        if (unit == "Celsius") {
            if (temp < -273.15) {
                cout << "Temperature cannot be below absolute zero." << endl;
                return;
            }
            value = temp;
        } else if (unit == "Fahrenheit") {
            double celsius = (temp - 32) * 5 / 9;
            if (celsius < -273.15) {
                cout << "Temperature cannot be below absolute zero." << endl;
                return;
            }
            value = celsius;
        } else if (unit == "Kelvin") {
            if (temp < 0) {
                cout << "Temperature cannot be below absolute zero." << endl;
                return;
            }
            value = temp - 273.15;
        }


    }

    double convert(string targetUnit) {

        if (targetUnit == "Celsius") {
            return value;
        } else if (targetUnit == "Fahrenheit") {
            return value * 9 / 5 + 32;
        } else if (targetUnit == "Kelvin") {
            return value + 273.15;
        }
        else
            cout<<"Invalid"<<endl;

        return 0;
    }

    void print() {
        cout << "The temperature is " << value << " " << unit << endl;
    }
};

int main() {
    Temperature temp;

    return 0;
}
