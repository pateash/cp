#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
/*
PROBLEM-Find the sum of elements from index l to r where 0 <= l <= r <= n-1
Change value of a specified element of the array arr[i] = x
where 0 <= i <= n-1.
SOLUTION- segment tree allows us to update in log(n) and also query in log(n)
time so if n queries need to be done it could be done in nlog(n)
*/
using namespace std;
class SegmentTreeLazy{
    vector<int>A;
    vector<pair<int,int>>lazy1;//for storing lazy tree
    vector<int>lazy2;//for storing lazy tree

    vector<pair<int,int>>st;//for storing segment tree

    int expcount(int n,int exp){
        int count=0;
        while(n%exp==0){
            count++;
            n/=exp;
        }
        return count;
    }
    void constructUtil(int start,int end,int index){
        //index represent the index of st
        //start and end are index of array from which we have
        //to generate the st
        if(start==end)
        {
            st[index]=make_pair(expcount(A[start],2),expcount(A[start],5));
        }
        int mid=(start+end)/2;
        constructUtil(start,mid,2*index);
        constructUtil(mid+1,end,2*index+1);
        st[index].first=st[index<<1].first+st[(index<<1)+1].first;
        st[index].second=st[index<<1].second+st[(index<<1)+1].second;
    }
    pair<int,int> queryUtil(int rstart,int rend,int qstart,int qend,int index ) {

        if (lazy1[index].first != 0 || lazy1[index].second != 0) {
            st[index].first += (rend - rstart + 1) * lazy1[index].first;//apply lazyness and remove
            st[index].second += (rend - rstart + 1) * lazy1[index].second;
            if (rstart != rend) {
                //propagate lazy to children
                lazy1[2 * index].first += lazy1[index].first;
                lazy1[2 * index].second += lazy1[index].second;
                lazy1[2 * index + 1].first += lazy1[index].first;
                lazy1[2 * index + 1].second += lazy1[index].second;
            }
            lazy1[index].first = lazy1[index].second = 0;
        }

        //NOW perform operations

        if (rstart == qstart && rend == qend)//this is what we wanted
            return st[index];
        int rmid = (rstart + rend) / 2;
        if (qend <= rmid)
            return queryUtil(rstart, rmid, qstart, qend, 2 * index);
        else if (qstart >= rmid + 1)
            return queryUtil(rmid + 1, rend, qstart, qend, 2 * index + 1);
       else {
                pair<int,int>p1=queryUtil(rstart, rmid, qstart, rmid, 2 * index) ;
                pair<int,int>p2=queryUtil(rmid + 1, rend, rmid + 1, qend, 2 * index + 1);
            pair<int,int>temp;
            temp.first=p1.first+p2.first;
            temp.second=p1.second+p2.second;
            return temp;
        }
    }
    void update1Util(int rstart,int rend,int ustart,int uend,int delta,int index) {
        //while updating or querying we always move lazyness(we can get required result only when we remove lazyness to that node)

        //here delta represents the value to be added
        //if check it any lazy propogation is there for this node
        if(lazy1[index].first!=0 || lazy1[index].second!=0 ){

            st[index].first+=(rend-rstart+1)*lazy1[index].first;//apply lazyness and remove
            st[index].second+=(rend-rstart+1)*lazy1[index].second;
            if(rstart!=rend){
                //propagate lazy to children
                lazy1[2*index].first+=lazy1[index].first;
                lazy1[2*index].second+=lazy1[index].second;
                lazy1[2*index+1].first+=lazy1[index].first;
                lazy1[2*index+1].second+=lazy1[index].second;
            }
            lazy1[index].first=lazy1[index].second=0;
        }
        if(rstart==ustart&&rend==uend){//if query overlaps with range
            //if this is what wanted
            int exp2=expcount(delta,2);
            int exp5=expcount(delta,5);
            st[index].first+=(rend-rstart+1)*exp2;//update this node and propagate lazyness to children
            st[index].second+=(rend-rstart+1)*exp5;//update this node and propagate lazyness to children

            if(rstart!=rend){
                //propagate lazy to children
                lazy1[2*index].first+=exp2;
                lazy1[2*index].second+=exp5;
                lazy1[2*index+1].first+=exp2;
                lazy1[2*index+1].second+=exp5;
            }
            return;//every thing is done
        }
        // THIS MEANS QUERY IS INSIDE RANGE(do not overlap, if out then we are not here)
        int rmid=(rstart+rend)/2;
        if(uend<=rmid)
            update1Util(rstart,rmid,ustart,rmid,delta,2*index);
        else if(ustart>=rmid+1)
            update1Util(rmid+1,rend,rmid+1,uend,delta,2*index+1);
        else{
            update1Util(rstart,rmid,ustart,rmid,delta,2*index);
            update1Util(rmid+1,rend,rmid+1,uend,delta,2*index+1);
        }
        st[index].first=st[index<<1].first+st[(index<<1)+1].first;
        st[index].second=st[index<<1].second+st[(index<<1)+1].second;
    }
    void update2Util(int rstart,int rend,int ustart,int uend,int delta,int index) {
        if (ustart > rend || uend < rstart)
            return;

        if(lazy1[index].first!=0 || lazy1[index].second!=0 ){

            st[index].first+=(rend-rstart+1)*lazy1[index].first;//apply lazyness and remove
            st[index].second+=(rend-rstart+1)*lazy1[index].second;
            if(rstart!=rend){
                //propagate lazy to children
                lazy1[2*index].first+=lazy1[index].first;
                lazy1[2*index].second+=lazy1[index].second;
                lazy1[2*index+1].first+=lazy1[index].first;
                lazy1[2*index+1].second+=lazy1[index].second;
            }
            lazy1[index].first=lazy1[index].second=0;
        }

        if (rstart == rend) {
            st[index].first = expcount((rstart - ustart + 1) * delta, 2);
            st[index].second = expcount((rstart - ustart + 1) * delta, 5);
            return;
        }
        int rmid = (rstart + rend) / 2;
        update2Util(rstart, rmid, ustart, uend, delta, index << 1);
        update2Util(rmid + 1, rend, ustart, uend, delta, (index << 1) + 1);
        st[index].first=st[index<<1].first+st[(index<<1)+1].first;
        st[index].second=st[index<<1].second+st[(index<<1)+1].second;
    }

public:
    SegmentTreeLazy(vector<int>A){
        this->A.resize(A.size());
        for(int i=0;i<A.size();i++){
            this->A[i]=A[i];
        }
        constructST();
    }
    void constructST(){
        int h=ceil(log2(A.size()));//max height of tree with n elements
        //ST will always be a complete Binary tree
        int STsize=pow(2,h+1);//max number of elements possible
        st.resize(STsize,make_pair(0,0));
        lazy1.resize(STsize,make_pair(0,0));//lazy tree of same size all set to 0
        //0 will be leaved as we do in heap and also it will not be destroyed when we leave the function
        constructUtil(0,A.size()-1,1);
        //returning the tree made
    }
    pair<int,int> query(int qstart,int qend){
        //start and end are index of sequence for which
        //we have to calculate the sum
            return queryUtil(0,A.size()-1,qstart,qend,1);
    }
    int update1(int ustart,int uend,int delta){

            //we have to update value and also update the nodes affected by it
            update1Util(0,A.size()-1,ustart,uend,delta,1);
            //we add delta to each node to get desired change in this(in sum query)
            //in this case else we may have to recurse back to
            //do the desired changes
    }
    int update2(int ustart,int uend,int delta){

        //we have to update value and also update the nodes affected by it
        update2Util(0,A.size()-1,ustart,uend,delta,1);
        //we add delta to each node to get desired change in this(in sum query)
        //in this case else we may have to recurse back to
        //do the desired changes
    }

};
// Driver program to test above functions

template <typename T>
void show_1d(T container){

    for(auto it=container.begin();it!=container.end();it++){
        cout<<*it<<" ";

    }
    cout<<endl;
}

template <typename  T>
void show_arr(T arr[],int size){
    cout<<"content in array is here"<<endl;
    for (int i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main(){
    int t;
    cin>>t;
    vector<int>arr;
    while(t--) {
     int n,m;
        cin>>n>>m;
        arr.resize(n);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        SegmentTreeLazy tree(arr);
        int type,L,R;
         int X,Y;
        for (int j = 0; j < m; ++j) {
          cin>>type;
          cin>>L>>R;
            if(type==1){
            cin>>X;
                tree.update1(L,R,X);

          }else if(type==2){
                cin>>Y;
                tree.update2(L,R,Y);
            }else{
                pair<int,int>p=tree.query(L,R);
                cout<<min(p.first,p.second)<<endl;
            }


        }
    }
    return 0;
}
