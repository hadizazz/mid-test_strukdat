/*
Nama Program	:
Nama			: Hadiza Cahya Firdaus
Npm				: 140810180042
Tanggal buat	: 24 April 2019
Deskripsi		:
*/

#include<iostream>
#include<iomanip>
using namespace std;
 
struct ElemtList{
	char nama[20];
	char namaOrang[20];
	int jumlah;
	int harga;
	ElemtList* next; 
};

typedef ElemtList* pointer;
typedef pointer list;

void createList(list& First){
	First=NULL;
}

void createElemt(pointer& pBaru){
	pBaru = new ElemtList;
	cout<<"Nama Pesanan \t: ";cin.getline(pBaru->nama,20);
	cout<<"Jumlah Pesanan \t: ";cin>>pBaru->jumlah;
	cout<<"Harga satuan \t: ";cin>>pBaru->harga;
	pBaru->next=NULL;
} 

void insertLast(list& First, pointer pBaru){
	pointer last; 
	if(First==NULL){
	  First=pBaru;
	}
 	else{
	last=First;
	while (last->next!=NULL){
	last=last->next;
	}
	  last->next=pBaru;
 	}
}

void sort(list& First,pointer pBantu){
	int tukar,temp;
	pointer terbesar,pNull=NULL;
	if(First==NULL){
	  return;
	}
	do{
	tukar=0;
	pBantu=First;
	while(pBantu->next!=NULL){
	   if(pBantu->jumlah > pBantu->next->jumlah){
	    swap(pBantu->jumlah,pBantu->next->jumlah);
	    tukar=1;
	   }
	   pBantu=pBantu->next;
	}
	  pNull=pBantu;
	}while(tukar); 
}

void swap(pointer a,pointer b){
	int temp =a->;
	a->info=b->info;
	b->info=temp;
}

void traversal(list First,pointer pBantu){
	int i=1;
	if(First==NULL){
		cout<<"List kosong"<<endl;
 	}
	else{
		pBantu=First;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<setw(2)<<"No"<<setw(15)<<"Nama Makanan"<<setw(11)<<"Harga"<<endl;
		cout<<"---------------------------------------------"<<endl;
		do{
		cout<<setw(1)<<i++<<setw(14)<<pBantu->nama<<setw(10)<<pBantu->harga<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		pBantu=pBantu->next; 
		}while(pBantu!=NULL);
	}
}

int main(){
	int n;
	list a;
	pointer b;
	createList(a);
	cout<<"Masukkan banyak pesanan = ";cin>>n;
for(int i=0;i<n;i++){
	createElemt(b);
	insertLast(a,b);
	}
	sort(a,b);
	traversal(a);
}
