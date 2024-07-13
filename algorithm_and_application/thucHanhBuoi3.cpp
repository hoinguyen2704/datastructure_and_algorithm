#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <ctime>
//#include <bits/stdc++.h>
using namespace std;

const  char* lastName[]={
  "Nguyen Thi",
  "Tran Thi",
  "Ha Thao",
  "Nguyen Binh",
  "Tran Thanh",
  "Hoang Tieu",
  "Han Vu",
  "Tran Vu",
  "Hoang Quach"
  };
const  char* firstName[]={
    "Hong",
    "Linh",
    "Quan",
    "Thao",
    "Giang",
    "An",
    "Luu"
  };
const char* Gender[]={
    "MALE",
    "FEMALE",
    "OTHER"
  };
struct student
{
  char lastName[15];
  char firstName[15];
  char fullName[31];
  int yearofBirth;
  char address[31];
  char id[5];
  friend ostream& operator<<(ostream &out, student st){
    out
    <<left<<setw(6)<<st.id
    <<left<<setw(15)<<st.lastName
    <<left<<setw(15)<<st.firstName
    <<left<<setw(31)<<st.fullName
    <<left<<setw(5)<<st.yearofBirth
    <<endl;
    return out;
  }
};
void merge_sort(student *, int , int );
void merge(student *, int , int , int );
void create_list_student(student *st, int n){
 for (int i = 0; i < n; i++)
 {
  strcpy(st[i].id, to_string(i+1).c_str()  );
  strcpy(st[i].lastName, lastName[rand()%9]);
  strcpy(st[i].firstName, firstName[rand()%7]);
  strcat(strcat(strcpy(st[i].fullName,st[i].lastName), " "),st[i].firstName);
  st[i].yearofBirth= (rand()%21+(-10))+2000;
 }

}
void merge_sort(student *st, int l, int r){
  if(l<r){
    int m= l+ (r-l)/2;
    merge_sort(st, l, m);
    merge_sort(st, m+1, r);

    merge(st, l, m, r);
  }
}
void merge(student *st, int l, int m, int r){
  int n1= m-l+1;
  int n2= r-m;
  student L[n1], R[n2];
  for(int i=0; i<n1; i++){
    L[i]= st[i+l];
  }
  for(int i=0; i<n2; i++){
    R[i]= st[i+m+1];
  }
  int i=0, j=0, count=l;
  while(i<n1&& j<n2){
    if(strcmp(L[i].firstName, R[j].firstName)<=0){
      st[count]=L[i];
      i++;
    }
    else{
      st[count]=R[j];
      j++;
    }
    count++;
  }
  while(i<n1){
    st[count]= L[i];
    i++, count++;
  }
  while(j<n2){
    st[count]=R[j];
    j++; count++;
  }
}
void print_list(student *st, int n){
  for (int i = 0; i < n; ++i)
  {
    cout<<st[i];
  }
}
int search_name(student *st, const char name[], int l, int r){
  if (strcmp(st[l].firstName,name)==0)
    return l;
  if (strcmp(st[r].firstName,name)==0)
    return r;
  
  if(l<r){
    int m= l+ (r-l)/2;
    if()
  }
return 1;
}
int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int n= rand()%4+10;
  student* st= new student();
  // char gt[15];
  // strcpy(gt, Gender[0]);
  // cout<<gt;
  cout<<n<<"danh sach ban dau"<<endl;
  create_list_student(st, n);
  print_list(st, n);
  cout<<"danh sach da sap xep"<<endl;
  merge_sort(st,0,n-1);
  print_list(st,n);
  char name[15];
  cout<<"nhap ten can tim: ";cin>>name;
  return 0;
}