#include <iostream>
#include <string>
#include <stdexcept>
class Book {
    std::string title;
    std::string author;
    int copies;
public:
    Book() : Book("Untitled", "Unknown", 0) {}
    explicit Book(const std::string& t) : Book(t, "Unknown", 1) {}
    Book(const std::string& t, const std::string& a, int c)
        : title(t), author(a), copies(c) {
        if (c < 0) throw std::invalid_argument("copies cannot be negative");
    }
    void print() const {
        std::cout << title << " | " << author << " | copies: " << copies << '\n';
    }
};
int main() {
    Book empty;
    Book donated("Clean Code");
    Book full("The C++ Programming Language", "Bjarne Stroustrup", 4);
    empty.print(); donated.print(); full.print();
    try { Book invalid("Bad record", "Test", -2); }
    catch (const std::invalid_argument& e) { std::cout << "Rejected: " << e.what() << '\n'; }
}
