#include "matrix.h"
#include "FunctionHub.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

Matrix::Matrix(size_t rows, size_t columns)
{
	m_rows = rows;
	m_columns = columns;
	m_elementCount = rows * columns;
	m_filledElements = 0;
	numberSet.resize(m_elementCount);
}

const int Matrix::GetRows()
{
	return m_rows;
}

const int Matrix::GetColumns()
{
	return m_columns;
}

void Matrix::New()
{
	double input;
	size_t row;
	size_t column;

	for (size_t i = 0; i < m_elementCount; ++i)
	{
		cin >> input;

		numberSet[i] = input;
	}
}

double& Matrix::operator()(size_t row, size_t column)
{
	if (row < 1 || row > m_rows || column < 1 || column > m_columns)
		throw std::out_of_range("Index out of bounds");

	return numberSet[(row - 1) * m_columns + (column - 1)];
}

const double& Matrix::operator()(size_t row, size_t column) const
{
	if (row < 1 || row > m_rows || column < 1 || column > m_columns)
		throw std::out_of_range("Index out of bounds");

	return numberSet[(row - 1) * m_columns + (column - 1)];
}

double Matrix::clean(double x)
{
	if (fabs(x) < 1e-10)
	{
		return 0;
	}
	return x;
}