#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/csphn_popust
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    /*
    john PHẢI đặt trc 1 bàn
    đầu tiên ta lấy bàn đặt trc mà nhỏ nhất, cần:
    tổng ai+bi nhỏ nhất
    sắp xếp ưu tiên theo bi càng nhỏ càng tốt, cứ thế mà cộng vào
    thằng đầu tiên là thằng có ai+bi và bi nhỏ nhất
    */
    ll n,i,j,k;
    cin>>n;
    vector<pair<ll,ll>> mang(n+5,{0,0});//ở đây ta cho .first là b, .second là a

    for(i=1;i<=n;i++){
        cin>>j>>k;//nhập a,b
        mang[i]={k,j};//cho b,a
    }
    sort(mang.begin()+1, mang.begin()+n+1);//sắp xếp theo bi
    //xây dụng mảng sufmin cho ai nhỏ nhất trên mảng sorted
    vector<ll> sufmin(n+5,1e18);
    for(i=n;i>=1;i--){
        sufmin[i]=min(sufmin[i+1], mang[i].second);
    }
    /*
    ta có trong k thằng bi đầu ta chọn, ta tính hiệu của ai và bi, ta cần hiệu bi-ai càng lớn càng tốt để giảm tổng đi
    vậy ta xây dụng premax, cụ thể là max của hiệu, không phải giá trị
    đồng thời kèm vị trí của sự thay đổi, để ta tính +- vào đó nữa
    */
    vector<pair<ll, ll>> premax(n+5,{-1e18,0});//ta cho theo thứ tự: hiệu, vị trí
    for(i=1;i<=n;i++){
        premax[i]=premax[i-1];
        ll hieu=mang[i].first-mang[i].second;
        if(premax[i].first<=hieu){
            premax[i].first=hieu;
            premax[i].second=i;
        }
    }
    //tính tổng đoạn sorted bi
    vector<ll> pre(n+5,0);//prefixsum của bi
    for(i=1;i<=n;i++){
        pre[i]=pre[i-1]+mang[i].first;
    }

    /*
    ta chia 2 trường hợp:
    chọn k, thì ta sẽ dùng premax để tính nhỏ nhất
    chọn k-1 sau đó chọn 1 thằng ở ngoài có giá trị ai nhỏ nhất để cho vào, dùng sufmin
    */
    ll tong=0, mintong=1e18;
    for(i=1;i<=n;i++){
        mintong=1e18;
        //th1: chọn k, dùng premax
        tong=pre[i];
        tong-=premax[i].first;//ta trừ đi hiệu, tạm hiểu tong-(bi-ai)=tong-bi+ai
        mintong=min(mintong, tong);
        //th2:
        tong=pre[i-1];
        tong+=sufmin[i];
        mintong=min(mintong, tong);
        cout<<mintong<<"\n";
    }


    return 0;
}
