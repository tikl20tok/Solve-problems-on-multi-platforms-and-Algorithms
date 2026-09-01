#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//FULL AC
//link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2470
/*
See pdf file
*/

ll i,dem=0;
void cusbuildLPS(string s, ll blength)//customized buildLPS
{
    ll len=0, m=s.size(); i=1;
    vector<ll> lps(s.size(),0);
    /*
    we already know that len always <blength if we running on string b
    so we can safely use if len == blength to get the match of b on a
    */
    while (i<m)
    {
        if (s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
            if (len==blength)//if match, then try missmatch to cut to get more true result if have, else we can miss
            {
                len=lps[len-1];
                dem+=1;
            }
        }
        else if (len!=0){
            len=lps[len-1];
        }
        else{
            lps[i]=0;
            i++;
        }
    }
    cout<<dem;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    string a,b;//a là xâu lớn, b là xâu nhỏ
    cin>>a>>b;

    string s = b + "#" + a;//chèn kí tự đặc biệt vào

    cusbuildLPS(s, b.size());
    return 0;
}
