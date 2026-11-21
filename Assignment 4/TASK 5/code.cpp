#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;
public:
    Cart& add(const string& item, double price) {
        if (n < 10 && price >= 0) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }
    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }
    double total() const {
        double sum = 0;
        for (int i = 0; i < n; ++i) sum += prices[i];
        return sum * (100 - discount) / 100;
    }
    void show() const {
        for (int i = 0; i < n; ++i)
            cout << items[i] << ": " << prices[i] << '\n';
    }
};

int main() {
    Cart direct;
    direct.add("Rice", 60).add("Dal", 120).setDiscount(10);
    cout << fixed << setprecision(2);
    cout << "Direct object total: " << direct.total() << '\n';

    Cart* pointer = &direct;
    pointer->add("Oil", 180);
    cout << "Pointer with -> total: " << pointer->total() << '\n';

    Cart& reference = direct;
    cout << "Reference total: " << reference.total() << '\n';

    Cart* dynamicCart = new Cart;
    dynamicCart->add("Milk", 50).add("Bread", 40);
    cout << "Dynamic object total: " << dynamicCart->total() << '\n';
    delete dynamicCart;

    Cart a, b, c;
    a.add("A", 100);
    b.add("B", 250);
    c.add("C", 175);
    Cart* activeCarts[] = {&a, &b, &c};
    int count = sizeof(activeCarts) / sizeof(activeCarts[0]);
    int best = 0;
    for (int i = 1; i < count; ++i)
        if (activeCarts[i]->total() > activeCarts[best]->total()) best = i;
    cout << "Highest cart total: " << activeCarts[best]->total() << '\n';
}
