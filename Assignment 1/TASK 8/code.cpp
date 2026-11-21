#include <iomanip>
#include <iostream>
#include <limits>
int main(){int hour;std::cout<<"Enter hour (0-23): ";if(!(std::cin>>hour)){std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');std::cout<<"Invalid input recovered\n";return 0;}std::cout<<"Hour accepted: "<<hour<<"\nFare example: Rs "<<std::fixed<<std::setprecision(2)<<10.0<<'\n';}
