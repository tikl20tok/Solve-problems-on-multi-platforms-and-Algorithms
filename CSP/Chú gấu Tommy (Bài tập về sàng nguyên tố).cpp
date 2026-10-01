#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//link: https://csp.vnoi.info/problem/tommy
//Full AC
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n;
    cin>>n;
    ll i,j;
    //xử lí prefixsum+ước+số nguyên tố
    ll maxi=1e7;
    vector<ll> spf(maxi+5);
    for(i=0;i<=maxi;i++){
        spf[i]=i;
    }
    for(i=2;i*i<=maxi;i++){
        if(spf[i]==i){
            for(j=i*i;j<=maxi;j+=i){
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
    vector<ll> cnt(maxi+5,0);//cnt[i] = count xem có bao nhiêu số x là bội của i
    ll last;
    for(i=1;i<=n;i++){
        cin>>j;
        last=0;
        while(j>1){
            if(spf[j]!=last){
                cnt[spf[j]]++;
                last=spf[j];
            }
            j/=spf[j];
        }
    }
    //biến cnt thành prefixsum luôn
    for(i=1;i<=maxi;i++){
        cnt[i]+=cnt[i-1];
    }
    ll m;
    cin>>m;
    ll l,r;
    while(m--){
        cin>>l>>r;
        //bài này chơi bẩn cho l,r <= 2*10^9 mà tối đa là 10^7, vậy nên gặp r>10^7 là cho ve 10^7 luôn ☠️
        r=min(maxi, r);
        cout<<cnt[r]-cnt[l-1];
        cout<<'\n';
    }
    


    return 0;
}
