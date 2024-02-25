#ifndef SAMPLE_STRING_SEARCH_H
#define SAMPLE_STRING_SEARCH_H

#include "../CommonLibs.h"

class StringSearch{
public:
        static vector<int> naiveSearch(string&T, string&P){
            int n=T.size(), m=P.size();
            vector<int> ans;
            for(int i=0;i<n;i++){
                bool found=true;
                for(int j=0;j<m && found;j++){
                    if(i+j>=n || T[i+j]!=P[j])
                        found=false;
                }
                if(found){
                    cout<<"found at:"<<i<<endl;
                    cout<<T.substr(i,m)<<endl;
                    ans.push_back(i);
                }
            }
            return ans;
        }
        static void kmpPreprocess(string&T, string&P, vector<int>&b){
            int m=P.size();
            int i=0,j=-1;
            b[0]=-1; // setting initial value as -1
            while(i<m){
                while(j>=0 && P[i]!=P[j]) // checking j>=0, as j=-1 initially
                    j=b[j]; // resetting j in case of different value using b[]
                i++;j++; // if same increment both
                b[i]=j; // set i index, keep incrementing if we find more same values
            }
        }

     //    this is similar to kmpPreprocess but applied on T instead
        static vector<int> kmpSearch(string& T, string& P, vector<int>&b){
            int n=T.size();
            int m = P.size();
            int i=0,j=0;
            vector<int>ans;
            while(i<n){
                while(j>=0 && T[i]!=P[j]) j=b[j]; // resetting j using b[], same as above
                i++;j++;
                if(j==m) { // if we found the full match
                    cout<< "found match at: "<<i-j<< endl;
                    cout<<T.substr(i-j,m)<<endl;
                    ans.push_back(i-j);
                    // start again for next match
                    j=b[j];
                }
            }
            return ans;
        }

};

void testStringSearch()
{
    cout<<"String Searching Algorithms\n================="<<endl;
    string T="I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
    string P="SEVENTY SEVEN";
    cout<<T<<endl<<P<<endl;
    // naive search
    cout<<"Naive Searching Algorithm\n================="<<endl;
    auto naive_ans= StringSearch::naiveSearch(T,P);
    assert(naive_ans.size()==2);
    cout<<"------------\n"<<endl;

    // KMP
    cout<<"KMP Searching Algorithm\n================="<<endl;
    vector<int>b(P.size());
    StringSearch::kmpPreprocess(T,P, b);
    show_1d(b);
    auto kmp_ans=StringSearch::kmpSearch(T,P, b);
    assert(kmp_ans.size()==2);
    assert(naive_ans==kmp_ans);
    cout<<"------------"<<endl;
}
#endif
