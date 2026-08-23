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

    ll n,m;
    cin>>n>>m;
    ll i=1,j=1;
    vector<vector<ll>> a(n+1,vector<ll>(m+1,0));
    
    ll total=0;
    ll dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
    ll direction=0;
    while (total<n*m)//do not use <= cuz after finish a valid process, total will+=1 (=n*m, valid) and that's the last process
    {
        
        //This use cycle direction to fill the matrix so it is easy to implement using MOD4 to manipulate the direction. The direction is defined as:
        /*
        define direction: 0->right, 1->down, 2->left, 3->up  => MOD4
        when from left to right: i=i (0), j+=1 (1)
        when from top to bottom: i+=1 (1), j=j (0)
        when from right to left: i=i (0), j-=1 (-1)
        when from bottom to top: i-=1 (-1), j=j (0)
        -> define a direction array: dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, index base on MOD4
        -> define a direction array: dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, index base on MOD4
        -> define formula when to change direction:
        out of bound: i<1 or i>n or j<1 or j>m, and has been visited: a[i][j]!=0
        */

        a[i][j]=++total;//total+=1 -> a[i][j]=total
        i+=dx[direction];
        j+=dy[direction];
        if (!(i>=1&&i<=n&&j>=1&&j<=m&&a[i][j]==0))//if not satisfy these condition, change the direction
        {
            //back to the valid position
            i-=dx[direction];
            j-=dy[direction];

            //change the direction
            direction=++direction%4;

            //go to the next position (cuz we changed to valid direction)
            i+=dx[direction];
            j+=dy[direction];
        }
    }
    //print it out
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

//solution link: https://marisaoj.com/solution/407/all

void ver1()
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
}
