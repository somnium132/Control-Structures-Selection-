#include <iostream>
#include <iomanip> // Output formatting operations
#include <cctype> // Character manipulation functions

using namespace std;

int main() {
    char maritalStatus;
    double salary, taxRate = 0.0, taxAmount;

    // Input marital status
    cout << "Enter marital status (S-single/M-married): ";
    cin >> maritalStatus;

    // Convert input to lowercase so it works whether the user types 'S' or 's'
    maritalStatus = tolower(maritalStatus);

    // Validate marital status
    if (maritalStatus != 's' && maritalStatus != 'm') {
        cout << "Error: Invalid marital status." << endl;
        cout << "Use 'Single' or 'Married' only!" << endl;
        return 1; // Terminate the program and return an error code
    }

    // Input salary
    cout << "Enter monthly salary (non-negative): ";
    cin >> salary;

    // Validate salary
    if (salary < 0) {
        cout << "Error: The salary must be a non-negative value only!" << endl;
        return 1; // Terminate the program and return an error code
    }

    // Calculate tax rate according to marital status and income level
    if (maritalStatus == 's') { // Single
        if (salary > 100000) taxRate = 0.30;
        else if (salary >= 50000) taxRate = 0.20;
        else taxRate = 0.10;
    } else if (maritalStatus == 'm') { // Married
        if (salary > 100000) taxRate = 0.25;
        else if (salary >= 50000) taxRate = 0.15;
        else taxRate = 0.05;
    }

    // Calculate tax amount
    taxAmount = salary * taxRate;

    // Display output
    cout << fixed << setprecision(2); // Set how many decimal places to show
    cout << "Employee Monthly Salary: " << salary << endl;
    cout << "Marital Status: " << (maritalStatus == 's' ? "Single" : "Married") << endl;
    cout << "Tax Rate: " << (taxRate * 100) << "%" << endl;
    cout << "Salary Tax: " << taxAmount << endl;

    return 0;
}


