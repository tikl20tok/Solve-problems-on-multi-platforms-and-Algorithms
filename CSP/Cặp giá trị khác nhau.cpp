#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//full ac
//link https://csp.vnoi.info/problem/lop822024_1ddpais
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    /*
    ở bài này, đạt tối ưu, ta sẽ duyệt theo các giá trị của a[i]
    vấn đề là abs(a[i])<=1000 nên ta sẽ duyệt thẳng 2000 lần
    còn nếu mà a[i] lớn hơn nhiều nhưng chỉ có 10^6=n giá trị khác nhau thì ta quản lí = touched
    nhưng bài này ko cần quản lí =touched phức tạp đến v vì a[i] khá nhỏ
    ai - aj = k
    => k + aj = ai
    i!=j -> chỉ khi k=0 thì mới thoả điều kiện trên
    vậy ta sẽ dùng count[i] xem giá trị i xuất hiện bao lần
    duyệt từng giá trị từ -1000 -> 1000
    +giá trị đó với k, check trong mảng có bao nhiêu rồi + tổng vào
    trường hợp mà k==0 thì tổng-=1; 
    */
    ll n,k;
    cin>>n>>k;
    ll i,j;
    vector<ll> cnt(2005,0);
    for(i=1;i<=n;i++){
        cin>>j;
        j+=1000;
        cnt[j]++;
    }
    ll val, gt;
    long long sum=0;
    for(i=0;i<=2000;i++){
        val=i-1000;
        gt=val+k;
        if(gt<=1000 && gt>=-1000){
            if(k==0){
                sum+=cnt[i]*(cnt[i]-1);
                continue;
            }
            sum+=cnt[gt+1000]*cnt[i];//+1000 vì nãy -1000 mà mảng đang theo hệ +1000 để index >=0
        }
    }
    cout<<sum;

    return 0;
}
