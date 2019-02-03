
//finding gcd of two numbers
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);  
}

/*
LCM OF N ELEMENTS
------------------
NOTE- formual lcm*gcd=a*b only hold for two values for three value it doesn't
so we can find it like
take ans=arr[0](as lcm of 1 element is itself)
lcm(ans,a[i])=(ans*arr[i])/(gcd(ans,a[i]))
*/

//fiding lcm of array
int lcmarr(int a[], int n) {
  int arrLcm= a[0];
  for (int i = 0; i < n; i++) {
    arrLcm= arrLcm*a[i]/gcd(arrLcm, a[i]);
  }
  return arrLcm;
}

//finding gcd of array 


/*
GCD OF N ELEMENTS
--------------------
take ans=arr[0](as gcd of 1 element is itself)
similary lcm of n elements can be found by iterating through while array and using 
ans as a and a[i] as b;
*/

int gcdarr(int a[],int n){
	int ans=a[0];
	for(int i=0;i<n;i++)
		ans=gcd(ans,a[i]);
	return ans;
}









