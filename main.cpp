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
   
    char choice;
    string sizeChoice;
    cout<<"Please select an item."<<endl;

    cout << left << setw(10) <<"Item"<< setw(10) << "Small(s)" << setw(10)<< "Medium(m)"<< setw(10)<< "Large(l)"<< endl;
    cout << left << setw(10) <<"A. Bread"<< setw(10) << "4" << setw(10)<< "6"<< setw(10)<< "10"<< endl;
    cout << left << setw(10) <<"B. Apple"<< setw(10) << "2" << setw(10)<< "4"<< setw(10)<< "6"<< endl;
    cout << left << setw(10) <<"C. Water"<< setw(10) << "1" << setw(10)<< "2.50"<< setw(10)<< "3.50"<< endl;
    cout << left << setw(10) <<"D. Sprite"<< setw(10) << "1.50" << setw(10)<< "2.50"<< setw(10)<< "3.50"<< endl;
    
    cin >> choice;
    if (choice == 'A'||'a'){
        cout<< "What size do you want?"<< endl;
        cin >> sizeChoice;
        cout << "How many?"<<endl;
        cin >> itemQuantity;
        if (sizeChoice == "Small" || sizeChoice == "s"){
            unitPrice = 4;
        }
        else if (sizeChoice == "Medium" || sizeChoice == "m"){
            unitPrice = 6;
        }
        else if (sizeChoice == "Large" || sizeChoice == "l"){
            unitPrice = 10;
        }
        
    } else if (choice == 'B'||'b'){
        cout<< "What size do you want?"<< endl;
        cin >> sizeChoice;
        cout << "How many?"<<endl;
        cin >> itemQuantity;
        if (sizeChoice == "Small" || sizeChoice == "s"){
            unitPrice = 2;
        }
        else if (sizeChoice == "Medium" || sizeChoice == "m"){
            unitPrice = 4;
        }
        else if (sizeChoice == "Large" || sizeChoice == "l"){
            unitPrice = 6;
        }
    } else if (choice == 'C'||'c'){
        cout<< "What size do you want?"<< endl;
        cin >> sizeChoice;
        cout << "How many?"<<endl;
        cin >> itemQuantity;
        if (sizeChoice == "Small" || sizeChoice == "s"){
            unitPrice = 1;
        }
        else if (sizeChoice == "Medium" || sizeChoice == "m"){
            unitPrice = 2.50;
        }
        else if (sizeChoice == "Large" || sizeChoice == "l"){
            unitPrice = 3.50;
        }
    } else if (choice == 'D'||'d'){
        cout<< "What size do you want?"<< endl;
        cin >> sizeChoice;
        cout << "How many?"<<endl;
        cin >> itemQuantity;
        if (sizeChoice == "Small" || sizeChoice == "s"){
            unitPrice = 1.50;
        }
        else if (sizeChoice == "Medium" || sizeChoice == "m"){
            unitPrice = 2.50;
        }
        else if (sizeChoice == "Large" || sizeChoice == "l"){
            unitPrice = 3.50;
        }
    }




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
}