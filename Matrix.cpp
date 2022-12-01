#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int **raw_matrix, int size_x, int size_y){
	if(size_x > 0 && size_y > 0){
		user_matrix = new int*[size_x];
		for(int i = 0; i < size_x; i++){
			for(int j = 0; j < size_y; j++){
				user_matrix[i][j] = raw_matrix[i][j];
			}
		}
	}
	rows = size_x;
	columns = size_y;
}

Matrix::Matrix(){
	user_matrix = new int*[10];

	for(int i = 0; i < 0; i++){
		user_matrix[i] = new int[10];
	}
	
	rows = 10; columns = 10;
}

int **Matrix::getMatrix(){
	return user_matrix;
};

void Matrix::setMatrix(int **raw_matrix, int size_x, int size_y){
	if(size_x > 0 && size_y > 0){
		user_matrix = new int*[size_x];
		for(int i = 0; i < size_x; i++){
			for(int j = 0; j < size_y; j++){
				user_matrix[i][j] = raw_matrix[i][j];
			}
		}
	}
	rows = size_x;
	columns = size_y;
};


int Matrix::getEntry(int x, int y){
	return user_matrix[x][y];
};

void Matrix::printElements(){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			std::cout << user_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
};

int *Matrix::getRow(int row_number){
	int *row = new int[columns];
	for(int i = 0; i < columns; i++){
		row[i] = user_matrix[row_number][i];
	}
	return row;
};

int *Matrix::getColumn(int column_number){
	if(column_number > 0){
		int *column = new int[rows];
		for(int i = 0; i < rows; i++){
			column[i] = user_matrix[i][column_number];
		}
		return column;
	}
	else {
		return nullptr;
	}
};

void Matrix::swapRow(int row_1, int row_2){
	// iterate across the first row, store all values in a temporary array, make all values the second row
	// iterate across second row, and make second row equal to temporary array values
	if((row_1-1 >= 0 && row_1 < rows) && (row_2-1 >= 0 && row_2 < rows)){
		int temporary_value = 0; 
		for(int i = 0; i < columns; i++){
			temporary_value = user_matrix[row_1-1][i];
			user_matrix[row_1-1][i] = user_matrix[row_2-1][i];
			user_matrix[row_2-1][i] = temporary_value;
		}
	}
	else {
		std::cout << "Out of row bounds (swapRow)" << "\n";
	}

};
void Matrix::addMultiple(int row_to_add, int row_to_receive, int scalar){
	if(row_to_add-1 >= 0 && row_to_add <= rows && row_to_receive-1>=0 && row_to_receive <= rows){
		int value = 0;
		for(int i = 0; i < columns; i++){
			value = scalar * user_matrix[row_to_add-1][i];
			user_matrix[row_to_receive-1][i] += value;
		}
	}
};

void Matrix::takeMultiple(int row_to_subtract, int row_to_receive, int scalar){
	if(row_to_subtract-1 >= 0 && row_to_subtract <= rows && row_to_receive-1>=0 && row_to_receive <= rows){
		int value = 0;
		for(int i = 0; i < columns; i++){
			value = scalar * user_matrix[row_to_subtract-1][i];
			user_matrix[row_to_receive-1][i] -= value;
		}
	}
};

Matrix::Matrix(std::vector<int> m, std::string dim){
	rows = dim.at(0) - '0'; columns = dim.at(2) - '0';
	if(rows > 1 && columns > 1){
		user_matrix = new int*[rows];
		for(int i = 0; i < rows; i++){
			user_matrix[i] = new int[columns];
		}

		bool greater_than_1 = true;

		int counter_r = 0; int counter_c = 0; int vector_counter = 0;
		for(auto a: m){
			user_matrix[counter_r][counter_c] = a;
			// std::cout << a << " " << counter_r << " " << counter_c << "\n";
			vector_counter++; counter_c++;
			if(counter_c % (columns) == 0){
				counter_r++;
				counter_c = 0;
			}			
		}
	}
	else {
		std::cout << "matrix is not a matrix" << "\n";
		user_matrix = new int*[10];
		for(int i = 0; i < 10; i++){
			user_matrix[i] = new int[10];
		}
	}
};