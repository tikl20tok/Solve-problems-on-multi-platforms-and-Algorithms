#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/prime
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    /*
    gọi root là bỏ hết luỹ thừa đi, để luỹ thừa 1 khi phân tích ra thừa số snt
    mỗi thằng sẽ chỉ có 1 root duy nhất, yeah, duy nhất
    sau đó duyệt trâu rồi đếm rồi gauss rồi cộng tổng là hết, chắc v
    */
    int t;
    cin>>t;
    ll i,j;
    ll maxi=1000000;
    vector<ll> snt(maxi+5,1);
    for(i=2;i<=maxi;i++){
        if(snt[i]==1){
            for(j=i;j<=maxi;j+=i)
                snt[j]*=i;
        }
    }
    vector<ll> cnt(maxi+5,0);
    ll a,b;
    ll sum;
    while(t--){
        cin>>a>>b;
        a=max((ll)2,a);b=max((ll)2,b);
        sum=0;
        for(i=a;i<=b;i++){
            sum+=cnt[snt[i]];
            cnt[snt[i]]++;
        }
        cout<<sum<<'\n';
        for(i=a;i<=b;i++){//reset
            cnt[snt[i]]=0;
        }
    }
    return 0;
}
/*bản này đúng nhưng tle, quản lí lằng nhằng, vấn đề là dù j cx đi qua thì cộng vào luôn lại còn bày đặt công thức ☠️
        
for(i=a;i<=b;i++){
    if(cnt[snt[i]]==0)//giảm việc chèn quá nhiều
        touched.insert(snt[i]);
    cnt[snt[i]]++;
}   
for(auto it=touched.begin();it!=touched.end();it++){
    val=cnt[*it];
    sum+=(val*(val-1))/2;//*it đang là snt[i] rồi
    cnt[*it]=0;
}

*/