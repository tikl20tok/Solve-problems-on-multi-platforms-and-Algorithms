#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    long long n,m;
    cin>>n>>m;
    long long i,j;
    vector<vector<long long>> a(n+1,vector<long long>(m+1));
    /*
    struct like this:

    ----->top
    ^      |
    |left  |right
    |      |
    |<----bottom
    */
    long long top=1;
    long long right=m;
    long long bottom=n;
    long long left=1;
    long long dem=0;

    long long total=n*m;

    //if not use total will cause false answer cuz write 4 time in the same cell (case 1 row or 1 column)
    while (top<=bottom&&left<=right&&total>0) //means line not collision so there a retangle to fill
    {
        if (total==0)
            break;
        //go to right (top way)
        for (i=left;i<=right;i++)
        {
            dem+=1;
            a[top][i]=dem;
            total-=1;
        }
        if (total==0)
            break;
        //go to under (right way)
        for (i=top+1;i<=bottom;i++)
        {
            dem+=1;
            a[i][right]=dem;
            total-=1;
        }
        if (total==0)
            break;
        //go to left (bottom way)
        for (i=right-1;i>=left;i--)
        {
            dem+=1;
            a[bottom][i]=dem;
            total-=1;
        }
        if (total==0)
            break;
        //go to up (left way)
        for (i=bottom-1;i>=top+1;i--)
        {
            dem+=1;
            a[i][left]=dem;
            total-=1;
        }
        if (total==0)
            break;
        top+=1;
        right-=1;
        bottom-=1;
        left+=1;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }



    return 0;
}
