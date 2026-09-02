#include<bits/std++.h>

/*
qua đây thì nhẹ nhàng hơn KMP nhiều rồi
z-algorithm có ý tưởng:
từ vị trí i đi lên, có bao kí tự của nó match đầu xâu
thông thường ae cứ dùng 2 vòng for là ra nhưng sẽ lên đến n^2 (ngây thơ)

vậy để giảm đpt về o(n) thì ta có:
Cửa sổ L;R cực mạnh làm constraint

vào trong code sẽ được giải thích từng phần
*/

using namespace std;

vector<int> buildZ(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {//vẫn là duyệt thô như thường
        //đây là twist
        if (i <= R) {
            z[i] = min(z[i - L], R - i + 1);
        }
        /*
        ta có cửa sổ l->r luôn đảm bảo sẽ giống 0 (l-l) -> r-l <index>
        gọi k=i-l
        ta có quyền bê nguyên z[k] vì xâu giống nhau thì mảng z cũng giống mà
        nhưng có 1 giới hạn: r
        nó chỉ đảm bảo đến hết r là match, chưa dám nói sau
        vậy:
        z[k] < r-i+1 <lượng kí tự>
        lúc này từ k->k+z[k]-1 = i->z[k]-1 luôn nằm trong cửa sổ r, đảm bảo đã match
        => lấy luôn z[k]
        nhưng
        z[k] >= r-i+1 <lượng kí tự>
        ta có k->k+z[k]-1 = i-> z[k]-1 > r-i+1 và đã match z[k] kí tự đầu
        ta khẳng định luôn, i->r nằm trong lượng kí tự đã match
        => lấy luôn r-i+1
        NHƯNG: ta không lấy z[k] vì z[k] mang tính đối chiếu với đầu xâu
        nó không có nghĩa là phù hợp được với đoạn xâu hiện tại nên cần
        giới hạn nó lại

        Vậy ta dùng phép min, lấy thằng nào nhỏ hơn: min(z[i - L], R - i + 1);
        */

        // Mở rộng bờ rào nếu còn trùng
        /*
        nhìn bên ngoài trong như 1 vòng for trong thuật toán n^2
        */
        //đảm bảo là index cuối cùng -1
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            //i+z[i]-1<n-1 <index> && s[size] = s[i+size] (i+size tượng trưng cho index HIỆN TẠI ĐANG CẦN CHECK)
            z[i]++;
        }

        // Cập nhật cửa sổ [L, R] mới
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string s = "abacababa";
    vector<int> z = buildZ(s);

    cout << "Index: ";
    for (int i = 0; i < s.length(); i++) cout << i << "\t";
    cout << "\nChar:  ";
    for (char c : s) cout << c << "\t";
    cout << "\nZ-arr: ";
    for (int val : z) cout << val << "\t";
    cout << "\n";

    return 0;
}
/*
để hiểu rõ hơn, ứng dụng + biến tấu -> đào sâu bản chất từng dòng code 1, dù thuật toán này nói gần như hết sạch ở trên r
thì xem ví dụ những bài
KMP và Z-algorithm trong đa số bài, gần như tất cả đều có thể thay thế cho nhau
Khác ở chỗ phải biến tấu phức tạp hơn hay không
*/