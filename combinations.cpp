#include <iostream>
#include <vector>
#include <string>
#include <random>



std::vector<std::string> creatingCombinations(int depth){
    std::vector<std::string> current_combination;
    std::vector<std::string> possibilities({"AM", "SM", "I"});
    for(int i = 0; i < depth; i++){
        int r = std::rand() * 3;
        current_combination.push_back(possibilities.at(r));
    }
    return current_combination;
}


std::vector<std::vector<std::string>> combinations(int depth){
    std::vector<std::vector<std::string>> combs;
    for(int i = 0; i < 100; i++){
        combs.push_back(creatingCombinations(depth));
    }
}   