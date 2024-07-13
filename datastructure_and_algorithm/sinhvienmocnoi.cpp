#include <bits/stdc++.h>
using namespace std;
struct sinhvien
{
    char msv[7];
    char ten[30];
    float diem;
    friend istream& operator>>(istream &in, sinhvien &sv){
        cout<<"ma sinh vien: "; fflush(stdin); in.getline(sv.msv, 7);
        cout<<"ten: "; fflush(stdin); in.getline(sv.ten, 30);
        cout<<"diem: "; in>>diem;
        return in;
    }
    friend ostream& operator<<(ostream &out, sinhvien sv){
        out<<left<<setw(9)<<sv.msv
        <<left<<setw(40)<<sv.ten
        <<left<<setw(5)<<sv.diem<<endl;
        return out;
    }
};
struct node 
{
    sinhvien sv;
    node *next;
};
typedef node* ptr;
ptr L;
void nhap_list(ptr &L){
    ptr p, q;
    char check;
    sinhvien sv;
    do
    {
        cin>>sv;
        p->sv=sv;
        p->next=NULL;
        if (L==NULL)
        {
            L=p;
        }
        else q->next=p;
        q=p;
    } while (toupper(check)=="Y");
    
}
int main(){

return 0;
}