#include<bits/stdc++.h>
using namespace std;

vector<int> prime_num;

void genarate_prime(int n)
{
    vector<bool> check;
    check.resize(n+1,true);

    for(int i=2;i<=n;i++)
    {
        if(check[i])
            prime_num.push_back(i);
        for(int j=2*i;j<=n;j+=i)
            check[j]=false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    genarate_prime(n);

    for(int val:prime_num)
        cout<< val << " ";
    cout<<"\n";

    return 0;
}
