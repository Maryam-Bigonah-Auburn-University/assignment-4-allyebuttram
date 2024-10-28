#include <iostream>
#include <string>
#include <array>
using namespace std;

class Month {
private:
    int monthNo; // 1 for January, 2 for February, etc.
    static const array<string, 12> monthNames; // Array of month names as first 3 letters

public:
    // Default constructor
    Month() : monthNo(1) {} // January by default

    // Constructor that sets the month using the first 3 letters as 3 arguments
    Month(char first, char second, char third) {
        setMonthFromString(string(1, first) + string(1, second) + string(1, third));
    }

    // Constructor that sets the month using an integer value
    Month(int month) {
        setMonthFromInt(month);
    }

    // Input function that sets the month from the first 3 letters of the month name
    void inputFromString() {
        string monthStr;
        cout << "Enter the first three letters of the month: ";
        cin >> monthStr;
        setMonthFromString(monthStr);
    }

    // Input function that sets the month from an integer value
    void inputFromInt() {
        int monthInt;
        cout << "Enter the month number (1 for Jan, 2 for Feb, etc.): ";
        cin >> monthInt;
        setMonthFromInt(monthInt);
    }

    // Output function that outputs the month as the first 3 letters of the month name
    void outputAsString() const {
        if (monthNo >= 1 && monthNo <= 12) {
            cout << "Month: " << monthNames[monthNo - 1] << endl;
        }
    }

    // Output function that outputs the month as a number (1 for Jan, 2 for Feb, etc.)
    void outputAsInt() const {
        cout << "Month number: " << monthNo << endl;
    }

    // Member function that returns the next month as a new Month object
    Month nextMonth() const {
        int nextMonthNo = (monthNo % 12) + 1; // Wrap around after December
        return Month(nextMonthNo);
    }

private:
    // Set month from string of the first 3 letters
    void setMonthFromString(const string& monthStr) {
        string lowerMonthStr = monthStr;
        for (auto& ch : lowerMonthStr) ch = tolower(ch); // Convert to lowercase for comparison
        for (int i = 0; i < 12; ++i) {
            if (lowerMonthStr == monthNames[i]) {
                monthNo = i + 1;
                return;
            }
        }
        monthNo = 1; // Default to January if input is invalid
    }

    // Set month from integer
    void setMonthFromInt(int monthInt) {
        if (monthInt >= 1 && monthInt <= 12) {
            monthNo = monthInt;
        } else {
            monthNo = 1; // Default to January if input is invalid
        }
    }
};

// Array of first three letters of each month
const array<string, 12> Month::monthNames = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};

// Test program for the Month class
int main() {
    Month month1; // Default constructor (January)
    Month month2('F', 'e', 'b'); // Constructor with 3 letters
    Month month3(4); // Constructor with integer (April)

    cout << "Testing default constructor:" << endl;
    month1.outputAsString();
    month1.outputAsInt();

    cout << "\nTesting constructor with 3 letters ('Feb'):" << endl;
    month2.outputAsString();
    month2.outputAsInt();

    cout << "\nTesting constructor with integer (4 for April):" << endl;
    month3.outputAsString();
    month3.outputAsInt();

    cout << "\nTesting next month function for April:" << endl;
    Month nextMonth = month3.nextMonth();
    nextMonth.outputAsString();
    nextMonth.outputAsInt();

    cout << "\nTesting input from string and integer:" << endl;
    Month inputMonth;
    inputMonth.inputFromString();
    inputMonth.outputAsString();
    inputMonth.outputAsInt();

    inputMonth.inputFromInt();
    inputMonth.outputAsString();
    inputMonth.outputAsInt();

    return 0;
}
