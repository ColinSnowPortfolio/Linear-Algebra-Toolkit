#ifndef DATABASE_H
#define DATABASE_H

#include "Matrix.h"

#include <vector>

using namespace std;

void Database(vector<Matrix>& list);
void AppendMatrix(vector<Matrix>& list);
void RemoveMatrix(vector<Matrix>& list);
void ViewMatrix(vector<Matrix>& list);
void ClearMatrix(vector<Matrix>& list);

#endif