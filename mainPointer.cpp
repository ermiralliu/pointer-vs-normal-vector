#include "requirements.hpp"

int main(){
    Random rand((unsigned) time(nullptr));
    std::random_device device;
    
    std::vector<Sth*> vec;
    vec.reserve(100000);
    for(int i=0; i<100000; ++i){
        vec.push_back( new Sth{ rand(), randomString(), randomString(), randomString()});
        //std::cout<<vec[i].a<<' ';
    }
    std::cout<<sizeof(Sth)<<'\n';
    const auto start = std::chrono::steady_clock::now();
    std::sort(vec.begin(), vec.end(), [](Sth* one, Sth* two){ return *one < *two ;});
    const std::chrono::duration<float, std::milli> elapsed = std::chrono::steady_clock::now() - start;
    std::cout<<elapsed.count() <<" ms\n";
    // for(int i = 0 ; i<200; ++i){
    //      std::cout<< vec[i]->a <<' '<< std::string(vec[i]->b.begin())<<'\n';
    // }
    for(auto& element: vec){
        delete element;
    }
}