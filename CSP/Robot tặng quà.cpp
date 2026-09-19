#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
mấu chốt sử dụng era, lấy spf
với mỗi spf[i], sẽ cho ta thừa số ng tố nhỏ nhất của nó
mỗi lần degrade xuống như vậy, với 1e6 thì tối đa 20 lần lặp, cái spf chính là 1 factor của nó
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);

    ll t,i,j;
    cin>>t;
    //sàng era biến tấu cho spf
    const ll MAX = 1e6;
    vector<ll> spf(MAX +5, 0);
    for (i = 2; i <= MAX; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (j = i * i; j <= MAX; j += i)
                if (spf[j] == 0)//chưa đi qua thì gán, thế này là có factor nhỏ nhất rồi
                    spf[j] = i;
            }
    }
    vector<ll> usnt(MAX +5, 0);//vừa check dùng chưa (used snt), vừa đếm tần suất; số ng tố tới 1e6 tầm 76688 j j đó, ko nhớ rõ
    vector<ll> touched;
    touched.reserve(80000);
    ll n, last;
    ll x;
while(t>0){
    t--;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        x=abs(x);
        /*
        phân tích ra ts nguyên tố, TỐI ĐA 20 LẦN LẶP, (vì 2^19.3333 ~= 1e6)
        NHƯNG chết người là có thể lặp tới 168 lần nếu dùng trivial division

        ->Dùng spf (smallest prime factor), tạo 1 lần rồi dùng luôn, theo dạng degrade (tự tìm hiểu thêm), cùng lắm lặp 20 lần, ko bị qua số nguyên tố nữa
        */
        if(spf[x] == x){
            if (usnt[spf[x]]==0)//đừng quên nhét vào touched
                touched.push_back(spf[x]);
            usnt[x]++;
            continue;
        }
        //chỉ áp dụng với != snt
        j=x;
        last=j;
        while(j>1){//tương đương j!=spf[j] hay j ko phải là snt
            //spf đi xuống có kết quả theo thứ tự TĂNG DẦN, nên dùng temp để phân biệt, tránh đếm trùng
            if(spf[j]!=last){
                if (usnt[spf[j]]==0)
                    touched.push_back(spf[j]);
                usnt[spf[j]]++;
                last=spf[j];
            }
            j/=spf[j];
        }
        //handle trường hợp là snt
    }
    ll kq=0;//kết quả
    for(i=0;i<touched.size();i++){
        if(usnt[ touched[i] ] && touched[i] !=0){//nếu để số 0 ở đây, 0 sẽ bị đếm 2 lần nếu nó là thằng lớn nhất
            kq=max(kq, usnt[ touched[i] ]);
            if (touched[i])//khác 0 ms reset nhé, ko là sai kq giờ
                usnt[ touched[i] ] = 0;//ĐỪNG QUÊN RESET
        }
    }
    cout<<kq+usnt[0]<<'\n';
    usnt[0] = 0; //ĐỪNG QUÊN RESET 0, LOL
    touched.clear();//Dọn mảng CỰC NHANH
    /*
    lí do tại sao số 0 được tính: số 0 là bội của mọi số, nhưng việc dùng sàng chỉ áp dụng với những số >=2
    -> Ngoài những thằng được thì những đứa ở vị trí 0 LUÔN ĐƯỢC NHẬN
    Vì: Robot khởi điểm tại vị trí 0
    Còn số 1 ko được tính bởi d>1 tức ko bao giờ đi qua vị trí 1
    */
}




    return 0;
}
/*
Lời bình:
Bài này khiến t mất 2 tiếng hơn  xíu
Chết người ko chỉ nằm ở thuật toán, mà còn nằm ở cách quản lí bộ nhớ VÀ VÒNG LẶP
Vòng lặp khiến TLE cực mạnh, phải thêm nhiều cái tối ưu cho nó
thuật toán ra đc 15p, còn debug cho TLE THÌ NHƯ COCK
*/