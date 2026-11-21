#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    virtual double rate() const { return 3.5; }
    virtual ~Account() { cout << "Account destroyed\n"; }
};

class SeniorAccount : public Account {
    double* history;
public:
    SeniorAccount() : history(new double[100]{}) {}
    double rate() const override { return 4.0; }
    ~SeniorAccount() override {
        delete[] history;
        cout << "SeniorAccount destroyed\n";
    }
};

int main() {
    vector<unique_ptr<Account>> accounts;
    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());

    cout << "Interest rates:\n";
    for (const auto& account : accounts)
        cout << account->rate() << "%\n";

    cout << "Releasing accounts:\n";
    accounts.clear();

    SeniorAccount senior;
    Account* basePointer = &senior;
    Account slicedCopy = senior; // Demonstrates object slicing.
    cout << "Virtual call through pointer: " << basePointer->rate() << "%\n";
    cout << "Sliced base object call: " << slicedCopy.rate() << "%\n";
}
