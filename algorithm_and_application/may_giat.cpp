#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

// Định nghĩa cấu trúc 'MayGiat' để lưu trữ thông tin của máy giặt
struct MayGiat {
    string id;
    std::string hangSanXuat;
    double khoiLuongGiat;
    double giaBan;
};
double sum_giaban()
vector<MayGiat> create(vector<MayGiat>& danhSachMayGiat){
  danhSachMayGiat.push_back({"001","Samsung", 7.5, 15});
  danhSachMayGiat.push_back({"002","LG", 8.0, 17.5});
  danhSachMayGiat.push_back({"003","Toshiba", 6.0, 120});
  danhSachMayGiat.push_back({"004","Electrolux", 7.0, 20});
  danhSachMayGiat.push_back({"005","Panasonic", 6.5, 14});
  danhSachMayGiat.push_back({"006","Hitachi", 8.5, 25});

  return danhSachMayGiat;
}
void print(const vector< MayGiat>& danhSachMayGiat){
    for (const auto& mayGiat : danhSachMayGiat) {
        std::cout
        <<left<<setw(5)<<mayGiat.id
        <<left<<setw(14)<<mayGiat.hangSanXuat
        <<left<<setw(5)<< mayGiat.khoiLuongGiat
        <<left<<setw(5)<< mayGiat.giaBan
        << std::endl;
    }
}
int main() {
    // Khởi tạo danh sách 7 máy giặt
  std::vector<MayGiat> danhSachMayGiat;
  danhSachMayGiat= create(danhSachMayGiat);
  print(danhSachMayGiat);
    // In thông tin của danh sách máy giặt

    return 0;
}

