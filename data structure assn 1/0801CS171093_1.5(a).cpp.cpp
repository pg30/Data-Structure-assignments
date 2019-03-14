#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<fstream>

#define ll long long

using namespace std;

int main()
{
    freopen("IntegerList.txt","r",stdin);

    ll i,n,k,sum=0,mn=1000000000,mx=0;

    for(i=0;i<10000;i++)
    {
        cin>>n;

        if(n  > mx)
            mx = n;
        if(n < mn)
            mn = n;

        sum+=n;
    }

    cout<<(sum-mx)<<" "<<(sum-mn);

    return 0;
}
