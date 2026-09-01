#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//FULL AC
//link: https://codeforces.com/problemset/problem/126/B
/*



Asterix, Obelix and their temporary buddies Suffix and Prefix has finally found the Harmony temple. However, its doors were firmly locked
and even Obelix had no luck opening them.

A little later they found a string s, carved on a rock below the temple's gates. Asterix supposed that that's the password that opens the
temple and read the string aloud. However, nothing happened. Then Asterix supposed that a password is some substring t of the string s.

Prefix supposed that the substring t is the beginning of the string s; Suffix supposed that the substring t should be the end of the string s;
and Obelix supposed that t should be located somewhere inside the string s, that is, t is neither its beginning, nor its end.

Asterix chose the substring t so as to please all his companions. Besides, from all acceptable variants Asterix chose the longest one (as
Asterix loves long strings). When Asterix read the substring t aloud, the temple doors opened.

You know the string s. Find the substring t or determine that such substring does not exist and all that's been written above is just a nice
legend.

Input
You are given the string s whose length can vary from 1 to 10^6 (inclusive), consisting of small Latin letters.

Output
Print the string t. If a suitable t string does not exist, then print "Just a legend" without the quotes.

Examples
input
fixprefixsuffix

output
fix

input
abcdabc

output
Just a legend
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
    //build lps
    vector<ll> lps(n,0);
    ll i,j;
    for (i=1;i<n;i++)
    {
        j=lps[i-1];
        while (j>0&&s[i]!=s[j]){
            j=lps[j-1];
        }
        if (s[i]==s[j])
            j++;
        lps[i]=j;
    }
    /*
    ở đây thấy yêu cầu 1 xâu t có 3 điểm phải bằng nhau:
    1 là tiền tổ
    2 là hậu tố
    3 là đoạn giữa (chẳng phải tiền tố cũng không phải hậu tổ, "Obelix"(trong đề))
    từ 1 và 2-> dùng lps
    4 là xâu con phải dài nhất (Asterix trong đề)
    Nhận thấy lps cũng build luôn tại i tức thoả mãn được cho điều kiện 2
    Vậy là từ lấy lps[n-1] làm gốc, nhảy xuống len=lps[len-1] để lấy toàn bộ size, 
    sau đó duyệt qua toàn bộ xâu xem có thằng nào trùng size đó không
    Lưu ý: Không chỉ lấy len=lps[n-1] mà còn phải dịch xuống len=lps[len-1] không thì là thiếu
    len=lps[n-1] đóng vai trò là đoạn suf có chứa đoạn cuối mà trùng nhau
    */
    vector<bool> a(n+5,false);
    j=lps[n-1];
    while (j>0){
        a[j]=true;
        j=lps[j-1];
    }
    ll check=0;
    for (i=1;i<n-1;i++){//Giải thích ở dưới
        if (a[lps[i]]){
            check=max(check,lps[i]);
        }
    }
    
    /*
    riêng kí tự cuối thì không cần kiểm tra vì nó sẽ phá vỡ quy tắc giống nhau hay không (xuất hiện lù lù ở cuối xâu nên check luôn đúng)
    riêng với những cái while j=lps[j-1] thì không phá quy tắc bởi nó chỉ cho ra độ dài nhưng ko xuất hiện lộ liễu
    rồi ta có thể so sánh với những cái còn lại mà hoàn toàn không để ý gì đến kt.
    Ta chỉ cần đánh dấu các border cần check và duyệt đến n-1 
    */
    /*for (i=0;i<n;i++)
        cout<<lps[i]<<" ";
    cout<<"\n";*/
    if (check){
        for (i=0;i<check;i++)
            cout<<s[i];
    }
    else
        cout<<"Just a legend";



    return 0;
}
