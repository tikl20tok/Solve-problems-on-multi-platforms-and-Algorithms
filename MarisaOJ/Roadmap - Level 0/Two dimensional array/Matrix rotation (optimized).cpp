#include<bits/stdc++.h>
using namespace std;
#define ll long long
//FULL AC
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    long long n;
    cin>>n;
    vector<vector<ll>> a(n+5,vector<ll> (n+5,0)), b(n+5,vector<ll> (n+5,0));
    ll i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            cin>>a[i][j];
        }

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            b[j][n-i+1] = a[i][j];//formula can easily deduced by writing example
            //with 0 based 2d array: n-i-1
        }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/*
there another solutions, even reduce 2x times of memory, but this one maybe the most understandable 
*/