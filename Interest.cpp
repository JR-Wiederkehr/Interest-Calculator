#include <iostream>
#include <cmath>

using namespace std;

void calculateSimpleInterest(double principal, double rate, double time) {
    double interest = (principal * rate * time) / 100;
    cout << "Simple Interest: " << interest << endl;
    cout << "Total Amount: " << principal + interest << endl;
}

void calculateCompoundInterest(double principal, double rate, double time, int n) {
    double amount = principal * pow((1 + rate / (n * 100)), n * time);
    double interest = amount - principal;
    cout << "Compound Interest: " << interest << endl;
    cout << "Total Amount: " << amount << endl;
}

void errorMessages(int x){
    switch(x){
        case 1:
            cout << "Invalid input! Please enter numeric values." << endl << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        case 2:
            cout << "Invalid input! Principal, rate, and time must be non-negative." << endl << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
    }
}

int main() {
    double principal, rate, time;
    int choice, n;
    int choiceCounter = 0;
    while(choice != 1 && choice != 2){
        if (choiceCounter > 0) {
            cout << endl << "Invalid choice! Please enter 1 or 2." << endl;
        }
        cout << "Interest Calculator" << endl;
        cout << "1. Simple Interest" << endl;
        cout << "2. Compound Interest" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        if (cin.fail()) {
            errorMessages(1);
        }
        choiceCounter++;
    }

    while (!cin.fail()) {
        cout << "Enter principal amount: ";
        cin >> principal;
        cout << "Enter rate of interest: ";
        cin >> rate;
        cout << "Enter time period (in years): ";
        cin >> time;
        if(cin.fail()){
            errorMessages(1);
        }
        else if (principal < 0 || rate < 0 || time < 0) {
            errorMessages(2);
        }
        else{
            break;
        } 
    }



    switch (choice) {
        case 1:
            calculateSimpleInterest(principal, rate, time);
            break;
        case 2:
            cout << "Enter number of times interest is compounded per year: ";
            cin >> n;
            calculateCompoundInterest(principal, rate, time, n);
            break;

    }

    return 0;
}

