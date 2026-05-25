#include "Matrix.h"
#include "Database.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Database(vector<Matrix>& list)
{
	size_t choice;
	bool databaseRunning = true;

	while (databaseRunning == true)
	{
		cout << "\nEnter number based on action needed:" <<
			"\n" << "0. Go back to menu"
			"\n" << "1. Add a matrix to database" <<
			"\n" << "2. Remove a matrix from the database" <<
			"\n" << "3. View a matrix from the database" <<
			"\n" << "4. Clear all matrices from the database" << endl;

		cin >> choice;

		while (choice != 0 && choice != 1 && choice != 2 &&
			   choice != 3 && choice != 4)
		{
			cout << "Enter a valid integer 0-4";
			cin >> choice;
		}

		if (choice == 0) { databaseRunning = false; }
		else if (choice == 1) { AppendMatrix(list); }
		else if (choice == 2) { RemoveMatrix(list); }
		else if (choice == 3) { ViewMatrix(list); }
		else if (choice == 4) { ClearMatrix(list); }
	}
}

void AppendMatrix(vector<Matrix>& list)
{
	cout << "\nEnter number of rows in the matrix:" << endl;
	size_t rows;
	cin >> rows;

	while (rows < 1)
	{
		cout << "\nEnter valid number of rows:" << endl;
		cin >> rows;
	}

	cout << "\nEnter number of columns in the matrix:" << endl;
	size_t columns;
	cin >> columns;

	while (columns < 1)
	{
		cout << "\nEnter valid number of columns:" << endl;
		cin >> columns;
	}

	Matrix temp(rows, columns);

	cout << "\nEnter " << rows * columns
		 << " entries for the matrix:" << endl;

	temp.New();
	list.push_back(temp);

	cout << "\nMatrix added to position " 
		 << list.size() << " of database." << endl;
}

void RemoveMatrix(vector<Matrix>& list)
{
	if (list.size() == 0)
	{
		cout << "\nDatabase is currently empty." << endl;
		return;
	}

	size_t indexRemoved;

	cout << "\nTotal matrices in list: " << list.size() << endl;
	cout << "Enter the position of the matrix to be removed"
		 << " or 0 to return to database menu:" << endl;

	cin >> indexRemoved;

	while (indexRemoved < 0 || indexRemoved > list.size())
	{
		if (list.size() == 1)
		{
			cout << "\nEnter a valid position (1) or " 
				 << "0 to return to the database menu:" << endl;
		}
		else
		{
			cout << "\nEnter a valid position (1-" << list.size()
				 << ") or 0 to return to the database menu:" << endl;
		}
		cin >> indexRemoved;
	}

	if (indexRemoved == 0) { return; }
	else { list.erase(list.begin() + indexRemoved - 1); }
	
	cout << "\nMatrix " << indexRemoved << " removed." << endl;
		 
}

void ViewMatrix(vector<Matrix>& list)
{
	if (list.size() == 0)
	{
		cout << "\nDatabase is currently empty." << endl;
		return;
	}

	size_t viewChoice;

	cout << "\nTotal matrices in list: " << list.size() << endl;
	cout << "Enter the position of the matrix to view "
		 <<  "or 0 to return to the database menu : " << endl;

	cin >> viewChoice;
	while (viewChoice < 0 || viewChoice > list.size())
	{
		if (list.size() == 1)
		{
			cout << "\nEnter a valid position (1) or "
				<< "0 to return to the database menu:" << endl;
		}
		else
		{
			cout << "\nEnter a valid position (1-" << list.size()
				<< ") or 0 to return to the database menu:" << endl;
		}
		cin >> viewChoice;
	}

	if (viewChoice == 0) { return; }
	else
	{
		cout << "Matrix in position " << viewChoice << ":" << endl;

		for (size_t i = 1; i <= list[viewChoice - 1].GetRows(); ++i)
		{
			for (size_t j = 1; j <= list[viewChoice - 1].GetColumns(); ++j)
			{
				cout << list[viewChoice - 1](i, j) << ' ';
			}
			cout << endl;
		}
	}
}

void ClearMatrix(vector<Matrix>& list)
{
	if (list.size() == 0)
	{
		cout << "\nDatabase is currently empty." << endl;
		return;
	}

	list.clear();

	cout << "\nDatabase is now empty" << endl;
}