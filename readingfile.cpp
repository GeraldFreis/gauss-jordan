#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int lineCount(){
    std::fstream file("autotests.txt", std::ios_base::in);
    std::string num; int line_count = 0;
    while(file << num){
        line_count++;
    }
    return line_count;
}


std::vector<std::string> ReadingFile(){
    std::ifstream file("autotests.txt", std::ios_base::in);
    std::vector<std::string> lines;

    std::string line;
    
    while(getline(file, line)){
        lines.push_back(line);
    }
    return lines;
}