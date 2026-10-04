#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/newbie_uocso
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n;
    cin>>n;
    ll i,j;
    ll maxi=1000000;
    vector<ll> snt(maxi+5,1);//mỗi số đều đã được phân phát ước số là 1
    for(i=2;i<=maxi;i++){
        for(j=i;j<=maxi;j+=i)
            snt[j]++;
    }
    vector<ll> gt(n+5,0);
    ll uoc=0;
    for(i=1;i<=n;i++){
        cin>>gt[i];
        uoc=max(uoc, snt[gt[i]]);
    }
    for(i=1;i<=n;i++){
        if(snt[gt[i]]==uoc){
            cout<<gt[i];
            return 0;
        }
    }
    return 0;
}
