#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/thithu2025_aandm
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,q,i,j;
    cin>>n>>q;
    vector<ll> a(n+5,0);
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.begin()+n+1);
    vector<ll> pre(n+5,0);
    for(i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll x, tong, tongx=0;
while(q--){
    cin>>x;
    tong=0;
    tongx+=x;//do nó tích luỹ
    //chat nhi phan
    ll start=1,en=n,mid,pos=0;
    while(start<=en){
        mid=start+(en-start)/2;
        if(a[mid]+tongx<0){
            pos=mid;
            start=mid+1;
        }
        else{
            en=mid-1;
        }
    }
    //phần tử âm tính riêng va + dồn
    tong += abs(pre[pos] + tongx*(pos));

    //dương
    tong += pre[n] - pre[pos] + tongx*(n-pos);
    cout<<tong<<'\n';
}

    return 0;
}
