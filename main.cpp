#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // --- Variable Declarations ---
    string foodName;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    char memberInput;
    bool isMember = false;

    const double TAX_RATE = 0.08; // 8% sales tax

    // --- 1. User Inputs ---
    cout << "=== COFFEE SHOP INPUT SYSTEM ===" << endl;
   
    cout << "Enter item name: ";
    getline(cin, foodName);

    cout << "Enter item code (single character): ";
    cin >> itemCode;

    cout << "Enter quantity: ";
    cin >> itemQuantity;

    cout << "Enter unit price: $";
    cin >> unitPrice;

    cout << "Is the customer a rewards member? (y/n): ";
    cin >> memberInput;
    if (memberInput == 'y' || memberInput == 'Y') {
        isMember = true;
    }

    // --- 2. Basic Calculations ---
    double subtotal = itemQuantity * unitPrice;
    double taxAmount = subtotal * TAX_RATE;
    double finalTotal = subtotal + taxAmount;

    // --- 3. Formatted Receipt Output ---
    cout << "\n==========================================" << endl;
    cout << "          JAVA & BYTES COFFEE SHOP        " << endl;
    cout << "==========================================" << endl;

    // Set fixed decimal formatting for currency
    cout << fixed << setprecision(2);

    cout << left << setw(25) << "Item Name:" << right << setw(15) << foodName << endl;
    cout << left << setw(25) << "Item Code:" << right << setw(15) << itemCode << endl;
    cout << left << setw(25) << "Quantity:" << right << setw(15) << itemQuantity << endl;
    cout << left << setw(25) << "Unit Price:" << right << setw(14) << "$" << unitPrice << endl;
    cout << left << setw(25) << "Member Status:" << right << setw(15) << (isMember ? "Yes" : "No") << endl;
   
    cout << "------------------------------------------" << endl;
    cout << left << setw(25) << "Subtotal:" << right << setw(14) << "$" << subtotal << endl;
    cout << left << setw(25) << "Tax (8%):" << right << setw(14) << "$" << taxAmount << endl;
    cout << "------------------------------------------" << endl;
    cout << left << setw(25) << "TOTAL:" << right << setw(14) << "$" << finalTotal << endl;
    cout << "==========================================" << endl;

    return 0;
