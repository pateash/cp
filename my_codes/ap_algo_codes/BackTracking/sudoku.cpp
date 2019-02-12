#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 9
/*
PROBLEM-
Given a partially filled 9×9 2D array ‘grid[9][9]’,
the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column,
and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.
INPUT- sudoku of 9*9
OUTPUT- solved sudoku of 9*9
*/
using namespace std;
//it will have n+1 elements showing path from 0 to 0
//as we can start from any node as it will be present in the cycle

void show_2d(int mat[N][N]){
    cout<<"showing "<<endl;
   for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
        cout<<mat[i][j]<<" ";
   cout<<endl;
   }
   cout<<endl;
}

bool rowSafe(int sudoku[][N],int row,int value){
 for (int i=0;i<N ;i++ )
     {
        if(sudoku[row][i]==value)
            return false;
     }
     return true;

}
bool colSafe(int sudoku[][N],int col,int value){
 for (int i=0;i<N ;i++ )
     {
        if(sudoku[i][col]==value)
            return false;
     }
     return true;

}

bool blockSafe(int sudoku[][N],int blockrowStart,int blockcolStart,int value){
   //blockrowStart and blockcolStart are the row and col at the
   //left top of box
   for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        if(sudoku[blockrowStart+i][blockcolStart+j]==value)
        return false;
   return true;
}

bool isSafe(int sudoku[][N],int row,int col,int value){
  //return true if is is ok to put value at row,col
  return rowSafe(sudoku,row,value)
         &&colSafe(sudoku,col,value)
         &&blockSafe(sudoku,row-row%3,col-col%3,value);

}
bool isEmptyBlock(int sudoku[][N],int& row,int& col){
   for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(sudoku[i][j]==0){
      //any empty
      row=i;
      col=j;
      return true;
     }
return false;
}
bool solveSudoku(int sudoku[][N]){
    int row,col;
    if(!isEmptyBlock(sudoku,row,col)){
        //if no empty block remains
        //if any empty exists then
        // refrences returns in row and col
        return true;
    }
    for (int i=1;i<=9;i++ )
    {
        if(isSafe(sudoku,row,col,i)){
            //if it is safe to put i at
            //(row,col)
            sudoku[row][col]=i;
            if(solveSudoku(sudoku))
                return true;
            else//backtracking
                sudoku[row][col]=0;//make empty

        }
     }
    return false;
}

int main()
{

  int sudoku[N][N]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    cout<<"solution starts"<<endl;
    show_2d(sudoku);

   if(solveSudoku(sudoku))
   {
       cout<<"the ans is "<<endl;
       show_2d(sudoku);
    }else{
   cout<<"No ans found!!!"<<endl;
   }

    return 0;
}
