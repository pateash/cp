#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>

/*
Given a cost matrix cost[][] and a position (m, n) in cost[][],
write a function that returns cost of minimum cost path to reach (m, n) from (0, 0).
Each cell of the matrix represents a cost to traverse through that cell.
Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination).
You can only traverse down, right and diagonally lower cells from a given cell, i.e.,
from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed.
You may assume that all costs are positive integers.
			RECURSION TREE FOR THIS PROBLEM
				          mC(2, 2)
			   /	         |         \
		mC(1, 1)        mC(1, 2)        mC(2, 1)
/      |      \      /      |      \         /      |       \
mC(0,0) mC(0,1) mC(1,0) mC(0,1) mC(0,2) mC(1,1) mC(1,0) mC(1,1) mC(2,0)
*/
using namespace std;

int m;
int n;
vector<vector<int>>mat;//matrix that store the values
// non DP simple solution
int shortest_path_nondp(int i,int j) {
	//we are starting from 0,0 and go upto m,n
	if (i == m-1&&j == n-1) {
		//if already on destination return cost of last block too
		return mat[i][j];
	}
	else if (i == m-1)
		//if we are on last row than we cannot go any where except right
		return mat[i][j]+shortest_path_nondp(i, j + 1);//we have to add the cost of this block

	else if (j == n-1)
		//if we are on last column then we can go only down
		return mat[i][j]+shortest_path_nondp(i + 1, j);//have to add the cost of this block
	else
	{
		//if all the three possibilities are allowed
		int ofRight = shortest_path_nondp(i, j+1);
		int ofDown = shortest_path_nondp(i+1, j);
		int ofRightDown = shortest_path_nondp(i + 1, j + 1);
		return mat[i][j] + min(ofRight, min(ofDown, ofRightDown));
		//returning min of all the three
	}
}
//DP solution
//time complexity = total size of table(or max no. of queries) * work in each query
//O(m*n)
vector<vector<int> >dp_table;
#define NIL -1
//for checking availability in dp(use value which can never appear in table)
int shortest_path_dp(int i,int j) {
	if (i == m-1&&j == n-1)
		return mat[i][j];
	if (dp_table[i][j] != NIL)//if already calculated
		return dp_table[i][j];
	if (i == m - 1)
	{
		dp_table[i][j] = mat[i][j] + shortest_path_dp(i, j + 1);
	}
	else if (j == n - 1)
	{
		dp_table[i][j] = mat[i][j] + shortest_path_dp(i+1, j);
	}
	else {
		int ofRight = shortest_path_dp(i, j + 1);
		int ofDown = shortest_path_dp(i + 1, j);
		int ofRightDown = shortest_path_dp(i + 1, j + 1);

		dp_table[i][j] = mat[i][j] + min(ofRight, min(ofDown, ofRightDown));
	}
	return dp_table[i][j];
}
int main() {
	cout << "enter m and n" << endl;
	//m and n are global
	cin >> m >> n;
	//initialising the matrix
	for (size_t i = 0; i < m; i++)
	{
		vector<int>temp(n);
		for (size_t j = 0; j < n; j++)
		{
			cin >> temp[j];
		}
		mat.push_back(temp);
	}
	//non dp solution
	cout << "NON_DP:";
	cout << shortest_path_nondp(0,0) << endl;
	//dp solution

	//initialising dp_table m*n all to NIL
  for (int i = 0; i <m; i++)
	{
		vector<int>temp(n, NIL);
		dp_table.push_back(temp);
	}

	cout << "DP: " << shortest_path_dp(0,0) << endl;
//	for (auto x : dp_table)
//	{
//		for (auto y : x)
//			cout << y << " ";
//		cout << endl;
//	}
//	system("pause");

}
/*
 INPUT-
 3 3
 1 2 3
 4 8 2
 1 5 3
 OUTPUT-
 8

*/
