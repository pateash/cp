
/*PROBLEM- MATRIX MULTIPLICATION PROBLEM
Given a sequence of matrices, find the most efficient way to multiply these matrices together.
The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. 
In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:
(ABC)D = (AB)(CD) = A(BCD) = ....

Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i].
We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain.

solution
if(i==j){
	MUL(i,j)=0;
}
else
  MUL(i,j)=MIN(MUL(i,k)+MUL(k,j)+p[i-1]*p[j]*p[k])
            k=i to j-1(so at k=1 no more break and at j-1 break at last)
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int minOperations(int p[], int i,int j) {
	//this function returns min. number of operations required for solution from i to j index of array
	//Ai matrix has dimension of  p[i-1]*p[i] that is why we starting i from 1
	if (i == j)//if only one matrix then nothing needs to be done
		return 0;
	int minOp = INT_MAX;//so that it get updated first time
	for (int k = i; k < j; k++) {
		minOp = min(minOp, minOperations(p, i, k) + minOperations(p, k + 1, j)+p[i-1]*p[k]*p[j]);
		/*
		* here p[i-1] because we need rows of A[i,k](matrix formed by multiplying A[i] to A[k]) which will be equal to row of A[i] i.e p[i-1] 
	    * p[k] = col of A[i,k] = rows of A[k+1,j](cols of A[i,k] will be p[k] and rows of A[k+1,j] will be p[k] becaus we have stored dimension
	    * for A[i] as p[i-1] and p[i])
	    * similarly for p[j]
		*/
	}
	return minOp;
}
//DP SOLUTION
vector<vector<int>>dp_table;
#define NIL -1
int minOperationsDP(int p[], int i, int j) {
	if (i == j)
		return 0;
	if (dp_table[i][j] != NIL)
		return dp_table[i][j];
	int minOp = INT_MAX;
	for (int k = i; k < j; k++) {
		minOp = min(minOp, minOperationsDP(p, i, k) + minOperationsDP(p, k + 1, j) + p[i - 1] * p[j] * p[k]);
	}
	dp_table[i][j] = minOp;
	return minOp;
}
int main()
{
	int p[] = { 1,2,3,4 };
	// this represent A[1*2] * B[2*3] * c[3*4]
	int size = sizeof(p) / sizeof(p[0]);
	cout << minOperations(p, 1, size - 1) << endl;

	// DP solution 
	for (size_t i = 0; i < size; i++)//index 0 will remain NIL forever here as we are using i from 1 
	{
		vector<int>temp(size,NIL);
		dp_table.push_back(temp);
	}
	cout << "NON_DP:" << minOperationsDP(p, 1, size - 1) << endl;
	system("pause");
	return 0;
}

