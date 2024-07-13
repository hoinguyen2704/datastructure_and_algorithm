#include <bits/stdc++.h>
using namespace std;
struct nhanvien {
	char hodem[30];
	char ten[10];
	char gioitinh[5];
	char mnv[10];
	float hesoluong;
	friend istream& operator>>(istream &in, nhanvien &nv) {
		cout<<"ma nhan vien: ";
		fflush(stdin);
		in.getline(nv.mnv,10);
		cout<<"ho dem: ";
		fflush(stdin);
		in.getline(nv.hodem,30);
		cout<<"ten: ";
		fflush(stdin);
		in.getline(nv.ten,10);
		cout<<"gioi tinh: ";
		fflush(stdin);
		in.getline(nv.gioitinh,5);
		cout<<"he so luong: ";
		in>>nv.hesoluong;
		return in;
	}
	friend ostream& operator<<(ostream &out, nhanvien nv) {
		out
		        <<left<<setw(10)<<nv.mnv
		        <<left<<setw(30)<<nv.hodem
		        <<left<<setw(10)<<nv.ten
		        <<left<<setw(5)<<nv.gioitinh
		        <<left<<setw(5)<<nv.hesoluong
		        <<endl;
		return out;
	}
};
struct node {
	nhanvien infor;
	node* next;
};

typedef node* tro;
tro L;
tro create(tro &L) {
	L=NULL;
	return L;
}
int empty(tro L) {
	return L==NULL;
}
nhanvien input(    char hodem[30],
                   char ten[10],
                   char gioitinh[5],
                   char mnv[10],
                   float hesoluong) {
	nhanvien nv;
	strcpy(nv.mnv,mnv);
	strcpy(nv.hodem,hodem);
	strcpy(nv.ten,ten);
	strcpy(nv.gioitinh,gioitinh);
	nv.hesoluong=hesoluong;
	return nv;
}

