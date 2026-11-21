#include <iostream>
#include <string>
class Token{static int next;int id;public:Token(){id=++next;}int get()const{return id;}static int issued(){return next-100;}};int Token::next=100;
class BusTicket{static int issued;static const int CAPACITY=3;int seat;std::string name;public:explicit BusTicket(const std::string& n):seat(0),name(n){if(issued<CAPACITY)seat=++issued;}static int count(){return issued;}void print()const{std::cout<<name<<": "<<(seat?"Seat "+std::to_string(seat):"Waiting")<<'\n';}};int BusTicket::issued=0;
int main(){Token a[3],extra;std::cout<<a[0].get()<<' '<<a[2].get()<<' '<<extra.get()<<' '<<Token::issued()<<'\n';BusTicket t[4]={BusTicket("Asha"),BusTicket("Bala"),BusTicket("Chitra"),BusTicket("Dev")};for(const auto& x:t)x.print();std::cout<<"Issued: "<<BusTicket::count()<<'\n';}
