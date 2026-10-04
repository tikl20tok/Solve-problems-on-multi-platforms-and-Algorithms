#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/tn25_sohh
//dùng tk namphong2706 mà vào
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll a,b;
    cin>>a>>b;
    ll i,j;
    ll maxi=10000000;//10^7
    vector<ll> snt(maxi+5,0);
    for(i=1;i<=maxi;i++){
        for(j=i;j<=maxi;j+=i)
            if(j!=i)
                snt[j]+=i;//tổng các ước nhỏ hơn chính nó
    }
    //tính hiệu
    for(i=1;i<=maxi;i++){
        snt[i]=abs(i-snt[i]);
    }
    snt[1]=1;//thấy bài có f(1)=1 nên gán luôn
    //prefixsum
    for(i=1;i<=maxi;i++){
        snt[i]+=snt[i-1];
    }
    cout<<snt[b]-snt[a-1];
    return 0;
}
