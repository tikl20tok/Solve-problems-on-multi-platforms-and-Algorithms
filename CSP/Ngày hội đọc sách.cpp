#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/tn25_docsach
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,t,a,b;
    cin>>n>>t>>a>>b;
    ll i,j;
    vector<ll> pre(n+5,0);
    for(i=1;i<=n;i++){
        cin>>j;
        pre[i]=pre[i-1]+j;
    }
    /*
    b<a
    thời gian đọc bìa: b
    thời gian đọc nội dung: a-b
    tổng thời gian đọc toàn bộ: a
    từ 1->i thì tổng thời gian đọc bìa là: i*b
    -> thời gian đọc nội dung còn lại: t-i*b //luôn >=0 do ta đã chặn điều kiện trước ở trên rồi
    => số lượng đọc được toàn bộ tối đa là: (t-i*b)/(a-b) và luôn <=i (số lượng sách)
    */
    ll slmcl;//số lượng max còn lại
    ll maxi=0;
    for(i=1;i<=n;i++){
        if(i*b>t)
            break;
        slmcl=min(i, (t-i*b)/(a-b));//cứ thấy cái điều kiện nào là ép luôn, lúc test ví dụ đề thì ko min sẽ sai nhưng t vẫn chưa c/m đc sao thêm min, thôi thì cứ gặp bài nào thấy restraint nào là ép luôn, ko thừa
        maxi=max(maxi, pre[i]-pre[i-slmcl]);
    }
    cout<<maxi;

    return 0;
}
