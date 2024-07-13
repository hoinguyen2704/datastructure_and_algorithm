#include <bits/stdc++.h>
using namespace std;
struct hocphan
{
    char mhp[10];
    char tenhp[30];
    int sotinchi;
    friend istream& operator>>(istream &in, hocphan &hp){
        cout<<"ma hoc phan: "; fflush(stdin); in.getline(hp.mhp,10);
        cout<<"ten hoc phan: "; fflush(stdin); in.getline(hp.tenhp,30);
        cout<<"so tin chi: ";in>>hp.sotinchi;
        return in;
    }
    friend ostream& operator<<(ostream &out, hocphan hp){
        out
        <<left<<setw(10)<<hp.mhp
        <<left<<setw(30)<<hp.tenhp
        <<left<<setw(3)<<hp.sotinchi<<endl;
        return out;
    }
};
struct node
{
    hocphan hp;
    node *next;
};
typedef node* ptr;
ptr first;
ptr create(ptr &first){
    first=NULL;
    return first;
}
void add_list(ptr &first){
    hocphan x;
    ptr q=first;
    char check;
    do
    {
        cin>>x;  
        ptr p=new node;
        p->hp=x;
        if (first==NULL)
        {
            first=p; cout<<"chen vao dau:\n";
        }
        else
        {
            cout<<"chen vao sau:\n";
            q->next=p;
        }
        q=p;
        cout<<"do you want to die(Y/N): ";
        fflush(stdin); cin>>check;
    } while (toupper(check)=='Y');
}
void xuat_list(ptr first){
    ptr q=first;
    while (q!=NULL)
    {
        cout<<q->hp;
        q=q->next;
    }
    cout<<endl;
}
void insert3(ptr &first){
    hocphan x;
    cin>>x;
    ptr temp=new node;
    temp->next=NULL;
    temp->hp=x;
    ptr q=first;
    for (int i = 0; i < 3; i++)
    {
        /* code */
    }
    
}
int main(){
ptr L;
create(L);
add_list(L);
xuat_list(L);
system("pause");
return 0;
}
// hp001
// tan gai
// 4
// y
// hp002
// ctdl va gt
// 1
// y
// hp003
// oidoioi
// 5
// n