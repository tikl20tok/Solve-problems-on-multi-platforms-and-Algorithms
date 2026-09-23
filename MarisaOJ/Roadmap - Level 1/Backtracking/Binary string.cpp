#include <bits/stdc++.h>
using namespace std;

int n;
string s;
/*
1 bài hc hay nx để hiểu rõ hơn về stack, workflow của đệ quy và cách cpu hoạt động
ở đây nhận thấy đang dùng chung biến s
Phản ứng đầu: ko đc vì sẽ bị loạn biến
NHƯNG THỰC TẾ:
Mỗi lần gặp 1 nhánh, c++ sẽ đi trải dài xuống nhánh đó và kết thúc rồi mới quay trở lại để thực hiện lệnh tiếp theo
chính bởi mỗi lần đi hết cây nên s chỉ dùng cho lúc đó
-> Ko đè biến của nhau giữa các workflow
*/
//FULL AC
void generate(int pos) {
    if (pos == n) {
        cout << s << '\n';
        return;
    }

    s[pos] = '0';
    generate(pos + 1);

    s[pos] = '1';
    generate(pos + 1);
}

int main() {
    cin >> n;

    s.resize(n);
    generate(0);


    return 0;
}
