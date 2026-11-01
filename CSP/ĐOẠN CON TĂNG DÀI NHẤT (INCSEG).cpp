#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/csphn_incseg
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n;
    cin>>n;
    ll i,j,k;
    vector<bool> a(n+5,true);
    cin>>k;//p tử đầu
    for(i=2;i<=n;i++){
        cin>>j;
        //so sánh vs p tử trc
        if(j<k)
            a[i]=false;
        k=j;
    }
    ll maxi=1, dem=0;
    for(i=1;i<=n;i++){
        if(a[i]==true)
            dem++;
        else
            dem=1;//tại mỗi phần tử riêng cx đc coi là đoạn con tăng dần
        maxi=max(maxi,dem);
    }
    cout<<maxi;

    return 0;
}
