#include <iostream>
enum class Zone{Inner,Middle,Outer}; constexpr long long FARES[]={1000,2000,3000};
long long fare(Zone z,bool peak){long long f=FARES[static_cast<int>(z)];return peak?f+f*20/100:f;}
int main(){std::cout<<"Recommended: enum class + constexpr integer-paise fare table\n";for(int z=0;z<3;++z)std::cout<<"Zone "<<z<<" peak fare paise: "<<fare(static_cast<Zone>(z),true)<<'\n';}
