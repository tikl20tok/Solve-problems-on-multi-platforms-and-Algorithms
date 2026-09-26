#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/csphn_demso
//Full AC
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    /*
    ý tưởng chung: dùng chính sàng nguyên tố, mỗi lần j đi qua thì +ước cho nó
    bên cạnh đó, điều kiện là số nguyên tố là 1, là true
    với số 0 có vô hạn ước nên ta vứt vì bt chắc nó inf, ko phải hữu hạn
    vs số 1 có 1 ước, duyệt từ 1

    */
    ll i,j,n,k;
    cin>>n>>k;
    ll MAX=1000000;
    vector<ll> snt(MAX+5, 0);
    //sàng được biến tấu cực ảo nhưng đảm bảo nlogn
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j+=i){
            snt[j]++;
        }
    }
    snt[1]=1;
    ll dem=0;//đếm, count
    //trường hợp số 1 tách riêng
    if(k==1){
        cout<<1;
        return 0;
        //tại đây, chỉ có duy nhất số 1 có 1 ước nên cout 1 rồi thoát
    }
    for(i=2;i<=n;i++){
        if(snt[i]==k){
            dem++;
        }
    }
    for(i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(i=1;i<=n;i++){
        cout<<snt[i]<<" ";
    }
    cout<<"\n";
    cout<<dem;
    return 0;
}
