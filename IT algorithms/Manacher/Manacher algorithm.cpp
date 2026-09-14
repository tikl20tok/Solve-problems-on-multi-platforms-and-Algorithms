#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
cơ bản thì đã học qua z-algorithm rồi thì cái manacher này cũng easy
cả 2 đều từ n^2 giảm về on theo trick tái sử dụng kết quả
để tái sử dụng, manacher cũng dùng 1 "windows" như z
nói đúng hơn là constraint, ko hoàn toàn là windows như z
và khi có được rồi thì cố mở rộng ra
=> Manacher = Z-algorithm_Palindrome version

nếu l r là start & end thì manacher có:
C (center) là tâm, R là end thôi
Đầu tiên là làm sao để có 1 index làm tâm, tức là palindrome luôn LẺ
-> Chèn kí tự đặc biệt giữa 2 kí tự, ví như "#"

Kết quả trả về: ĐỘ DÀI DÀI NHẤT LÀ PALINDROME (chú thích thêm ở phía cuối)
**Lưu ý: KHÔNG phải SIZE, mà BÁN KÍNH, tức i+p[i] sẽ đến điểm cuối của palindrome**
->đặt r=i+p[i] => p[i]=r-i, ko phải là r-i+1 là lưu SIZE
Bán kính ko được định nghĩa là size nên:
Bán kính = r-i;
SIZE = r-i +1;

C đang là tâm dài nhất, R là giới hạn của tâm dài nhất

ta biết có i, thì qua tâm C thì i'->C == C->i mà với giới hạn R
thì
       i'          C           i
<------|-----------|-----------|------>
       <-----d----><-----d----->
ta có c = (i+i')/2 (trung bình cộng) => i' = 2c-i

1 ví dụ nhỏ nếu 2 cái trong min = nhau
L        i'        C         i         R
[--------|---------|---------|---------]
<- R-i ->                    <-- R-i -->
   p[i']                        p[i]
p[i] = min(r-i, p[2c-i])
giải thích đoạn này PHỨC TẠP HƠN XÍU z-algorithm

ta đã có mirror (phản chiếu) của i, mà i' là tâm, thì i cũng là tâm, đồng nghĩa p[i] <=> p[i'] (chưa = hoàn toàn vì còn giới hạn R)
giờ: gần như giống hết z-algorithm
mirror = 2c-i
p[mirror] < r-i
có nghĩa là đoạn match nhỏ hơn r-i, vượt qua là chưa được khám phá
-> chọn p[mirror] cho an toàn

p[mirror] >= r-i
nghĩa là đoạn match lớn hơn r-i, đồng nghĩa:
- r-i ở bên trong -> nằm trong đoạn match
- đoạn qua r chưa được khám phá
=> chọn r-i cho an toàn

*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP", "r", stdin);
    freopen("TESTING.OUT", "w", stdout);

    string s = "abababa";
    //cin>>s;
    ll i,j;
    string ts="$#";//temporary string
    ts.reserve(2*s.size()+5);
    vector<ll> p(2*s.size()+5, 0);
    //manacher algorithm
    //chèn kí tự đặc biệt vào
    for(i=0;i<s.size();i++){
        ts+=s[i];
        ts+="#";
    }
    ts+="%";//chèn thêm kí tự ở cuối và đầu để tránh tràn chỉ số
    /*
    ý nghĩa của kí tự đặc biệt ở cuối và đầu:
    - giảm phức tạp quản lí con trỏ vì:
    chạy đến đó, kí tự đặc biệt khác hẳn nhau, while tự dừng

    */
    ll c=0, r=0;
    for(i=1; i<ts.size(); i++){
        if(i < r){
            p[i] = min(r-i, p[2*c - i]);
        }
        //mở rộng vùng, ko cần kiểm soát index, chỉ cần check match hay không
        while(ts[i + p[i] + 1] == ts[i - p[i] - 1]){
            p[i]++;
        }
        if(i+p[i] > r){
            c = i;
            r = i+p[i];
        }
    }

    for(i=0; i<p.size(); i++){
        cout<<p[i]<<" ";
    }
    /*
    lưu ý nho nhỏ:
    hiện tại bán kính vẫn tính kí tự đặc biệt, nên khi trích xem số thực cho nửa phần thì
    trừ đi "#" (hoặc kí tự đặc biệt), đúng ra là /2 luôn p[i] rồi +1 (cho kí tự tại i) là ra SIZE 

    NHƯNG
    chính p[i] là đại diện luôn cho độ dài xâu Palindrome rồi, vì nó mở bán kính
    khi có chèn kí tự đặc biệt, nó mở sang phía phải thôi
    mà chèn rồi tức *2, đúng = xâu gốc

    nếu muốn biết độ dài half thì:
  |-p[i]/2, ở đây, p[i]:
  |  
  ->Chẵn thì -> lẻ hoặc chẵn cho half
    Lẻ thì -> Chẵn

    start index = (i - p[i])/2 => ra index trên xâu GỐC, ko phải ts (Đã chèn)
    end index = :
    - chẵn: start + p[i] (2*half)
    - lẻ: start + p[i] - 1 
    => -1 đơn giản vì tâm được tính 2 lần
    => còn chẵn thì 2 cái riêng biệt, ko cùng tâm, nên ko cần trừ

    return 0;
}
