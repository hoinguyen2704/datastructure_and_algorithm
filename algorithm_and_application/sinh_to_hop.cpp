#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
using namespace std;
void create(int *a, int k) {
	for(int i=0; i<k; i++) {
		a[i]=i;
	}
}
void print(int *a, int k) {
	for(int i=0; i<k; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void tohop(int *index, int k, int n, bool& isFinal) {
	int i=k-1;
	while(i>=0 && index[i]==n-k+i) {
		--i;
	}
	if(i==-1) {
		isFinal=true;
	} else {
		index[i]+=1;
		for(int j=i+1; j<= k-1; j++) {
			index[j]=index[j-1]+1;
		}
	}
}
void tohop_quaylui(int index[], int k, int n, int i) {
	for(int j=index[i-1]+1; j<= n-k+i; j++) {
		index[i]=j;
		if(i==k-1) {
			print(index, k);
		} else {
			tohop_quaylui(index, k, n, i+1);
		}
	}
}
void hoanvi(int *index, int k, bool& isFinal) {
	int i=k-1-1;
	while(i>=0 && index[i] > index[i+1]) {
		--i;
	}
	if(i==-1) {
		isFinal=true;
	} else {

		int j=k-1;
		while(index[i] > index[j]) {
			--j;
		}
		swap(index[i], index[j]);
		sort(index+i+1, index +k);
	}
}
void print_link(int *index, int *result, int k) {
	for(int i=0; i<k; i++) {
		cout<<result[index[i]]<<" ";
	}
	cout<<endl;
}
void chinhhop(int index[], int k, int n,bool& ishv, bool& isth) {
	if(!ishv) {
		hoanvi(index, k, ishv);
		return;
	}
	sort(index, index+k);
	if(!isth) {
		tohop(index, k, n, isth);
		ishv=false;
	}
}
void chinh_hop(int index[], int n, int k, bool& isFinal_hoanvi, bool& isFinal_Tohop) {
	print(index, k);
	while(!isFinal_hoanvi) {
		int i=k-1-1;
		while(i>=0 && index[i] > index[i+1]) {
			--i;
		}
		if(i==-1) {
			isFinal_hoanvi=true;
		} else {
			int j=k-1;
			while(index[j] < index[i]) {
				--j;
			}
			swap(index[i], index[j]);
			print(index, k);
			sort(index +i+1, index +k);
		}
	}
	sort(index,index+k);
	while(!isFinal_Tohop) {
		int i=k-1;
		while(i>=0&& index[i]==n-k+i) {
			--i;
		}
		if(i==-1) {
			isFinal_Tohop=true;
			return;
		} else {
			index[i]+=1;
			for(int j=i+1; j<k; j++) {
				index[j]=index[j-1]+1;
			}
			print(index, k);
			isFinal_hoanvi=false;
			chinh_hop(index, n, k, isFinal_hoanvi, isFinal_Tohop);
		}
	}
}
void chinhhop2(int index[], int k, int n, bool& ishv, bool& isth) {
	if(!ishv) {
		int i=k-1-1;
		while(i>=0 && !(index[i] <= index[i+1] )) {
			--i;
		}
		if(i==-1) {
			ishv=true;
		} else {
			int j=k-1;
			while(!(index[i]<index[j])) {
				--j;
			}
			swap(index[i],index[j]);
			sort(index+i+1, index+k);
			return;
		}
	}
	sort(index, index+k);
	//to hop
	if(!isth) {
		int i=k-1;
		while(i>=0 && !(index[i] <n-k+i )) {
			--i;
		}
		if(i==-1) {
			isth=true;
		} else {
			index[i]+=1;
			for(int j=i+1; j<k; j++) {
				index[j]=index[j-1]+1;
			}
			ishv=false;
		}
	}
	return;
}
int main() {
	srand(time(NULL));
	int n=7;
	int list[n];
	int start[7]= {3, 5, 7, 8, 9, 4, 2};
	print(start, n);
	create(list, n);
	print(list, n);
	int k=5;
	int index[5]= {0};
//  create(index, k);
	print(index, k);
	bool isFinal_tohop=false;
	bool isFinal_hoanvi=false;
	cout<<"start\n";
//  while(!isFinal){
//    cout<<left<<setw(10)<<"index";
//    print(index, k);
//    cout<<left<<setw(10)<<"result";
//    print_link(index, start, k);
//    generate(index, k, n, isFinal);
//    cout<<endl;
//  }
//  while(!isFinal){
//    cout<<left<<setw(10)<<"index";
//    print(index, k);
//    cout<<left<<setw(10)<<"result";
//    print_link(index, start, k);
//    hoanvi(index, k, isFinal);
//        cout<<endl;
//  }
	cout<<"chinh hop\n";
//  print(index, k);
//  chinh_hop(index, n, k, isFinal_hoanvi, isFinal_tohop);
//  chinhhop(index, k, n, isFinal_hoanvi, isFinal_tohop);
//while( !(isFinal_hoanvi==true && isFinal_tohop==true) ){
//  print(index, k);
//  chinhhop2(index, k, n, isFinal_hoanvi, isFinal_tohop);
//}
//while( !(isFinal_hoanvi==true && isFinal_tohop==true) ){
//  print(index, k);
//  chinhhop(index, k, n, isFinal_hoanvi, isFinal_tohop);
//}
	tohop_quaylui(index, k, n, 0);
	return 0;
}