#include <bits/stdc++.h>
using namespace std;
struct thi_sinh
{
    char Sobd[10];
    char Hoten[30];
    float Tdiem;
};
struct node
{
    thi_sinh infor;
    node* next;
};
typedef node* ptr;
ptr L;
void create( ptr &L){
    L=nullptr;
}
void nhap(thi_sinh &TS){
    cout<<"so bao danh: "; fflush(stdin); cin.getline(TS.Sobd,10);
    cout<<"ten: "; fflush(stdin); cin.getline(TS.Hoten, 30);
    cout<<"diem: "; cin>>TS.Tdiem;
}
void xuat(thi_sinh TS){
    cout
    <<left<<setw(10)<<TS.Sobd<<"\t"
    <<left<<setw(30)<<TS.Hoten<<"\t"
    <<left<<setw(10)<<TS.Tdiem<<"\t"
    <<endl;
}
thi_sinh create(char sobd[], char ten[], float Tdiem){
    thi_sinh X;
    strcpy(X.Sobd,sobd);
    strcpy(X.Hoten,ten);
    X.Tdiem=Tdiem;
    return X;
}
void addlist(ptr &L, int n){
    ptr q=L;  
    start:
    if (n==0)
    {
        return;
    }
    thi_sinh TS;
    nhap(TS);
    ptr p=new node;
    p->infor=TS;
    p->next=NULL;
  
    if (L==NULL)
    {
        L=p;
    }
    else
    {
        q->next=p;
    }
    q=p;
    --n;
    goto start;
}
void xuat_sv00x(ptr L){
    while (L!=NULL)
    {
        if (strcmp( L->infor.Sobd,"sv003")==0)
        {
            xuat(L->infor);
        }
        L=L->next;
    }
    
}
void xoa_4(ptr L){
    for (int i = 1; i < 3 && L->next!=NULL; ++i)
    {
        L=L->next;
    }
    if (L->next==NULL)
    {
        cout<<"vi tri xoa khong hop le\n";
    }
    else
    {
    ptr T=L->next;
    L->next=L->next->next;
    delete T;        
    }
}
void insert_pre(ptr &L){
    thi_sinh TS;
    nhap(TS);
    ptr p=new node;
    p->infor=TS;
    p->next=NULL;
    if (strcmp(L->infor.Sobd,"sv011")==0)
    {
        p->next=L;
        L=p;
    }
    else
    {
        ptr q=L;
        while (q->next!=NULL && strcmp(q->next->infor.Sobd,"sv011")!=0)
        {
            q=q->next;
        }
        p->next=q->next;
        q->next=p;
    }
}
void xuat_max(ptr L){
    ptr q=L->next;
    float max = L->infor.Tdiem;
    cout<<endl;
    while (q!=NULL)
    {
        if (q->infor.Tdiem>max)
        {
            max=q->infor.Tdiem;
        }
        q=q->next;
    }
    while (L!=NULL)
    {
        if (L->infor.Tdiem==max)
        {
            xuat(L->infor);
        }
        L=L->next;
    }
}
void insert(ptr &L){
    int k;
    cout<<"k= ";cin>>k;
    ptr q=L;
    thi_sinh TS;
    nhap(TS);
    ptr p=new node;
    p->infor=TS;
    p->next=NULL;
    if(k==1)
	{
        p->next=L;
        L=p;
        return;
    }
    while (q->next!=NULL && k>2)
    {
        q=q->next;
        --k;
    }
    insert:
    p->next=q->next;
    q->next=p;
}
void xuatlist(ptr L){
    while (L!= NULL)
    {
        xuat(L->infor);
        L=L->next;
    }
}
int main(){
    
while (1)
{
cout
<<"\n"
<<"1: create \n"
<<"2:  add list\n"
<<"3: print list \n"
<<"4: xuat max \n"
<<"5: insert \n"
<<"6: print sv003 \n"
<<"7: xoa 4 \n"
<<"8: chen truoc sv004 \n"
<<endl;
    int k;
    cin>>k;
    if (k==1)
    {
        ptr L;
        create(L);
    }
    if (k==2)
    {
        addlist(L, 10);
    }
    if (k==3)
    {
        xuatlist(L);
    }
    if (k==4)
    {
        xuat_max(L);
    }
    if (k==5)
    {
        insert(L);
    }
    if (k==6)
    {
        xuat_sv00x(L);
    }
    if (k==7)
    {
        xoa_4(L);
    }
    if (k==8)
    {
        insert_pre(L);
    }
}
return 0;
}