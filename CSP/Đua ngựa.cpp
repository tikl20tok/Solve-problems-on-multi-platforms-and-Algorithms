#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/csphn_race
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    /*
    tất cả ngựa phải cùng thi đấu, tức ghép đủ n cặp
    */
    ll n,i,j,k,na,nb;
    cin>>n;na=n;nb=n;
    vector<ll> a(n+1,0), b(n+1,0);
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(a.begin()+1, a.begin()+n+1);
    sort(b.begin()+1, b.begin()+n+1);
    /*
    sau khi sort thì ta dùng 2 con trỏ trên mỗi mảng (tổng 4)
    mạnh nhất a đấu mạnh nhất b, nếu thắng thì kq++
    nếu ko, xét yếu nhất của 2 bên
    nếu a thắng, kq++, nếu ko, -- và cho yếu nhất a đánh với MẠNH NHẤT b
    NHƯNG nếu 2 yếu nhất hoà nhau thì triệt nó luôn, ta đi tiếp trước khi hi sinh
    **việc này nhằm triệt tiêu những thằng mạnh của b, gọi là HY SINH
    */
    ll la=1,lb=1,ra=n,rb=n,kq=0;
    while(la<=ra&&lb<=rb){
        if(a[ra]>b[rb]){
            kq++;
            ra--;rb--;
        }
        else{
            if(a[la]>b[lb]){
                kq++;
                la++;lb++;
            }
            else{
                //ta sẽ kiểu gì cũng phải hi sinh con yếu nhất NHƯNG trước khi hi sinh phải xét xem có hoà với thằng mạnh nhất ko
                if(a[la]<b[rb]){
                    kq--;
                }
                //hoà thì ko phải trừ
                la++;rb--;
            }
        }
    }
    cout<<kq;




    return 0;
}
