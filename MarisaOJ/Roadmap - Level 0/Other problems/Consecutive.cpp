#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll prefixsum[1500000+5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    /*
    giả sử tồn tại 1 đoạn liên tiếp mà = n
    thì ta có:
    a + (a+1) + (a+2) + ... + (a+k-1) = n với k là số số hạng

    a + (a+1) + (a+2) + ... + (a+k-1)
    = k*a + [(k-1)*k]/2
    = [2*k*a + (k-1)*k]/2
    = k*(2*a + k - 1)/2 
    = n
    => 2*n = k*(2*a + k - 1)
    2a-1 luôn lẻ
    k lẻ thì (2*a + k -1) chẵn
    k chắn thì (2*a + k -1) lẻ
    -> 1 lẻ 1 chẵn
    mà là số nguyên
    -> k và (2*a + k -1) là ước của 2n, quan trong là đảm bảo được 1 chắn 1 lẻ 
    và a nguyên
    => a=[ 2n/k +1 -k ]/2
    mà, giả 2n/k nếu k = i thì 2n/k = ucln
    -> a=[ucln +1 -i]/2
    mà ucln hay i 1 lẻ 1 chẵn => C/M đc luôn chẵn
    => a nguyên trong mọi trường hợp xác định (1 lẻ 1 chẵn ước)
    xong bài
    */
    ll n,i,j;
    ll dem=0;
    cin>>n;
    ll ucl;//ước còn lại
    for(i=2;i*i<2*n;i++){//phải từ 2 đến dưới 2*n bởi ít nhất 2 thằng cộng lại
        if(2*n % i == 0){
            ucl=2*n /i;
            if((ucl%2==0 && i%2!=0) || (i%2==0 && ucl%2!=0)){
                dem++;
            }
        }
    }
    cout<<dem;
    return 0;
}
