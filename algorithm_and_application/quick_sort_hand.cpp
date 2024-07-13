#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void create(int *a, int n){
  for(int i=0; i<n; i++){
    a[i]= rand()%31-15;
  }
}
void print(int *a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
int partition_hoare(int *a, int l, int r){
  int pivot =a[l];
  int i=l-1;
  int j= r+1;
  while(true){
    do{
      ++i;
    }
    while(a[i] < pivot);
    do{
      --j;
    }
    while(a[j] > pivot);
    if(i<j){
      swap(a[i], a[j]);
    }
    else
    return j;
  }
}
int partition(int *a, int l, int r){
  int pivot = a[r];
  int i=l;
  for(int j=l; j<r; j++){
    if(a[j]<= pivot ){
      swap(a[i], a[j]);
      ++i;
    }
  }
  swap(a[i], a[r]);
  return i;
}
void quick_sort(int *a, int l, int r){
  if (l<r){
    int q=partition(a, l, r);
//    int q= partition_hoare(a, l, r);
    quick_sort(a, l, q-1);
    quick_sort(a, q+1, r);
  }
}
int main(){
  srand(time(NULL));
  int n;
  n= 10;
  int *a;
  cout<<n<<endl;
  create(a, n);
  print(a, n);
  quick_sort(a, 0, n-1);
  print(a, n);
  return 0;
}