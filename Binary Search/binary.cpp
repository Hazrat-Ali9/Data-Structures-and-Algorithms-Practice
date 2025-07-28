#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
    int A[5]={1,2,3,4,5};
    int k=13;

    int low=0,high=n-1,mid;
    bool flag=true;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]==k)
        {
            cout<< k <<" Found at index "<<mid<<"\n";
            flag=false;
            break;
        }
        else if(k<mid)
            high=mid-1;
        else
            low=mid+1;
    }
    if(flag)
        cout<< k <<" Not found!\n";
    return 0;
}

