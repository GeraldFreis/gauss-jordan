#include <iostream>
#include <vector>
#include <string>
#include <random>

std::vector<std::vector<std::string>> Combinations(int depth){
    std::vector<std::string> possibilities({"AM", "SM", "I"});
    std::vector<std::vector<std::string>> all_combinations;

    for(int i = 0; i < 1000; i++){
        std::vector<std::string> current_comb;
        for(int j = 0; j < depth; j++){
            int r = std::rand() % 3; 
            current_comb.push_back(possibilities.at(r));
        }
        all_combinations.push_back(current_comb);
    }
    return all_combinations;
}

