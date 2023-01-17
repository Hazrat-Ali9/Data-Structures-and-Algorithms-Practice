#include<bits/stdc++.h>

using namespace std;

bool prime_checker(long long int n)
{
    if(n%2==0)
        return false;
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}


int main(void)
{
    long long int n;
    cin>>n;
    vector<long long int> prime={2};

    for(int i=3;i<n;i+=2)
    {
        if(prime_checker(i))
            prime.push_back(i);
    }

    for(int i=0;i<prime.size();i++)
        cout<<prime[i]<<", ";

    return 0;
}
