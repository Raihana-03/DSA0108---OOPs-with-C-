#include <climits>
#include <iostream>
int main(){long long journeys[]={20000,500000,3000000};for(long long n:journeys){long long total=n*3600;std::cout<<n<<" journeys: "<<total<<" paise (Rs "<<total/100<<")\n";}std::cout<<"INT_MAX = "<<INT_MAX<<"\n";}
