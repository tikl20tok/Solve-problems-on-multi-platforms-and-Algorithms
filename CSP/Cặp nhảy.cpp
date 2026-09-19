#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link đề: https://csp.vnoi.info/problem/csphn_dancing
vector<ll> a(100000+5,0), b(100000+5,0), tdc(100000+5,0);//tdc = tối đa cặp
ll n;
ll bsa(ll val){
    ll start=1,en=n,mid;
    while(start<=en){
        mid=start+(en-start)/2;
        if(a[mid]<=val){//vì cần cái lớn hơn, ko phải >=
            start=mid+1;
        }
        else{
            en=mid-1;
        }
    }
    return start;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    cin>>n;
    ll i,j;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    ll vt;
    sort(a.begin()+1, a.begin()+n+1);
    for(i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b.begin()+1, b.begin()+n+1);
    for(i=1;i<=n;i++){
        vt=bsa(b[i]);
        tdc[i]=n-vt+1;//ghép được với tối đa bao đứa
    }
    ll tich=1, dem=0;
    for(i=n;i>=1;i--){
        dem++;
        if(tdc[i]-(dem-1)){//-1 ở đây là để bỏ cô gái đang xét hiện tại
            tich*=(tdc[i]-(dem-1));
        }
        else{
            cout<<0;//hết thằng sử dụng
            return 0;
        }
        tich%=1000000007;
    }
    cout<<tich;



    return 0;
}
