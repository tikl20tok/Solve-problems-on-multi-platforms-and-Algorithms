#include<bits/stdc++.h>
using namespace std;
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

Kết quả trả về: BÁN KÍNH DÀI NHẤT mà là PALINDROME từ i

       i'          C           i
<------|-----------|-----------|------>
       <-----d----><-----d----->
ta có c = (i+i')/2 (trung bình cộng) => i' =2c-i

L'       i'        C         i         R
[--------|---------|---------|---------]
                             <-- R-i -->

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    

    return 0;
}