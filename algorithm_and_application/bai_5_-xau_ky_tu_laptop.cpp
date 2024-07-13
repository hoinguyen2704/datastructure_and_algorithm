#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
struct laptop {
	string hsx;
	string cauhinh;
	int giaban;
};
istream& operator>>(istream& is, laptop& l) {
	cout<<"Nhap hang san xuat"<<endl;
	fflush(stdin);
	getline(is,l.hsx);
	cout<<"Nhap cau hinh"<<endl;
	fflush(stdin);
	getline(is,l.cauhinh);
	cout<<"Nhap gia ban"<<endl;
	is>>l.giaban;
	return is;
}
void print(vector<laptop> const &v) {
	cout<<"Danh sach cac laptop"<<endl;
	cout<<left<<setw(10)<<"HSX"<<left<<setw(45)<<left<<"CH"<<setw(10)<<"Gia"<<endl;
	for(int i=0; i < v.size(); i++) {
		cout<<left<<setw(10)<<v[i].hsx;
		cout<<left<<setw(45)<<v[i].cauhinh;
		cout<<left<<setw(10)<<v[i].giaban;
		cout<<endl;
	}
}
vector<laptop> create(int n) {
	vector<laptop> v;
	for(int i=0; i<n; i++) {
		laptop l;
		cin>>l;
		v.push_back(l);
		cout<<endl;
	}
	return v;
}
int boyer_moore(string s, string p) {
	int n=s.length();
	int m=p.length();
	int i=0;
	int j=0;
	while(i<n) {
		while(j<m && s[i]==p[j])
			i++,j++;
		if(j==m)
			return i-j;
		i=i-j+1;
		j=0;
	}
	return -1;
}
void boyer_moore_horspool(string s, string p) {
	int n=s.length();
	int m=p.length();
	int i=0;
	int j=0;
	int k=0;
	int t=0;
	while(i<n) {
		while(j<m && s[i]==p[j])
			i++,j++;
		if(j==m) {
			cout<<"Found at index "<<i-j<<endl;
			i=i-j+1;
			j=0;
		} else {
			k=j;
			while(k>0 && s[i-k]!=p[k-1])
				k--;
			if(k==0) {
				i++;
				j=0;
			} else {
				i=i-k+1;
				j=k;
			}
		}
	}
}
int char_in_string(const char &c,const string &str) {
	for(int i=0; i<str.length(); i++) {
		if(str[i]==c)
			return i;
	}
	return -1;
}
int boyer_moore_horspool2(const string &T, const string &p) {
	int dem=0, v=p.length(), i= v-1;
	while(i<T.length()) {
		int x= v-1;
		while (x>=0 && p[x]==T[i]) {
			x--;
			i--;
		}
		if (x<0) {
			dem+=1;
			i+=2*v;
		} else {
			int k = char_in_string(T[i],p);
			if(k<0) {
				i=i+v;
			} else {
				i+=v-x;
			}
		}
	}
	return dem;
}
vector<int> Z_algo(const string &S) {
	int n= S.size();
	vector<int> z (n);
	int l,r;
	l=r=0;
	for(int i=1; i<n; i++) {
		if(i>r) {
			l=r=i;
			while(r<n && S[r-l]==S[r]) {
				++r;
			}
			z[i]=r-l;
			--r;
		} else if(z[i-l] < r-i+1) {
			z[i]= z[i-l];
		} else {
			l=i;
			while(r<n && S[r-l]== S[r]) {
				++r;
			}
			z[i]= r-l;
			--r;
		}
	}
	return z;
}
int F1(const string &T, const string &p) {
	int  v=p.length(), i= v-1;
	while(i<T.length()) {
		int x= v-1;
		while (x>=0 && p[x]==T[i]) {
			x--;
			i--;
		}
		if (x<0) {
			return i+1;
		} else {
			int k = char_in_string(T[i],p);
			if(k<0) {
				i=i+v;
			} else {
				i=i+v-x;
			}
		}
	}
	return -1;
}
int F3(vector<laptop> const &v) {
	int r=0;
	string p= "RAM 16GB";
	int n=v.size();
	for(int i=0; i<n; i++) {
		if(F1(v[i].cauhinh,p)!=-1)
			r++;
	}
	return r;
}
//int search(vector<laptop> const &v, string p){
//    int n=v.size();
//    for(int i=0;i<n;i++){
//        if(boyer_moore(v[i].cauhinh,p)!=-1)
//            return i;
//    }
//    return -1;
//}
int main() {
	int n= 6;
	vector<laptop> v;
	v= create(n);
	print(v);
	cout<<F3(v)<<endl;
//    cout<<boyer_moore_horspool2(v[0].cauhinh,"GB");
//    cout<<F3(v);
//    cout<<v[2].cauhinh.length();
	// system("pause");
	return 0;
}
//HP
//CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB
//15000000
//ACER
//CPU 2.5GHz upto 3.7GHz-RAM 8GB-HDD 2TB
//12000000
//APPLE
//CPU 2.7GHz upto 3.5GHz-RAM 32GB-SSD 2TB
//42000000
//ASUS
//CPU 2.4GHz upto 3.6GHz-RAM 64GB-HDD 2TB
//32000000
//SAMSUNG
//CPU 2.2GHz upto 3.2GHz-RAM 16GB-HDD 2TB
//56000000
//DELL
//CPU 2.9GHz upto 3.9GHz-RAM 16GB-HDD 2TB
//90000000