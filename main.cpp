#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    // Daily totals
    double grandTotalSales = 0.0;
    int totalCustomers = 0;
    char anotherCustomer = 'Y';

    const double TAX_RATE = 0.08;

    // Outer loop: process multiple customers
    while (toupper(anotherCustomer) == 'Y') {

        // Customer variables
        string customerName;
        char memberInput;
        bool isMember = false;

        cout << "\nEnter customer name: ";
        getline(cin, customerName);

        string receipt = "";
        double subtotal = 0.0;
        char choice;

        // Menu loop for the current customer
        do {
            cout << "\n=== JAVA & BYTES COFFEE SHOP ===\n";

            cout << left << setw(12) << "Item"
                 << setw(12) << "Small (s)"
                 << setw(12) << "Medium (m)"
                 << setw(12) << "Large (l)" << endl;

            cout << left << setw(12) << "A. Bread"
                 << setw(12) << "4.00"
                 << setw(12) << "6.00"
                 << setw(12) << "10.00" << endl;

            cout << left << setw(12) << "B. Apple"
                 << setw(12) << "2.00"
                 << setw(12) << "4.00"
                 << setw(12) << "6.00" << endl;

            cout << left << setw(12) << "C. Water"
                 << setw(12) << "1.00"
                 << setw(12) << "2.50"
                 << setw(12) << "3.50" << endl;

            cout << left << setw(12) << "D. Sprite"
                 << setw(12) << "1.50"
                 << setw(12) << "2.50"
                 << setw(12) << "3.50" << endl;

            cout << "E. Checkout\n";

            cout << "Please select an item: ";
            cin >> choice;
            choice = toupper(choice);

            // Validate menu choice
            while (choice != 'A' && choice != 'B' &&
                   choice != 'C' && choice != 'D' &&
                   choice != 'E') {

                cout << "Invalid choice. Enter A, B, C, D, or E: ";
                cin >> choice;
                choice = toupper(choice);
            }

            // Checkout ends the menu loop
            if (choice == 'E') {
                break;
            }

            string foodName;
            char itemCode = choice;
            char sizeChoice;
            int itemQuantity = 0;
            double unitPrice = 0.0;

            // Identify the selected item
            if (choice == 'A') {
                foodName = "Bread";
            }
            else if (choice == 'B') {
                foodName = "Apple";
            }
            else if (choice == 'C') {
                foodName = "Water";
            }
            else if (choice == 'D') {
                foodName = "Sprite";
            }

            // Get and validate size
            cout << "What size do you want? (S/M/L): ";
            cin >> sizeChoice;
            sizeChoice = toupper(sizeChoice);

            while (sizeChoice != 'S' &&
                   sizeChoice != 'M' &&
                   sizeChoice != 'L') {

                cout << "Invalid size. Enter S, M, or L: ";
                cin >> sizeChoice;
                sizeChoice = toupper(sizeChoice);
            }

            // Determine price based on item and size
            if (choice == 'A') {
                if (sizeChoice == 'S') unitPrice = 4.00;
                else if (sizeChoice == 'M') unitPrice = 6.00;
                else unitPrice = 10.00;
            }
            else if (choice == 'B') {
                if (sizeChoice == 'S') unitPrice = 2.00;
                else if (sizeChoice == 'M') unitPrice = 4.00;
                else unitPrice = 6.00;
            }
            else if (choice == 'C') {
                if (sizeChoice == 'S') unitPrice = 1.00;
                else if (sizeChoice == 'M') unitPrice = 2.50;
                else unitPrice = 3.50;
            }
            else if (choice == 'D') {
                if (sizeChoice == 'S') unitPrice = 1.50;
                else if (sizeChoice == 'M') unitPrice = 2.50;
                else unitPrice = 3.50;
            }

            // Get and validate quantity
            cout << "How many? ";
            cin >> itemQuantity;

            while (cin.fail() || itemQuantity <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');

                cout << "Enter a valid quantity greater than zero: ";
                cin >> itemQuantity;
            }

            // Calculate item total
            double itemTotal = itemQuantity * unitPrice;
            subtotal += itemTotal;

            // String accumulator: format one receipt line
            ostringstream line;
            line << left << setw(12) << foodName
                 << setw(8) << sizeChoice
                 << "Qty: " << setw(4) << itemQuantity
                 << "$" << fixed << setprecision(2)
                 << itemTotal << "\n";

            receipt += line.str();

            cout << "\n" << itemQuantity << " " << foodName
                 << "(s) added to your order.\n";

            cout << fixed << setprecision(2);
            cout << "Current subtotal: $" << subtotal << endl;

        } while (true);

        // Ask about rewards membership
        cout << "\nIs the customer a rewards member? (y/n): ";
        cin >> memberInput;

        while (toupper(memberInput) != 'Y' &&
               toupper(memberInput) != 'N') {
            cout << "Please enter Y or N: ";
            cin >> memberInput;
        }

        if (toupper(memberInput) == 'Y') {
            isMember = true;
        }

        // Calculate tax and final total
        double taxAmount = subtotal * TAX_RATE;
        double finalTotal = subtotal + taxAmount;

        // Calculate loyalty points, rounding down
        int loyaltyPoints = static_cast<int>(finalTotal / 3);

        // Print receipt
        cout << fixed << setprecision(2);

        cout << "\n==========================================\n";
        cout << "          JAVA & BYTES COFFEE SHOP\n";
        cout << "==========================================\n";

        cout << "Customer Name: " << customerName << "\n";
        cout << "Member Status: " << (isMember ? "Yes" : "No") << "\n";

        cout << "------------------------------------------\n";
        cout << left << setw(12) << "Item"
             << setw(8) << "Size"
             << setw(10) << "Quantity"
             << "Amount\n";

        cout << "------------------------------------------\n";
        cout << receipt;
        cout << "------------------------------------------\n";

        cout << left << setw(25) << "Subtotal:"
             << right << "$" << subtotal << "\n";

        cout << left << setw(25) << "Tax (8%):"
             << right << "$" << taxAmount << "\n";

        cout << left << setw(25) << "TOTAL:"
             << right << "$" << finalTotal << "\n";

        cout << "Loyalty Points: ";
        for (int i = 0; i < loyaltyPoints; i++) {
            cout << "*";
        }
        cout << " (" << loyaltyPoints << " points)\n";

        cout << "==========================================\n";

        // Update daily totals
        grandTotalSales += finalTotal;
        totalCustomers++;

        // Ask whether another customer needs service
        cout << "\nIs there another customer? (Y/N): ";
        cin >> anotherCustomer;

        while (toupper(anotherCustomer) != 'Y' &&
               toupper(anotherCustomer) != 'N') {
            cout << "Please enter Y or N: ";
            cin >> anotherCustomer;
        }

        // Remove newline before the next customer's getline
        cin.ignore(10000, '\n');
    }

    // End-of-day report
    cout << fixed << setprecision(2);

    cout << "\n==========================================\n";
    cout << "             END OF DAY REPORT\n";
    cout << "==========================================\n";

    cout << "Total customers: " << totalCustomers << endl;
    cout << "Grand total sales: $" << grandTotalSales << endl;

    cout << "==========================================\n";

    return 0;
}
}
