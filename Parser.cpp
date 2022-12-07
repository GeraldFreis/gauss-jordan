#include <string>
#include <vector>
#include <iostream>

std::string get_numbers(std::string input){
    if(input.size() > 1){
        std::string number; char current_char = input.at(0);
        if(current_char != '-'){ // if the number is positive
            int counter = 0;

            while(current_char != ' ' && current_char >= '0' && current_char <= '9' && counter < input.size()){
                number = number + current_char;
                counter++;
                current_char = input.at(counter);
            }
            return number;
        } else { // if the number is negative
            number = "-"; current_char = input.at(1);
            int counter = 1;
            while(current_char != ' ' && current_char >= '0' && current_char <= '9' && counter < input.size()){
                number += current_char;
                counter++;
                current_char = input.at(counter);
            }
            return number;
        }
    }
    return input;
}

std::vector<int> string_to_numbers(std::string raw_input){
    std::vector<int> numbers;

    if(raw_input.size() > 0){
        while(raw_input.size() > 1){
            if(raw_input.at(0) == ' '){raw_input.erase(raw_input.begin());}
            std::string number = get_numbers(raw_input);
            if(number.size() != 1){

                for(int i = 0; i < number.size()-1; i++){
                    if(raw_input.size()>2){
                        raw_input.erase(raw_input.begin());
                    }
                }
                if(raw_input.size()>=1){
                    raw_input.erase(raw_input.begin());
                }
            } else {
                std::cout << number << "\n";
                raw_input.erase(raw_input.begin());
                raw_input.erase(raw_input.begin());
            }
            if(raw_input.size()>1){
                std::cout << raw_input << "\n";
            }
            numbers.push_back(std::stoi(number));
        }
    }

    return numbers;
}