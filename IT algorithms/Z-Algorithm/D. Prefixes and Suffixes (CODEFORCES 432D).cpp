#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
//FULL AC
//link: https://codeforces.com/problemset/problem/432/D
/*
You have a string s = S1S2 ... Ss, where |s| is the length of string s, and s; its i-th character.

Let's introduce several definitions:

. A substring s[i .. j] (1 ≤i≤j|s|) of string s is string sSi+1 ... Sj.
. The prefix of string s of length l (1 ≤1≤|s|) is string s[1 .. l].
. The suffix of string s of length l (1 ≤1≤|s|) is string s[|s|-l+1 .. |s|].

Your task is, for any prefix of string s which matches a suffix of string s, print the number of times it occurs in string s as a substring.

Input
The single line contains a sequence of characters s1s2 ... S|s| (1 ≤|s| ≤10^5)-string s. The string only consists of UPPERCASE ENGLISH
letters.

Output
In the first line, print integer k (0≤k≤|s|) - the number of prefixes that match a suffix of string s. Next print k lines, in each line print two
integers li Ci. Numbers li Ci mean that the prefix of the length li matches the suffix of length li and occurs in string s as a substring ci times.
Print pairs li Ci in the order of INCREASING li.

Examples

input
ABACABA

output
14
3 2
71

input
AAA

output
3
L 3
22
3 1
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    string s;
    cin>>s;
    ll n=s.size();
    ll i,j;
    /*
    ta có nhận xét trên định nghĩa đề bài:
    với mỗi z đi, thì i+z[i]-1 phải =n để nó là suffix
    đi ngược từ dưới lên trên bởi từ dưới thì sẽ dễ dàng check cho kt hơn
    ở đây sẽ lưu luôn kt[z[i]]=true

    */
    //z-algorithm
    vector<ll> z(n+5,0);
    ll l=0,r=0;
    for (i=1;i<n;i++){
        if (i<=r){
            z[i]=min(z[i-l], r-i+1);
        }
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if (z[i]+i-1 >r){
            l=i;
            r=i+z[i]-1;
        }
    }
    vector<ll> cnt(n+5,0);//cnt=count
    vector<bool> kt(n+5,false);//kt= kiểm tra
    //việc dùng giá trị tiểu 0 hay 1 ko ảnh hưởng lắm vì dù gì z[0] luôn =0
    for (i=n-1;i>=1;i--){
        if(i+z[i]-1==n-1){
            kt[z[i]]=true; //xác nhận là 1 border
        }
        cnt[z[i]]++;
    }
    //giờ đến cộng dồn ngược, với mỗi kt[z[i]]!=0, tức là khả thi, thì ắt một thằng lớn hơn chứa nó sẽ hợp lệ cho vào ->+chính nó
    ll dem=0, dem1=0;
    //ở đây ta ko dùng chiếu z[i] vào kt mà là i là size, không bao giờ có size=n
    for (i=n-1;i>=1;i--){
        if(kt[i])
            dem1+=1;
        cnt[i]+=dem;
        dem=cnt[i];
        //<=>cnt[i]+=cnt[i+1]
    }
    /*
    phân tích dem=kt[i]
    kt[i] tức là có kt[i] xâu prefix độ dài i
    tại mỗi độ dài i đó, tồn tại những độ dài nhỏ hơn i
    mà độ dài nhỏ hơn đó biết đâu lại hợp lệ thì count lại +=1
    nhân lên với kt[i] lần thì đó chính là kt[i]
    ta sợ những thằng nhỏ hơn nữa không nhận được count của nó? không lo,
    vì mỗi khi đi xuống, là ta cộng thằng đã cộng rồi, tức có chứa thằng lớn nhất rồi
    vậy nên mỗi lần đi xuống là kết quả tích luỹ của những thằng trên
    ->Cộng dồn ngược

    nhưng có 1 lưu ý:
    giả sử có:
    z[i]=z[j]=x và i<j
    ắt hẳn không có:
    i+x==n nên j+x>n vì không có z[] nào + vị trí của nó >n
    -> chỉ  j+z[i]==n hợp lệ là border thì i cũng ăn sái

    Còn 1 twist:
    với những cái không phải là border, nhưng LỚN HƠN 1 BORDER
    thì PHẢI TÍNH THÊM vì z[] lớn đó có chứa border nhỏ
    */
    cout<<dem1+1<<"\n";
    for(i=0;i<n;i++){
        if(kt[i]){
            cout<<i<<" "<<cnt[i]+1<<"\n"; //kt[z[i]]+1 vì còn tính thêm prefix nữa, hoặc tạm hiểu là truyền trạng thái thêm của cả xâu vào nữa
        }
    }
    cout<<n<<" "<<1<<"\n";//cái cuối là toàn xâu


    /*
    for (i=0;i<n;i++)
        cout<<z[i]<<" ";
    cout<<endl;
    for (i=0;i<n;i++)
        cout<<s[i]<<" ";
    cout<<endl;
    for (i=0;i<n;i++)
        cout<<i<<" ";
    cout<<endl;
    */





    return 0;
}
