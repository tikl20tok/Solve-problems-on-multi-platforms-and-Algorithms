#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Về mặt bản chất, buildLPS là KMP trên chính nó (so sánh xâu bị shift 1 (1->cuối) đầu VỚI xâu gốc (0->cuối-1 do len)) NHƯNG max(len)<=m-1

/*
hiểu lps đơn giản: Tiền tố trùng hậu tố
có index i
từ 0->i, lấy từng đợt ra đc các tiền tố (prefix)
từ i->0, xâu vẫn lấy thứ tự từ trái sang phải (suffix)
ví dụ: abcdefg, i=4 = e
-> pre: a; ab; abc; abcd
-> suf: e; de; cde; bcde
**size luôn <=4 (chỉ lấy đến i-3/1), cấm lấy toàn bộ bởi lấy toàn bộ là pre=suf, conflict

yêu cầu kiên quyết: pre phải luôn bắt đầu từ 0, suf luôn phải bắt đầu từ cuối (nhưng lấy xâu theo thứ tự trái sang phải, ngược lại)

khi so sánh ví dụ: abab -> i=3 ->  pre: có aba, suf: có aba -> len =3;
nhìn chung là truyền trạng thái của thằng lớn nhất, thay vì mỗi khi dịch i, ta phải trích và so sánh lại từ đầu
*/
//Cách 1: Đúng cách, NHƯNG KHÓ HIỂU VCL
vector<int> buildLPS(string P) {
    int m = P.length();
    vector<int> lps(m, 0);
    int len = 0; // Độ dài tiền tố trùng hậu tố hiện tại
    int i = 1;   // Con trỏ duyệt qua xâu từ vị trí 1

    /*
    Lưu ý:
    tại mỗi i (index), lps[i] là lượng max lượng kí tự match NẾU TÍNH CẢ P[i]
    -> Ta không nên nhìn thuật toán theo vòng while mà NÊN NHÌN THEO i (index) vì while có thể >i để đưa len về giá trị thích hợp nhất
    */
    while (i < m) {//chính là i<=m-1 (ĐÃ HẾT XÂU)
        if (P[i] == P[len]) {
            len++;//lượng kí tự match (max)
            lps[i] = len;//max lượng kí tự match tại đoạn đó
            i++;//tăng index, đi tiếp tìm kí tự khớp
        } else {
            if (len != 0) {
                // Nhảy lùi len thông minh để tìm giá trị khớp với phía trước
                len = lps[len - 1];//rối não nhất
                //ko tăng i để len về giá trị len thích hợp nhất nếu tính cả kí tự P[i]
            } else {
                lps[i] = 0;//nếu len = 0 rồi thì đành chấp nhận chuỗi đã đứt -> kí tự match max là 0
                //ta thấy trong ví dụ dưới khi P[i]=c, len được đưa về giá trị hợp nhất là 0 (QUA 2 VÒNG WHILE), tức đã đứt chuỗi nên lps[i]=0
                i++;//tăng index, đi tiếp tìm kí tự khớp
            }
        }
    }
    return lps;
}
/*
rối não nhất:
A. Sơ bộ
LPS = Longest Prefix which is also Suffix
giả sử lps[k]=V
-> xâu T[0....V-1] = T[k-V+1...k]

Ta hiểu đơn giản len là tổng kí tự đang khớp song vị trí của kí tự đang khớp là len-1 (trong xâu gốc)
Nếu len tăng, tức trong xâu có đoạn xâu con giống nhau -> về mặt bản chất là shift, đẩy index đầu lên, giữ len là lượng kí

B. tại sao len = lps[len - 1] ?

len đang là số lượng kí tự match, vậy index của kí tự đang match là len-1 (kiểu như string.length()/.size() -1 mới là index của kí tự cuối)

bài gốc: sao để đi lùi len -1 từ từ mà kiểm tra lại
chắc chắn ko thể chỉ kiểm tra match hay không khi nó đang lùi  -> dễ sai mà phải kiểm tra cả đoạn còn lại
-> tăng độ phức tạp nếu muốn đúng
vậy rút ngắn kiểu gì?

ta hỏi xuống TẠI INDEX len -1 có max bao kí tự khớp, đó là lí do gán len=lps[len-1]
ta rối vì hiện tại len đóng 2 vai trò:
1. Tổng kí tự đang khớp tại index i => Cái khiến ta lu mờ vì nó tương đương với <2.>
2. Là index của string cần match (0->cuối) => Đây là bản chất của xoắn não và là MỤC ĐÍCH CHÍNH,
=> tại sao lps vốn dùng cho xâu shift lại dùng cho xâu gốc?
Về mặt bản chất, lps dùng cho cả 2, chỉ là thao tác khiến ta nhầm tưởng lps chỉ dùng cho xâu gốc
len = lps[len-1] có thể thao tác nhiều lần để tìm vị trí đúng
-> mỗi lần chỉ là giảm nấc để kiểm tra xem nấc nào phù hợp
Nếu có nhiều cái giống nhau, ta có nhiều xâu shift, len-1 chỉ là degrade từng nấc trên xâu đã shift mà vẫn đối xứng được với xâu gốc <mô phỏng> (vì xâu shift mà giống thì đương nhiên đối xứng đc với xâu gốc)
ta nhận thấy giống quy hoạch động truyền trạng thái

C. Ngắn gọn:
MỤC ĐÍCH CHÍNH & BẢN CHẤT CỦA KMP / LPS:

1. 'len' đóng hai vai trò song song:
   - Độ dài đoạn đã match (Số lượng)
   - Index của ký tự kế tiếp trên xâu gốc cần so sánh (Index = len)
   - Vị trí ký tự cuối cùng của đoạn match trên xâu gốc là (len - 1)

2. Phép gán len = lps[len - 1]:
   - Về bản chất là QUY HOẠCH ĐỘNG TRUYỀN TRẠNG THÁI (Failure Function).
   - Mỗi lần gán chỉ là "degrade" (hạ) từng nấc trạng thái trên xâu đã shift.
   - Do tính chất đối xứng, xâu shift vừa khớp HOÀN TOÀN GIỐNG xâu gốc đoạn [0..len-1],
     nên mảng lps dùng chung cho cả 2 mà không hề làm mất tính chính xác.
   - Vòng lặp while đóng vai trò hạ nấc liên tục cho đến khi tìm được trạng thái mắc
     hoặc chạm đáy (len = 0).

HOẶC 

Không cần cố hiểu len=lps[len-1] làm gì
Hiểu đơn giản nó là tìm độ dài lớn nhất match mà chứa kí tự tại index i hiện tại
*/


