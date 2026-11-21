#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;
public:
    Address(const string& c, int p) : city(c), pin(p) {
        cout << "Address+ ";
    }
    ~Address() { cout << "Address- "; }
    string str() const { return city + "-" + to_string(pin); }
};

class Person {
protected:
    string name;
    int age;
    Address home;
public:
    Person(const string& n, int a, const string& city, int pin)
        : name(n), age(a), home(city, pin) {
        cout << "Person+ ";
    }
    virtual ~Person() { cout << "Person- "; }
};

class Course {
    string title;
public:
    Course(const string& t) : title(t) { cout << "Course+ "; }
    ~Course() { cout << "Course- "; }
    string getTitle() const { return title; }
};

class Student : public Person {
    long long regNo;
    Course course;
public:
    Student(const string& n, int a, long long r, const string& city,
            int pin, const string& c)
        : Person(n, a, city, pin), regNo(r), course(c) {
        cout << "Student+ ";
    }
    ~Student() override { cout << "Student- "; }
    void print() const {
        cout << "\n" << regNo << " " << name << " (" << age << ") "
             << home.str() << " " << course.getTitle() << '\n';
    }
};

class Staff : public Person {
    string department;
public:
    Staff(const string& n, int a, const string& city, int pin, const string& d)
        : Person(n, a, city, pin), department(d) {
        cout << "Staff+ ";
    }
    ~Staff() override { cout << "Staff- "; }
};

int main() {
    cout << "Student lifetime:\n";
    {
        Student s("Kavya", 19, 192311001, "Salem", 636001, "OOP");
        s.print();
    }
    cout << "\nStaff lifetime:\n";
    {
        Staff st("Ravi", 40, "Chennai", 600001, "CSE");
    }
    cout << '\n';
}
