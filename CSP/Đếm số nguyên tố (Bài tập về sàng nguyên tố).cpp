#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//FULL AC
//link: https://csp.vnoi.info/problem/cbn_prime_c2_p2
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,q;
    cin>>q;
    ll MAX=1000000;
    vector<bool> snt(MAX+5, true);//so nguyen to
    ll i,j;
    for(i=2;i*i<=MAX;i++){
        if(snt[i]){
            for(j=i*i;j<=MAX;j+=i){
                snt[j]=false;
            }
        }
    }
    vector<ll> pre(MAX+5,0);//prefixsum cho snt
    for(i=2;i<=MAX;i++){
        pre[i]=pre[i-1];
        if(snt[i]){
            pre[i]++;
        }
    }
    while(q--){
        cin>>n;
        cout<<pre[n]<<"\n";
    }
    return 0;
}
