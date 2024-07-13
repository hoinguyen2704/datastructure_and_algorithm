#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
int* create(int n) {
	int* root = (int*)malloc(n * sizeof(int));
	root[0] = 1;
	for (int i = 1; i < n; i++) {
		root[i] = root[i - 1] + rand() % 5 + 1;
	}
	return root;
}
void set(int* set,int n) {
	for (int i = 0; i < n; i++) {
		set[i] = i + 1;
	}
}
void print(int* list, int n) {
	for (int i = 0; i <n; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}
void print(int *root, int *result, int n) {
	for (int i = 1; i <= n; i++) {
		cout << root[result[i]-1] << " ";
	}
	cout << endl;
}
int* hoanvi(int* a, int n, bool &isfinal) {
	int i=n-1;
	while(i>0 && a[i] > a[i+1]) {
		--i;
	}
	if(i==0) {
		isfinal =true;
	} else {
		int j = n;
		while(a[j]<a[i]) {
			--j;
		}
		swap(a[i], a[j]);
		sort(a+i+1, a+n+1);
	}
	return a;
}
int* tohop(int *a, int n, int k, bool &isfinal) {
	int i=k;
	while(i>=1 && a[i]==n-k+i) {
		--i;
	}
	if(i==0) {
		isfinal = true;
	} else {
		a[i]+=1;
		for(int j=i+1; j<=k; j++) {
			a[j]=a[j-1]+1;
		}
	}
	return a;
}
int char_in_string(const char& c, const string& P) {
	for(int i=0; i<P.length(); i++) {
		if(c==P[i]) {
			return i;
		}
	}
	return -1;
}
int boyer_moore_hospol(const string& T, const string& p) {
	int dem=0, v= p.length(), i=v-1;
	while(i<T.length()) {
		int x= v-1;
		while(x>=0 && T[i]==p[x]) {
			--x;
			--i;
		}
		if(x<0) {
			i+=2*v;
			++dem;
		} else {
			int k= char_in_string(T[i], p);
			if(k<0) {
				i+=v;
			} else {
				i+=v-x;
			}
		}
	}
	return dem;
}
int boyer_moore_hospolv2(const string& T, const string& p) {
	int dem=0, v= p.length(), i=v-1;
	while(i<T.length()) {
		int x= v-1;
		while(x>=0 && T[i]==p[x]) {
			--x;
			--i;
		}
		if(x<0) {
			return i;
//      i+=2*v;
//			++dem;
		} else {
			int k= char_in_string(T[i], p);
			if(k<0) {
				i+=v;
			} else {
				i+=v-x;
			}
		}
	}
	return -1;
}
int* z_algo(const string& S) {
	int n= S.length();
	int* z = new int(n);
	z[0]=-1;
	int r=0, l=0;
	for(int i=1; i<n; i++) {
		if(r<i) {
			l=i;
			r=i;
			while(r<n && S[r-l]==S[r]) {
				++r;
			}
			z[i]= r-l;
			--r;
		} else if(z[i-l]<r-i+1) {
			z[i]= z[i-l];
		} else {
			l=i;
			while(r<n && S[r-l]==S[r]) {
				++r;
			}
			z[i]=r-l;
			--r;
		}
	}
	return z;
}
void z_algo(const string& S, int* z) {
	int n= S.length();
	int l=0, r=0;
	z[0]=-1;
	for(int i=1; i<n; i++) {
		if(i>r) {
			l=i;
			r=i;
			while(r<n && S[r-l]==S[r]) {
				++r;
			}
			z[i]= r-l;
			--r;
		} else if(z[i-l]<r-i+1) {
			z[i]=z[i-l];
		} else {
			l=i;
			while(r<n && S[r-l]==S[r]) {
				++r;
			}
			z[i]= r-l;
			--r;
		}
	}
}
//void try(int k, int n, int i, int* result, bool* used){
//  for(int i=0; i<)
//}
int main() {
	srand(time(NULL));
	int n=7;
//    cin >> n;
	int* list_ran = create(n);
	int* result = (int*)malloc(n*sizeof(int));
	set(result,n);
	result[n]=0;
	sort(result, result+n+1);

	print(list_ran,n);
	print(result, sizeof(result));

//    vector<int> tohop(n);
//    set(tohop);
//    for (int i = 0; i < n; i++) {
//        cout << tohop[i] << " ";
//    }
//    tohop.push_back(0);
//	bool isfinal=false;
//	while(!isfinal) {
//		print(result, n);
//    print(list_ran,result, n);
//		result = hoanvi(result, n, isfinal);
//		result = tohop(result, n, n-1, isfinal);
//	}
	string p="Viet";
	cout<<"p= "<<p<<endl;
	string T="Ban Viet o Viet Nam";
	string sum= p+"$"+T;
	cout<<"T= "<<T<<endl;
	cout<<boyer_moore_hospolv2(T,p)<<endl;
	int *z=z_algo(sum);
	for(int i=0; i<T.length(); i++) {
		cout<<z[i]<<" ";
	}
	cout<<endl;
	return 0;
}