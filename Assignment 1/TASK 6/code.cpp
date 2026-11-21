#include <iomanip>
#include <iostream>
enum class Zone { Inner, Middle, Outer };
constexpr int BASE[] = {1000,2000,3000};
constexpr int SURCHARGE=20; constexpr long long MIN_BALANCE=5000;
long long fare(Zone z,bool peak){ int base=0; switch(z){case Zone::Inner:base=BASE[0];break;case Zone::Middle:base=BASE[1];break;case Zone::Outer:base=BASE[2];break;} return peak?base+base*SURCHARGE/100:base; }
bool canTravel(long long balance,long long f){return balance-f>=MIN_BALANCE;}
int main(){long long balance=10000; struct Trip{Zone zone;bool peak;}; Trip trips[]={{Zone::Inner,false},{Zone::Outer,true},{Zone::Middle,false}}; for(const Trip&t:trips){auto f=fare(t.zone,t.peak);if(canTravel(balance,f)){balance-=f;std::cout<<"Fare Rs "<<f/100<<'.'<<std::setw(2)<<std::setfill('0')<<f%100<<std::setfill(' ');}else std::cout<<"Denied (low balance)";std::cout<<"  balance Rs "<<balance/100<<'\n';}}
