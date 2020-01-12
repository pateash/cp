//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_FENWICKTREE_H
#define SAMPLE_FENWICKTREE_H

#include "CommonLibs.h"

using namespace std;

class FenwickTree {
private:
    vector<int> ft;

    int LSOne( int S){ // return values of Least Significant one, ex - for  110 -> LSOne(6) -> 10(2)
        return (S & (-S));
    }
public:
    FenwickTree() = default;

    // initialization: n + 1 zeroes, ignore index 0
    FenwickTree(int n) { ft.assign(n + 1, 0); }

    // initialization: n + 1 zeroes, ignore index 0
    // then adjust all with the value
    FenwickTree(vector<int>v) {
        int n=v.size();
        ft.assign(n + 1, 0);
        for(int i=0;i<v.size();i++){
            adjust(i + 1, v[i]); // ft uses 1 based indexing
        }
    }

    int rsq(int b) {   // from start to end                                  // returns RSQ(1, b)
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum; }

    int rsq(int a, int b) {                              // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); } // return prefixSum(b) - prefixSum(a-1)

    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int index, int v) {                    // note: n = ft.size() - 1
        for (; index < (int)ft.size(); index += LSOne(index)) ft[index] += v; }

    void display(){
        for(int i=1;i<ft.size();i++){
            cout<<ft[i]<<" ";
        }
        cout<<endl;
    }

};

#endif

int main() {
    // idx   0 1 2 3 4 5 6 7  8 9 10, no index 0!
    FenwickTree ft(10);     // ft = {-,0,0,0,0,0,0,0, 0,0,0} // create without array
    ft.adjust(2, 1);        // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1
    ft.adjust(4, 1);        // ft = {-,0,1,0,2,0,0,0, 2,0,0}, idx 4,8 => +1
    ft.adjust(5, 2);        // ft = {-,0,1,0,2,2,2,0, 4,0,0}, idx 5,6,8 => +2
    ft.adjust(6, 3);        // ft = {-,0,1,0,2,2,5,0, 7,0,0}, idx 6,8 => +3
    ft.adjust(7, 2);        // ft = {-,0,1,0,2,2,5,2, 9,0,0}, idx 7,8 => +2
    ft.adjust(8, 1);        // ft = {-,0,1,0,2,2,5,2,10,0,0}, idx 8 => +1
    ft.adjust(9, 1);        // ft = {-,0,1,0,2,2,5,2,10,1,1}, idx 9,k10 => +1
    printf("%d\n", ft.rsq(1, 1));  // 0 => ft[1] = 0
    printf("%d\n", ft.rsq(1, 2));  // 1 => ft[2] = 1
    printf("%d\n", ft.rsq(1, 6));  // 7 => ft[6] + ft[4] = 5 + 2 = 7
    printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
    printf("%d\n", ft.rsq(3, 6));  // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1 = 6

    ft.adjust(5, 2); // update demo
    printf("%d\n", ft.rsq(1, 10)); // now 13
    // return 0;

    cout<<" --------------------\n";
    //EXAMPLE 2
    vector<int>v = {1,2,3,4,5};
    FenwickTree ft2(v);
    ft2.display();

    cout<<ft2.rsq(3)<<endl; // 0,2
    ft2.adjust(1,3);

    ft2.display();
    cout<<ft2.rsq(3)<<endl; // 0,2

}

/* //output

 0
1
7
11
6
13
 --------------------
1 3 3 10 5
6
4 6 3 13 5
9
 */
