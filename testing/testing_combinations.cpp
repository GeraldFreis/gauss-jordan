// #include "../combinations.cpp"
#include <iostream>
#include <vector>
#include <string>

extern std::vector<std::vector<std::string>> Combinations(int depth);




int main(){
    for(auto a: Combinations(15)){
        for(auto b: a){
            std::cout << b << " ";
        }
        std::cout << "\n";
    }
}