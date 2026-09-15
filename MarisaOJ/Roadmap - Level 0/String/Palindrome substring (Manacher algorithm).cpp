#include<bits/stdc++.h>
using namespace std;
#define ll long long
//LƯU Ý: BÀI NÀY KO PHẢI TOÀN THỂ SUBSTRING, CHỈ CẮT ĐẦU HOẶC ĐUÔI (THU HẸP) THÔI 
/*
ta có 1 kí tự được coi là xâu palindrome
-> dem = s.size() trước
giờ chỉ được cắt đầu hoặc đuôi tuỳ ý
vậy sử dụng luôn manacher
với mỗi p[i] là size của 1 palindrome thì /2 ra được số, dem+= vào là xong
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);
    
    string s;
    cin>>s;
    ll i,j;
    //prepare for manacher
    string ts = "!#";
    for(i=0;i<s.size();i++){
        ts+=s[i];
        ts+="#";
    }
    ts+="%";

    //manacher algorithm
    ll c=0, r=0;
    vector<ll> p(ts.size()+5,0);
    for(i=1;i<ts.size();i++){
        if(i<r){
            p[i] = min(r-i, p[2*c - i]);
        }
        while(ts[i - p[i] - 1] == ts[i + p[i] + 1]){
            p[i]++;
        }
        if(i+p[i] > r){
            c=i;
            r=i+p[i];
        }
    }
    ll dem = s.size();//1 char count as a palindrome
    for(i=0; i<p.size(); i++){
        if(p[i]){
            dem+=p[i]/2;
        }
    }
    cout<<dem;

    return 0;
}