#include <iostream>
#include <cstdlib>
#include <set>//make sure unique elements are there
/*
PROBLEM-
Subset sum problem is to find subset of elements,
that are selected from a given set whose sum adds up to a given number K.
We are considering the set contains non-negative values.(non negative leads to subtraction which may lead to other solution)
It is assumed that the input set is unique (no duplicates are presented),
because if duplicates will be there there may be many solutios(However order is not considered in set)
*/
using namespace std;
using si=set<int>;
bool solveSubsetProblem(si &s,si &subset,int remK){//using refrence because sets will change
    //remK has remaining sum to be required
    if(remK==0)
        return true;
    else if(remK<0)
        return false;
    for(auto it=s.begin();it!=s.end();it++)
    {
        //trying all element from set and giving it to subset
        int temp=*it;
        subset.insert(temp);//giving it to subset
        s.erase(temp);//removing it from set
        if(solveSubsetProblem(s,subset,remK-temp))
            return true;
        else{
        //make as it was
        s.insert(temp);//giving back it to set
        subset.erase(temp);//removing it from subset

        }
    }
    return false;
}
int main()
{
    cout<<"enter number of elements in set"<<endl;
    int n;
    cin>>n;
    si s;
    cout<<"enter set"<<endl;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        s.insert(temp);
    }
    cout<<"enter the Value of K"<<endl;
    int K;
    cin>>K;
    si subset;//set to store the ans;
    if(solveSubsetProblem(s,subset,K)){
        cout<<"Ans found!!!"<<endl;
        for(auto it=subset.begin();it!=subset.end();it++){//showing ans
            cout<<*it<<" ";
        }
        cout<<endl;
    }else{
    cout<<"No way found!!!"<<endl;
    }

    return 0;
}
