#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    //we just can use each character 1 time -> max size of s (string that need to be check) must <=n or <=m first

    long long n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<char>> a(n+5,vector<char>(m+5));
    long long i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    string altstr;
    altstr.reserve(max(n,m)+5);
    long long x,y;
    bool kt=false;

    //horizontal search
    if (s.size()<=m)
    {
        for (i=1;i<=n;i++)
        {
            //get string
            altstr.clear();
            for (j=1;j<=m;j++)
            {
                altstr.push_back(a[i][j]);
            }
            bool check1;
            for (x=0;x<=altstr.size()-s.size();x++)
            {
                check1=true;
                for (y=0;y<s.size();y++)
                {
                    if (altstr[x+y]!=s[y])
                    {
                        check1=false;
                        break;
                    }
                }
                if (check1==true)
                {
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }

    //vertical search
    if (s.size()<=n)
    {
        for (j=1;j<=m;j++)
        {
            //get string
            altstr.clear();
            
            for (i=1;i<=n;i++)
            {
                altstr.push_back(a[i][j]);
            }
            bool check1;
            for (x=0;x<=altstr.size()-s.size();x++)
            {
                check1=true;
                for (y=0;y<s.size();y++)
                {
                    if (altstr[x+y]!=s[y])
                    {
                        check1=false;
                        break;
                    }
                }
                if (check1==true)
                {
                    cout<<"YES";
                    return 0;
                }
            }
        }

    }

    if (kt==false)
        cout<<"NO";




    return 0;
}




