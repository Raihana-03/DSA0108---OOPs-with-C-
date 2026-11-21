#include <iostream>
enum class Zone { Inner, Middle, Outer };
constexpr int FARE_PAISE[] = {1000, 2000, 3000};
constexpr int SURCHARGE_PERCENT = 20;
int main(){ std::cout << "Inner=Rs10 Middle=Rs20 Outer=Rs30\nSurcharge=20%\n"; }
