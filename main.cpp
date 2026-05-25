#include "Matrix.h"
#include "FunctionHub.h"
#include "Database.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
	size_t choice;
	vector<Matrix> matrixList;
	
	cout << "Welcome to Colin Snow's Linear Algebra Toolkit v1.0" << endl;

	bool menuRunning = true;
	while ( menuRunning )
	{
		cout << "\nMenu\nEnter number based on action needed:" <<
			"\n" << "0. Quit" <<
			"\n" << "1. Add/remove matrices in database"
			"\n" << "2. Add/subtract matrices" <<
			"\n" << "3. Multiply matrices" <<
			"\n" << "4. Convert to reduced row echelon form" <<
			"\n" << "5. Find determinant" <<
			"\n" << "6. Is nonsingular?" <<
			"\n" << "7. Geometric transformations" <<
			"\n" << "8. Find eigenvectors and corresponding eigenvalues" <<
			"\n" << "9. Diagonalize a matrix" << endl;

		cin >> choice;

		while (choice != 0 && choice != 1 && choice != 2 && 
			   choice != 3 && choice != 4 && choice != 5 && 
			   choice != 6 && choice != 7 && choice != 8 &&
			   choice != 9)
		{
			cout << "Enter a valid integer 0-8";
			cin >> choice;
		}

		if		(choice == 0) { menuRunning = false; }
		else if (choice == 1) { Database(matrixList); }
		else if (choice == 2) { AddMatrices(); }
		else if (choice == 3) { MultiplyMatrices(); }
		else if (choice == 4) { RREF(); }
		else if (choice == 5) { Determinant(); }
		else if (choice == 6) { Nonsingular(); }
		else if (choice == 7) { Geometric(); }
		else if (choice == 8) { Eigen(); }
		else if (choice == 9) { Diagonalize(); }
		
	}	

	cout << "\nThank you for using the program!" << endl;
	return 0;

}