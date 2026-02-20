#include <iostream>
using namespace std;

int main() {

    double sales[5][4] = {0};
    int salesperson, product;
    double amount;
    char choice;

    do {
        cout << "\nEnter Salesperson number (1-4): ";
        cin >> salesperson;

        cout << "Enter Product number (1-5): ";
        cin >> product;

        cout << "Enter Total Sales Amount: ";
        cin >> amount;

        sales[product - 1][salesperson - 1] += amount;

        cout << "Enter another sales slip? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    cout << "\nMONTHLY SALES SUMMARY\n";

    for (int i = 0; i < 5; i++) {
        cout << "Product " << i + 1 << ": ";

        for (int j = 0; j < 4; j++) {
            cout << sales[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}