//Cách 2: Viết theo quy hoặc động, tại i nào, giải quyết dứt điểm
/*
bản thân thằng này cũng như vòng while, được cái code ngắn và nhìn mạch lạc, rõ ràng hơn
ở đây nhìn rõ hơn về function của lps[j-1], so sánh với tiền tố (xâu gốc) thì
nó liên tục thử bỏ đoạn hợp lí ở dưới: ví dụ:
abcde, đang có e, bỏ đoạn abc đi chả hạn còn de, bỏ liên tục đến khi tìm được cái hợp nhất
Nó cắt được như vậy vì ta hiểu đơn giản với mỗi value của lps[], tức có 1 xâu con ngần ấy kí tự match
Để hiểu rõ hơn và 1 ứng dụng để nhìn ra bản chất của j(len) = lps[j(len) - 1] thì "Finding Borders"

Ta có mỗi lần so sánh tiền tố và hậu tố, để biết bằng nhau hay gì đó ắt phải CÙNG ĐỘ DÀI
ở qhđ này, j có vai trò như len ở trên kia
     0 1 2 3 4 5 6
xâu: a b a b a b c
tại i=1
pre: a; suf: b ->false j=0
i=2
pre: ab; suf: ba -> false j=0
i=3
pre: aba; suf: bab
Qua đây ta có nhận xét i liên tục tượng trưng cho KÍ TỰ CUỐI CÙNG của 1 suf
Còn j = lps[i-1] -> Trạng thái trước có bao kí tự match, cụ thể ta đang lấy index+1 ở xâu gốc để so sánh tiếp, cái này tượng trưng luôn cho kí tự tiếp theo của pre trước đó
Vậy là xong, hết, còn j=lps[j-1] thì hiểu là:
Nhảy xuống TỪNG XÂU CON SUF ĐÃ MATCH mà CÓ CHỨA KÍ TỰ i HIỆN TẠI có khả năng (Nếu lps[] lớn hơn 0 và đã build xong)
Còn trong vòng lặp nó có ý nghĩa tương tự nhưng do nếu missmatch thì chuyển CÓ CHỨA KÍ TỰ i-1 để cắt xuống thằng nào phù hợp
Cắt dựa trên nguyên lí trùng trong xâu: Từ cuối xâu đi, sẽ có thằng nào trùng với thằng ké nó, lấy lượng nhỏ nhất bỏ đi rồi thử lại
ví dụ: 
ababababab, có 5 cụm ab, ta chỉ bỏ 1 cụm "ab" thành ababab (3ab), nếu bỏ 1 cụm "abab" thì sẽ gây giảm đi lượng trùng mà vẫn giống nhau
ta giảm liên tục như thế đến khi nào mà cụm trung đó biến mất để lộ ra kí tự mới (có thể trùng i-1 hoặc khác i-1) để ta so sánh với s[i]

Hiểu được DP này rồi ta dễ dàng hiểu đc KMP()
Ví dụ thực tế: "Finding Borders"

string s = "abababc"
0 1 2 3 4 5 6
a b a b a b c
i: 1 j(len): 0 lps[1]: 0
i: 2 j(len): 1 lps[2]: 1
i: 3 j(len): 2 lps[3]: 2 đây 2 = "ab"
i: 4 j(len): 3 lps[4]: 3 đây 3 = "aba"
i: 5 j(len): 4 lps[5]: 4 đây 4 = "abab"
i: 6 j(len): 2 lps[6]: 0 j = lps[4-1=3] = 2
i: 6 j(len): 0 lps[6]: 0
Đấy, ta thấy chỉ có "abab" trùng, cắt 1 "ab" đi, thật ra ta có thể mạnh tay cắt "abab" nhưng làm thế sẽ phá vỡ quy ước chung (ở trên)
, loại bỏ hết trùng sẽ RA 1 KÍ KHÁC để xem khả thi ko nếu nối vào c HOẶC KO RA J -> ĐỨT CHUỖI
Vậy ta đã chứng minh được định nghĩa được viết trên kia là ĐÚNG
*/
vector<int> buildLPS2(string s){
    long long n = s.size();
    vector<int> lps(n,0);
    long long tg=-1;
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];
            /*cout<<"i: "<<i<<" j(len): "<<j<<" lps["<<i<<"]: "<<lps[i]<<endl;
            tg = j;*/
        }
        if (s[i] == s[j]) {
            j++;
        }
        lps[i] = j;
        /*if (tg!=j)
            cout<<"i: "<<i<<" j(len): "<<j<<" lps["<<i<<"]: "<<lps[i]<<endl;*/
    }
    return lps;
}    

