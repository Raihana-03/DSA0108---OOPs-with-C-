#include <iostream>
class SmartCard{long long balance; public: explicit SmartCard(long long b):balance(b){} bool canTravel(long long f)const{return balance-f>=5000;} bool deduct(long long f){if(!canTravel(f))return false;balance-=f;return true;} long long getBalance()const{return balance;}};
bool proceduralCanTravel(long long balance,long long fare){return balance-fare>=5000;}
int main(){long long balance=10000; std::cout<<"Procedural allowed: "<<proceduralCanTravel(balance,2000)<<'\n';SmartCard card(balance);card.deduct(2000);std::cout<<"OOP balance (paise): "<<card.getBalance()<<'\n';}
