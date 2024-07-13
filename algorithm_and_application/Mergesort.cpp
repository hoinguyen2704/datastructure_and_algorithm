#include <iostream>
#include <cstdlib>
#include <ctime>

void set_array(int* , int );
void print_array(int*, int);
void merge_sort(int *, int , int );
void merge_array(int *, int , int , int );
using namespace std;
int main(){
	srand(time(NULL));// để seed ngẫu nhiên theo thời gian
	int n;
	n=rand()%10+10;

	cout<<n<<endl<<"day ban dau"<<endl;//khởi tạo mảng
	int *array= new int(n);
	set_array(array, n);
	print_array(array, n);

	cout<<"day sap xep tang"<<endl;
	merge_sort(array, 0, n-1);
	print_array(array, n);
	return 0;
}
void set_array(int *array, int n){
	for (int i = 0; i < n; i++)
	{
		array[i]= rand()%30-15;
	}
}
void print_array(int *array, int n){
	for (int i = 0; i < n; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void merge_array(int *array, int l, int m, int r){
	int i, j;
	int n1= m-l+1;
	int n2= r-m;
	int R[n2], L[n1];
	for (i = 0; i < n1; i++)
	{
		L[i]= array[l+i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j]=array[m+1+j];
	}
	 i=0;
	 j=0;
	int count=l;
	while (i<n1 && j< n2)
	{
		if (L[i]<R[j])
		{
			array[count]= L[i];
			i++;
		}
		else
		{
			array[count]= R[j];
			j++;
		}
		count++;
	}
	while (i<n1){
		array[count]= L[i];
		i++; count++;
	}
	while (j<n2)
	{
		array[count]= R[j];
		j++, count++;
	}
}
void merge_sort(int *array, int l, int r){
	if (l<r)
	{
	int m= l + (r-l)/2;
	merge_sort(array,l, m);
	merge_sort(array, m+1, r);
	merge_array(array, l, m , r);
	}
}