#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];

    int pos=0,neg=0,zero=0;

    for(int i=0;i<n;i++)
    {
        if(A[i]>0)
            pos++;
        else if(A[i]<0)
            neg++;
        else
            zero++;
    }
    cout<< "Positive Number -> " << pos <<endl;
    cout<< "Negetive Number -> " << neg <<endl;
    cout<< "Zero -> " << zero <<endl;

    return 0;
}