//Sau khi KMP trên chính nó, KMP với xâu cần so sánh
bool KMP(string P, string T) { // P là xâu LỚN, T là xâu NHỎ cần kiểm tra
    vector<int> lps = buildLPS(T); // 1. BẢNG CHỈ DẪN PHẢI DỰNG TRÊN XÂU NHỎ T

    //n là độ dài xâu LỚN P, m là xâu nhỏ
    int n = P.length();
    int m = T.length();

    int i = 0; // i duyệt trên xâu LỚN P (chỉ tiến, 0 -> n-1)
    int j = 0; // j duyệt trên xâu NHỎ T (nhảy lùi bằng lps, 0 -> m) ko phải m-1 vì j CÒN ĐÓNG VAI TRÒ LÀ SỐ KÍ TỰ ĐÃ KHỚP, ko chỉ index

    //Trong bài toán này, nếu như bị lệch thì j sẽ bị giảm, CHỈ CẦN J=M thôi là kết quả đúng
    while (i < n) { // Duyệt hết xâu LỚN P
        if (P[i] == T[j]) { // So sánh ký tự P[i] của xâu lớn với T[j] của xâu nhỏ
            i++;
            j++;
            if (j == m) { //Đủ r, true thôi
                return true;
            }
        }
        else
        { // Bị lệch
            if (j != 0) {
                j = lps[j - 1]; // Lùi j trên sổ tay lps của T
            } else {
                i++; // j = 0 rồi thì tiến i trên xâu lớn P
            }
        }
    }
    return false; // Chạy hết xâu P mà j chưa bao giờ chạm m -> Không có T trong P
}
/*
Nhận thấy KMP và buildLPS có cấu trúc khá giống nhau, chỉ khác:
KMP điều khiển con trỏ, ko phải build nên chỉ thêm check và bỏ thay đổi lps
buildLPS thì thêm thay đổi lps (ở nhánh else len/j!=0)
*/

int main() {
    string P = "abababc";
    string T = "ababc";
    vector<int> lps = buildLPS(T);
    cout<<"LARGE STRING: "<<P<<endl;
    cout<<"SMALL STRING: "<<T<<endl;
    cout<<"LPS of small string: ";
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " ";
    }

    if (KMP(P, T)) {
        cout << "\nYes";
    }
    else {
        cout << "\nNo";
    }

    return 0;
}


/*
buildLPS:
P="abababc"
workflow: (sau i++)
i: 1 j(len): 0 lps[1]: 0
i: 2 j(len): 1 lps[2]: 1
i: 3 j(len): 2 lps[3]: 2
i: 4 j(len): 3 lps[4]: 3
i: 5 j(len): 4 lps[5]: 4
i: 6 j(len): 2 lps[6]: 0
i: 6 j(len): 0 lps[6]: 0
*/

