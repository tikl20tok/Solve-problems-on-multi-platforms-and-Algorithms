#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,m;
    cin>>n>>m;
    /*
    a1 a2 an là nguyên dương, vậy số luôn phải <m
    tiếp, bài này ko hỏi từng f1 f2 f3 fm mà hỏi thẳng luôn fm = bao nhiêu, tức:
    chỉ lấy tổng tất cả các số <=m, hết
    */
    vector<ll> a((ll)1e6+5,0);
    ll i,j;
    for(i=1;i<=n;i++){
        cin>>j;
        a[i]=j;
    }
    sort(a.begin()+1, a.begin()+n+1);
    /*
    ta cần:
    x+y<=m
    mà ta đã có x và m
    vậy: tìm giới hạn của y, từ vị trí hiện tại tới y sẽ ghép được bao cặp
    làm như vậy với mỗi phần tử, duyệt tăng cho dễ, sort mảng trc
    dpt: n log n
    */
    ll dem=0;
    for(i=1;i<n;i++){
        auto it=upper_bound(a.begin()+1+i, a.begin()+n+1, m-a[i]);
        ll idx=it-a.begin();
        if(it==a.begin()+n+1){
            idx=n;
            dem+=idx-i;//cái này ko -1 vì ta đã dịch xuống phạm vi chuẩn r
            continue;
        }
        dem+=idx-i -1;//-1 vì đang là p tử lớn hơn hẳn, vậy vị trí thoả mãn cuối là -1 của nó
    }
    cout<<dem;

    return 0;
}
