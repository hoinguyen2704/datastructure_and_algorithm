#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int n;
int *a=new int;
int partition(int *, int , int );
void create_array(){
    for (int i = 0; i < n; i++)
    {
        a[i]= rand()%21-10;
    }
}
void print_array(){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
// phan hoach lomuto _ tac gia 
void quick_sort(int *a, int p, int r){
    if (p<r)
    {
        int q=partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}
int partition(int *a, int p, int r){
    int x=a[r];
    int i=p-1;
    for (int j = p; j < r; j++)
    {
        if (a[j]<=x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    n= rand()%10+10;
    cout<<n<<endl;
    create_array();
    print_array();
    quick_sort(a,0,n-1);
    print_array();
    return 0;
}
