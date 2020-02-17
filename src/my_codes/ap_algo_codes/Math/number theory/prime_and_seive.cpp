
#include<bits/stdc++.h>

using namespace std;

 bool isprime(int n){
     if(n==2)
         return true;
     for(int i=2;i<=ceil(sqrt(n));i++){
         if(n%i==0)
             return false;
     }
     return  true;
 }


struct seive{
    vector<bool> v;//represents number
    vector<int> pcount;//counts number of primes upto that n
public:
    seive(int size){
        //size is range of seive
        v.resize(size+1,true);//make every body prime initially

        pcount.resize(size+1,0);
     
      /*
          //run the process
         execute();
     
      NOTE- this statement may cause problem here as seen in some other problems
      so write it down in main() or solve()      
      */
      
    }
    /*******************************************************************

     in reality we do not have to go to each element and cutoff its multiples
     and we can just cutoff multiples of all integers i

     i<=sqrt(size)

      because if a number i is composite, then it will definitely will be cutoff 
      by a number x<=sqrt(i), so it will be definitely cut off by sqrt(size). 
     but here as we are doing counting etc. so we have to do it.
    *************************************************************************/
    void execute(){
        //this function perform execution
        //of seive
         int n=2;
        //index goes upto end of string
        int limit=v.size();
        int prevcount=0;//so that for n=2 we get 0+1 =1
        while(n<=limit){
            if(v[n]==true){
                pcount[n]=prevcount+1;
                int k=2*n;//k will go up to end to cross others
                while(k<=limit){
                    v[k]=false;
                    k+=n;
                }
            }
            else{
                pcount[n]=prevcount;

            }
            prevcount=pcount[n];
            n++;
        }
    }
    int get_pcount(int n){
     //return no. of prime numbers upto n
        //n should be <= limit

        return pcount[n];
    }

    bool isprime(int n){
        //n should be <= limit
        return v[n];
    }
    void show_primes(int n){
     //show prime upto n (n should be less than size of seive)
          for(int i=2;i<=n;i++)
          {
              if(v[i])
                cout<<i<<"  "<<endl;
          }
    }
};
int main(){
    freopen("C:\\Users\\ashish_patel\\Documents\\CodeBlocks Project\\codechef\\out.txt","w",stdout);
    seive s(100);
//    cout<<"primes  up to 20"<<endl;
//    s.show_primes(20);
    
    /* ****************************
     this has been moved here because of problems in constructor
      ******************************** */
       s.execute(); //run the process
       
    
    for(int i=0;i<10;i++){
        int x=rand()%100;
        if(s.isprime(x)){
            cout<<x<<" is prime";
        }
        else{
            cout<<x<<" is not prime";
        }
        cout<<",\tno. of primes up to "<<x<< " is "<<s.get_pcount(x)<<endl;
    }
   return 0;

}
