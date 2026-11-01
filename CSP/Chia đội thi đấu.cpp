#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> cnt;
//link: https://csp.vnoi.info/problem/l812025_thidau
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,k;
    cin>>n>>k;
    ll i,j;
    vector<ll> a(n+5,0);
    for(i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    ll dem=0;
    for(i=1;i<=n;i++){
        j=a[i];
        if(k/2==j)//sẽ có trường hợp này, ta cùng truy cập vào 1 phần tử và -2 lần
            continue;
        auto it1=cnt.find(j), it2=cnt.find(k-j);
        if(it2==cnt.end())
            continue;
        if(it1->second==0||it2->second==0){
            continue;
        }
        dem+=1;
        it1->second-=1;it2->second-=1;
    }
    cout<<dem;

    return 0;
}
