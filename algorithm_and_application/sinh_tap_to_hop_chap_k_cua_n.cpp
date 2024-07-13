#include <iostream>

/*
max c?a 1 ph?n t? = n-k +(i+1) v?i i ch?y t? 0

*/
using namespace std;
int n, k;
bool isFinal=false;
int a[100];
char S[8]= {'0','A', 'B','C', 'D', 'E', 'F', 'G'};
void create_config(int *a, int k) {
	for(int i=1; i<=k; i++) {
		a[i]=i;
	}
}
void print_config(int *a, int k) {
	for(int i=1; i<=k; i++) {
		cout<<a[i];
	}
	cout<<endl;
}
void check_return(int *a, int k, int index) {
	while(index > k) {
		a[index]= a[index-1]+1;
		++index;
	}
}

void generate_config(int *a, int k, int n) {
	int i= k;
	while(i>=1 && a[i]==n-k+i) {
		--i;
	}
	if(i==0) {
		isFinal= true;
	} else {
		a[i]+=1;
		for(int j=i+1; j<=k; j++) {
			a[j]=a[j-1]+1;
		}
	}
}
int main(int argc, char const *argv[]) {
	int n, k;
	cout<<"n= ";
	cin>>n;
	cout<<"k= ";
	cin>>k;
	create_config(a, k);
	while(!isFinal) {
		print_config(a, k);
		generate_config(a, k, n);
	}
//print_config(a, k);
	return 0;
}
