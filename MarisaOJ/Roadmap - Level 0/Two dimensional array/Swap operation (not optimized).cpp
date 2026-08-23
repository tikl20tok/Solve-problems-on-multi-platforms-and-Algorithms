#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> arr(n+5,vector<long long>(m+5));
    long long i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }

    long long x,y,z;
    while (q--)
    {
        cin>>x>>y>>z;
        if (x==1)
        {
            swap(arr[y],arr[z]);
        }
        else
        {
            for (i=1;i<=n;i++)
            {
                swap(arr[i][y],arr[i][z]);
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }



    return 0;
}