#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
struct hanghoa {
	char mahang[10];
	char ten[30];
	int soluong;
};
struct node {
	hanghoa infor;
	node* next;
};
typedef node* ptr;
ptr L;
//khoi tao danh sach rong
ptr creat(ptr &L) {
	L=nullptr;
	return L;
}
int empty(ptr L) {
	return L==nullptr;
}
hanghoa tao(const char mahang[10],const char ten[30], int soluong) {
	hanghoa temp;
	strcpy(temp.mahang, mahang);
	strcpy(temp.ten, ten);
	temp.soluong=soluong;
	return temp;
}

void add_last()
void create_list(ptr &L) {

}
void xuat(hanghoa sp) {
	cout
	        <<left<<setw(10)<<sp.mahang
	        <<left<<setw(30)<<sp.ten
	        <<left<<setw(5)<<sp.soluong
	        <<endl;
}

int main(int argc, char const *argv[]) {
	hanghoa sp1, sp2, sp3, sp4;
	sp1= tao("sp001","bim bim", 12);
	sp2= tao("sp002","kimochi", 14);
	sp3= tao("sp003","yamate", 16);
	sp4= tao("sp004","kjnjsncsd", 4);
	xuat(sp1);

	return 0;
}
