#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

struct fridge;
ostream& operator<<(ostream&, fridge&);
ostream& operator<<(ostream&, const vector <fridge>&);
vector<fridge> create();
bool compare(const fridge&, const fridge&);

struct fridge {
	string hsx;
	int area;
	double weight;
};
ostream& operator<<(ostream& out, fridge& f) {
	out
	        << left << setw(15) << f.hsx
	        << left << setw(5) << f.area
	        << left << setw(5) << f.weight
	        << endl;
	return out;
}
ostream& operator<<(ostream& out, const vector <fridge>& f) {
	out
	        << left << setw(15) << "hang sx"
	        << left << setw(5) << "area"
	        << left << setw(5) << "wei"
	        << endl;
	for (int i = 0; i < f.size(); i++) {
		out
		        << left << setw(15) << f[i].hsx
		        << left << setw(5) << f[i].area
		        << left << setw(5) << f[i].weight
		        << endl;
	}
	return out;
}
vector<fridge> create() {
	vector<fridge> f = {
		{"toshiba",4,12.8},
		{"panasonic",6,34.6},
		{"huawei",30,67.8},
		{"samsung",5,70.8},
		{"xiaomi",7,52.8},
		{"daikin",11,27.8},
		{"casper",9,37.9},
		{"wanghao",2,12.9},
		{"yzf",7,4.7}
	};
	return f;
}
bool compare(const fridge& v1, const fridge& v2) {
	return v1.weight > v2.weight;
}
pair<int, vector<fridge>> A(const vector<fridge>& v, const int& n, double weight) {
	pair<int, vector<fridge>> result;
	for (int i = 0; i < v.size() && weight>0; i++) {
		if (v[i].weight < weight) {
			weight -= v[i].weight;
			result.second.push_back(v[i]);
			result.first++;
		}
	}
	return result;
}

pair <vector<fridge>, pair<int, double>> B(const vector<fridge>& v, const int& n, const int& area, vector<vector<double>>& dp) {
	pair<vector<fridge>, pair<int, double>> result_list_count_sumWeight;
	for (int i = 0; i <= area; i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= area; j++) {

			dp[i][j] = dp[i - 1][j];

			if (v[i - 1].area <= j) {
				dp[i][j] = max(
				               dp[i - 1][j],
				               dp[i - 1][j - v[i - 1].area] + v[i - 1].weight
				           );
			}
		}
	}

	int area_temp = area;
	for (int i = n; i > 0; i--) {

		if (dp[i][area_temp] > dp[i - 1][area_temp]) {
			result_list_count_sumWeight.second.second += v[i - 1].weight;
			area_temp -= v[i - 1].area;
			result_list_count_sumWeight.first.push_back(v[i - 1]);
		}

	}
	result_list_count_sumWeight.second.first = result_list_count_sumWeight.first.size();
	return result_list_count_sumWeight;

}
int main() {
	vector<fridge> v = create();
	int n = v.size();
	int area = 20;
	double weight = 65.7;
	cout << "n= " << n << "\tarea=" << area << "\tf= " << weight << endl;
	sort(v.begin(), v.end(), compare);
	cout << v;
	//su dung thuat toan A
	pair<int, vector<fridge>> result_A = A(v, n, weight);
	double sumweight = 0;
	for (int i = 0; i < result_A.second.size(); i++) {
		sumweight += result_A.second[i].weight;
	}
	if (sumweight == weight) {
		cout << "\nthuat toan A tim thay phuong an\n";
		cout
		        << "so luong = " << result_A.first << endl << "danh sach tu lanh duoc chon\n" << result_A.second;
	} else {
		cout << "khong co phuong an\n";
	}
	//su dung thuat toan B
	vector<vector<double>> dp(n + 1, vector<double>(area + 1));
	pair <vector<fridge>, pair<int, double>> result_B;
	result_B = B(v, n, area, dp);

	if (result_B.first.empty()) {
		cout << "\nthuat toan B khong co phuong an\n";
	} else {
		cout << "\nthuat toan B tim thay phuong an\n";
		cout << "bang phuong an\n";
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < area + 1; j++) {
				cout << left << setw(6) << dp[i][j];
			}
			cout << "\n";
		}
		cout
		        << "so luong = " << result_B.second.first << endl
		        << "tong trong luong = " << result_B.second.second << endl
		        << "danh sach tu lanh duoc chon\n" << result_B.first << endl
		        ;
		cout << "\n";
	}
	return 0;
}