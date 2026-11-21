#include <iostream>
class Time{int h,m;public:Time(int hh,int mm):h(hh),m(mm){}friend int minutesBetween(const Time&,const Time&);friend bool earlier(const Time&,const Time&);};
inline int minutesBetween(const Time&a,const Time&b){int x=a.h*60+a.m,y=b.h*60+b.m;return x>y?x-y:y-x;}
inline bool earlier(const Time&a,const Time&b){return a.h*60+a.m<b.h*60+b.m;}
int main(){Time d(9,45),a(13,10);std::cout<<minutesBetween(d,a)<<' '<<std::boolalpha<<earlier(a,d)<<'\n';Time n(12,0),b(11,59),s(12,0);std::cout<<minutesBetween(b,n)<<' '<<earlier(b,n)<<'\n'<<minutesBetween(n,s)<<' '<<earlier(n,s)<<'\n';}
