#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

class Matrix
{
public:
	Matrix(size_t rows, size_t columns);
	const size_t GetRows();
	const size_t GetColumns();
	void New();
	double& operator()(size_t row, size_t column);
	const double& operator()(size_t row, size_t column) const;

private:

	double clean(double x);

	size_t m_filledElements;
	size_t m_rows;
	size_t m_columns;
	size_t m_elementCount;
	vector<double> numberSet;
	vector<double> invNumberSet;
};

#endif