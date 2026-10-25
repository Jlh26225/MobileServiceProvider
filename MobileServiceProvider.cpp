// Write a program that calculates a customer's monthly bill. It should input the customer's name, which plan was purchased, and how many gigabytes were used. 
// It should then create a bill that includes the input information and the total amount due. 
// It should also display how much money plan A customers would save if they purchased plan B or C, and how much money plan B customers would save if they purchased plan C. 
// If there would be no savings, no message should be printed. Wherever possible, use named constants instead of numbers.

// Plan A : For $39.99 per month, 2 gigabytes are provided.Additional usage costs $8.00 per gigabyte.
// Plan B : For $59.99 per month, 8 gigabytes are provided.Additional usage costs $8.00 per gigabyte.
// Plan C : For $79.99 per month, unlimited data is provided.

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

int main() {
    // Named constants for plans
    const double PLAN_A_BASE = 39.99;
    const double PLAN_A_LIMIT = 2.0;
    const double PLAN_A_RATE = 8.00;

    const double PLAN_B_BASE = 59.99;
    const double PLAN_B_LIMIT = 8.0;
    const double PLAN_B_RATE = 8.00;

    const double PLAN_C_BASE = 79.99;

    string customerName;
    char planChoice;
    double gigabytesUsed;

    // Input collection
    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter the plan purchased (A, B, or C): ";
    cin >> planChoice;
    planChoice = toupper(planChoice);

    // Input validation for plan choice
    while (planChoice != 'A' && planChoice != 'B' && planChoice != 'C') {
        cout << "Invalid plan. Please enter A, B, or C: ";
        cin >> planChoice;
        planChoice = toupper(planChoice);
    }

    cout << "Enter the number of gigabytes used: ";
    cin >> gigabytesUsed;

    // Input validation for gigabytes
    while (gigabytesUsed < 0) {
        cout << "Gigabytes cannot be negative. Enter again: ";
        cin >> gigabytesUsed;
    }

    // Calculate costs for all plans for comparison
    double costA = PLAN_A_BASE;
    if (gigabytesUsed > PLAN_A_LIMIT) {
        costA += (gigabytesUsed - PLAN_A_LIMIT) * PLAN_A_RATE;
    }

    double costB = PLAN_B_BASE;
    if (gigabytesUsed > PLAN_B_LIMIT) {
        costB += (gigabytesUsed - PLAN_B_LIMIT) * PLAN_B_RATE;
    }

    double costC = PLAN_C_BASE;

    // Determine current bill based on purchased plan
    double currentCost = 0.0;
    if (planChoice == 'A') {
        currentCost = costA;
    }
    else if (planChoice == 'B') {
        currentCost = costB;
    }
    else if (planChoice == 'C') {
        currentCost = costC;
    }

    // Output the bill details
    cout << fixed << setprecision(2);
    cout << "\n--- Monthly Bill ---" << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Plan Purchased: Plan " << planChoice << endl;
    cout << "Gigabytes Used: " << gigabytesUsed << " GB" << endl;
    cout << "Total Amount Due: $" << currentCost << endl;

    // Display savings messages if applicable
    if (planChoice == 'A') {
        if (costB < costA) {
            cout << "You would save $" << (costA - costB) << " by switching to Plan B." << endl;
        }
        if (costC < costA) {
            cout << "You would save $" << (costA - costC) << " by switching to Plan C." << endl;
        }
    }
    else if (planChoice == 'B') {
        if (costC < costB) {
            cout << "You would save $" << (costB - costC) << " by switching to Plan C." << endl;
        }
    }

    return 0;
}