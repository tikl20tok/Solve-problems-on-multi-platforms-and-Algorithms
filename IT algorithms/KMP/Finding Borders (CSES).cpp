#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//FULL AC
//link: https://cses.fi/problemset/task/1732
/*
A border of a string is a prefix that is also a suffix of the string but not the whole
string. For example, the borders of abcababcab are ab and abcab.

Your task is to find all border lengths of a given string.

Input

The only input line has a string of length n consisting of characters a-z.

Output

Print all border lengths of the string in increasing order.
Constraints

1 ≤ n < 10^6

Example

Input:
abcababcab

Output:
2 5
*/



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    string s;
    cin>>s;
    //buildLPS
    long long n=s.size();
    vector<ll> lps(n, 0);
    long long tg=-1;
    ll i;
    for (i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        lps[i] = j;
    } 
    vector<ll> idx; idx.reserve(n);
    ll len=lps[n-1];
    //lấy theo thứ tự giảm dần
    while (len!=0)
    {
        idx.push_back(len);
        len=lps[len-1];
    }
    //thì in ngược ra thứ tự tăng dần
    for (i=idx.size()-1;i>=0;i--)
        cout<<idx[i]<<" ";






    return 0;
}
