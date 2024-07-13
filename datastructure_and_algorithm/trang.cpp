#include<bits/stdc++.h>
#include<iomanip>
#include<iostream>
using namespace std ;
#define Max 100
struct Sinhvien
{
    char  masv[10];
    char ten [17] ;
    float diem ;
};
struct List
{
    int cnt ;
    Sinhvien E[Max];
} ;
void Initialize ( List &L)
{
    L.cnt = -1 ;
}
void Nhapsv( Sinhvien &sv)
{
    cout << " Ma sv";
    fflush(stdin);
    cin.getline(sv.masv, 10);
    cout << "Ten ";
    fflush(stdin);
    cin.getline(sv.ten, 17);
    cout<<"Diem";
    cin >> sv.diem ;
}
void Nhapds( List &L)
{
    int n ;
    cout <<" nhap so sinh vien ";
    cin >> n;
    Initialize(L);
    Sinhvien x ;
    int i=0;
    while( n--)
    {
        i++;
        cout <<" Nhap sv thu " <<i<<endl;
        Nhapsv(x);
    }

}
void hienthids( List L)
{
    cout << setw(5) << "STT" ;
    cout << setw(10) << "Ma sv" ;
    cout << setw(10) << "Ten";
    cout << setw(10) << "Diem "<<endl ;
    for( int i=0; i<=L.cnt; i++)
    {
        cout << setw(5) << (i+1); ;
        cout << setw(10) << L.E[i].masv ;
        cout << setw(10) << L.E[i].ten;
        cout << setw(10) << L.E[i].diem<<endl ;
    }
}
//Chen 1 sv vao vi tri k
void Insert( List &L)
{
    int i,k ;
    cout <<" Nhap k ";
    cin >> k;
    Sinhvien(x);
    if( k<=L.cnt)
    {
        cout << " Nhap tt sv can them ";
        Nhapsv(x);
        for( i= L.cnt ; i>=k; i--)
            L.E[i+1]= L.E[i];
        L.cnt++;
        L.E[k-1]= x;
    }
    cout <<" DS vua chen " ;
    hienthids(L);
}
//Xoa 1 sinhvien o vi tri k
void Del(List &L)
{
    int i, k;
    cout << " Nhap k";
    cin >> k;
    for( int i = k-1; i<=L.cnt; i++)
        L.E[i]=L.E[i+1];
    L.cnt -- ;
    cout <<" DS vua xoa " ;
    hienthids(L);
}
int main()
{
    List L;
    Nhapds(L);
    cout <<" DS vua nhap " ;
    hienthids(L);
//   Del(L);
//   Insert(L);
}