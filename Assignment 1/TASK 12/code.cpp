#include <iostream>
#include <array>
enum class Zone{Inner,Middle,Outer,Airport};
constexpr std::array<long long,4> FARES={1000,2000,3000,6000};
class MonthlyPass{Zone first,second;public:MonthlyPass(Zone a,Zone b):first(a),second(b){}bool covers(Zone z)const{return z==first||z==second;}};
long long fare(Zone z,bool peak,bool weekend){long long base=FARES[static_cast<int>(z)];if(weekend)return base*90/100;return peak?base+base*20/100:base;}
int main(){MonthlyPass pass(Zone::Inner,Zone::Airport);std::cout<<"Airport weekday peak paise: "<<fare(Zone::Airport,true,false)<<'\n';std::cout<<"Airport weekend fare paise: "<<fare(Zone::Airport,true,true)<<'\n';std::cout<<"Pass covers Airport: "<<pass.covers(Zone::Airport)<<'\n';}
