#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int* create(const int& n) {
	int *list_ran = (int*) malloc(n*sizeof(int));
	for(int i=0; i<n; i++) {
		list_ran[i]= i+1;
	}
//	list_ran[0]=0;
	return list_ran;
}
void print(const int* list_rand,const int& n) {
	for(int i=0; i<n; i++) {
		cout<<list_rand[i]<<" ";
	}
	cout<<endl;
}
int* sinhHoanVi(int* list_ran, int n, bool& isFinal) {
	int i=n-2;
	int *result = list_ran;
	while(i>=0 && result[i] > result[i+1]) {
		--i;
	}
	if(i<0) {
		isFinal=true;
	} else {
		int j=n-1;
		while(result[j] < result[i]) {
			--j;
		}
		swap(result[i],result[j]);
		sort(result+i+1, result+n);
	}
	return result;
}
int* sinhtohop(int* list_ran,const int& n,const int& k, bool& isFinal) {
	int *result = list_ran;
	int i=k-1;
	while(i>=0 && result[i] == n-k+i+1) {
		--i;
	}
	if(i<0) {
		isFinal=true;
	} else {
		result[i]+=1;
		for(int j=i+1; j<k; j++) {
			result[j]=result[j-1]+1;
		}
	}
	return result;
}
int main() {
	srand(time(NULL));
	int n;
	cin>>n;
	int *list_ran=create(n);
	int *result = create(n-2);
  reverse(list_ran+1,list_ran+n);
	print(list_ran, n);
//	print(result, n-1);
//  sort(list_ran,list_ran+n, greater<int>());
//	print(list_ran, n);
	bool isfinal = false;
//	while(!isfinal) {
//		print(list_ran, n);
//		list_ran = sinhHoanVi(list_ran, n, isfinal);
//	}
//	while(!isfinal) {
//		print(list_ran, n-2);
//		list_ran = sinhtohop(list_ran, n, n-2, isfinal);
//	}
	return 0;
}