#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void generatePermutations(int arr[], int n, int k) {
	if (k == n) {
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}

	for (int i = k; i < n; ++i) {
		swap(arr[k], arr[i]);
		generatePermutations(arr, n, k + 1);
		swap(arr[k], arr[i]); // Hoàn tác d? th? giá tr? khác
	}
}
void xuat(int* result, int n) {
	for (int i = 0; i < n; ++i)
		cout << result[i] << " ";
	cout << endl;
}
void Try(int k, int n, int* result, bool* used) {
	for(int i=0; i<n; i++) {
		if(!used[i]) {
			result[k]=i;
			used[i]=true;
			if(k==n-1) {
				xuat(result,n);
			} else {
				Try(k+1, n, result, used);
			}
			used[i]=false;
		}
	}
}
void Try(int k, int n, int* result, int index){
  int prev = (index==0)?0:result[index-1]+1;
  for(int j=prev; j<=n-k+index; j++){
    result[index]= j;
    if(index==k-1){
      xuat(result, k);
    }
    else{
      Try(k,n,result,index+1);
    }
  }
}
int main() {
	int n;
	cout << "Nhap so phan tu (n): ";
	cin >> n;
  int k=n-2;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
		arr[i] = i;
//	cout<<sizeof(arr)<<endl;
  xuat(arr,n);
	bool used[n]= {false};
//	generatePermutations(arr, n, 0);
//	Try(0, n, arr, used);
  Try(k,n,arr,0);
	return 0;
}
