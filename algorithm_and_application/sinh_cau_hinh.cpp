#include <iostream>
using namespace std;
/*
int n=3;
000
001
010
011
100
101
110
111
=> số lượng = 2^n
=> biết cấu hình đầu + cấu hình cuối
-> khởi tạo cấu hình đầu
-> while(chưa phải cấu hình cuối){
in ra cấu hình hiện tại
sinh cấu hình kế tiếp}
*/
bool isFinal=false;
int a[100];
void create_config(int *a, int n){
 for(int i=1; i<= n; i++){
   a[i]=0;
 }
}
void generate_config(int *a, int n){
  int i=n;
  while(i>=1 && a[i]==1){
    a[i]=0;
    --i;
  }
  if(i==0){
    isFinal=true;
  }
  else{
    a[i]=1;
  }
}
void print_config(int *a, int n){
  for(int i=1; i<=n; i++){
    cout<<a[i];
  }
  cout<<endl;
}
int main(int argc, char const *argv[])
{

  int n;
  cin>>n;
  create_config(a, n);
  while(!isFinal){
    print_config(a, n);
    generate_config(a, n);
  }
  return 0;
}
