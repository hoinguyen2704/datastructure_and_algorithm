#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

struct vatpham;
int knapSack( vatpham* &, vatpham*,const int&,const int& );
vatpham* truy_vet(const vatpham*, vatpham* &,int, int, vector <vector <int>>& );
struct vatpham {
	int giatri;
	int trongluong;
};
ostream& operator<<(std::ostream& os, const vatpham &vp) {
	os
	        <<left<<setw(10)<<vp.giatri
	        <<left<<setw(10)<<vp.trongluong
	        <<endl;
	return os;
}
void print(vatpham* list, int n) {
	cout
	        <<left<<setw(10)<<"gia tri"
	        <<left<<setw(10)<<"trong luong"
	        <<endl;
	for(int i=0; i<n; i++) {
		cout<<list[i];
	}
}
void print(const vector <vatpham> &list) {
	cout
	        <<left<<setw(10)<<"gia tri"
	        <<left<<setw(10)<<"trong luong"
	        <<endl;
	for(int i=0; i < list.size(); i++) {
		cout<<list[i];
	}
}
vatpham* create(int n) {
	vatpham *list=
//  new vatpham();
	    (vatpham*) malloc(n*sizeof(vatpham));
	for(int i=0; i<n; i++) {
		list[i]= {
			15+rand()%15+rand()%15,
			rand()%15+1
		};
	}
	return list;
}
bool compare_giatri(const vatpham &v1, const vatpham& v2) {
	return v1.giatri<v2.giatri;
}
bool compare_kl(const vatpham &v1, const vatpham& v2) {
	return v1.trongluong<v2.trongluong;
}
vector<vatpham> truy_vet( vatpham* &root, vector<vatpham> result, int n, int weigh, vector <vector <int>> &dp) {
	while (n>0) {
		if (dp[n][weigh] == dp[n-1][weigh]) {
			--n;
		} else {
			result.push_back(root[n-1]);
			weigh -= root[n-1].trongluong;
			--n;
		}
	}
	return result;
}
int knapSack(vatpham* &list, vector<vatpham> &result,const int& n,const int& weigh) {
	vector <vector<int>> dp (n+1, vector <int> (weigh+1));
	int i, j;
	for(j=0; j<= weigh; j++) {
		dp[0][j]=0;
	}
	for(i=1; i<=n; i++) {
		for(j=0; j<= weigh; j++) {
			dp[i][j] = dp[i-1][j];
			if(list[i-1].trongluong <= j) {
				dp[i][j]= max(
				              dp[i-1][j],
				              dp[i-1][j-list[i-1].trongluong]+list[i-1].giatri
				          );
			}
		}
	}
	cout<<left<<setw(4)<<"";
	for(i=0; i<=weigh; i++) {
		cout<<left<<setw(4)<<i;
	}
	cout<<endl;
	for(i=0; i<=n; i++) {
		cout<<left<<setw(4)<<i;
		for(j=0; j<=weigh; j++) {
			cout
			        <<left<<setw(4)
			        <<dp[i][j];
		}
		cout<<endl;
	}
	result = truy_vet(list, result, n, weigh, dp);
	return dp[n][weigh];
}
int main() {
	srand(time(NULL));
	int n;
	n= 8;
	int kho = 20;
	cout<<"n = "<<n<<"\tkho = "<<kho
	    <<endl;
//  vatpham *list= (vatpham*) malloc(n*sizeof(vatpham));
//  vatpham *list=new vatpham();
//    for(int i=0; i<n; i++){
//      list[i]={
//        15+rand()%15+rand()%15,
//        15+rand()%15+rand()%15,
//    };
//  }
	vatpham *list= new vatpham();
	list=create(n);
//  sort(list, list +n,compare_kl);
	print(list, n);
	cout<<"endl"<<endl;
	vector <vatpham> result;
	cout<<knapSack(list, result, n, kho);
	reverse(result.begin(), result.end());
	cout<<endl<<"vat pham duoc chon: \n";
	print(result);
	free(list);
//  delete(list);
	return 0;
}