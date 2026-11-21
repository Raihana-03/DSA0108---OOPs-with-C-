#include <iostream>
int main(){ int a=7,b=2; double c=a/b, d=static_cast<double>(a)/b; char ch='A'+2; bool flag=5; unsigned int u=1; int s=-1;
std::cout<<c<<' '<<d<<'\n'<<ch<<' '<<ch+1<<'\n'<<flag<<' '<<std::boolalpha<<flag<<'\n'<<(s<u?"s < u":"s >= u")<<'\n'; }
