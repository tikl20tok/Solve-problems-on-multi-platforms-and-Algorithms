#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

//link đề: https://oj.vnoi.info/problem/SUBSTR, https://vnspoj.github.io/problems/SUBSTR.html (kèm code giải bài <giải theo cách 2>)
/*
Cho xâu A va xâu B chỉ gom cac chu cai thuong. Xau B đuoc goi la xuat hien tai vị tri i của xau A nếu: Ai = B1, Ai+1 = B2,..Ai+blength-1 = Bblength

Hãy tìm TẤT CẢ cac vị trí mà B xuất hiện trong A.

Input

. Dòng 1: xâu A.
· Dòng 2: xâu B.

Độ dài A, B không quá 1000000.

Output
· Ghi ra các vị trí tìm được trên 1 dòng (thứ tự tăng dần). Nếu B không xuất hiện trong A thì bỏ trắng.

E.g:
Input:
aaaaa
aa

Output:
1 2 3 4

*/
/*
Không cần cố hiểu len=lps[len-1] làm gì
Hiểu đơn giản nó là tìm độ dài lớn nhất match mà chứa kí tự tại index i hiện tại
*/

//Cách 1: áp dụng đầy đủ
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

//Cách 2: Rút gọn code/thuật toán
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll i;

/*
Ý tưởng cốt lõi:
1. B kiểu gì cũng phải dùng buildLPS để tạo lps của chính nó, KMP trên chính nó
2. Rồi A cũng KMP trên B dựa trên lps có sẵn
-> Có điểm tương đồng để gộp cả 2:
Sau khi buildLPS B rồi, ta có thể nhảy luôn sang A và dùng chính build LPS
Nhưng làm sao để tách 2 xâu ra? -> Dùng 1 kí tự đặc biệt như "#"

Vậy cùng 1 khung, ta chỉ thêm:
Tụt len xuống khi len=blength tức là xác nhận có xâu B bên trong xâu A, tụt để kiểm tra nếu có xâu khả thi đằng sau tồn tại
Còn về kí tự đặc biệt đã được xử lí triệt để vì nó không trùng 1 kí tự nào khác, len tự động về 0
*/

vector<ll> cusbuildLPS(string s, ll blength){//customized buildLPS
    /*
    ý tưởng cốt lõi:
    gộp xâu s = b + "#" + a
    b = xâu nhỏ, a = xâu lớn
    */
    vector<ll> lps(s.size(),0);
    ll m = s.size();
    ll len = 0;
    i = 1;//i phải bắt đầu từ đầu xâu a, tức là b.size()+1 (b.size() sẽ cho ra "#", +1 ra đầu tiên của a)
    while (i<m)
    {
        /*
        gặp dấu "#" cũng chẳng cần nhánh if riêng vì nhánh elseif len!=0 đã xử lí trót lọt rồi
        */
        if (s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
            if (len==blength){
                len = lps[len-1];
            }
        }
        else{
            if (len!=0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
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

    vector<ll> lps = cusbuildLPS(s, static_cast<ll> (b.size()));

    for (i=b.size()+1;i<s.size();i++)
    {
        if (lps[i]==b.size()){
            cout<<i-2*b.size()+1<<" ";//i-(b.size()-1)<cái này là lấy vị trị đầu> - b.size()(csai này là trừ đi xâu b ở đầu và dấu "#")
        }
    }


    return 0;
}

/*
so sánh cách 1 và 2:
Cách 1 là đầy đủ KMP, tốn bộ nhớ ít hơn
Cách 2 là KMP tối giản, bộ nhớ tốn nhiều nhưng implement nhanh hơn
*/
