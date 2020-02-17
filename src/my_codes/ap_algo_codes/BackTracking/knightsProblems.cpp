/*
  THE KNIGHT'S PROBLEM
  Q.The knight is placed on the first block of an empty board and,
   moving according to the rules of chess,must visit each square exactly once?
  example for 8*8 chessboard
  ans-
  0  59  38  33  30  17   8  63
 37  34  31  60   9  62  29  16
 58   1  36  39  32  27  18   7
 35  48  41  26  61  10  15  28
 42  57   2  49  40  23   6  19
 47  50  45  54  25  20  11  14
 56  43  52   3  22  13  24   5
 51  46  55  44  53   4  21  12
 (here no. start from 0 to 63 ,0 starting
  63 means block where last move was done...)
*/
#define N 8 // solving for 8*8 normal chess
#define NIL -1// it indicates if the place is empty
#include<bits/stdc++.h>
using namespace std;

bool isValid(int x,int y,int solution[][N]){
//this fn tell is the coordinates are valid or not
if(x<N&&x>=0&&y<N&&y>=0&&solution[x][y]==NIL)//if inside chess board and empty place
    return true;
else
    return false;
}
bool solveKnightsProblemUtil(int x,int y ,int moveNumber,int solution[N][N],int moveX[],int moveY[]){
  //this function finds all possible moves recursively using backtracking
  // x and y are present cooardinates now
  //moveNumber is the move you gonna make now
  //moveX and moveY have the move cooardinates
  int next_x;
  int next_y;
   if(moveNumber==N*N)
    return true;//if all moves has been done
   for(int i=0;i<N;i++){
        //trying all moves
        next_x=x+moveX[i];
        next_y=y+moveY[i];
        if(isValid(next_x,next_y,solution))
        {//if move is valid go to place move and try next move
            solution[next_x][next_y]=moveNumber;//add moveNumber to appropriate coordinates
            if(solveKnightsProblemUtil(next_x,next_y,moveNumber+1,solution,moveX,moveY))//trying to find the next
               return true;
            else
            {//if move fails we have to backtrack
                solution[next_x][next_y]=-1;
            }

        }

   }
  //if after trying all from 0 to N could not able to find true solution return false
  return false;

}
void solveKnightsProblem(){
   int solution[N][N];
   int moveX[N]={  2, 1, -1, -2, -2, -1,  1,  2 };//the x coardinates moves from origin(0,0) for a knight(can be used to find nextmove by adding)
   int moveY[N]={  1, 2,  2,  1, -1, -2, -2, -1 };//the y coardinates moves from origin(0,0) for a knight
  //initialising all places
   for (int i=0;i<N ;i++ )
     for(int j=0;j<N;j++)
       solution[i][j]=NIL ;//-1 means the place is empty(chal chaldi gayi hai ya nahi us place par)
    //initialising solution as starting from 0
    solution[0][0]=0;
   bool ans=solveKnightsProblemUtil(0,0,1,solution,moveX,moveY);
   if(ans)
   {
       puts("solution found!");
   for (int i=0;i<N ;i++ ){
     for(int j=0;j<N;j++)
     cout<<solution[i][j]<<" ";
     cout<<endl;
    }
   }
   else
    cout<<"solution does not found!"<<endl;
}
int main()
{
    solveKnightsProblem();
    return 0;
}
