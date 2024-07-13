#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

 struct student
 {
    char last_name[30];
    char first_name[30];
    char fullname[60];
    int year;
    friend ostream& operator<<(ostream& out, student st){
      out
      <<left<<setw(30)<<st.first_name
      <<left<<setw(30)<<st.last_name
      <<left<<setw(60)<<st.fullname
      <<endl;
      return out;
    }
 };
 void create_list(student *L, int n){
 	for(int i=0; i<n; i++){

    }
 }
void setname(char name1[], char name2[], student &st){
    strcpy(st.first_name, name1);
    strcpy(st.last_name, name2);
    strcat(strcat(strcat(st.fullname, st.first_name)," ") , st.last_name);
}
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    char* first_name[]={"Nguyen Thi", "Tran Ngoc", "Hoang Ngoc",
    "Dao Thi", "Nguyen Thi"};
    char* last_name[]={"Anh", "Hong", "Thao", "Hang", "Linh",
    "Quan", "Hao", "Huan"};
    int i= rand()%5;
    int j= rand()%4;
    student st;
    // st.name= first_name[i]+" "+ last_name[j];
    // cout<<st.name;
    // stringstream ss;
    // ss<<first_name[i];
    // ss<<" ";
    // ss<<last_name[j];
    // char* name_1[]= first_name[i]+ last_name[j];
   //  char name_1[60];
   //  strcpy(name_1, first_name[i]);
    // ss.getline(name_1,35,',');
   //  cout<<name_1;
   setname(first_name[i], last_name[j], st);
   cout<<st;
   system("pause");
    return 0;
}
