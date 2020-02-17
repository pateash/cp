#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

class SegmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n;  //n stores number of elements in A(array)
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    /*
     p-index
     L-range Left, R-range right
    */
    if (L == R)                            // as L == R, either one is fine
      st[p] = L;                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;//here segment tree stores index so we have to compare array elements
  } }

/*
   here rmq() return ans to range min query,
   L,R -> range of that node(rstart,rend)
   i,j -> query range(qstart,qend)
*/
  int rmq(int p, int L, int R, int i, int j) {  // O(log n)

    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];// inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;   // both can't be -1, it were then we have already return -1 in first statement         

    return (A[p1] <= A[p2]) ? p1 : p2; 

  }
  int update_point(int p, int L, int R, int idx, int new_value) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    int i = idx, j = idx;

    // if the current interval does not intersect 
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
      A[i] = new_value; // update the underlying array
      return st[p] = L; // this index
    }

    // compute the minimum pition in the 
    // left and right part of the interval
    int p1, p2;
    p1 = update_point(left(p) , L , (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

    // return the pition where the overall minimum is
    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }

//update range is taken from update point range(i,j) ,updating a  pint will be range(i,i)
  int update_range(int p, int L, int R, int i,int j, int new_value) {
    // CASE 1 (if query is not in range of this node) nothing need to be done return this node's value
    // if the current interval does not intersect 
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];
    
    //CASE 2 if range exactly match L,R update all 
    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
       A[i] = new_value; // update the underlying array
      return st[p] = L; // this index
    }

    // compute the minimum pition in the 
    // left and right part of the interval
    int p1, p2;
    p1 = update_point(left(p) , L , (L + R) / 2, i,j, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R,i,j, new_value);

    // return the pition where the overall minimum is
    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }
public:
  /*
  constructor constructs segment tree 
  */
  SegmentTree(const vi &_A) {
    A = _A;  // copy content for local usage, assignment operator is already for vector

    n = (int)A.size();

    st.assign(4 * n, 0);            // create large enough vector of zeroes
    
    build(1, 0, n - 1);                                  // recursive build
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading

//it updates an element in array
  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); 
  }
};
  
int main() {
  int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
  vi A(arr, arr + 7);                      // copy the contents to a vector
  SegmentTree st(A);

  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("              A is {18,17,13,19,15, 11,20}\n");
  printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));             // answer = index 2
  printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));             // answer = index 5
  printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));             // answer = index 4
  printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));             // answer = index 0
  printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));             // answer = index 1
  printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));             // answer = index 5

  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("Now, modify A into {18,17,13,19,15,100,20}\n");
  st.update_point(5, 100);                    // update A[5] from 11 to 100
  printf("These values do not change\n");
  printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));                            // 2
  printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));                            // 4
  printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));                            // 0
  printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));                            // 1
  printf("These values change\n");
  printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));                         // 5->2
  printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));                         // 5->4
  printf("RMQ(4, 5) = %d\n", st.rmq(4, 5));                         // 5->4

  return 0;
}
