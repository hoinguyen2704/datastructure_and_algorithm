#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;

struct student
{
    char Name[20];
    char Last_Name[20];
    int year;
    friend ostream& operator<<(ostream& os, student st){
        os
        <<left<<setw(21)<<st.Last_Name
        <<left<<setw(21)<<st.Name
        <<left<<setw(5)<<st.year
        <<endl;
        return os;
    }
};
student create_student(const char Name[], const char Last_Name[], int year){
    student st;
    strcpy(st.Name, Name);
    strcpy(st.Last_Name, Last_Name);
    st.year= year;
    return st;
}
student* create_list(student *L, int n){
    L[0]=create_student("Thao", "Tran Thanh", 2003);
    L[1]=create_student("Ly", "Dang Quynh", 2003);
    L[2]=create_student("Hoi", "Nguyen Tien", 2003);
    L[3]=create_student("Ly", "Nguyen Huong", 2004);
    L[4]=create_student("Anh", "Nguyen Thi", 2000);
    L[5]=create_student("Hong", "Nguyen Thi", 2004);
    return L;
}
void print_list(student *L, int n){
	for(int i=0; i< n; i++){
		cout<<L[i];
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{

    // srand(time(NULL));
    // int n= rand()%10+5;
    // cout<<n;
    int n=6;
    student *L= new student;
    L= create_list(L, n);
    print_list(L, n);
    return 0;
}
