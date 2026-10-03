#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//full ac
//link: https://csp.vnoi.info/problem/csphn_darr
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    /*
    ta có prefix, mỗi phần tử đang có hệ số 1
    có sum=k*tổng toàn dãy, mỗi phần tử có k hệ số
    để phân k đoạn mà mỗi đoạn nhân hệ số thuộc 1->k tức:
    k*prefix[n] - prefix[](lặp prefix k-1 lần, tức là biên) là lớn nhất
    vậy cần prefix[] nhỏ nhất, vậy ta sort prefix, lặp k-1 lần, trừ dần đi những thằng nhỏ nhất là được

    bên cạnh đó, pre[n] ko được tính vào trong đoạn sort vì trong mọi trường hợp, đều ko thể đc chọn làm biên
    */
    ll n,k,i,j;
    cin>>n>>k;
    vector<ll> pre(n+5,0);
    for(i=1;i<=n;i++){
        cin>>j;
        pre[i]=pre[i-1]+j;
    }
    ll sum=k*pre[n];
    sort(pre.begin()+1, pre.begin()+n);//ko sort pre[n]
    for(i=1;i<=k-1;i++){
        sum-=pre[i];
    }
    cout<<sum;

    return 0;
}
