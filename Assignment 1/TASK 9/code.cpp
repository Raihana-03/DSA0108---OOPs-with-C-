#include <iostream>
long long farePaise(int zone,bool peak){if(zone<1||zone>3)return -1;long long base=zone*1000;return peak?base+base*20/100:base;}
int main(){int zones[]={1,2,3};for(int z:zones)std::cout<<"Zone "<<z<<" off-peak paise: "<<farePaise(z,false)<<", peak paise: "<<farePaise(z,true)<<'\n';std::cout<<"Invalid zone: "<<farePaise(4,false)<<'\n';}
