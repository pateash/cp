/*LIST OF FUNCTIONS
1-ll power(ll a,ll b)
2-ll gcd(ll a,ll b)


*/


ll power(ll a,ll b){
    if(b==0)
        return 1;
    ll ans=power(a,b/2);
    if(b&1)
        return ans*ans*b;
    else
        return ans*ans;
}
ll gcd(ll a,ll b){
 if(b==0)
    return a;
 else
  return (b,a%b);	
}