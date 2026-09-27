#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll a,b;
    ll i,j;
    ll MAX=1000000;
    vector<bool> snt(MAX+5, true);
    for(i=2;i*i<=MAX;i++){
        for(j=i*i;j<=MAX;j+=i*i){
            snt[j]=false;
        }
    }
    vector<ll> pre(MAX+5,0);
    for(i=1;i<=MAX;i++){
        pre[i]=pre[i-1];
        if(snt[i]){
            pre[i]++;
        }
    }

    ll q;
    cin>>q;
    while(q--){
        cin>>a>>b;
        cout<<pre[b]-pre[a-1]<<'\n';
    }

    return 0;
}
