#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;
 struct node
 {
    string id;
    int giaban;
    int ghe;
 };
void create_list(node L[], int n){
    for (int i = 0; i < n; ++i)
    {
        L[i].id="VN00"+to_string(i+1);
        L[i].giaban=rand()%11+5;
        L[i].ghe=rand()%100;
    }
}
void print_node(node x){
    cout
    <<left<<setw(6)<<x.id
    <<left<<setw(5)<<x.giaban
    <<left<<setw(5)<<x.ghe
    <<endl;
}
void print_list(node L[], int n){
  for(int i=0; i<n; i++){
    print_node(L[i]);
  }
}
void abc(int index[], int k){
  for(int i=1; i<=k; i++){
    cout<<index[i]<<" ";
  }
  cout<<endl;

}
void hoanvi(int index[], bool used[],int n, int k, int i){
  for(int j=1; j<=k; j++){
    if(!used[j]){
      index[i]=j;
      used[j]=true;
    if(i==k){
      abc(index, k);
    }
    else{
      hoanvi(index, used, n, k, i+1);
    }
      used[j]=false;
    }
  }
}


void merge(const void *a, const void *bq ){
  
}
void try_(int index[], int n, int k, int i){
// cac kha nag co the nhan duoc a[i-1]+1 -> n-k+i
// cau hinh cuoi cung khi i=k;
  for(int j= index[i-1]+1; j<= n-k+i; j++){

    index[i]=j;
    if(i==k){
        abc(index, k);
      }
    else{
      try_(index, n, k, i+1);
    }
  }
}
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n=rand()%5+6;
    node L[n];
    create_list(L,n);
    print_list(L, n);
    int index[5]={0,5,6,7,8};
    int k=4;
    bool used[5]={0,0,0,0,0};
//    try_(index, n, k, 1);
    hoanvi(index, used,n , k, 1);
    return 0;
}
