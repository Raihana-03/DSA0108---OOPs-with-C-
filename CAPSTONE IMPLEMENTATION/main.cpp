#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
private:
    string name;
    string type;
    string location;
    string status;

public:
    Item(const string& itemName, const string& itemType, const string& itemLocation)
        : name(itemName), type(itemType), location(itemLocation), status("Available") {}

    void display() const {
        cout << "\nItem Name: " << name
             << "\nType: " << type
             << "\nLocation: " << location
             << "\nStatus: " << status << "\n";
    }
};

class LostAndFoundSystem {
private:
    vector<Item> items;

public:
    void reportItem(const string& name, const string& type, const string& location) {
        items.emplace_back(name, type, location);
        cout << "\nItem reported successfully!\n";
    }

    void displayItems() const {
        if (items.empty()) {
            cout << "\nNo items reported yet.\n";
            return;
        }

        for (const Item& item : items) {
            item.display();
        }
    }
};

int main() {
    LostAndFoundSystem system;
    int choice = 0;

    do {
        cout << "\n--- Campus Lost and Found ---\n"
             << "1. Report an item\n"
             << "2. View reported items\n"
             << "3. Exit\n"
             << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            return 1;
        }

        if (choice == 1) {
            string name, type, location;

            cout << "Enter item name: ";
            getline(cin >> ws, name);

            cout << "Enter type (Lost/Found): ";
            getline(cin, type);

            cout << "Enter location: ";
            getline(cin, location);

            system.reportItem(name, type, location);
        } else if (choice == 2) {
            system.displayItems();
        } else if (choice == 3) {
            cout << "Thank you!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
