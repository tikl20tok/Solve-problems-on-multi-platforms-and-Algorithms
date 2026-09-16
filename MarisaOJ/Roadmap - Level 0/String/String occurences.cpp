#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP", "r", stdin);
    freopen("TESTING.OUT", "w", stdout);

    string s, t;
    cin>>s>>t;
    ll i, j;
    //kmp algorithm
    string ts = t + "#" + s;
    vector<ll> lps(ts.size()+5, 0);
    for(i=1;i<ts.size();i++){
        j = lps[i-1];
        while(j > 0  &&  ts[i] != ts[j]){
            j = lps[j-1];
        }
        if(ts[i] == ts[j]){
            j++;
        }
        lps[i] = j;
    }
    ll dem = 0;
    for(i=1;i<ts.size();i++){
        if(lps[i] == t.size()){
            dem++;
        }
    }
    cout<<dem;

    /*
    cout<<'\n';
    for(i=0;i<ts.size();i++){
        cout<<lps[i]<<" ";
    }
    */

    
    return 0;
}
