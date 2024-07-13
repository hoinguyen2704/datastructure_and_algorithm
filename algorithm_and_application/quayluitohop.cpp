#include <iostream>
using namespace std;
void xuat(int* result, int n) {
	for (int i = 0; i < n; ++i)
		cout << result[i] << " ";
	cout << endl;
}
void generateCombinations(int arr[], int n, int k, int idx, int start) {
	if (idx == k) {
		xuat(arr, k);
		return;
	}

	for (int i = start; i < n; ++i) {
		arr[idx] = i;
		generateCombinations(arr, n, k, idx + 1, i + 1);
	}
}

int main() {
	int n, k;
	cout << "Nhap so phan tu (n): ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;

	int arr[k];
	generateCombinations(arr, n, k, 0, 0);

	return 0;
}
