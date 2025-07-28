#include<bits/stdc++.h>
using namespace std;

vector<int> counting_sort(vector<int> A, int n)
{
    vector<int> sorted;
    vector<int> freq(n+1);
    for(int i=0;i<n;i++)
        freq[A[i]]+=1;
    for(int i=0;i<=n;i++)
        while(freq[i]--)
            sorted.push_back(i);
    return sorted;
}

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];

    A = counting_sort(A,n);

    for(int val:A)
        cout << val << " ";

    return 0;
}
