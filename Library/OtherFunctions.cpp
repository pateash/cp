//
// Created by ashish on 26/1/18.
//

//utility functions

template<typename T> T mod(T x){ //this function return |x| value
    return x<0? -x:x;
}
template<typename T> T gcd(T a,T b){
    if(b==0) return a;
    return gcd(b,a%b);
}


//O(log n) power function without mod
ll power(int (i,int c){
    if(c==0) return 1;
    if (c==1) {
        return i;
    }
    ll ans=power(i,c/2);
    ans=(ans*ans);
    if(c%2==1) ans=(ans*i);
    return ans;
}