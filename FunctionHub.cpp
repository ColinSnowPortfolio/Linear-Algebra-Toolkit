#include "Matrix.h"
#include "FunctionHub.h"

#include <string>
#include <iostream>

using namespace std;

void AddMatrices(vector<Matrix>& list)
{
	if (list.size() == 0)
	{
		cout << "\nDatabase is currently empty." << endl;
		return;
	}

	size_t addendCount;
	vector<size_t> addendIndexList;
	size_t addendIndex;
	bool dimEqual = true;

	cout << "\nEnter how many matrices to add: " << endl;
	cin >> addendCount;

	while (addendCount < 2)
	{
		cout << "\nEnter a valid addend count (2+):" << endl;
		cin >> addendCount;
	}

	cout << "\nEnter the position of " << addendCount
		<< " matrices in the database to sum:" << endl;

	for (size_t i = 0; i < addendCount; ++i)
	{
		cin >> addendIndex;
		while (addendIndex < 1 || addendIndex > list.size())
		{
			if (list.size() == 1)
			{
				cout << "\nEnter a valid position (1):" << endl;
			}
			else
			{
				cout << "\nEnter a valid position (1-"
					<< list.size() << "):" << endl;
			}
			cin >> addendIndex;
		}

		addendIndexList.push_back(addendIndex);
	}

	size_t rowDim = list[addendIndexList[0] - 1].GetRows();
	size_t colDim = list[addendIndexList[0] - 1].GetColumns();

	Matrix sum(rowDim, colDim);

	for (size_t k = 0; k < addendCount; ++k)
	{
		if (rowDim != list[addendIndexList[k] - 1].GetRows() ||
			colDim != list[addendIndexList[k] - 1].GetColumns())
		{
			cout << "\nDimensions of matrices are not equal" 
				 << " and matrices cannot be added." << endl;

			return;
		}
		for (size_t i = 1; i <= rowDim; ++i)
		{
			for (size_t j = 1; j <= colDim; ++j)
			{
				sum(i, j) += list[addendIndexList[k] - 1](i, j);
			}
		}
	}

	cout << "\nSum of matrices:" << endl;
	for (size_t i = 1; i <= rowDim; ++i)
	{
		for (size_t j = 1; j <= colDim; ++j)
		{
			cout << sum(i, j) << ' ';
		}
		cout << endl;
	}

	size_t choice;

	cout << "\nEnter number for what to do with matrix sum:"
		 << "\n1. Discard"
		 << "\n2. Add to database"
		 << "\n3. Replace matrix in database"
		 << endl;

	cin >> choice;

	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "\nEnter a valid integer 1-3" << endl;
		cin >> choice;
	}

	if (choice == 1) { return; }
	else if (choice == 2)
	{
		list.push_back(sum);

		cout << "\nMatrix sum added to position "
			 << list.size() << " of databse." << endl;

		return;
	}
	else if (choice == 3)
	{
		size_t replaceIndex;
		cout << "\n Enter which position to replace in database:" << endl;
		cin >> replaceIndex;

		while (replaceIndex < 1 || replaceIndex > list.size())
		{
			if (list.size() == 1)
			{
				cout << "\nEnter a valid position (1):" << endl;
			}
			else
			{
				cout << "\nEnter a valid position (1-"
					<< list.size() << "):" << endl;
			}
			cin >> replaceIndex;
		}

		list[replaceIndex - 1] = sum;

	}
}

void MultiplyMatrices(vector<Matrix>& list)
{

}

void RREF(vector<Matrix>& list)
{

}

void Determinant(vector<Matrix>& list)
{

}

void Nonsingular(vector<Matrix>& list)
{

}

void Geometric(vector<Matrix>& list)
{

}

void Eigen(vector<Matrix>& list)
{

}

void Diagonalize(vector<Matrix>& list)
{

}