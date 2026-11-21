#include <iomanip>
#include <iostream>
class Money {
    long long paise;
public:
    Money(long long rupees=0,int p=0):paise(rupees*100+p){}
    explicit Money(long long totalPaise, bool):paise(totalPaise){}
    Money operator+(const Money& rhs) const { return Money(paise+rhs.paise,true); }
    Money operator-(const Money& rhs) const { return Money(paise-rhs.paise,true); }
    Money& operator+=(const Money& rhs) { paise+=rhs.paise; return *this; }
    bool operator==(const Money& rhs) const { return paise==rhs.paise; }
    bool operator<(const Money& rhs) const { return paise<rhs.paise; }
    friend std::ostream& operator<<(std::ostream& out,const Money& m) {
        long long v=m.paise, whole=v/100, cents=v%100;
        if(cents<0)cents=-cents;
        if(v<0 && whole==0) out << "-";
        out << "Rs " << (whole<0?-whole:whole) << '.' << std::setw(2) << std::setfill('0') << cents << std::setfill(' ');
        return out;
    }
    friend std::istream& operator>>(std::istream& in,Money& m) {
        long long r; char dot; int p;
        if(in>>r>>dot>>p && dot=='.') m.paise=r*100+(r<0?-p:p);
        else in.setstate(std::ios::failbit);
        return in;
    }
};
int main() {
    Money a(120,75),b(79,25),c=a+b;
    std::cout<<c<<'\n'<<std::boolalpha<<(c==Money(200))<<'\n';
    Money carry=Money(0,75)+Money(0,50);
    std::cout<<"Carry test: "<<carry<<'\n';
    std::cout<<"Negative subtraction: "<<(Money(1,0)-Money(2,0))<<'\n';
    Money bill(10,0); bill+=a; std::cout<<"Bill: "<<bill<<'\n';
}
