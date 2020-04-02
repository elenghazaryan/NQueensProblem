#include "NQueensProblem.h"
#include <iostream>
using namespace std;

QueensProblem::QueensProblem(int _NumOfQueens)
	: NumOfQueens(_NumOfQueens)
{
	//here we are creating 2D array with as many rows and columns as the number of queens
	ChessTable.resize(NumOfQueens);
	for (auto& ChessRow : ChessTable)
		ChessRow.resize(NumOfQueens);
	//resizing cols and rows
}

void QueensProblem::solve()
{
	//solve the problem starting with the first column(0)
	if (SetQueens(0)) {
		PrintQueens();
	}
	else {
		cout << "There is no solution ...\n";
	}
}

bool QueensProblem::SetQueens(int ColIndex)
{
	//if we have considered as many queens as the number of rows/cols then we are done !!!
	// so we have found valid places for all the queens
	if (ColIndex == NumOfQueens) {
		return true;
	}
	for (int RowIndex = 0; RowIndex < NumOfQueens; ++RowIndex) {
		//check if the given location is valid
		if (IsPlaceValid(RowIndex, ColIndex)) {
			//valid place? so put a queen to this location
			ChessTable[RowIndex][ColIndex] = 1;
			//check next queen(next col)
			if (SetQueens(ColIndex + 1)) 
				return true;
			//we failed to put a given queen in a given col: BACKTRACKING !!!
			ChessTable[RowIndex][ColIndex] = 0;
		}

	}
	return false;
}

bool QueensProblem::IsPlaceValid(int RowIndex, int ColIndex) const
{
	//there can't be another queen in the same row
	for (int i = 0; i < ColIndex; i++)
		if (ChessTable[RowIndex][i] == 1)
			return false;
	//there is a queen in the diagonal (from top left to bottom right)
	for (int i = RowIndex, j = ColIndex; i >= 0 && j >= 0; i--, j--) {
		if (ChessTable[i][j] == 1)
			return false;
	}
	//there is a queen in the diagonal (from top right to bottom left)
	for (int i = RowIndex, j = ColIndex; i < NumOfQueens && j >= 0; i++, j--) {
		if (ChessTable[i][j] == 1)
			return false;
	}
	return true;
}

void QueensProblem::PrintQueens() const
{	//there is aqueen where the table contains a 1 else there is no queens(0 value)
	// * represents the queens and - is an empty state
	for (size_t i = 0; i < ChessTable.size(); i++) {
		for (size_t j = 0; j < ChessTable.size(); j++) {
			if (ChessTable[i][j] == 1) {
				cout << " * ";
			}
			else {
				cout << " - ";
			}
		}
		cout << " \n ";
	}
}