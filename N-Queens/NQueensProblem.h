#pragma once
#include <vector>
using namespace std;

class QueensProblem
{
	vector <vector<int>> ChessTable;
	int NumOfQueens = 0;

public:
	QueensProblem(int _NumOfQueens);
	void solve();

private:
	bool SetQueens(int ColIndex);
	bool IsPlaceValid(int RowIndex, int ColIndex) const;
	void PrintQueens() const;
};