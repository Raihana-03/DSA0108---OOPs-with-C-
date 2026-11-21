#include <cmath>
#include <iostream>
#include <stdexcept>
class Complex {
    double re,im;
public:
    Complex():re(0),im(0){}
    Complex(double real):re(real),im(0){}
    Complex(double real,double imag):re(real),im(imag){}
    Complex operator+(const Complex& z)const{return {re+z.re,im+z.im};}
    Complex operator-(const Complex& z)const{return {re-z.re,im-z.im};}
    Complex operator*(const Complex& z)const{return {re*z.re-im*z.im,re*z.im+im*z.re};}
    Complex operator/(const Complex& z)const{
        double d=z.re*z.re+z.im*z.im;
        if(d==0.0)throw std::domain_error("division by zero impedance");
        return {(re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d};
    }
    bool operator==(const Complex& z)const{return std::abs(re-z.re)<1e-9&&std::abs(im-z.im)<1e-9;}
    double magnitude()const{return std::sqrt(re*re+im*im);}
    friend std::ostream& operator<<(std::ostream& out,const Complex& z){return out<<z.re<<(z.im<0?" - j":" + j")<<std::abs(z.im);}
};
int main(){
    const double pi=std::acos(-1.0),f=50.0,w=2*pi*f,L=0.1,C=100e-6;
    Complex resistor(10,0),inductor(0,w*L),capacitor(0,-1.0/(w*C));
    Complex series=resistor+inductor+capacitor;
    Complex parallel=(resistor*inductor)/(resistor+inductor);
    std::cout<<"Resistor: "<<resistor<<" ohm, |Z|="<<resistor.magnitude()<<'\n';
    std::cout<<"Inductor: "<<inductor<<" ohm\nCapacitor: "<<capacitor<<" ohm\n";
    std::cout<<"Series RLC: "<<series<<" ohm, |Z|="<<series.magnitude()<<'\n';
    std::cout<<"Parallel R-L: "<<parallel<<" ohm, |Z|="<<parallel.magnitude()<<'\n';
    try{Complex bad=resistor/Complex(0,0);std::cout<<bad;}
    catch(const std::domain_error& e){std::cout<<"Safe error: "<<e.what()<<'\n';}
}
