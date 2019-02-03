//this function return just greater element in sorted Array O(log n)

int bmaxSearch(vector<int>vect,int x)
{
    int start=0,end=vect.size()-1;
    int mid;
    while(start<=end){
        mid=(start+end)/2;
        if(vect[mid]==x)
            return mid+1;
        else if(vect[mid]<x&&vect[mid+1]>x)
            return mid+1;
         else if(vect[mid]>x&&vect[mid-1]<x)
            return mid;
          else if(vect[mid]<x)
               start=mid+1;
        else if(vect[mid]>x)
            end=mid-1;
    }
}