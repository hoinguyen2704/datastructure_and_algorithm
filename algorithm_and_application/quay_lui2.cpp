#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int n=7;
int k=3;
int a[20];
//max = n-k+i
//min = a[i-1]+1
void create_array() {
	for (int i = 0; i < k+1; i++) {
		a[i]=i;
	}
}
void print_array() {
	for (int i = 1; i < k+1; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void Try(int i) {
	for(int j= a[i-1]+1; j<= n-k+i; j++) {
		a[i]=j;
		if(i==k) {
			print_array();
		} else {
			Try(i+1);
		}
	}
}


int main(int argc, char const *argv[]) {
	create_array();
	// print_array();
	Try(1);
	return 0;
}

