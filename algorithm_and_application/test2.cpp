#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;
struct chuyen_bay;
void print(chuyen_bay [], int );
struct chuyen_bay
{
    string id;
    int giave;
    int soghengoi;
};
struct check{
  chuyen_bay infor;
  bool used;
  int index;
};
void create_list(chuyen_bay L[], int n){
    for(int i=0; i<n; i++){
        L[i]= {"VN00" +to_string(i+1), (rand()%11+5)*10000, rand()%101 +100};
    }
}
void print_node(chuyen_bay x){
    cout
    <<left<<setw(7)<<x.id
    <<left<<setw(8)<<x.giave
    <<left<<setw(4)<<x.soghengoi
    <<endl;
}
void print(chuyen_bay L[], int n){
    cout
    <<left<<setw(7)<<"ID"
    <<left<<setw(8)<<"COST"
    <<left<<setw(4)<<"SEAT"
    <<endl;
  for(int i=0; i<n; i++){
    print_node(L[i]);
  }
}
int A1(chuyen_bay L[], int n, int i){
  if(i==n){
    return 0;
  }
  if(L[i].giave >= 70000){
    cout
    <<left<<setw(7)<<L[i].id
    <<left<<setw(8)<<L[i].giave
    <<left<<setw(4)<<L[i].soghengoi
    <<endl;
    return 1+ A1(L, n, i+1);
  }
   return A1(L, n, i+1);
}
chuyen_bay A2(chuyen_bay L[], int l, int r){
  if(l<r){
    int m= l + (r-l)/2;
    chuyen_bay left =A2(L, l, m);
    chuyen_bay right =A2(L, m+1, r );
    if( left.giave < right.giave ){
      return left;
    }
    else{
      return right;
    }
  }
  if(l==r){
    return L[l];
  }
  return L[l];
}

void create_check(check array[] ,chuyen_bay L[] , int n){
  for(int i=0; i<n; i++){
    array[i].infor= L[i];
    array[i].used=false;
    array[i].index=i+1;
  }
}

void abc(chuyen_bay L[],int index[], int count){
  for(int i=0; i<count; i++)
  {
    cout<<L[index[i+1]-1].id<<" ";
  }
  cout<<endl;
}
void A3(chuyen_bay L[] ,int index[],int n_check, int k_check, int i_check){

  for(int j= index[i_check-1]+1; j <= n_check - k_check + i_check; j++){
    index[i_check]= j;
    if(i_check==k_check){
      abc(L, index, k_check);
    }
    else{
      A3( L, index, n_check, k_check, i_check+1);
    }
  }
}
int main(){
    srand(time(NULL));
    int n=rand()%5+6;
    cout<<"n= "<<n<<endl;
    chuyen_bay fly[n];
    create_list(fly, n);
    print(fly, n);
    cout<<"\ndanh sach chuyen bay co gia ve >= 70000"<<endl;
    cout<<A1(fly, n, 0)<<endl;
    cout<<"\nchuyen bay co gia ve thap nhat la: \n";
    print_node(A2(fly, 0, n-1));

    check data[n];
    create_check(data,fly, n);
    cout<<endl;
    int k=4;
    int index[5]={0,1,2,3,4};
    A3(fly, index, n, k, 1);
    return 0;
}