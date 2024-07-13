#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
/* push_back(giá trị nhập)-> nhập giá trị vào cuối
- .pop_back(): xóa phần tử ở vị trí cuối cùng
begin(): trỏ đến phần tử đầu tiên
rend(): trước phần tử đầu tiên
end(): con trỏ đến sau phần tử cuối cùng
rbegin(): phần tử cuối cùng
con trỏ iterator có thể sử dụng các toán tử
-.> thay thế vector <datatype> name = v.begin();
-> thay bằng auto name=v.begin();
- nếu phần tử có chỉ số x => con trỏ đến: v.begin() +x 
- .clear(): xóa toàn bộ phần tử trong vector
- .insert(iterator_trỏ đến vị trí, giá trị chèn)
- .erase(iterator trỏ đến vị trí): xóa phần tử ở vị trí truyền vào
- .assign(số phần tử, giá trị): gán các phần tử trong vector có sùng 1 giá trị
- .resize(n) thay đổi lại kích thước về n phần tử
- 
*/

using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    ifstream in;
    in.open("in.txt",std::ios_base::in);
    stringstream ss;
    ss<<in.rdbuf();
    // while (!in.eof())
    // {
    //     ll num;
    //     in>>num;
    //     ss<<num;
    // }
    int n; ss>>n;
    vector <int> v;
    for (int i = 0; i < n; ++i)
    {
        ll num;
        ss>>num;
        v.push_back(num);
    }
    // v.push_back(12);
    // v.push_back(2);
    // v.push_back(10);
    // v.push_back(950);
    cout<<v.size()<<endl;
    // for (auto &&x : v)
    // {
    //     x+=1000;
    // }

    for (auto &&x : v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    v.insert(v.begin()+2, 2,500);
    auto it=v.end()-1;
    // it+=5;
    *it = 15;
    v.erase(v.begin()+10);

    // cout<<*it<<endl;
    vector <int> ::iterator it2;//độ phức tạo o(n)

  for ( it2 = v.begin(); it2 != v.end(); ++it2)
  {
    cout<<*it2<<" ";
  }
    cout<<endl;
    cout<<v[4]<<endl;


    system("pause");
    return 0;
}


