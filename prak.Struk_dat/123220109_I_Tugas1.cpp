#include <iostream>
#include <iomanip>
#include <string>
#include <malloc.h>
#define true 1
#define false 0

using namespace std;

struct mahasiswa {
	string nama;
	string alamat;
	string NIM;
};

mahasiswa mhs[5];

void input (int *jmlh ) {
	int banyak=0;
	cout << setw (43) << setfill ('=') << ' ' << endl;
	cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI MENU INPUT" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
	cout << setw (43) << setfill ('=') << ' ' << endl;
	cout << "| banyak data : "; cin>>banyak;

	for (int i=*jmlh; i < *jmlh+banyak; i++) {
		cout << "|" << setw (41) << setfill ('-') << '|' << endl;
		cout << "| NO :  "<< i+1 << endl;
		cout << "| nama \t\t: ";
		getline(cin >> ws, mhs[i].nama);
		cout << "| alamat\t: ";
		cin>>mhs[i].alamat;
		cout << "| NIM \t\t: ";
		cin>>mhs[i].NIM;
	}
		cout << "|" << setw (41) << setfill ('-') << '|' << endl;
// jmlh disini akan mempengaruhi nilai count di int main
	*jmlh=*jmlh+banyak;
}

void output (int total) {
	cout << setw (44) << setfill ('=') << ' ' << endl;
	cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI MENU OUTPUT" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
	cout << setw (44) << setfill ('=') << ' ' << endl;

	for (int i=0; i < total; i++) {
		cout <<"| nama \t\t: "<< mhs[i].nama << endl;
		cout <<"| NIM \t\t: "<< mhs[i].NIM << endl;
		cout <<"| alamat \t: "<< mhs[i].alamat << endl;
	cout << setw (43) << setfill ('-') << '|' << endl;
	}
	cout << "jumlah MHS : " << total << endl;
}

//function pointer untuk mengubah alamat baru 
void update(string *lama){
	string baru;
	cout << "\nAlamat baru : ";
	cin >> baru;
	*lama = baru;
}

void search (int jmlh ) {
	string cari;
	int pilih;

	cout << setw (44) << setfill ('=') << ' ' << endl;
	cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI MENU UPDATE" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
	cout << setw (44) << setfill ('=') << ' ' << endl;
	cout << "| Pilih metode pencarian                  |\n";
	cout << "| 1. NAMA                                 |\n";
	cout << "| 2. NIM                                  |\n";
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
	cout << "| Pilih :";
	cin>>pilih;

	if (pilih==1) {
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "| nama yang dicari ? : ";
		getline(cin >> ws, cari);
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		bool found=false;
		int s=0;;
		while (s < jmlh) {
			if (cari == mhs[s].nama) {
				cout <<"| " << mhs[s].NIM<< endl;
				cout <<"| " << mhs[s].nama << endl;
				cout <<"| " << mhs[s].alamat << endl;
				found=true;
				cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
				update (&mhs[s].alamat);
			}
			s++;
		}
		cout << endl;
		if ( !found && s==jmlh) {
			cout << "Data Tidak Ditemukan ";
		}
	}
	else {
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "| NIM yang dicari ? : "; cin >> cari;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		bool found=false;
		int s=0;
		while (s < jmlh) {
			if (cari.compare(mhs[s].NIM)==0) {
				cout <<"| " << mhs[s].NIM<< endl;
				cout <<"| " << mhs[s].nama << endl;
				cout <<"| " << mhs[s].alamat << endl;
				found=true;
				cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
				update (&mhs[s].alamat);
			}
			s++;
		}
		cout << endl;
		if ( !found && s==jmlh) {
			cout << "Data Tidak Ditemukan ";
		}
	}
}

int main () {
	int count;
	char back;
	int menu;
	for (back='y'; back=='y'; ) {
		system ("cls");
		cout << setw (44) << setfill ('=') << ' ' << endl;
		cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI PRAKTIKUM 1" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
		cout << setw (44) << setfill ('=') << ' ' << endl;
		cout << "| 1. input                                |"<< endl;
		cout << "| 2. output                               |"<< endl;
		cout << "| 3. update                               |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "| 4. exit                                 |"<< endl;
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
			output(count);
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

			case 3:
				system ("cls");
			search(count);
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

			case 4:
				system ("cls");
			back='n';
			cout << setw (53) << setfill ('=') << ' ' << endl;
			cout << "|" << setw (6) <<  setfill (' ') << ' ' << "TERIMAKASIH SUDAH MENCOBA PROGRAM SAYA" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
			cout << setw (53) << setfill ('=') << ' ' << endl;

		}
	}
}