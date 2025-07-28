#include<bits/stdc++.h>
using namespace std;

vector<int> Merge_sort(vector<int> A)
{
    if(A.size()<=1)
        return A;
    vector<int> first,last;
    for(int i=0;i<A.size()/2;i++)
        first.push_back(A[i]);
    for(int i=A.size()/2;i<A.size();i++)
        last.push_back(A[i]);

    first = Merge_sort(first);
    last = Merge_sort(last);

    vector<int> sorted;

    for(int i=0,j=0; i<first.size() || j<last.size();)
    {
        if(i==first.size())
        {
            sorted.push_back(last[j]);
            j++;
        }
        else if(j==last.size())
        {
            sorted.push_back(first[i]);
            i++;
        }
        else if(first[i]>last[j])
        {
            sorted.push_back(first[i]);
            i++;
        }
        else
        {
            sorted.push_back(last[j]);
            j++;
        }
    }
    return sorted;
}

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>> A[i];

    A = Merge_sort(A);

    for(int val:A)
        cout << val << " ";

    return 0;
}

