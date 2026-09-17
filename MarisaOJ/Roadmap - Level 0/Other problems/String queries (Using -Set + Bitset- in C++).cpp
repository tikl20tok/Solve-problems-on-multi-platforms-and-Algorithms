#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
set: o log n
unordered set: o 1
*/
bitset<321272385> a;
//khai báo global hoặc static bool (thêm static) mặc định khởi tạo = false với cả bitset và bool
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n, q;
    cin>>n;
    ll i, j;  
    ll dem=0, tong;
    string s;
    ll lt[6];
    lt[1]=26;
    lt[2]=676;
    lt[3]=17576;
    lt[4]=456976;
    lt[5]=11881376;
    for(i=1;i<=n;i++){
        cin>>s;
        /*
        do độ dài nhỏ nên dùng pow, 26^5 = 11'881'376, tạo bool(bitset) khoảng 321272380 + 5 phần tử
        */
        //encode
        dem=1;
        tong=0;
        //max 5 kí tự
        for(j=0;j<s.size();j++){
            tong+=(s[j] - 'a' + 1)*lt[dem];
            dem++;
        }
        a[tong] = 1;
    }

    cin>>q;
    for(i=1;i<=q;i++){
        cin>>s;
        //encode
        dem=1;
        tong=0;
        //max 5 kí tự
        for(j=0;j<s.size();j++){
            tong+=(s[j] - 'a' + 1)*lt[dem];
            dem++;
        }
        if(a[tong]){
            cout<<"YES";
        }
        else
            cout<<"NO";
        cout<<"\n";
    }

    return 0;
}
/*
Cách mới đang hoạt động sẽ tốt hơn:
dù cả 2 cách đều hash, nhưng khác nhau ở bước truy cập để kiểm tra dù đều là o(1):
unordered set
xử lí collision,...
bool (hoặc bitset nếu muốn giảm bộ nhớ gấp 8 lần):
truy cập đúng địa chỉ trong RAM luôn
*/
//Cách lười nhất thế giới, vẫn đúng nhưng bài này quá trick, đành tự encode, giải thích ở trên
/*
    set thì sẽ ko reserve được, bên cạnh đó còn phải xử lí logn lại mỗi lần, tốn thời gian
    unordered reserve được, lại còn o 1, đành chấp nhận rủi ro sai nh
*/
/*
ll n, q;
    cin>>n;
    ll i,j;
    
    unordered_set<string> a;
    a.reserve(n+5);
    string s;
    for(i=1;i<=n;i++){
        cin>>s;
        a.insert(s);
    }
    cin>>q;
    for(i=1;i<=q;i++){
        cin>>s;
        if(a.count(s)){
            cout<<"YES";
        }
        else
            cout<<"NO";
        cout<<"\n";
    }
*/