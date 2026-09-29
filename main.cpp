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

    const double TAX_RATEAR = 0.065; // 6.5% sales tax
    const double TAX_RATEFC = 0.005; // 0.5% sales tax
    const double TAX_RATECM = 0.02125; // 2.125% sales tax

    // --- 1. User Inputs ---
    cout << "=== COFFEE SHOP INPUT SYSTEM ===" << endl;
   

    char choice;
    string sizeChoice;
    cout<<"Please select an item."<<endl;

    cout << left << setw(10) <<"Item"<< setw(10) << "Small(s)" << setw(10)<< "Medium(m)"<< setw(10)<< "Large(l)"<< endl;
    cout << setw(10) <<"A. Bread" << setw(11) << "$4.00" << setw(10)<< "$6.00"<< setw(10)<< "$10.00"<< endl;
    cout << setw(10) <<"B. Apple" << setw(11) << "$2.00" << setw(10)<< "$4.00"<< setw(10)<< "$6.00"<< endl;
    cout << setw(10) <<"C. Water"<< setw(11) << "$1.00" << setw(10)<< "$2.50"<< setw(10)<< "$3.50"<< endl;
    cout << setw(10) <<"D. Sprite"<<  setw(11) << "$1.50" << setw(10)<< "$2.50"<< setw(10)<< "$3.50"<< endl;
    
    // choices
    cin >> choice;
    if (choice == 'A'||choice == 'a'){
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
        } else {
            cout << "Invalid Input, redo inputs" << endl;
            return 0;
        } 
        
    } else if (choice == 'B'||choice == 'b'){
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
        } else {
            cout << "Invalid Input, redo inputs" << endl;
            return 0;
        }
    } else if (choice == 'C'||choice == 'c'){
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
        } else {
            cout << "Invalid Input, redo inputs" << endl;
            return 0;
        }
    } else if (choice == 'D'||choice == 'd'){
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
        else {
            cout << "Invalid Input, redo inputs" << endl;
            return 0;
        }
    } else {
        cout << "Invalid Input, redo inputs" << endl;
        return 0;
    }



    isMember = false;
    cout << "Is the customer a rewards member? (y/n): ";
    cin >> memberInput;
    if (memberInput == 'y' || memberInput == 'Y') {
        isMember = true;
    } else if (memberInput == 'n' || memberInput == 'N') {
        isMember = false;
    } else {
        cout << "Invalid input, redo inputs" << endl;
    }
 // Set fixed decimal formatting for currency
    cout << fixed << setprecision(2);
    // --- 2. Basic Calculations ---
    double subtotal = itemQuantity * unitPrice;
    double taxAmountAR = subtotal * TAX_RATEAR;
    double taxAmountFC = subtotal * TAX_RATEFC;
    double taxAmountCM = subtotal * TAX_RATECM;
    double totalTax  = taxAmountAR + taxAmountFC + taxAmountCM;
    double tipInput = 0;
    double tip = 0;
    char tipChoice;
    cout << setw(10) << left << "Tip Selection" <<right << setw(13) << "Amount" << endl;
    cout << setw(10) << left << "A. 15%" <<right << setw(10) << "$" << subtotal * 0.15 << endl;
    cout << setw(10) << left << "B. 20%" <<right << setw(10) << "$" << subtotal * 0.2 << endl;
    cout << setw(10) << left << "C. 25%" <<right << setw(10) << "$" << subtotal * 0.25 << endl;
    cout << setw(10) << left << "D. Other Amount" <<right << setw(10) << endl;
    cin >> tipChoice; 

    // Tips 
    if (tipChoice == 'A' || tipChoice == 'a'){
        cout << "Thank you for tipping 15%" << endl;
        tip = 0.15*subtotal;
    } else if (tipChoice == 'B' || tipChoice == 'b'){
        cout << "Thank you for tipping 20%" << endl;
        tip = 0.20*subtotal;        
    } else if (tipChoice == 'C' || tipChoice == 'c'){
        cout << "Thank you for tipping 25%" << endl;
        tip = 0.25*subtotal; 
    } else if (tipChoice == 'D' || tipChoice == 'd'){
        cout << "How much would you like to tip?" << endl;
        cin >> tipInput;
        tip = tipInput;
    } else {
        cout << "That is not an option" << endl;
    }

    double finalTotal = subtotal + totalTax + tip;

    // --- 3. Formatted Receipt Output ---
    cout << "\n==========================================" << endl;
    cout << "          JAVA & BYTES COFFEE SHOP        " << endl;
    cout << "==========================================" << endl;

   
    /*USE THIS CODE IN // TO ENABLE ITEM CODE DISPLAY*/
    //cout << left << setw(25) << "Item Code:" << right << setw(15) << itemCode << endl;
    cout << left << setw(25) << "Item Name:" << right << setw(15) << foodName << endl;
    cout << left << setw(25) << "Quantity:" << right << setw(15) << itemQuantity << endl;
    cout << left << setw(25) << "Unit Price:" << right << setw(14) << "$" << unitPrice << endl;
    cout << left << setw(25) << "Member Status:" << right << setw(17) << (isMember ? "Yes" : "No") << endl;
   
    cout << "------------------------------------------" << endl;
    cout << left << setw(25) << "Subtotal:" << right << setw(14) << "$" << subtotal << endl;
    cout << left << setw(25) << "Tip:" << right << setw(14) << "$" << tip << endl;
    cout << left << setw(25) << "Arkansas Tax (6.5%):" << right << setw(14) << "$" << taxAmountAR << endl;
    cout << left << setw(25) << "Faulkner County Tax (0.5%):" << right << setw(12) << "$" << taxAmountFC << endl;
    cout << left << setw(25) << "Conway Municipal Tax (2.125%):" << right << setw(9) << "$" << taxAmountCM << endl;
    cout << left << setw(25) << "Total Tax:" << right << setw(14) << "$" << totalTax << endl;
    cout << "------------------------------------------" << endl;
    cout << left << setw(25) << "TOTAL:" << right << setw(14) << "$" << finalTotal << endl;
    cout << "==========================================" << endl;

    return 0;
}