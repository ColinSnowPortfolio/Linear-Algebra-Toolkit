#ifndef FUNCTIONHUB_H
#define FUNCTIONHUB_H

#include "Matrix.h"

#include <vector>

using namespace std;

void AddMatrices(vector<Matrix>& list);
void MultiplyMatrices(vector<Matrix>& list);
void RREF(vector<Matrix>& list);
void Determinant(vector<Matrix>& list);
void Nonsingular(vector<Matrix>& list);
void Geometric(vector<Matrix>& list);
void Eigen(vector<Matrix>& list);
void Diagonalize(vector<Matrix>& list);

#endif