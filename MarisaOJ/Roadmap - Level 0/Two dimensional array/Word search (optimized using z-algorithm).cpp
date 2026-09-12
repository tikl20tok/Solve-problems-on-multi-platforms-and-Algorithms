#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,m;
    cin>>n>>m;
    ll i,j;
    vector<string> a(n+5, "");
    for (i=0;i<n;i++){
        cin>>a[i];
    }
    string s,k;
    bool kt;
    ll l,r;
    cin>>s;
    vector<ll> z(max(n,m)+5, 0);
    //horizontal search
    if (m >= s.size()){
        for(i=0;i<n;i++){
            //z-algorithm
            k=s+"#"+a[i];//check if s in a[i]
            l=0;r=0;
            fill(z.begin(), z.end(), 0);//reset array
            for(j=0;j<k.size();j++){
                if(j<=r){
                    z[j]=min(z[j-l], r-j+1);
                }
                while(j+z[j]<n && k[z[j]]==k[z[j] + j]){
                    z[j]++;
                }
                if(j+z[j]-1>r){
                    l=j;
                    r=j+z[j]-1;
                }
            }
            for(j=s.size()+1;j<k.size();j++){
                if(z[j]==s.size()){
                    kt=true;
                    break;
                }
            }
        }

        //reverse
        for (j=n-1;j>=0;j--){
            l=0;r=0;
            k=s+"#";
            for(i=m-1;i>=0;i--){
                k+=a[j][i];
            }
            //z-algorithm
            fill(z.begin(), z.end(), 0);//reset array
            for(i=0;i<k.size();i++){
                if(i<=r){
                    z[i]=min(z[i-l], r-i+1);
                }
                while(i+z[i]<=n && k[z[i]]==k[z[i] + i]){
                    z[i]++;
                }
                if(i+z[i]-1>r){
                    l=i;
                    r=i+z[i]-1;
                }
            }
            for(i=s.size()+1;i<k.size();i++){
                if(z[i]==s.size()){
                    kt=true;
                    break;
                }
            }
        }
    }
    if(kt==true){
        cout<<"YES";
        return 0;
    }

    //vertical search
    if(s.size() <= n){
        for (j=0;j<m;j++){
            l=0;r=0;
            k=s+"#";
            for(i=0;i<n;i++){
                k+=a[i][j];
            }
            //z-algorithm
            fill(z.begin(), z.end(), 0);//reset array
            for(i=0;i<k.size();i++){
                if(i<=r){
                    z[i]=min(z[i-l], r-i+1);
                }
                while(i+z[i]<=n && k[z[i]]==k[z[i] + i]){
                    z[i]++;
                }
                if(i+z[i]-1>r){
                    l=i;
                    r=i+z[i]-1;
                }
            }
            for(i=s.size()+1;i<k.size();i++){
                if(z[i]==s.size()){
                    kt=true;
                    break;
                }
            }
        }

        //reverse
        for (j=m-1;j>=0;j--){
            l=0;r=0;
            k=s+"#";
            for(i=n-1;i>=0;i--){
                k+=a[i][j];
            }
            //z-algorithm
            fill(z.begin(), z.end(), 0);//reset array
            for(i=0;i<k.size();i++){
                if(i<=r){
                    z[i]=min(z[i-l], r-i+1);
                }
                while(i+z[i]<=n && k[z[i]]==k[z[i] + i]){
                    z[i]++;
                }
                if(i+z[i]-1>r){
                    l=i;
                    r=i+z[i]-1;
                }
            }
            for(i=s.size()+1;i<k.size();i++){
                if(z[i]==s.size()){
                    kt=true;
                    break;
                }
            }
        }
    }
    if (kt){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";


    return 0;
}




//word search ver 1, not optimized, maybe >=^3
/*
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
    vector<vector<char>> a(n+5,vector<char>(m+5));
    long long i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>s;

    string altstr;
    altstr.reserve(max(n,m)+5);
    long long x,y;
    bool kt=false;

    //horizontal search
    if (s.size()<=m)
    {
        //left to right
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
        //right to left
        for (i=n;i>=1;i--)
        {
            //get string
            altstr.clear();
            for (j=m;j>=1;j--)
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
        //top to bottom
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
        //bottom to top
        for (j=m;j>=1;j--)
        {
            //get string
            altstr.clear();
            
            for (i=n;i>=1;i--)
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
*/



