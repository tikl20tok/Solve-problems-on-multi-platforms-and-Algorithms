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
    ll n=s.size();
    ll i,j;
    //buildLPS
    vector<ll> lps(n,0);
    for (i=1;i<n;i++){
        j=lps[i-1];
        while (j>0&&s[i]!=s[j]){
            j=lps[j-1];
        }
        if (s[i]==s[j])
            j++;
        lps[i]=j;
    }

    /*
    0 1 2 3 4 5 6
    a b c a b c a
    0 0 0 1 2 3 4 
    abc,      3
    abcabc,   6
    abcabca.  7
    lặp lại xâu liên tục, phần cuối sẽ là 1 phần
    -> tại lps cuối chắc chắn sẽ có là match bao nhiêu so với xâu lặp (Lượng kí tự match với xâu lặp)
    Để có được càng nhiều border càng tốt, dùng phép nhảy lùi j=lps[j-1]
    ok, vậy giả sử ta có size rồi, t đặt j tại vị trí cuối, trên lý thuyết thì các vị trí còn lại sẽ bị fill 0
    ví dụ: j1=4 -> như mảng lps, còn các giá trị 0 là gốc để so sánh mà gốc là "abc"
    -> abc hợp lệ
    tương tự degrade xuống, j2=1 -> từ 0->5 =0 tức "abcabc"
    Ta làm vậy cũng đảm bảo thứ tự tăng dần, xong, HẾT BÀI
    j3=0 -> toàn bộ xâu
    Vậy ta suy ra được công thức:
    với mỗi j để tìm/biết được bao số 0 còn lại thì ta áp dụng: (n-1)-j +1(bù size) = n-j
    */
    j=lps[n-1];
    while (j>=0){//thêm cả số 0 vào nữa tính luôn cả xâu, xong việc
        cout<<n-j<<" ";
        if (j==0) 
            break;
        j=lps[j-1];
    }



    return 0;
}
