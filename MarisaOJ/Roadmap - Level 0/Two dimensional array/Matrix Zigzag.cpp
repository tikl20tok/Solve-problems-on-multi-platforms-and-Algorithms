#include<bits/stdc++.h>
using namespace std;
#define ll long long
//full ac
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin>>n>>m;
    ll i,j;
    vector<vector<ll>> a(n+5, vector<ll> (m+5,0));
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    i=1;j=1;
    bool up=true;
    ll dem=1;//ô đầu tiên nên +1
    while(dem <= n*m+1){
        cout<<a[i][j]<<" ";
        if (dem == n*m){
            break;
        }
        if(up){
            if(i==1 && j<m){
                j++;
                up=!up; 
                dem++;
                continue;
            }
            //i==1 hoặc ko NHƯNG J=M
            if(j==m){//đi xuống
                up=!up;
                i++;
                dem++;
                continue;
            }
            //bình thường, ko cần đảo state
            i--;j++;
            dem++;
            continue;
        }
        //nếu down
        if(i==n && j<m){
            j++;
            up=!up;
            dem++;
            continue;
        }
        if(j==1){
            up=!up;
            i++;
            dem++;
            continue;
        }
        i++; j--;
        dem++;
    }
    /*
    we have:
    /^ (up right direction): -> (if can't /^ anymore); if can't -> we will go down (this is the end case)
    / (down left direction): share the same, but if can't, we will go up
    */
    return 0;
}
