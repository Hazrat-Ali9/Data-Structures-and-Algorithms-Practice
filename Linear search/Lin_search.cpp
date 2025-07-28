#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>> n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>> A[i];

    cout<< "Enter key to find: ";
    cin>>k;

    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(A[i]==k)
        {
            cout<< k << " Found at index " << i <<endl;
            flag=false;
            break;
        }
    }
    if(flag)
        cout << k << " Not Found!"<< endl;

    return 0;
}
