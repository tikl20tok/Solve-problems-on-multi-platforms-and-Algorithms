#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/contest10_thuthach
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll t,k,a,b;
    cin>>t;
    ll i,j,start,en,mid;
    ll x;
while(t--){
    cin>>k>>a>>b;
    start=1, en=1'000'000'000'000'000'000;
    //binary search
    /*
    ý tưởng sơ bộ:
    đề bảo tìm số thứ k trong dãy triệt các số có ước là a hoặc b
    công thức có bao số có ước là a hoặc b là x/a + x/b + x/ucln(a,b)
    vậy phần còn lại là x - cái trên
    ta sẽ nâng giảm giới hạn đến khi x-cái trên = k thì thôi
    max 60 lần lặp
    */
    ll x;
    while(start<=en){
        mid = start + (en-start)/2;
        x= mid - (mid/a + mid/b - mid/lcm(a,b));
        if(x>=k){
            en=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<start<<"\n";
}


    return 0;
}
