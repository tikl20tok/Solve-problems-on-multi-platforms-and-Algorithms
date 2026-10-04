#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/contest10_haiuoc
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll MAX=2000000;
    vector<bool> snt(MAX+5, true);//so nguyen to
    ll i,j;
    /*
    lặp lại a[i]-=1 tới khi còn 2 ước tức kéo về số nguyên tố gần nhất mà <= số hiện tại
    vậy là theo thứ tự lặp 1 bảng chạy prefix truyền trạng thái là xong
    */
    for(i=2;i*i<=MAX;i++){
        if(snt[i]){
            for(j=i*i;j<=MAX;j+=i){
                snt[j]=false;
            }
        }
    }
    vector<ll> cacsnt(MAX+5);
    for(i=2;i<=MAX;i++){
        cacsnt[i]=cacsnt[i-1];
        if(snt[i])
            cacsnt[i]=i;
    }

    ll n;cin>>n;
    for(i=1;i<=n;i++){
        cin>>j;
        cout<<cacsnt[j]<<'\n';
    }
    return 0;
}
