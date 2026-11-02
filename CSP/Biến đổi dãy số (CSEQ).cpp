#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/csphn_cseq
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    /*
    đoạn có tổng S, T là tổng đoạn từ i->j, -T là tổng đoạn đó sau khi đổi dấu
    Tổng cả đoạn sau khi đổi là: S-T+(-T) = S-2T = S+2(-T)
    cần T là min, dễ dàng làm được = kadane max khi ta đổi thành -T là MAX.
    vậy ta đảo dấu dãy rồi dùng kadane algorithm
    */
    ll n,i,j,s=0;
    cin>>n;
    vector<ll> a(n+5,0);
    for(i=1;i<=n;i++){
        cin>>j;
        a[i]=-j;//đảo dấu
        s+=j;
    }
    ll temp = 0, maxsum = -1e18;
    for(i = 1; i <= n; i++){//kadane phiên bản KHÔNG RỖNG
        temp = max(a[i], temp + a[i]);
        maxsum = max(maxsum, temp);
    }
    cout<<s+2*maxsum;
    return 0;
}
