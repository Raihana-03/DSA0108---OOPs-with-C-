#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person(string n, int i) : name(n), id(i) {
        cout << "Person ";
    }
    void showPerson() const { cout << name << " " << id << '\n'; }
    virtual ~Person() = default;
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
public:
    Student(string n, int i, string p, double c)
        : Person(n, i), programme(p), cgpa(c) {
        cout << "Student ";
    }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;
public:
    Staff(string n, int i, string d, double s)
        : Person(n, i), department(d), salary(s) {
        cout << "Staff ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p, double c, string d, double s)
        : Person(n, i), Student(n, i, p, c), Staff(n, i, d, s) {
        cout << "TeachingAssistant ";
    }
    void display() const {
        showPerson();
        cout << programme << " " << cgpa << " " << department << " " << salary << '\n';
    }
};

class ResearchScholar : public Student {
    double fellowship;
public:
    ResearchScholar(string n, int i, string p, double c, double f)
        : Person(n, i), Student(n, i, p, c), fellowship(f) {}
    void showFellowship() const { cout << "Fellowship: " << fellowship << '\n'; }
};

int main() {
    cout << "Teaching assistant construction: ";
    TeachingAssistant ta("Kavya", 201, "CSE", 8.7, "AI Lab", 25000);
    cout << "\nTeaching assistant details: ";
    ta.display();

    cout << "Research scholar: ";
    ResearchScholar rs("Arun", 202, "CSE", 9.1, 12000);
    rs.showFellowship();
}
