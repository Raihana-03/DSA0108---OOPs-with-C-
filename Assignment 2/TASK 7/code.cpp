#include <iostream>
#include <chrono>
class Shift{int a[10]{},n=0;public:void add(int v){if(n<10)a[n++]=v;else{for(int i=1;i<10;i++)a[i-1]=a[i];a[9]=v;}}int latest()const{return n?a[n-1]:-1;}};
class Ring{int a[10]{},n=0,next=0;public:void add(int v){a[next]=v;next=(next+1)%10;if(n<10)++n;}int latest()const{return n?a[(next+9)%10]:-1;}};
int main(){constexpr int N=1000000;Shift old;Ring revised;auto s=std::chrono::steady_clock::now();for(int i=0;i<N;i++)old.add(i);auto m=std::chrono::steady_clock::now();for(int i=0;i<N;i++)revised.add(i);auto e=std::chrono::steady_clock::now();std::cout<<"Original latest: "<<old.latest()<<'\n'<<"Redesigned latest: "<<revised.latest()<<'\n'<<"Original microseconds: "<<std::chrono::duration_cast<std::chrono::microseconds>(m-s).count()<<'\n'<<"Circular microseconds: "<<std::chrono::duration_cast<std::chrono::microseconds>(e-m).count()<<'\n'<<"Shift insertion O(10); circular insertion O(1).\n";}