void add_list(tro &L) {
	nhanvien nv;
	tro q=L;
	int n;
	cout<<"nhap so luong phan tu: ";
	cin>>n;
	for (int i = 0; i < n; i++) {
		cout<<"nhap nhan vien thu: "<<i+1<<endl;
		cin>>nv;
		tro p= new node;
		p->infor=nv;
		p->next=NULL;
		if (empty(L)) {
			L=p;
		} else {
			q->next=p;
		}
		q=p;
	}
}
void display_list(tro L) {
	if (empty(L)) {
		cout<<"danh sach rong!!!!\n";
	} else {
		cout
		        <<left<<setw(5)<<"STT"
		        <<left<<setw(10)<<"MNV"
		        <<left<<setw(30)<<"ho dem"
		        <<left<<setw(10)<<"ten"
		        <<left<<setw(5)<<"GT"
		        <<left<<setw(5)<<"hs lg"
		        <<endl;
		int i=0;
		while (L!=NULL) {
			cout
			        <<left<<setw(5)<<++i;
			cout<<L->infor;
			L=L->next;
		}
	}
}
tro del_max(tro &L) {
	if (empty(L)) {
		cout<<"danh sach rong: \n";
		return L;
	}

	tro temp_max=new node;
	temp_max->infor=L->infor;
	tro q=L->next;
find_max:
	while (q!=NULL) {
		if (q->infor.hesoluong >= temp_max->infor.hesoluong) {
			temp_max=q;
		}
		q=q->next;
	}
del_max:
	if (L->infor.hesoluong==temp_max->infor.hesoluong) {
		tro temp=L;
		L=L->next;
		free(temp);
	} else {
		q=L;
		while (q!=NULL) {
			if (q->next->infor.hesoluong==temp_max->infor.hesoluong) {
				tro temp=q->next;
				q->next=q->next->next;
				free(temp);
			}
			q=q->next;
		}
	}
	return L;
}
tro insert_sort(tro &L) {

	tro sorted=NULL;
	while (L!=NULL) {
		tro current=L;
		L=L->next;
		if (sorted==NULL || current->infor.hesoluong <= sorted->infor.hesoluong) {
			current->next=sorted;
			sorted=current;
		} else {
			tro temp=sorted;
			while (temp->next!=NULL && current->infor.hesoluong > temp->next->infor.hesoluong) {
				temp=temp->next;
			}
			current->next=temp->next;
			temp->next=current;
		}
	}
	L=sorted;

	//     tro q= temp1;
	//     temp1=temp1->next;
	//     tro temp2=L;
	//     if (q->infor.hesoluong < L->infor.hesoluong)
	//     {
	//         q->next=L->next;
	//         L->next=q;
	//     }
	//     else
	//     {
	//      while (temp2!=NULL && temp2->next->infor.hesoluong < q->infor.hesoluong)
	//     {
	//         temp2=temp2->next;
	//     }
	//     q->next=temp2->next;
	//     temp2->next=q;
	//     }
	return L;
}
tro insert_sort(tro &L, const int n) {
	tro sorted=NULL;
	while (L!=NULL) {
		tro current=L;
		L=L->next;
		if (sorted==NULL|| current->infor.hesoluong >= sorted->infor.hesoluong) {
			current->next=sorted;
			sorted=current;
		} else {
			tro temp=sorted;
			while (temp->next!=NULL && temp->next->infor.hesoluong > current->infor.hesoluong) {
				temp=temp->next;
			}
			current->next=temp->next;
			temp->next=current;
		}
	}
	L=sorted;
	return L;
}
tro search_mnv(tro L) {
	char mnv[10];
	cout<<"nhap ma nhan vien can tim: ";
	fflush(stdin);
	cin.getline(mnv, 10);
	while (L!=nullptr) {
		if (strcmp(L->infor.mnv,mnv)==0) {
			cout<<L->infor;
			return L;
		}
		L=L->next;
	}
	cout<<"nhan vien khong ton tai\n";
	return L;
}
tro search_mnv(tro L, int n) {
	while (L!=nullptr) {
		if (strcmp(L->infor.mnv,"nv003")==0) {
			cout<<L->infor;
			return L;
		}
		L=L->next;
	}
	cout<<"nhan vien khong ton tai\n";
	return L;
}
void del(tro &L) {
	tro q=L;
	int k;
	cout<<"xoa vi tri thu k= ";
	cin>>k;
	if (k==0) {
		cout<<"khong the xoa\n";
	}
	if (k==1) {
		L=L->next;
	} else if (k==2) {
		L->next=L->next->next;
	} else if (k>2) {
		while (k>2) {
			k-=1;
			q=q->next;
		}
		q->next=q->next->next;
	}
}
int main(int argc, char const *argv[]) {
start:
	cout<<"\n\tMENU\n"
	    <<"1: create list\n"
	    <<"2: empty list\n"
	    <<"3: add list\n"
	    <<"4: display list\n"
	    <<"5: delete max\n"
	    <<"6: insert sort \n"
	    <<"7: insert sort reverse \n"
	    <<"8: search mnv \n"
	    <<"9: search mnv sv003 \n"
	    <<"10: del sv k \n"
	    <<endl;
	int n;
	cin>>n;
	switch (n) {
		case 1:
			tro L;
			create (L);
			break;
		case 2:
			if (empty(L)) {
				cout<<"danh sach rong\n";
			} else {
				cout<<"danh sach khong rong\n";
			}
			break;
		case 3:
			add_list(L);
			break;
		case 4:
			display_list(L);
			break;
		case 5:
			del_max(L);
			break;
		case 6:
			insert_sort(L);
			break;
		case 7:
			insert_sort(L,1);
			break;
		case 8:
			search_mnv(L);
			break;
		case 9:
			search_mnv(L,3);
			break;
		case 10:
			del(L);
			break;
		default:
			goto start;
			break;
	}
	goto start;
	return 0;
}
