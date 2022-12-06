#include "Gauss_Jordan.h"
#include <vector>
#include <string>
#include <iostream>


GaussJordan::GaussJordan(Matrix m){
    user_matrix = m;
};

bool GaussJordan::isReduced(){
    // check if rows > columns
    if(user_matrix.getDimensions().at(0) > user_matrix.getDimensions().at(1)){
        int *last_row = user_matrix.getRow(user_matrix.getDimensions().at(0));
        for(int i = 0; i < user_matrix.getDimensions().at(1); i++){
            if(last_row[i]!=0){return false;}
        }
    }

    for(int i = 0; i < user_matrix.getDimensions().at(1); i++){
        for(int j = 0; j < user_matrix.getDimensions().at(0); j++){
            int pivot = i;
            if(i!=j){
                if(user_matrix.getEntry(pivot,j)!=0){return false;}
            }
        }
    }
    return true;
}

void GaussJordan::reduceColumn(int column, int pivot, int i){
    // find a value that when I combine the pivot with the current column value will be equal to zero
    for(int j = 0; j < user_matrix.getDimensions().at(0); j++){
        for(int z = -50; z < 50; z++){
            if(z*pivot + user_matrix.getEntry(j,i) == 0){
                user_matrix.addMultiple(i, j, z);
                std::string command = std::to_string(z) + "AM";
                commands.push(command);
            }
        }
    }
}

void GaussJordan::testCombination(std::vector<std::string> current_combination){
    for(auto combination: current_combination){
        if(combination == "AM"){
            // iterate across each row and try to create a pivot
            for(int c = 0; c < user_matrix.getDimensions().at(1); c++){
                if(c < user_matrix.getDimensions().at(1)){

                    int pivot = user_matrix.getEntry(c,c);

                    for(int i = 0; i < user_matrix.getDimensions().at(0); i++){

                        for(int scalar = -50; scalar < 50; scalar++){
                            if(scalar != 0){
                                if(scalar * pivot + user_matrix.getEntry(i,i) == 0){
                                    user_matrix.addMultiple(c,i,scalar);
                                    std::string command = std::to_string(scalar);
                                    command += "AM";
                                    commands.push(command);
                                    break;
                                }
                            }
                        }
                    }
                }    
            }
        }
        else if(combination == "I"){
            for(int row = 0; row < user_matrix.getDimensions().at(0); row++){
                for(int column = 0; column < user_matrix.getDimensions().at(1); column++){
                    if(row!=column && user_matrix.getEntry(row, column)!=0){
                        user_matrix.swapRow(1,2);
                    }
                }
            }
        } else if(combination == "SM"){
            continue;
        }        
    }
}

extern std::vector<std::vector<std::string>> Combinations(int depth); // provides all combinations (file reading takes longer than generation)

void GaussJordan::solve(){
    int rows = user_matrix.getDimensions().at(0); int columns = user_matrix.getDimensions().at(1);
    std::vector<std::vector<std::string>> all_combinations = Combinations(15);
    while(!all_combinations.empty() && !isReduced()){
        testCombination(all_combinations.at(0));
        all_combinations.erase(all_combinations.begin());
    }
    // for(int i = 1; i < columns; i++){
    //     if(i-1 < columns){
    //         int *current_row = user_matrix.getRow(i);
    //         int pivot_value = current_row[i-1];
    //         reduceColumn(i-1, pivot_value, i-1);
    //         // std::cout << pivot_value << "\n";
    //     } else {break;}
    // }
}

void GaussJordan::printCommands(){
    while(!commands.empty()){
        std::cout << commands.front() << "\n";
        commands.pop();
    }
}   

void GaussJordan::printMatrix(){
    user_matrix.printElements();
}

