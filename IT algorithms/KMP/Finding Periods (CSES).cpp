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
of abcabca are abc, abcabc and abcabca.

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
    






    return 0;
}
