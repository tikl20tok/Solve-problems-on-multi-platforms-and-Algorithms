#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

vector<long long> buildLPS(string s)
{
    long long m=s.size();
    vector<long long> lps(m,0);
    long long i=1,len=0;
    while (i<m)
    {
        if (s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else if (len!=0)
        {
            len=lps[len-1];
        }
        else
        {
            lps[i]=0;
            i++;
        }
    }
    return lps;
}
vector<long long> KMP(string s1, string s2)
{
    vector<long long> lps = buildLPS(s2);
    vector<long long> firstidx;
    firstidx.reserve(s1.size());
    long long m=s2.size(),n=s1.size();
    long long i=0,j=0;
    while (i<n)
    {
        if (s1[i]==s2[j])
        {
            i++;
            j++;
            if (j==m)
            {
                //thông thường ta sẽ return true tại đây nhưng nào ngờ đây mới là chỗ để lấy được vị trí đầu xuất hiện xâu hợp lệ
                firstidx.push_back(i-m+1);
                //tưởng như xong nhưng thực tế để tránh thiếu, ta nên lùi j = cách giả lập đây là trường hợp missmatch
                //đồng thời cũng để rút bớt xâu và tìm được độ dài dài nhất nhỏ hơn hiện tại chứa kí tự này
                j=lps[j-1];
            }
        }
        else if (j!=0)
        {
            j=lps[j-1];
        }
        else
        {
            i++;
        }
    }
    return firstidx;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    string a,b;
    cin>>a>>b;
    vector<long long> firstindex=KMP(a,b);
    //ko cần sort vì đã vị trí nhập đã tăng dần rồi
    for (long long i=0;i<firstindex.size();i++)
    {
        cout<<firstindex[i]<<" ";
    }




    return 0;
}
