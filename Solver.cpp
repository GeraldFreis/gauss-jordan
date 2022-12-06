#include "Solver.h"

bool allZeros(int *row, int len){
    for(int i = 0; i < len; i++){
        if(row[i] != 0){
            return false;
        }
    }
    return true;
}

int pivotPosition(int *row, int len){
    
    for(int i = 0; i < len; i++){
        if(row[i] != 0){
            return i;
        }
    }
    return 0;
}

bool isPivot(int *column, int len, int pivot_position){
    if(pivot_position <= len-1 && pivot_position >= 0){
        for(int i = 0; i < len; i++){
            if(column[i] != 0 && i != pivot_position){
                return false;
            }
        }
    
    return true;
    }
    return false;
}

// private:

//checking if the user_matrix matrix is reduced
bool Solver::isReduced(){
    /* 
    for a matrix to be in row reduced form:
        Rows composed only of zeros must be in the last row
        left-most non-zero entry of each row must be a pivot
        each pivot is further to the right of the row preceeding it
    */ 

   // check if there is a row of zeros 
   for(int i = 0; i < rows; i++){
        int *current_row = m.getRow(i);
        if(i != (rows-1)){
            if(allZeros(current_row, columns) == true){
                return false;
            }
        }
   }

   // checking if left-most non-zero is a pivot
        // iterate across every row and check that the last pivot is further left than the preceding pivots
    int last_pivot = 0; 
    for(int i = 0; i < rows; i++){
        int *current_row = m.getRow(i);
        if(allZeros(current_row, columns) == true){break;}
        int this_pivot = pivotPosition(current_row, columns);
        
        if(this_pivot < last_pivot){
            return false;
        }
        else {last_pivot = this_pivot;}
    }

    // checking if every pivot is in fact a pivot
        // iterate across every row and get the pivot position
        // iterate across every column and check if the pivot is an actual pivot
    int *pivot_array = new int[columns];

    if(rows >= columns){
        for(int i = 0; i < columns; i++){
            int *current_row = m.getRow(i);
            pivot_array[i] = pivotPosition(current_row, columns);
        }
    }

    for(int i = 0; i < columns; i++){
        int *current_column = m.getColumn(i);

        if(isPivot(current_column, rows, pivot_array[i]) == false){
            // std::cout << pivot_array[i] << "\n";
            // std::cout << "failed at 46" << "\n";
            return false;
        }
    }
    delete [] pivot_array;

    return true;
}


void Solver::reduceColumns(){
    /*iterate across every row:
        grab every pivot in every row:
        iterate across all of the numbers above it (iterate across all rows in that column position)
        find a multiple of the pivot that when added or subtracted from the current position produces zero
        enact this step
    */
   for(int row = 0; row < rows; row++){
        // getting every pivot and its position
        int *current_row = m.getRow(row); 
        int pivot_position = pivotPosition(current_row, columns);
        std::cout << pivot_position;
        int pivot = m.getEntry(row, pivot_position);

        // iterating across every row
        for(int new_row = 0; new_row < rows; new_row++){
            if(new_row != row){
                for(int scalar = -100; scalar < 101; scalar++){
                    if((scalar != 0) && (scalar * pivot + m.getEntry(new_row, pivot_position) == 0) && (isReduced() == false)){
                        
                        std::string command = "Add Multiple of: ";
                        command +=  std::to_string(scalar); command += " x row: ";
                        command += std::to_string(row+1);
                        command += " to row: ";
                        command += std::to_string(new_row+1);

                        commands.push(command);
                        std::cout << command << '\n';
                        m.addMultiple(row, new_row, scalar);
                        m.printElements(); std::cout << "\n";
                        
                    }
                }
            }
        }
   }

   
    
}



void Solver::solve(){
    int counter = 0;
    
    while(isReduced() == false && counter < 10){
        reduceColumns();
        // printMatrix(); std::cout << "\n\n";
        counter++;
    }
}


void Solver::printSteps(){
    while(isReduced()!=false && commands.empty() == false){
        std::cout << commands.front() << "\n";
        commands.pop();
    }
}
void Solver::printMatrix(){
    m.printElements();
}