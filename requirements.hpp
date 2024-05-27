#include <chrono>
#include <algorithm>
#include <vector>
#include <random>
#include <iostream>
#include <array>

using Random = std::subtract_with_carry_engine<unsigned long long int,30,20,30>;
using Strandom = std::subtract_with_carry_engine<unsigned char, 7, 4,7>;

struct Sth{
    private:
        unsigned long long int a;
        std::array<char,64> b;
        std::array<char,64> c;
        std::array<char,64> d;
    public:
        Sth(unsigned long long int a, std::array<char,64>  b, std::array<char,64> c, std::array<char,64> d): a{a}, b{b}, c{c}, d{d} { }

        bool operator<(Sth two){
            return a<two.a;
        }
    // void print(){
    //     std::cout<<a<<' '<<b<<' '<<c<<' '<<'d'<<'\n';
    // }
};

std::array<char,64> randomString(){
    std::random_device device;
    Strandom strand(device());
    std::uniform_int_distribution<> distribution(1,255);
    std::array<char, 64> str;
    for(char& a : str)
        a = distribution(strand);
    str[63] = '\0';
    return str;
}
