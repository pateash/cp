#include <iostream>
#include <vector>
/*
this is a classic N Queens problems
Problem--
The N Queen is the problem of placing N chess queens on an N×N chessboard,
so that no two queens attack each other.
For example, following is a solution for 4 Queen problem.
*/
using namespace std;
int size;
vector<vector<int>>chess_ans;
void show2d(vector<vector<int>>v) {
    cout << "your 2d vector is" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        for (auto i = it->begin(); i != it->end(); i++)
            cout << *i << " ";
        cout << endl;
    }
    cout << endl;
}
void init2D(vector<vector<int>>& v) {
    //initialising path to xsize*ysize all zero matrix
    for (int i = 0; i<size; i++) {
        vector<int>temp(size);
        v.push_back(temp);
    }
}

bool isSafe(int x,int y){
// we are checking if placing queen at this index is safe,
// per chess_ans matrix till now
//As we are going from up to down and left to right we,
// do not need to check  for letter indices
// SAME COLUMN CHECK
  for(int i=0;i<x;i++){//same row will not ever have going one by one
    if(chess_ans[i][y]==1)
        return false;
  }
// DIAGONAL CHECK
// for diagonal we have to do it all the from top-left and top-right only (coming from top to bottom)

 //TOP LEFT
  for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
     if(chess_ans[i][j]==1)
        return false;
 //TOP RIGHT
    for(int i=x-1,j=y+1;i>=0&&j<size;i--,j++)
     if(chess_ans[i][j]==1)
        return false;

  return true;

}
bool solveNQUeens(int xindex) {
    extern int size;
    if (xindex == size)//if all indexes has been done
        return true;
    //we are starting from x index 0 and trying to put a queen in each row(as only one is possible)
    //and then trying each y index of putting in it
    for (int yindex = 0; yindex < size; yindex++) {
        if(isSafe(xindex,yindex)){
            chess_ans[xindex][yindex] = 1;
            if (solveNQUeens(xindex + 1))
                return true;
            else
                chess_ans[xindex][yindex] = 0;
      }
    }
    return false;//if we can't get true from any try
}

int main()
{
    extern int size;
    cout << "enter the size of chess" << endl;
    cin >> size;
    init2D(chess_ans);
    //cout<<"after initialisation\n";
    //show2d(chess_ans);
    if (solveNQUeens(0))
        show2d(chess_ans);
    else
        cout << "No way found!!!" << endl;
    return 0;
}
