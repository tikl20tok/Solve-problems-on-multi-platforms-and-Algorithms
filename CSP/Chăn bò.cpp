#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/olp20_cows
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,s;
    cin>>n>>s;
    /*
    số hiệu bò từ 1 -> n, => tổng là n(n+1) /2
    chỉ có 1 con bò bị lạc
    số hiệu sẽ là tổng đó -s
    */
    n=(n*(n+1))/2;
    cout<<n-s;

    return 0;
}
