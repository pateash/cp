
// this is Just the implementation of Segment Tree
// also as we are only updating a single element, LAZY is not needed
// as we will always have to reach out to that single element anyways.
using vi=vector<int>;
class NumArray {
    vi st, A;
    int n;
    int INVALID = INT_MIN;
    int left(int p){ return p<<1;}
    int right(int p){ return (p<<1)+1;}

    void build(int p, int L, int R){
        if(L==R) st[p]=A[L];
        else {
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            st[p]= st[left(p)] + st[right(p)];
        }
    }
    void update(int p, int L, int R, int index, int val){
        // if outside then ignore
        if(index < L || index > R) return;

        if(L==R && index==L){  // if reached that index
            st[p]=val;
        }else{
            update(left(p), L, (L+R)/2, index, val);
            update(right(p), (L+R)/2+1, R,index, val);
            //now updating the value backward
            st[p]= st[left(p)] + st[right(p)];
        }
    }
    int sumRange(int p, int L, int R, int i, int j){
        // if outside range return INVALID
        if(j<L or i>R) return INVALID;

        // if fully inside return value
        if(L>=i and R<=j) return st[p];

        // partial find both and return value
        int lsum = sumRange(left(p), L, (L+R)/2, i, j);
        int rsum = sumRange(right(p), (L+R)/2+1, R,i ,j);
        if(lsum==INVALID) return rsum;
        if(rsum==INVALID) return lsum;
        return lsum+rsum;
    }
public:
    NumArray(vector<int>& nums) {
        this->A=nums;
        this->n=nums.size();
        st.resize(4*n,INVALID); // to store the default values
        build(1,0,n-1);
    }

    void update(int index, int val) {
        update(1, 0, n-1, index, val);
    }

    int sumRange(int left, int right) {
       return sumRange(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
