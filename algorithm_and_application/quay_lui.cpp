#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int n= 4;
int k=3;
int a[10];
void create_config() {
	for(int i=0; i<=k; i++) {
		a[i]= 0;
	}
}
void create_array() {
	for(int i=0; i<=k; i++) {
		a[i]= i;
	}
}
void print_config() {
	for(int i=1; i<=k; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void print_array() {
	for(int i=1; i<=k; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void generate_config(int i) {
	for(int j=0; j<=1; j++) {
		a[i]=j;
		if(i==k) {
			print_config();
		} else {
			generate_config(i+1);
		}
	}
}
void generate_array(int i) {
	for(int j=1; j<=n; j++) {
		a[i]=j;
		if(i==k) {
			print_array();
		} else {
			generate_array(i+1);
		}
	}
}
int main() {
//  srand(time(NULL));
	cout<<"n= "<<n<<"\tk= "<<k<<endl;
	create_array();
//  print_array();
	generate_array(1);
	return 0;
}