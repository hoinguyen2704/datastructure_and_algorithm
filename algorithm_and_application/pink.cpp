#include<bits/stdc++.h>

using namespace std;

struct LoHoa
{
    string loaiHoa;
    int soLuong;
    string mauSac;
};

void hienThi(LoHoa a[], int n)
{
    cout << "---------------------Danh sach lo hoa------------------------" << endl;
    cout << setw(20) << left << "Loai hoa";
    cout << setw(20) << left << "So luong hoa";
    cout << setw(20) << left << "Mau sac" << endl;
    for(int i = 1; i <= n; i++) {
        cout << setw(20) << left << a[i].loaiHoa;
        cout << setw(20) << left << a[i].soLuong;
        cout << setw(20) << left << a[i].mauSac << endl;
    }
}

int tongSoLuongHoa(LoHoa a[], int n)
{
    int tong = a[n].soLuong;
    if(n == 1)
        return a[n].soLuong;
    else {
        tong += tongSoLuongHoa(a,n-1);
    }
    return tong;
}

int tongHoaTheoMau(LoHoa a[], int n, string mau, int l, int r)
{
    int tong = 0;
    if(l == r) {
        if(a[l].mauSac == mau)
            return a[l].soLuong;
    }
    else {
        int m = (l + r) / 2;
        tong += tongHoaTheoMau(a,n,mau,l,m) + tongHoaTheoMau(a,n,mau,m+1,r);
    }
    return tong;
}

void kTaoCauHinh(int index[], int k)
{
   for(int i = 1; i <= k; i++) {
       index[i] = i;
   }
}

void sinhCauHinh(int index[], int k, int n, int &done)
{
   int i = k;
   while(i >= 1 && index[i] == n - k + i) {
       --i;
   }
   if(i == 0) {
       done = 0;
   }
   else {
       index[i]++;
       for(int j = i + 1; j <= k; j++)
           index[j] = index[j-1] + 1;
   }
}

void hienThiCauHinh(LoHoa a[], int index[], int k, int done, int n)
{
   while(done) {
       for(int i = 1; i <= k; i++) {
           cout << a[index[i]].loaiHoa << " " << a[index[i]].mauSac << " || ";
       }
       cout << endl;
       sinhCauHinh(index,k,n,done);
   }
}

void Try(LoHoa a[], int index[], int n, int k, int i)
{
    for(int j = index[i - 1] + 1; j <= n - k + i; j++) {
        index[i] = j;
        if(i == k) {
            for(int i = 1; i <= k; i++)
                cout << a[index[i]].loaiHoa << " " << a[index[i]].mauSac << "||";
            cout << endl;
        }
        else Try(a,index,n,k,i+1);
    }
}

int main()
{
    int n = 7;
    LoHoa a[10];
    a[1] = {"Hoa mai", 10, "vang"};
    a[2] = {"Hoa dao", 11, "hong"};
    a[3] = {"Hoa hong", 7, "do"};
    a[4] = {"Hoa ly", 10, "trang"};
    a[5] = {"Hoa hong", 5, "trang"};
    a[6] = {"Hoa cuc", 9, "vang"};
    a[7] = {"Hoa mai", 6, "trang"};
    hienThi(a,n);
    cout << "Tong so luong hoa: " << tongSoLuongHoa(a,n) << endl;
    string mau = "vang";
    cout << "Tong so hoa co mau " << mau << " la: " << tongHoaTheoMau(a,n,mau,1,n) << endl;
    int k = 5;
    int index[10];
    index[0] = 0;
//    int done = 1;
//    kTaoCauHinh(index, k);
//    hienThiCauHinh(a, index, k, done, n);
    Try(a,index,n,k,1);
}
