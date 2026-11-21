#include <cstring>
#include <iostream>
class Text {
    char* data;
public:
    Text(const char* s="") { data=new char[std::strlen(s)+1]; std::strcpy(data,s); }
    Text(const Text& other) { data=new char[std::strlen(other.data)+1]; std::strcpy(data,other.data); std::cout<<"[copy] "; }
    Text& operator=(const Text& other) {
        if(this!=&other){char* fresh=new char[std::strlen(other.data)+1];std::strcpy(fresh,other.data);delete[] data;data=fresh;}
        return *this;
    }
    ~Text(){delete[] data;}
    Text& operator+=(const Text& rhs) {
        char* fresh=new char[std::strlen(data)+std::strlen(rhs.data)+1];
        std::strcpy(fresh,data);std::strcat(fresh,rhs.data);delete[] data;data=fresh;return *this;
    }
    friend Text operator+(const Text& a,const Text& b){Text result(a);result+=b;return result;}
    bool operator==(const Text& rhs)const{return std::strcmp(data,rhs.data)==0;}
    bool operator!=(const Text& rhs)const{return !(*this==rhs);}
    friend std::ostream& operator<<(std::ostream& out,const Text& t){return out<<t.data;}
};
int main(){
    Text a("Hello"),b(" "),c("World");
    Text message=a+b+c;
    std::cout<<"Message: "<<message<<'\n';
    std::cout<<"Empty text: "<<Text("")<<'\n';
    a=a;
    std::cout<<"Self assignment: "<<a<<'\n';
    std::cout<<std::boolalpha<<"Equal to Hello: "<<(a==Text("Hello"))<<'\n';
    Text longText("A very long message for the SMS gateway");
    std::cout<<"Long: "<<longText<<'\n';
}
