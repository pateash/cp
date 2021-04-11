#include<bits/stdc++.h>

using namespace std;

struct seive{
    vector<bool> v;//represents number
    int seiveSize;
public:
    seive(int size){
        //size is range of seive
        seiveSize=size;
        v.resize(size+1,true);//make every body prime initially

        /*
            //run the process
           execute();

        NOTE- this statement may cause problem here as seen in some other problems
        so write it down in main() or solve()
        */

    }
    /*******************************************************************

    we can just cutoff multiples of all integers i(that is what we are doing here)
     i<=sqrt(size)

      because if a number i is composite, then it will definitely will be cutoff
      by a number x<=sqrt(i), so it will be definitely cut off by sqrt(size).
    *************************************************************************/
    void executeEfficient(){
        //this function perform execution
        //of seive
        int n=2;
        //index goes upto end of string
        int limit=ceil(sqrt(seiveSize));
        while(n<=limit){
            if(v[n]==true){
                int k=2*n;//k will go up to end to cross others
                while(k<v.size()){
                    v[k]=false;
                    k+=n;
                }
            }
            n++;
        }
    }
    void show_primes(int n){
        //show prime upto n (n should be less than size of seive)
        for(int i=2;i<=n;i++)
        {
            if(v[i])
                cout<<i<<"  "<<endl;
        }
    }
    bool isprime(int n){
        //n should be <= limit
        return v[n];
    }
};

int main()
{

    seive s(50);
    s.executeEfficient();
    s.show_primes(50);

}
