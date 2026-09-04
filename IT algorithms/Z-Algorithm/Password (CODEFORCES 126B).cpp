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
    ll i,j;
    ll l=0, r=0;
    //z-algorithm
    for (i=1;i<n;i++){
        if (i<r){
            z[i]=min(z[i], r-i+1);
        }
        while (z[i]+i <n && z[i]==z[i+z[i]]){
            z[i]++;
        }
        if (i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    /*
    ta cần:
    3 xâu giống nhau bên trong, 1 cái pre, 1 cái suf, 1 cái giữa
    trong tất cả thoả mãn, lấy cái lớn nhất

    dựa trên thuật toán z-algorithm
    để là suf: index phải reach n
    để là giữa: index ko reach n
    2 cái có số giống nhau,
    chính bởi vậy ta sẽ sử dụng 1 bool pair
    */
    


    return 0;
}
