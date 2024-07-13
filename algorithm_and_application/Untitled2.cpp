#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
using namespace std;
int n=5;
int k=3;
int kt=k+1;

void merge(int *a, int l, int m, int r){
  int n1= m-l+1, n2= r-m;
  int L[n1], R[n2];
  for(int i=0; i<n1; i++){
    L[i]= a[l+i];
  }
  for(int j=0; j<n2; j++){
    R[j]= a[m+1+j];
  }
  int i=0, j=0, count = l;
  while( i<n1 && j<n2 ){
    if(L[i] < R[j]){
      a[count]= L[i];
      ++i;
    }
    else{
      a[count]= R[j];
      ++j;
    }
    ++count;
  }
  while(i<n1){
    a[count]=L[i];
    ++count;
    ++i;
  }
  while(j<n2){
    a[count]=R[j];
    ++count;
    ++j;
  }
}

void merge_sort(int *a, int l, int r){
  if(l<r){
    int m= l + (r-l)/2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    merge(a, l, m, r);
  }
}

string hangSanXuat[]={"Xiaomi", "SamSung","Apple","Toshiba","Google","TCL","LG","Electrolux","Panasonic","Hitachi"
};

struct mayGiat{
    string id;
    string hangSanXuat;
    double khoiLuongGiat;
    double giaBan;
};
void create(mayGiat danhSachMayGiat[]){
  for(int i=0; i<n ; i++){
    danhSachMayGiat[i]={"00"+to_string(i+1) , hangSanXuat[ rand()%  (sizeof(hangSanXuat)/sizeof(string)) ],
    (double) (rand()%71 + 50)/10, (double)(rand()%151 + 100)/10  };
  }
}
void print(mayGiat x){
    cout
    <<left<<setw(4)<<x.id
    <<left<<setw(15)<<x.hangSanXuat
    <<left<<setw(6)<<x.khoiLuongGiat
    <<left<<setw(6)<<x.giaBan
    <<endl;
}
void print(mayGiat danhSachMayGiat[]){
    cout
    <<left<<setw(4)<<"id"
    <<left<<setw(15)<<"HangSX"
    <<left<<setw(6)<<"KL"
    <<left<<setw(6)<<"pay"
    <<endl;
  for(int i=0; i< n; i++){
    cout
    <<left<<setw(4)<<danhSachMayGiat[i].id
    <<left<<setw(15)<<danhSachMayGiat[i].hangSanXuat
    <<left<<setw(6)<<danhSachMayGiat[i].khoiLuongGiat
    <<left<<setw(6)<<danhSachMayGiat[i].giaBan
    <<endl;
  }
}
double sum_pay(mayGiat ds[], int i){
  if(i==0){
    return ds[i].giaBan;
  }
  else{
    return sum_pay(ds, i-1)+ ds[i].giaBan;
  }
}
int A2(mayGiat DS[], int l, int r){
  if(l<r){
    int m= l+ (r-l)/2;
    return A2(DS, l, m) + A2(DS, m+1, r);
  }
  else{
    if(DS[l].khoiLuongGiat>9){
      print(DS[l]);
      return 1;
    }
  }
  return 0;
}
bool isfinal_tohop=false;
bool isfinal_hoanvi=false;

void khoitao(int index[], int k){
  for(int i=1; i <=k; i++){
    index[i]=i;
  }
}
void create(bool used[]){
  for(int i=0; i<kt; i++){
    used[i]= false;
  }
}
void sinhhoanvi(mayGiat DS[],int index[], int k, int n){
    int i=k-1;
    while(i>=1 && (index[i] > index[i+1])){
      --i;
    }
    if(i==0){
      isfinal_hoanvi=true;
    }
    else{
    int j=k;
    while(index[j] < index[i]){
      --j;
    }
    swap(index[i], index[j]);

//    sort(index+i+1, index +k+1);
    merge_sort(index, i+1, k);
    }
}


void quaylui_hoanvi(mayGiat DS[], int index[], int k, int i, bool used[]){
  for(int j= 1; j<=k; j++){
    if(used[j]==false){
      used[j]= true;
      index[i]= index[j];
      if(i==k){
        for(int i=1; i<=k; i++){
          cout<<DS[index[i]-1].id<<" ";
        }
        cout<<endl;
      }
      else{
        quaylui_hoanvi(DS, index, k, i+1, used);
      }
    used[j]=false;
  }

}
}
void quaylui_tohop(mayGiat DS[], int index[], int k, int i){
  for(int j= index[i-1]+1; j<= n-k+i; j++){
    index[i]=j;
    if(i==k){
    for(int i=1; i<=k; i++){
      cout<<DS[index[i]-1].id<<" ";
    }
    cout<<endl;
    }
    else {
      quaylui_tohop(DS,  index, k, i+1);
    }
  }
}
int main(){
  srand((time(NULL)));
  mayGiat danhSachMayGiat[n];
  create(danhSachMayGiat);
  print(danhSachMayGiat);
  double sumpay= sum_pay(danhSachMayGiat, n);
  cout<<"\ntong gia ban= "<<sumpay<<endl;
  int count=0;
  count= A2(danhSachMayGiat, 0, n-1);
  cout<<"\nso luong= "<<count<<endl;
  int index[kt];
  khoitao(index, k);
  bool used[kt];
  create(used);

  index [0]=0;
  for(const auto& x: index){
    cout<<x<<" ";
  }
  cout<<endl;
  int so_cach_chon=0;
//  quaylui_tohop(danhSachMayGiat, index, k, 1);
quaylui_hoanvi(danhSachMayGiat, index, k, 1, used);
//  so_cach_chon= print(danhSachMayGiat, index, k);
//  sinhtohop(danhSachMayGiat, index, k, n);
//cout<<"so cach chon la: "<<so_cach_chon;
  return 0;
}