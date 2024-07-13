#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
struct index{
	int first_index;
	int last_index;
	int sum_array;
};
void export_id(index id){
	cout<<id.first_index<<" "
	<<id.last_index<<" "
	<<id.sum_array<<endl; 
}
void set_id(index &id ){
    id.first_index=0;
    id.last_index=0;
    id.sum_array=0;
}
void print_array(int*, int);
void set_array(int *, int );
int algo4__day_con_dai_nhat(int *, int);
int kadane_sum_maxarray(int*, int, index& ) ;
//int* kadane_index(int *, int , index );
void export_id(index );
void set_id(index & );

int main(int argc, char const *argv[])
{
    int n;
    srand(time(NULL));
    n= rand()%10+4;
    cout<<n<<endl;
    int *a= new int[n];
    set_array(a, n);
    print_array(a, n);
    index id;
    set_id(id);
    
    cout<<algo4__day_con_dai_nhat(a, n)<<endl;
    cout<<kadane_sum_maxarray(a, n, id)<<endl;
    export_id(id);
    return 0;
}

void print_array(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    cout<<endl;
}
void set_array(int *a, int n){
    for (int i=0; i<n; i++)
    {
        a[i]= rand()%50-25;
    }
}
int algo4__day_con_dai_nhat(int *a, int n){
    int max_array= a[0], s[n];
    s[0]=a[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i-1]>0)
        {
            s[i]= s[i-1]+ s[i];
        }
        else
        {
            s[i]= a[i];
        }
        max_array = max(max_array, s[i]);
    }
    return max_array;
}
int kadane_sum_maxarray(int *a, int n, index &id){
	int sum1=0;//tính tổng liên tiếp
	int sum2=-1e5;//ghi nhận kỉ lục

	id.first_index=0;
	id.last_index =0;
	id.sum_array=sum2;
	for(int i=0; i<n; i++){
		sum1+=a[i];
		if(sum1>sum2){
			sum2= sum1;
			id.last_index= i;
			}

		if(sum1<=0){
			sum1=0;
		}
	}
    int sum2_temp=sum2;
    int j=id.last_index;
    while(sum2_temp>0){
        sum2_temp-= a[j];
        --j;
	}
	id.first_index=j+1;
	id.sum_array=sum2;
	return sum2;
}
void sum(int a){
    for
}
//int* kadane_index(int *a, int n){
//	int *index= new int[2];
	
	