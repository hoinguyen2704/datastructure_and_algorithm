#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
int n;
int k;
struct machine
{
    string name;
    string color;
    double weight;
    friend ostream& operator<<(ostream& os,machine ms){
    os
    <<left<<setw(20)<<ms.name
    <<left<<setw(8)<<ms.color
    <<left<<setw(4)<<ms.weight
    <<endl;
    return os;
}
};

void print_list(machine mc[]){
    for(int i=0;i<k;i++){
    cout<<mc[i];
    }   
}
int main(int argc, char const *argv[])
{
    n=10;
    k=7;
    machine list_machines[k];
    list_machines[0]={"laptops", "black", 10.6};
    list_machines[1]={"personal computer","while", 9.2};
    list_machines[2]={"may giat","red", 7.4};
    list_machines[3]={"may xay sinh to","blue", 10.3};
    list_machines[4]={"may vat quan ao","green", 8.5};
    list_machines[5]={"kjbejrg","puple", 10.6};
    list_machines[6]={"lllololo","unknow", 17.5};
    print_list(list_machines);
    system("pause");
    return 0;
}
