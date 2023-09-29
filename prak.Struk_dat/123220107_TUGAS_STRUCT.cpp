#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
	int jml;
	char nama [30]; 
	int hrg;
	} keranjang ; 
keranjang buah[30];

bool out=false;
void input(int *count);
void output(int bnyk);
void cari(int byk);
void ulang();

int main(){
if (out) return 0; 
int x;
static int count = 0;
cout<<"Data Nama Buah\n";
cout<<"1. Input nama buah\n";
cout<<"2. Lihat Nama Buah\n";
cout<<"3. Cari Nama Buah\n";
cout<<"0. Keluar\n";
cout<<"Pilihan : ";cin>>x;
	switch (x){
		case 1: input(&count); main(); break;	
		case 2: output(count); main();break;
		case 3: cari(count); main();break;
		case 0: return 0;break;
		default : cout<<"\nERROR,Input anda salah\n\n";main();break;
		}

}

void input(int *count){
	int i,a;
	cout<<"\nBanyak data : ";cin>>a;
	for(i=*count;i<*count+a;i++){
	cout<<"\nNama Buah : ";cin.ignore();cin.getline(buah[i].nama,30);
	cout<<"Harga buah : ";cin>>buah[i].hrg;
	cout<<"Jumlah buah : ";cin>>buah[i].jml;
	}
	*count=*count+a;
	ulang();
	}
	
void ulang(){
	char y;
	cout<<"\nKembali ke Menu? (y/n)";cin>>y;
	if (y=='y'){cout<<"\n";}else if (y=='n') {out=true; cout<<"\n";} else {cout<<"\nInput Salah\n"; ulang();}
	}

void output(int bnyk){
	int i;
	cout<<"\nOUTPUT DATA\n";
	cout<<"Banyak data : "<<bnyk<<"\n\n";
	for(i=0;i<bnyk;i++){
	cout<<"Nama Buah : "<<buah[i].nama;
	cout<<"\nHarga buah : "<<buah[i].hrg;
	cout<<"\nJumlah buah : "<<buah[i].jml;
	cout<<"\n\n";
	}
	ulang();
	}
	
void cari(int byk){
	char fruit[30];
	int i=0; bool found=false;
	cout<<"Masukkan nama buah : ";cin.ignore();cin.getline(fruit,30);
	while(i<byk&& !found){
		if (strcmp(buah[i].nama,fruit)==0) found=true;
		else i++;
		}
	if(found) {cout<<"\nData ditemukan!!\n";
		cout<<"\nNama Buah : "<<buah[i].nama;
		cout<<"\nHarga buah : "<<buah[i].hrg;
		cout<<"\nJumlah buah : "<<buah[i].jml;
		cout<<"\n";
		} else cout<<"Data tidak ditemukan!!\n"; 
	ulang();
	
	
	
	}
