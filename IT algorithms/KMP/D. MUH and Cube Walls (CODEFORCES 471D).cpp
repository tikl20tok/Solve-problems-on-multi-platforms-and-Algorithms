#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;

//link: https://codeforces.com/problemset/problem/471/D
/*
Polar bears Menshykov and Uslada from the zoo of St. Petersburg and elephant Horace from the zoo of Kiev got hold of lots of wooden
cubes somewhere. They started making cube towers by placing the cubes one on top of the other. They defined multiple towers standing in
a line as a wall. A wall can consist of towers of different heights.

Horace was the first to finish making his wall. He called his wall an elephant. The wall consists of w towers. The bears also finished making
their wall but they didn't give it a name. Their wall consists of n towers. Horace looked at the bears' tower and wondered: in how many parts
of the wall can he "see an elephant"? He can "see an elephant" on a segment of w contiguous towers if the heights of the towers on the
segment match as a sequence the heights of the towers in Horace's wall. In order to see as many elephants as possible, Horace can raise
and lower his wall. He even can lower the wall below the ground level (see the pictures to the samples for clarification).

Your task is to count the number of segments where Horace can "see an elephant".

Input
The first line contains two integers n and w (1 <n, w ≤2.10>)-the number of towers in the bears' and the elephant's walls
correspondingly. The second line contains n integers ai (1 ≤ai ≤109)-the heights of the towers in the bears' wall. The third line contains
w integers bi (1 ≤bi≤ 109)-the heights of the towers in the elephant's wall.

Output
Print the number of segments in the bears' wall where Horace can "see an elephant".

Examples

input
13 5
2 4 5 5 4 3 2 2 2 3 3 2 1
3 4 4 3 2

output
2

Note
The picture to the left shows Horace's wall from the sample, the picture to the right shows the bears' wall. The segments where Horace can
"see an elephant" are in gray.

See the image: D. MUH and Cube Walls (CODEFORCES 471D) Illustration.png
*/




/*
Tóm gọn đề bài:
Có mảng A (tường của 2 gấu) và mảng B (của Horace)
A gồm n phần tử
B gồm w phần tử

Hỏi ĐOẠN B xuất hiện trong A bao nhiêu lần, có thể nâng/chỉnh TOÀN BỘ bức tường w tuỳ ý.
*Lưu ý là ĐOẠN, không phải số phần tử*
*Chỉnh là phải CHỈNH CẢ B theo 1 số*
*/
/*
Giải thích qua ví dụ
13 5
2 4 5 5 4 3 2 2 2 3 3 2 1
3 4 4 3 2 -> 1 0 -1 -1
  0 1 2 3 4 (+1)0 1 2 3 4(-1)
*/
/*
Ta nhận cũng chỉ có 1 bức tường
Horace đang muốn có bao đoạn CÓ THỂ nhìn thấy tường, tức ko phải nhân bản tường ra
Nhận xét: tạo mảng hiệu (diff arr), xét hiệu i+1 với i
Làm như vậy cho cả 2 mảng
Sau đó dùng kmp vào so sánh như bài check if string B in A là xong
Border case ở dưới giải rồi
ở đây có 1 nhận xét nữa:
    index đầu luôn là 0
    nhưng khi đi lên, chưa chắc số 0 định nghĩa cho cái đầu tiên
    Mà ta đang xét theo diff -> chỉ cần lps[i]=w-1
    Bên cạnh đó bỏ xét kí tự đầu tiên luôn
    Nếu còn tồn tại số 0 ở đó, so sánh sẽ không bao giờ ra

Cách dưới là quản lí idx khá phức tạp để đỡ tăng bộ nhớ+tối ưu thời gian và typing, dù có thể tối ưu hơn một chút nhưng cài đặt dài, lằng nhằng
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll n,w;
    cin>>n>>w;
    vector<ll> a(n+5,0), b(w+5,0);
    ll i,j;
    for (i=0;i<n;i++){
        cin>>a[i];
    }
    for (i=0;i<w;i++){
        cin>>b[i];
    }
    if (w==1){//nếu bằng 1 thì kiểu gì nâng hạ cũng giống được nhau, đáp án luôn là n
        cout<<n;
        return 0;
    }
    if (n<w){//tường lớn hơn hẳn thì nhìn qua kiểu đ j
        cout<<0;
        return 0;
    }
    vector<ll> hieu(n+5+w,0);//hiệu
    
    for (i=1;i<w;i++){//tổng w-1 phần tử, index hieu kết thúc tại w-2
        hieu[i-1]=b[i]-b[i-1];
    }
    //-> tại w-1 là outlier:
    hieu[w-1]=1000000000000;//số này không bao giờ có trong input đề bài; có vai trò là phân cách 2 mảng
    //->bắt đầu tại w
    for (i=w;i<=w+(n-1)-1;i++){//tổng n-1 phần tử, index hieu kết thúc tại w+(n-1)-1
        hieu[i]= a[i-w+1]-a[i-w];
    }

    //lps
    vector<ll> lps(hieu.size(),0);
    for (i=1;i<=w+(n-1)-1;i++){
        j=lps[i-1];
        while (j>0&&hieu[j]!=hieu[i]){
            j=lps[j-1];
        }
        if (hieu[j]==hieu[i])
            j++;
        lps[i]=j;
    }
    
    ll dem=0;
    for (i=w;i<=w+(n-1)-1;i++){//tổng n-1 phần tử, index hieu kết thúc tại w+(n-1)-1
        if (lps[i]==w-1)
            dem++;
    }
    /*
    for (i=0;i<=w+(n-1)-1;i++)
        cout<<hieu[i]<<" ";
    cout<<endl;
    for (i=0;i<=w+(n-1)-1;i++)
        cout<<lps[i]<<" ";
    cout<<endl;
    */
    cout<<dem;

    return 0;
}
