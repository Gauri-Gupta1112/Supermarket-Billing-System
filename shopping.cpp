#include "shopping.h"

void shopping::menu() {
    int choice;
    string email, password;

    do {
        cout << "\t\t\t___________________________\n";
        cout << "\t\t\t   Supermarket Main Menu   \n";
        cout << "\t\t\t___________________________\n";
        cout << "\t\t\t1) Administrator\n";
        cout << "\t\t\t2) Buyer\n";
        cout << "\t\t\t3) Exit\n";
        cout << "\n\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;

                if (email == "admin@email.com" && password == "admin123") {
                    administrator();
                } else {
                    cout << "Invalid credentials. Try again.\n";
                }
                break;

            case 2:
                buyer();
                break;

            case 3:
                exit(0);

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}

void shopping::administrator() {
    int choice;

    do {
        cout << "\n\t\tAdministrator Menu\n";
        cout << "1) Add Product\n";
        cout << "2) Edit Product\n";
        cout << "3) Delete Product\n";
        cout << "4) Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add(); break;
            case 2: edit(); break;
            case 3: rem(); break;
            case 4: return;
            default: cout << "Invalid choice.\n";
        }
    } while (true);
}

void shopping::buyer() {
    int choice;

    do {
        cout << "\n\t\tBuyer Menu\n";
        cout << "1) Buy Product\n";
        cout << "2) Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: receipt(); break;
            case 2: return;
            default: cout << "Invalid choice.\n";
        }
    } while (true);
}

void shopping::add() {
    fstream data;
    int token = 0;

    cout << "Enter product code: ";
    cin >> pcode;
    cout << "Enter product name: ";
    cin >> pname;
    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter discount: ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    } else {
        int c;
        float p, d;
        string n;

        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (c == pcode) {
                token++;
                break;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token) {
            cout << "Product code already exists. Try again.\n";
        } else {
            data.open("database.txt", ios::app | ios::out);
            data << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
            cout << "Record inserted successfully.\n";
        }
    }
}

void shopping::edit() {
    // Code for editing products...
}

void shopping::rem() {
    
    // Code for removing products...
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);

    cout << "\nProduct Code\tName\tPrice\n";
    if (!data) {
        cout << "No products found.\n";
    } else {
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            cout << pcode << "\t\t" << pname << "\t" << price << "\n";
            data >> pcode >> pname >> price >> dis;
        }
    }
    data.close();
}

void shopping::receipt() {
    // Code for generating receipts...
}
