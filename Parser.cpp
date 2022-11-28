#include <string>
#include <vector>
#include <iostream>

std::string get_numbers(std::string input){
    if(input.size() > 1){
        std::string number; char currentchar = input.at(0);
        int counter = 0;

        while(currentchar != ' ' && currentchar >= '0' && currentchar <= '9'){
            number = number + currentchar;
            counter++;
            currentchar = input.at(counter);
        }
        return number;
    }
    return input;
}

std::vector<int> string_to_numbers(std::string raw_input){
    std::vector<int> numbers;

    if(raw_input.size() > 0){
        while(raw_input.size() > 0){
            std::string number = get_numbers(raw_input);
            if(number.size() != 1){
                for(int i = 0; i < number.size()-1; i++){
                    raw_input.erase(raw_input.begin());
                }
            } else {
                raw_input.erase(raw_input.begin());
                raw_input.erase(raw_input.begin());
            }
            // std::cout << raw_input.size();

            numbers.push_back(std::stoi(number));
        }
    }

    return numbers;
}