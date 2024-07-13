#include <bits/stdc++.h>
using namespace std;
struct hanghoa
{
    char mahang[10];
    char tenhanghoa[30];
    char tennsx[30];
    int year_product;
    //prototype funcion in class hanghoa
    friend istream& operator>>(istream &, hanghoa &);
    friend ostream& operator<<(ostream&, hanghoa );
};

struct Node
{
    hanghoa info;
    Node *next;
};
typedef Node* pointer;
// declare funcion in class hanghoa

istream& operator>>(istream &in, hanghoa &sanpham){
    cout<<"ma san pham: "; fflush(stdin); in.getline(sanpham.mahang,10);
    cout<<"ten san pham: "; fflush(stdin); in.getline(sanpham.tenhanghoa,30);
    cout<<"ten nha san xuat: "; fflush(stdin); in.getline(sanpham.tennsx,30);
    cout<<"nam san xuat: " ;in>>sanpham.year_product;
    return in;
}
ostream& operator<<(ostream &out, hanghoa sanpham){
    out<<left<<setw(10)<<sanpham.mahang
    <<left<<setw(30)<<sanpham.tenhanghoa
    <<left<<setw(30)<<sanpham.tennsx
    <<left<<setw(5)<<sanpham.year_product<<endl;
    return out;
}
//prototype funcion with class Node
pointer create(pointer &);
pointer create_node(hanghoa );
bool empty(pointer );
pointer add_list(pointer &);
pointer add_list(hanghoa sp, pointer&);
pointer insert_last(hanghoa , pointer &);
pointer insert_first(hanghoa , pointer &);
void print_list(pointer);
void insert_custom(const char mahang[10], pointer &);
hanghoa create_info(const char mahang[10],
   const char tenhanghoa[30],
    const char tennsx[30],
    const int year_product );
void print_Samsung(pointer);
//declare funcion
pointer create(pointer &first){
    first=NULL;
    return first;
}
pointer create_node(hanghoa sp){
    pointer temp=new Node;
    temp->info=sp;
    temp->next=NULL;
    return temp;
}
bool empty(pointer first){
    return first==NULL;
}
pointer add_list(pointer &first){
    start:
    cout<<"do you know add the produce(y/n): ";char check; cin>>check;
    if (check=='y')
    {
        hanghoa sp;
        cin>>sp;
        insert_last(sp, first);
        goto start;
    }
    return first;
}
pointer add_list(hanghoa sp, pointer &first)
{
    insert_last(sp, first);
    return first;
}
pointer insert_last(hanghoa sp, pointer &first)
{
    if (empty(first))
    {
        insert_first(sp, first);
        return first;
    }
    pointer temp=new Node;
    temp->info=sp;
    temp->next=NULL;
    pointer run=first;
    while (run->next!=NULL)
    {
        run=run->next;
    }
    run->next=temp;
    return first;
}
pointer insert_first(hanghoa sp, pointer &first){
    pointer temp=new Node;
    temp->info=sp;
    temp->next=NULL;
    if (empty(first))
    {
        first=temp;
        return first;
    }
    else{
    temp->next=first;
    first=temp;
    return first;
    }
    return first;
}
void print_list(pointer first)
{
    pointer temp=first;
    while (temp!=NULL)
    {
        cout<<temp->info;
        temp=temp->next;
    }
}
void insert_custom(const char mahang[10], pointer &first)
{
    pointer temp=first;
    if (strcmp(first->info.mahang,mahang)==0)
    {
        insert_first(create_info("sp***","hang moi","khong biet",10),first);
    }
    while (temp->next!=NULL)
    {
        if (strcmp(temp->next->info.mahang, mahang)==0 )
        {
           pointer tempnode=create_node(create_info("sp***","hang moi","khong biet",2023));
            tempnode->next=temp->next;
            temp->next=tempnode;
            return;
        }
        temp=temp->next;
    }
}
hanghoa create_info(const char mahang[10], const char tenhanghoa[30], const char tennsx[30], const int year_product)
{
    hanghoa temp;
    strcpy(temp.mahang,mahang);
    strcpy(temp.tenhanghoa,tenhanghoa);
    strcpy(temp.tennsx,tennsx);
    temp.year_product=year_product;
    return temp;
}
void print_Samsung(pointer first)
{
    pointer temp=first;
    while (temp!=NULL)
    {
        if (strcmp(temp->info.tennsx,"Samsung")==0)
        {
            cout<<temp->info;
        }
        temp=temp->next;
    }
    
}
int main()
{

    pointer list_produce=new Node;
    create(list_produce);
    check:
    if (empty(list_produce))
    {   
        cout<<"danh sach rong: \n";
        goto end;
    }
    else
    {
        cout<<"danh sach khac rong: \n";
        goto end;
    }
    goto check;
    end:
    add_list(create_info("sp001", "bim bim", "oishi",2023),list_produce);
    add_list(create_info("sp002", "ninja h2r", "kawasaki",2021),list_produce);
    add_list(create_info("sp003", "r1m", "yamaha",2019),list_produce);
    add_list(create_info("sp004", "bmw s1000rr", "bmw",2024),list_produce);
    insert_first(create_info("sp005","ducati legera","ducati",2015),list_produce);
    add_list(create_info("sp006","galaxy s23 ultra", "Samsung",2023),list_produce);
    add_list(create_info("sp007","galaxy foud", "Samsung",2024),list_produce);
    print_list(list_produce);
    cout<<"cac san pham cua sam sung:\n";
    print_Samsung(list_produce);
    cout<<"chen tuy chon: \n";
    insert_custom("sp003",list_produce);
    print_list(list_produce);
    return 0;
}
