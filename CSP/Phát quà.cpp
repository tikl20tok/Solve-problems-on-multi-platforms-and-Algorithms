#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/csphn_gifts
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,k;
    cin>>n>>k;
    ll i,j;
    vector<ll> pre(n+5,0), sufmax(n+5,0), premax(n+5,0);
    for(i=1;i<=n;i++){
        cin>>j;
        pre[i]=pre[i-1]+j;
    }
    /*
    tấm chọn max là bên phải hoặc bên trái của cám, nên phải xét cả 2 phía = suf và pre
    */
    //sufmax
    for(i=n-k+1;i>=1;i--){
        sufmax[i]=max(sufmax[i+1], pre[i+k-1]-pre[i-1]);
    }
    for(i=k;i<=n;i++){
        premax[i]=max(premax[i-1], pre[i]-pre[i-k+1 -1]);
    }
    //lọc
    ll gt=1e18;
    for(i=1;i<=n-k+1;i++){//i đang là vị trí cám bắt đầu chọn, vậy premax[i-1]
        gt=min(gt, max(premax[i-1], sufmax[i+k-1 +1]));//chừa ra đoạn giữa, ta lấy max trái phải rồi lấy min của các cái đó
        //không duyệt từ i=k+1 vì sẽ sót suf
    }
    cout<<gt;
    

    return 0;
}
