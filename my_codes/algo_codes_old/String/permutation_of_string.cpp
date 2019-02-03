// codechef.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void write_permutation(string &s,int start,int last) {
 if(start==last){//jab last tak ke permuatation nikal aaye to print kar do
    cout<<s<<endl;
    return;
 }
 for(int i=start;i <=last;i++){

    swap(s[start],s[i]);
    write_permutation(s,start+1,last);//iska permutation kar chuke hai ange wale saro ke sath(start ke ange wale ko naya start bana denge)
    swap(s[start],s[i]);//jisse ki angli value of i ke liye string wahi wana rahe jo pahle tha
 }
}
int main()
{
	string s;
	cin >> s;
	cout << "permutation is \n";
	write_permutation(s,0,s.size()-1);
	return 0;
}
