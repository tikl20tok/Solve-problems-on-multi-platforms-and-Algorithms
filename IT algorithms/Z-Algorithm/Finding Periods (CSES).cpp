#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//FULL AC
//link: https://cses.fi/problemset/task/1733
/*
A period of a string is a prefix that can be used to generate the whole string by
repeating the prefix. The last repetition may be partial. For example, the periods
of abcabca are
abc,
abcabc,
abcabca.

Your task is to find all period lengths of a string.

Input

The only input line has a string of length n consisting of characters a-z.

Output

Print all period lengths in increasing order.

Constraints

1 <n <= 10^6

Example

Input:
abcabca

Output:
3 6 7
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
    /*
    nếu để z algorithm chạy trên này, có 1 nhận xét là sẽ liên tục lấy được trùng đoạn đầu bao nhiêu, yeah
    ừm, trùng đoạn đầu bao nhiêu, vậy thì ắt hẳn là đoạn đầu đó chính là đoạn mà ta lặp
    vậy ra được 1 kết luận là chỉ cần lấy n-z[i]
    tuy nhiên, z chỉ đảm bảo cho ta match pre bao kí tự từ i
    NHƯNG không đảm bảo nó có trải dài đến hết xâu không
    chính bởi vậy còn cần phải check xem là i+z[i]=n hay không nữa

    i càng tăng, thì số lượng có khả năng match càng giảm, đồng nghĩa phép trừ kia càng tăng
    vậy ta duyệt i xuôi rồi in ra theo thứ tự là xong việc
    đồng thời ta vẫn đảm bảo được từng con số sẽ khác nhau, bởi vì i càng tăng, trong khi điểm cuối là n cố định
    nên nếu có số thoả mãn thì tất cả sẽ khác nhau, ko cần check lại

    còn border case: toàn bộ xâu, thì in ra luôn size là xong
    */
    //z algorithm
    vector<ll> z(s.size()+5,0);
    ll l=0,r=0;
    for (i=1;i<s.size();i++){
        if (i<=r){
            z[i]=min(z[i-l],r-i+1);
        }
        while (i+z[i]<s.size() && s[z[i]]==s[z[i] + i]){
            z[i]++;
        }
        if (i +z[i]-1 > r){
            l=i;
            r=i +z[i]-1;
        }
    }

    /*
    for (i=1;i<s.size();i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;
    */

    for (i=1;i<s.size();i++){
        if (z[i]+i==s.size()){
            cout<<s.size()-z[i]<<" ";
            //hay là cout<<i<<" "; , bản chất như 1
        }
    }
    cout<<s.size();

    return 0;
}
