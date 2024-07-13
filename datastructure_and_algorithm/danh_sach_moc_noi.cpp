#include <bits/stdc++.h>
using namespace std;

struct sinhvien
{
    char hoten[35];
    char msv[9];
    float point;
    void nhap();
    void xuat();
};
struct listsv
{
    sinhvien sv;
    listsv* next;
};
typedef listsv* pointer;
int empty(pointer first){
    return first==NULL;
}
void create(pointer &first){
    first=NULL;
}
void insert_first(sinhvien x, pointer &first){
    pointer temp=new listsv;
    temp->sv=x;
    temp->next=NULL;
    if (first==NULL)
    {
        temp->next=first;
        first=temp;
    }
}
void insert_last(sinhvien x, pointer &first){
    pointer temp=new listsv;
    temp->sv=x;
    temp->next=NULL;
    if (first==NULL)
    {
        insert_first(x, first);
        cout<<"da chen vao dau: \n";
        return;
    }
    pointer q=first;
    while (q->next!=NULL)
    {
        q=q->next;
    }
    q->next=temp;
}
void sinhvien::nhap(){
    cout<<"msv: "; fflush(stdin); cin.getline(msv,9);
    cout<<"ho ten: ";fflush(stdin); cin.getline(hoten,35);
    cout<<"diem: ";cin>>point;    
}
void sinhvien:: xuat(){
    cout<<left<<setw(10)<<msv
    <<left<<setw(40)<<hoten
    <<left<<setw(4)<<point<<endl;
}
pointer nhaplist(pointer first){
    start:
    char check;
    cout<<"ban co muon nhap them vao du lieu vao khong(y/n): ";
    cin>>check;
    if (check=='y')
    {
        goto input;
    }
    else
    {
        goto end;
    }
    
    input:
    sinhvien x;
    x.nhap();
    insert_last(x,first);
    goto start;
    end:
    return first;
}
void xuat_list(pointer first){
    pointer q=first;
    cout<<"xuat danh sach:\n";
    while (q!=NULL)
    {
        q->sv.xuat();
        q=q->next;
    }
}
int main(){
    // int n; cin>>n;
    pointer first;
    create(first);
    
    // for (int i = 0; i < n; ++i)
    // {
    //     sinhvien x;
    //     x.nhap();
    //     insert_last(x,first);
    // }
    // nhaplist(first);
    first=nhaplist(first);
    cout<<"danh sach: \n";
    xuat_list(first);
    return 0;
}