#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,c;
    cin>>n>>c;
    ll i,j;
    vector<ll> x(n+5,0);
    for(i=1;i<=n;i++)
        cin>>x[i];
    sort(x.begin()+1, x.begin()+n+1);
    ll start=1, en=1000'000'000, mid;
    //dpt: log(10^9)*n
    /*
    ta sẽ thử lắp từng giá trị vào
    yêu cầu khoảng cách nhỏ nhất trong mảng là lớn nhất
    -> mỗi kc chỉ cần >= mid
    đi lên từng index, cần x[i]-last >= mid, rồi đi tiếp, quan trọng là phải đạt được c lần chọn 
    */
    ll kq=0;
    ll last;
    while(start<=en){
        mid=start+(en-start)/2;
        last=x[1];//luôn chọn phần tử đầu tiên
        j=c-1;//luôn chọn phần tử đầu tiên
        for(i=2;i<=n;i++){
            if(x[i]-last >= mid){//đã sort, đảm bảo ko âm
                last=x[i];
                j--;
            }
        }
        if(j<=0){//tức có >= cọc có thể sử dụng, thử tăng khoảng cách cọc lên
            start=mid+1;
            kq=max(kq,mid);
        }
        else{//thiếu cọc, giảm giới hạn
            en=mid-1;
        }
    }
    cout<<kq;
    return 0;
}
