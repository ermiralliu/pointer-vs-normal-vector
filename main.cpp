#include "requirements.hpp"

int main(){
    std::vector<Sth> vec;
    vec.reserve(100000);
    Random rand((unsigned) time(nullptr));
    
    for(int i=0; i<100000; ++i){
        vec.push_back(Sth{ rand(), randomString(), randomString(), randomString()});
        // std::cout<<vec[i].a<<' '<<std::string(vec[i].b.begin())<<' '<< std::string(vec[i].c.begin())<<std::string(vec[i].d.begin())<<'\n';
    }
    std::cout<<sizeof(Sth)<< '\n';
    const auto start = std::chrono::steady_clock::now();
    std::sort(vec.begin(), vec.end());
    const std::chrono::duration<float, std::milli> elapsed = std::chrono::steady_clock::now() - start;
    std::cout<<elapsed.count() <<" ms"<<'\n';
    //auto length = &vec[0].b[0] - &vec[0].c[0];              //ends up being -64, do they're right next to each other in memory;
    //std::cout<< length;
    // for(int i = 0 ; i<200; ++i){
    //     std::cout<< vec[i].a <<' '<< std::string(vec[i].b.begin())<<'\n';
    // }
}