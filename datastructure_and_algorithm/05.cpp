#include <bits/stdc++.h>
using namespace std;
#define max 20
struct  monhoc
{
    char mmh[10];
    char ten[30];
    int sodonvihoc;
    float diem;
};
struct listsb
{
    monhoc E[max];
    int count;
};
listsb L;
void create(listsb &L){
    L.count =-1;
}
void nhap(monhoc &temp){
    cout<<"ten mon hoc: "; fflush(stdin); cin.getline(temp.ten,30);
    cout<<"so don vi hoc: "; cin>>temp.sodonvihoc;
}
void xuat(monhoc temp){
    cout
    <<left<<setw(30)<<temp.ten <<"\t"
    <<left<<setw(10)<< temp.sodonvihoc<<"\t"
    <<endl;
}
void nhap(listsb &L){
	for (int i=0; i<5; i++){
		L.count =i;
		nhap(L.E[L.count]);
	}
}
void xuat(listsb L){
    cout<<L.count<<endl;
    for (int i = 0; i < L.count+1; i++)
    {
        xuat(L.E[i]);
    }
}
int main(){
listsb L;
create(L);
nhap(L);
xuat(L);
cout<<sqrt(2);
return 0;
}