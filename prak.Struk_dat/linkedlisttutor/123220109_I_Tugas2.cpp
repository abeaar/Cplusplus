#include <iostream>
#include <iomanip>
#include <malloc.h>
typedef struct node* tipeptr;
#define true 1
#define false 0
using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode {
     typeinfo info; typeptr next;
};
typeptr awal, akhir;

void buatlistbaru();
void sisipnode(typeinfo IB);
void hapusnode(typeinfo IH);
void bacamaju();
void bacamundur();
int listkosong();
void input(int *jmlh), search(), output(), hapus();

int main () {
	int count;
	char back;
	int menu;
	for (back='y'; back=='y'; ) {
		system ("cls");
		cout << setw (44) << setfill ('=') << ' ' << endl;
		cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI PRAKTIKUM 2" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
		cout << setw (44) << setfill ('=') << ' ' << endl;
		cout << "| 1. input                                |"<< endl;
		cout << "| 2. search                               |"<< endl;
		cout << "| 3. output                               |"<< endl;
		cout << "| 4. erase                                |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "| 5. exit                                 |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "pilih : ";
		cin>>menu;
		switch (menu) {
			case 1:
				system ("cls");
			input(&count);
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

			case 2:
				system ("cls");
			search();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

			case 3:
				system ("cls");
			output();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

			case 4:
				system ("cls");
			hapus();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

			case 5:
				system ("cls");
			back='n';
			cout << setw (53) << setfill ('=') << ' ' << endl;
			cout << "|" << setw (6) <<  setfill (' ') << ' ' << "TERIMAKASIH SUDAH MENCOBA PROGRAM SAYA" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
			cout << setw (53) << setfill ('=') << ' ' << endl;

		}
	}
}
void buatlistbaru()
{
  typeptr list;
  list=NULL;
  awal=list;
  akhir=list;
}


void input(int *jmlh){
	int banyak=0, num;
	cout << setw (43) << setfill ('=') << ' ' << endl;
	cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI MENU INPUT" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
	cout << setw (43) << setfill ('=') << ' ' << endl;
	cout << "| banyak data : "; cin>>banyak;
		for (int i = 0; i < *jmlh+banyak; i++)
		{
			cout << "| NO " <<i+1<< " : ";
			cin >> num;
			sisipnode(num);
		}
	cout << "\n| List data : ";
	bacamaju();
	cout << endl << endl;
}

void sisipnode(typeinfo IB)
{ typeptr NB, bantu;
  NB=(typenode *) malloc(sizeof(typenode));
  NB->info=IB;
  NB->next=NULL;
  if (listkosong())
  { awal=NB;
	 akhir=NB; }
  else if (IB <= awal->info)       // Sisip di depan
	 { NB->next=awal;
		awal=NB; }
  else
	 { bantu=awal;
		while (bantu->next!=NULL && IB > bantu->next->info)
			  bantu=bantu->next;
		NB->next=bantu->next;  // Sisip di tengah atau di belakang
		bantu->next=NB;
		if (IB>akhir->info)
			akhir=NB;
	 }
}

void bacamaju()
{
  typeptr bantu;
  bantu=awal;
  while (bantu!=NULL)
  {
	 cout << " [" << bantu->info << "]  ";
	 bantu=bantu->next;
}
}

int listkosong()
{ if(awal==NULL)
	 return(true);
  else
	 return(false); 
}

void search(){
    int cari;
    int i=0;
    typeptr bantu=awal;
	cout << setw (44) << setfill ('=') << ' ' << endl;
	cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI MENU CARI" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
	cout << setw (44) << setfill ('=') << ' ' << endl;
    cout << "| Input Angka yang Dicari : "; cin >>cari;
	cout << endl;
    while (bantu!=NULL){
        i++;
        if (bantu->info == cari){
            cout << "| Angka ada di list ke-"<<i<< " : "<<bantu->info;
			cout << endl;
        }
        bantu=bantu->next;
    }
	if ( bantu == NULL) {
			cout << "\n| Data Tidak Ditemukan |\n";
		}	
}

void output (){
	cout << setw (44) << setfill ('=') << ' ' << endl;
	cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI MENU OUTPUT" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
	cout << setw (44) << setfill ('=') << ' ' << endl;
	cout << "| List angka : \n\n";
	bacamaju();
	cout << endl;
}

void hapus(){
	cout << setw (44) << setfill ('=') << ' ' << endl;
	cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI MENU HAPUS" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
	cout << setw (44) << setfill ('=') << ' ' << endl;
    int angka;
	cout << "| list lama : " ; bacamaju();
    cout << "\n\n| angka yang ingin dihapus : ";
    cin >> angka; 
	hapusnode(angka);
	cout << "| list baru : \n";
	cout << "|\n";
	cout << "| "; bacamaju();
	cout << endl;
}
void hapusnode(typeinfo IH)
{ typeptr hapus, bantu;
  if (listkosong())
	 cout << "List masih kosong";
  else if (awal->info==IH)
  { hapus=awal;                     // Hapus di awal
	 awal=hapus->next;
	 free(hapus); }
  else
  { bantu=awal;
	 while (bantu->next->next!=NULL && IH!=bantu->next->info)
		 bantu=bantu->next;
	 if (IH==bantu->next->info)
		 { hapus=bantu->next;
			if (hapus==akhir)             // Hapus di akhir
			  { akhir=bantu;
				 akhir->next=NULL; }
			else
				 bantu->next=hapus->next;   // Hapus di tengah
			free(hapus);
		  }
	 else
		cout << "Node tidak ditemukan!\n";  }
}
