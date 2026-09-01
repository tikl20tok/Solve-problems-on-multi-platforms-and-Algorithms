#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//FULL AC
//link: https://codeforces.com/problemset/problem/432/D
/*
You have a string s = S1S2 ... Ss, where |s| is the length of string s, and s; its i-th character.

Let's introduce several definitions:

. A substring s[i .. j] (1 ≤i≤j|s|) of string s is string sSi+1 ... Sj.
. The prefix of string s of length l (1 ≤1≤|s|) is string s[1 .. l].
. The suffix of string s of length l (1 ≤1≤|s|) is string s[|s|-l+1 .. |s|].

Your task is, for any prefix of string s which matches a suffix of string s, print the number of times it occurs in string s as a substring.

Input
The single line contains a sequence of characters s1s2 ... S|s| (1 ≤|s| ≤10^5)-string s. The string only consists of UPPERCASE ENGLISH
letters.

Output
In the first line, print integer k (0≤k≤|s|) - the number of prefixes that match a suffix of string s. Next print k lines, in each line print two
integers li Ci. Numbers li Ci mean that the prefix of the length li matches the suffix of length li and occurs in string s as a substring ci times.
Print pairs li Ci in the order of INCREASING li.

Examples

input
ABACABA

output
14
3 2
71

input
AAA

output
3
L 3
22
3 1
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
    /*
    ta có nhận xét trên định nghĩa đề bài:
    xâu được tính từ 1 -> |s|, hoàn toàn có thể chuyển dịch về 0
    l là length
    định nghĩa pre: 0->l-1
    SUF: |s|-1-l+1 = |s|-l -> |s|-1
    vậy là suf phải có đít là cuối xâu
    -> chỉ cần nhảy j=lps[j-1] là xong 
    in ra:
    li -> length
    ci -> số lần xuất hiện
    để tính số lần xuất hiện mà không bị phức tạp n^2 thì?

    
    */


    return 0;
}
