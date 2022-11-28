#ifndef MATRIX
#define MATRIX
#include <vector>
#include <string>

class Matrix {
	private:
		int **user_matrix;
		int rows;
		int columns;

	public:
		Matrix(int **raw_matrix, int size_x, int size_y);
		Matrix(std::vector<int> m, std::string dim);
		int **getMatrix();
		void setMatrix(int **raw_matrix, int size_x, int size_y);

		void resizeMatrix(int sized_x, int size_y);
		int getEntry(int x, int y);
		void printElements();

		int *getRow(int row_number);
		int *getColumn(int column_number);

		void swapRow(int row_1, int row_2);
		void addMultiple(int row_1, int row_2, int scalar);
		void takeMultiple(int row_1, int row_2, int scalar);
		
		// ~Matrix(){for(int i = 0; i < rows; i++){delete [] user_matrix[i];}}

};


#endif