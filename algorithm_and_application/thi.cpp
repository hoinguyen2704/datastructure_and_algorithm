#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

struct laptop;
ostream& operator<<(ostream&, laptop );
ostream& operator<<(ostream&, vector<laptop> );
ostream& operator<<(ostream&, vector<int> );
void xuat(vector<int>, int );
void xuat(vector<laptop>, vector<int>, int );
vector<int> sinhtohop(vector<int>&, int, int, bool&);
vector<int> sinhhoanvi(vector<int>&, int, bool&);
void Try(vector<int> &, int, int, int, int );
void Try(vector<int>&, int, int, int );
void Try(vector<int>&,vector<bool>&, int, int );
//implement
struct laptop {
	string hangsx;
	string cauhinh;
	int giaban;
	int khoiluong;
};
//
ostream& operator<<(ostream& out, laptop lap) {
	out
	        <<left<<setw(10)<<lap.hangsx
	        <<left<<setw(35)<<lap.cauhinh
	        <<left<<setw(6)<<lap.giaban
	        <<left<<setw(4)<<lap.khoiluong
	        <<endl;
	return out;
}
ostream& operator<<(ostream& out, vector<laptop> lap) {
	for(int i=0; i<lap.size(); i++) {
		out<<lap[i];
	}
	return out;
}
ostream& operator<<(ostream& out, vector<int> array) {
	for(int i=0; i<array.size(); i++) {
		out<<array[i]<<" ";
	}
	out<<endl;
	return out;
}
void xuat(vector<int> array, int n) {
	for(int i=0; i<n; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void xuat(vector<laptop> v, vector<int> array, int n) {
	for(int i=0; i<n; i++) {
		cout<<left<<setw(12)<<v[array[i]].hangsx;
	}
	cout<<endl;
}
vector<int> sinhtohop(vector<int> &array, int n, int k, bool &isfinal) {
	int i=k-1;
	while(i>=0 && array[i]==n-k+i) {
		--i;
	}
	if(i<0) {
		isfinal=true;
	} else {
		array[i]+=1;
		for(int j=i+1; j<=k; j++) {
			array[j]= array[j-1]+1;
		}
	}
	return array;
}
vector<int> sinhhoanvi(vector<int> &array, int n, bool &isfinal) {
	int i=n-1;
	while(i>=0 && array[i-1] > array[i]) {
		--i;
	}
	if(i<0) {
		isfinal=true;
	} else {
		int j=n-1;
		while(array[j] < array[i-1]) {
			--j;
		}
		swap(array[j], array[i-1]);
		sort(array.begin()+i, array.end());
	}
	return array;
}
void Try(vector<int> &array, int n, int k, int index, int start) {
	if(index==k) {
		xuat(array, k);
		return;
	}
	for(int i=start; i<n; i++) {
		array[index]=i;
		Try(array, n, k, index+1, i+1);
	}
}
void Try(vector<int> &array, int n, int k, int index) {
	int prev = (index==0)?0:array[index-1]+1;
	for(int j= prev; j<= n-k+index; j++) {
		array[index]=j;
		if(index==k-1) {
			xuat(array, k); 
		} else {
			Try(array, n, k, index+1);
		}
	}
}
void Try(vector<int> &array,vector<bool> &used, int n, int index) {
	for(int i=0; i<n; i++) {
		if(!used[i]) {
			array[index]=i;
			used[i]=true;
			if(index==n-1) {
				xuat(array, n);
			} else {
				Try(array, used, n, index+1);
			}
			used[i]=false;
		}
	}
}
vector<laptop> truyvet(vector<laptop> v, int n, int weight, vector<vector<int>> dp, int &sum) {
	vector<laptop> result;
	while(n>0) {
		if(dp[n][weight] == dp[n-1][weight]) {
			--n;
		} else {
			result.push_back(v[n-1]);
			weight-= v[n-1].khoiluong;
			sum+=v[n-1].khoiluong;
			--n;
		}
	}
//	reverse(result.begin(), result.end());
	return result;
}
pair<pair<int,int>, pair<int, vector<laptop>>> quyhoachdong
(vector<laptop> v, int n, int weight) {
	int i=0, j=0;
	vector<vector<int>> dp (n+1, vector<int> (weight+1));
	for(int j=0; j<= weight; j++) {
		dp[0][j]=0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=weight; j++) {
			dp[i][j]= dp[i-1][j];
			if(v[i-1].khoiluong<=j) {
				dp[i][j]= max(
				              dp[i-1][j],
				              dp[i-1][j-v[i-1].khoiluong] + v[i-1].giaban
				          );
			}
		}
	}
	int sumWeight=0;
	int sumgiatri=dp[n][weight];
	vector<laptop> result= truyvet(v, n, weight, dp, sumWeight);
	int count = result.size();
	pair<pair<int,int>, pair<int, vector<laptop>>> count_giatri_trongluong_danhsach;
	count_giatri_trongluong_danhsach.first.first= count;
	count_giatri_trongluong_danhsach.first.second= sumgiatri;
	count_giatri_trongluong_danhsach.second.first= sumWeight;
	count_giatri_trongluong_danhsach.second.second= result;

//	cout<<left<<setw(4)<<"";
//	for(i=0; i<=weight; i++) {
//		cout<<left<<setw(4)<<i;
//	}
	cout<<endl;
	for(i=0; i<=n; i++) {
//		cout<<left<<setw(4)<<i;
		for(j=0; j<=weight; j++) {
			cout
			        <<left<<setw(4)
			        <<dp[i][j];
		}
		cout<<endl;
	}

	return count_giatri_trongluong_danhsach;

}
int char_in_string(const char& p, const string& S) {
	for(int i=0; i<S.length(); i++) {
		if(p==S[i]) {
			return i;
		}
	}
	return -1;
}
int boyer(const string& T, const string& p) {
	int dem=0, v= p.length(), i=v-1;
	while(i<T.length()) {
		int x= v-1;
		while(x>=0 && p[x]==T[i]) {
			--i;
			--x;
		}
		if(x<0) {
			return i+1;
			++dem;
			i+=2*v;
		} else {
			int k = char_in_string(T[i], p);
			if(k<0) {
				i+=v;
			} else {
				i+=v-x;
			}
		}
	}
	return dem;
}
vector<int> z_algo(const string& S) {
	int n= S.length();
	vector<int> z(n,0);
	int l=0, r=0;
	for(int i=0; i<n; i++) {
		if(r<i) {
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
			z[i]=r-l;
			--r;
		}
	}
	return z;
}
vector<int> truyvet(const string& S, const string& sub) {
	string concat= sub+"$"+S;
	vector<int> result;
	vector<int> z= z_algo(concat);
	for(int i=0; i< z.size(); i++) {
		if(z[i]==sub.size()) {
			result.push_back(i-sub.size()-1);
		}
	}
	return result;
}
bool compare(const laptop& l1,const laptop& l2 ) {
	return l1.giaban>l2.giaban;
}
pair<pair<int,int>, pair<int, vector<laptop>>>
thamlam_function(vector<laptop> v, int giatien) {
	vector<laptop> result;
	int count=0;
	int tonggiatien=0;
	int tongWeight;
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++) {
		if(v[i].giaban <= giatien) {
			result.push_back(v[i]);
			giatien-=v[i].giaban;
			++count;
			tonggiatien+=v[i].giaban;
			tongWeight+=v[i].khoiluong;
		}
	}
	pair<pair<int,int>, pair<int, vector<laptop>>> count_giaban_trongluong_list;
	count_giaban_trongluong_list.first.first=count;
	count_giaban_trongluong_list.first.second=tonggiatien;
	count_giaban_trongluong_list.second.first=tongWeight;
	count_giaban_trongluong_list.second.second=result;

	return count_giaban_trongluong_list;
}
int main() {
	int n=7;
	int giatri=500;
	int weight = 30;
	vector<laptop> v= {
		{"M0: Dell", "Intel Core i5, 8GB RAM, 256GB SSD", 100, 18},
		{"M1: HP", "AMD Ryzen 7, 16GB RAM, 512GB SSD", 120, 22},
		{"M2: Lenovo", "Intel Core i7, 32GB RAM, 1TB SSD", 150, 25},
		{"M3: Asus", "Intel Core i3, 16GB RAM, 256GB SSD", 60, 15},
		{"M4: Acer", "AMD Ryzen 5, 8GB RAM, 512GB SSD", 80, 17},
		{"M5: MSI", "Intel Core i9, 32GB RAM, 1TB SSD", 250, 30},
		{"M6: Apple", "M1 chip, 16GB RAM, 512GB SSD", 180, 13}
	};
	cout<<v;
	vector<int> array(n);
	vector<bool> used(n);

	for(int i=0; i<array.size(); i++) {
		array[i]=i;
	}
	fill(used.begin(), used.end(), false);
	cout<<array;
	bool isfinal= false;
//  while(!isfinal){
//    xuat(v,array, n);
//    array=sinhtohop(array, n, n-2, isfinal);
//      xuat(array, n);
//      array= sinhhoanvi(array, n , isfinal);
//  }
//	Try(array, n, n-2, 0, 0);
//  Try(array, n, n-2, 0);
//	Try(array, used, n, 0);
//	pair<pair<int,int>, pair<int, vector<laptop>>> QHD = quyhoachdong(v, n, weight);
//	cout<<"so luong: "<<QHD.first.first<<endl;
//	cout<<"tong gia tri: "<<QHD.first.second<<endl;
//	cout<<"tong trong luong: "<<QHD.second.first<<endl;
//	cout<<"danh sach duoc chon\n"<<QHD.second.second;
//	vector<int> z = truyvet(v[0].cauhinh, "GB");
//  cout<<z;
//  int dem = boyer(v[0].cauhinh, "GB");
//  cout<<dem;
	pair<pair<int,int>, pair<int, vector<laptop>>> thamlam = thamlam_function(v, giatri);
	cout<<"so luong: "<<thamlam.first.first<<endl;
	cout<<"tong gia tri: "<<thamlam.first.second<<endl;
	cout<<"tong trong luong: "<<thamlam.second.first<<endl;
	cout<<"danh sach duoc chon\n"<<thamlam.second.second;
	return 0;
}