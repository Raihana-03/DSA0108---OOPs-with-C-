#include <iostream>
#include <stdexcept>
#include <string>
class Time {
    int seconds;
public:
    explicit Time(int s=0):seconds(s<0?0:s){}
    Time& operator++(){++seconds;return *this;}
    Time operator++(int){Time old=*this;++seconds;return old;}
    bool operator==(const Time& t)const{return seconds==t.seconds;}
    bool operator<(const Time& t)const{return seconds<t.seconds;}
    int value()const{return seconds;}
    void print()const{std::cout<<seconds/3600<<':'<<(seconds/60)%60<<':'<<seconds%60;}
};
class Playlist {
    std::string* tracks; int n;
public:
    Playlist(const std::string a[],int size):tracks(size?new std::string[size]:nullptr),n(size){for(int i=0;i<n;++i)tracks[i]=a[i];}
    ~Playlist(){delete[] tracks;}
    std::string& operator[](int i){if(i<0||i>=n)throw std::out_of_range("track index out of range");return tracks[i];}
    const std::string& operator[](int i)const{if(i<0||i>=n)throw std::out_of_range("track index out of range");return tracks[i];}
};
int main(){
    Time t(3599); Time a=t++; Time b=++t;
    std::cout<<"a="<<a.value()<<" b="<<b.value()<<" t="<<t.value()<<'\n';
    Time roll(3599); ++roll; std::cout<<"Roll-over seconds: ";roll.print();std::cout<<'\n';
    std::string songs[]={"Intro","Main Theme","Finale"}; Playlist p(songs,3);
    std::cout<<"Playing: "<<p[1]<<'\n';
    try{std::cout<<p[-1]<<'\n';}catch(const std::out_of_range& e){std::cout<<"Checked: "<<e.what()<<'\n';}
    try{std::cout<<p[3]<<'\n';}catch(const std::out_of_range& e){std::cout<<"Checked: "<<e.what()<<'\n';}
}
