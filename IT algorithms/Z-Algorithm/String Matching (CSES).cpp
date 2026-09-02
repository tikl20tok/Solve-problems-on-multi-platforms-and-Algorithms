#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//FULL AC
//link: https://cses.fi/problemset/task/1753
/*
Given a string and a pattern, your task is to count the number of positions
where the pattern occurs in the string.

Input

The first input line has a string of length n, and the second input line has a
pattern of length m. Both of them consist of characters a-z.

Output

Print one integer: the number of occurrences.

Constraints

. 1≤n,m ≤ 10^6

Example

Input:
saippuakauppias
pp

Output:
2
*/
//lazy code:
vector<ll> zalaver(string a, string b){//Z-Algorithm lazy version
    string s = b+"$"+a;
    ll i,l=0,r=0;
    ll w=s.size();
    vector<ll> z(w+5,0);
    for (i=1;i<w;i++){
        if (i<=r){
            z[i]=min(z[i-l], r-i+1);
        }
        while (i+z[i]<w && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if (i+z[i]-1 > r){//index < r
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}

vector<ll> zasever(string a, string b){//Z-Algorithm serious version
    cho 2 con trỏ, chạy trên string b (Xâu con) và xâu lớn
    cái này phức tạp hoá việc sử dụng con trỏ, ko đáng để dùng, còn nếu thích thì cứ thử
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    string a,b;
    cin>>a>>b;
    /*
    ta có ý tưởng về z algorithm:
    ta ghép xâu a và b lại cùng 1 cái ngăn cách đặc biệt ở giữa (vd: a+"$"+b)
    ta có 2 hướng: lazy code hoặc nghiêm túc
    lazy code:
    viết đúng cái z algorithm ko cần sửa vào trong
    cơ bản là sẽ lãng phí cái vòng lặp xâu con, nhưng mà không đáng kể, cũng chẳng ảnh hưởng gì đến kết quả
    nghiêm túc: 1 bản chất
    do chỉ cần so sánh với đầu xâu là ta đặt xâu con ở đó
    xâu to ở bên ngoài
    vậy ta cho z algorithm chạy từ đầu của xâu to thay vì đầu xâu (từ nhỏ)
    */
    vector<ll> z=zalaver(a,b);
    ll i, dem=0;
    for (i=0;i<a.size()+b.size()+1;i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;
    for (i=b.size()+1;i<a.size()+b.size()+1;i++){
        if (z[i]==b.size())
            dem++;
    }
    cout<<dem;
    cout<<endl;
    dem=0;
    z=zasever(a,b);
    for (i=0;i<a.size()+b.size()+1;i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;
    for (i=b.size()+1;i<a.size()+b.size()+1;i++){
        if (z[i]==b.size())
            dem++;
    }
    cout<<dem;





    return 0;
}
