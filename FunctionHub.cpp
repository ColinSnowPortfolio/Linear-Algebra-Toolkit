#include "Matrix.h"
#include "FunctionHub.h"

#include <string>
#include <iostream>

using namespace std;

void AddMatrices() 
{
	cout << endl;
	cout << "How many matrices to add together?" << endl;
	size_t matrixCount;
	cin >> matrixCount;

	while (matrixCount < 2)
	{
		cout << "\nEnter valid matrix count for addition (2+)" << endl;
		cin >> matrixCount;
	}

	cout << "\nHow many rows in the matrices?" << endl;
	size_t rows;
	cin >> rows;

	while (rows < 1)
	{
		cout << "\nEnter valid number of rows" << endl;
		cin >> rows;
	}

	cout << "\nHow many columns in the matrices" << endl;
	size_t columns;
	cin >> columns;

	while (columns < 1)
	{
		cout << "\nEnter valid number of columns" << endl;
		cin >> columns;
	}

	// Create sum matrix and add each matrix onto it
	Matrix sum(rows, columns);

	for (size_t i = 1; i <= matrixCount; ++i)
	{
		Matrix temp(rows, columns);

		cout << "\nFor matrix " << i << ", enter " 
			 << rows * columns << " entries." << endl;

		temp.New();

		for (size_t i = 1; i <= rows; ++i)
		{
			for (size_t j = 1; j <= columns; ++j)
			{
				sum(i, j) += temp(i, j);
			}
		}
	}

	// Display sum matrix
	cout << "\nSum of matrices: " << endl;
	for (size_t i = 1; i <= rows; ++i)
	{
		for (size_t j = 1; j <= columns; ++j)
		{
			cout << sum(i, j) << ' ';
		}
		cout << endl;
	}

}

void MultiplyMatrices() 
{

}

void RREF()
{

}

void Determinant()
{

}

void Nonsingular()
{

}

void Geometric()
{

}

void Eigen()
{

}

void Diagonalize()
{

}