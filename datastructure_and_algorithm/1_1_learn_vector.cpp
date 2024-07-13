#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    int n; cin>>n;
    vector <int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }
    for (auto &&x : v)
    {
        cout<<x<<" ";
    }
    // cout<<v[2];
    
    return 0;
}
