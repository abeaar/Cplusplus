#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string antrian[5], stack[5];

int jmlh=0,maks=5, back=0, front=0, top=0;

bool full() {
    if (top == maks) {
        return true;
    } else {
        return false;
    }
}
bool empty() {
    if (top == 0) {
        return true;
    } else {
        return false;
    }
}

bool fullarray() {
    if (back == maks) {
        return true;
    } else {
        return false;
    }
}

bool emptyarray() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

int count(){
    if(emptyarray()){
        return 0;
    } else if (fullarray()){
        return maks;
    } else {
        return back;
    }
}
void baca(){
	if (emptyarray())
	{
		cout << "antrian kosong!!\n";
	} else {
		cout << "\n\nWaiting list\n";
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		for (int i = 0; i < maks; i++)
		{
			cout <<"| no\t\t: "<< i+1 << endl; 
			cout <<"| Nama\t\t: "<<antrian[i] << endl; 
		}
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "\n\nDone list\n";
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		for (int i = 0; i < maks; i++)
		{
			cout <<"| no\t\t: "<< i+1 << endl; 
			cout <<"| Nama\t\t: "<<stack[i] << endl; 
		}
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
    }
}

void output (){
   baca();
}

void enqueue () {
	string inputnama;
	int banyak;
	if (fullarray())
	{
		cout << "antrian penuh !!" << endl;
	} else {
		cout << "masukan jumlah pelanggan : "; cin >> banyak;
		for (int i = 0; i < banyak; i++)
		{
			cout << "input nama : "; cin >> inputnama;
			if (emptyarray()){
				antrian[0] = inputnama;
				front++;
				back++;
			} else {
				antrian[back] = inputnama;
				back++;
			}
		}
	}	
}

void push(string record){
	if (full()) {
        cout << "Data Penuh!!" << endl;
    } else {
        stack[top] = record;
        top++;
    }
}

void dequeue (){
	int i=0;
    if (emptyarray()){
        cout << "Antrian KOSONG!!\n";
    } else {
		push (antrian[i]);
        for(i = 0 ; i < back ; i++){
            antrian[i] = antrian[i+1];
        }
        back = back - 1;
    }
}



int main () {
	int menu;
	for (char back='y'; back=='y'; ) {
		system ("cls");
		cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
		cout << "|     SELAMAT DATANG DI RUMAH MAKAN Y     |"<< endl;
		cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
		cout << "| 1. lihat Antrian                        |"<< endl;
		cout << "| 2. Pesan                                |"<< endl;
		cout << "| 3. Ambil                                |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "| 4. Exit                                 |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "pilih : ";
		cin>>menu;
		switch (menu) {
			case 1:
			output();
			cout << "\nkembali ke menu ? [y/n] "; 	
			cin>>back;
			break;
			case 2:
            enqueue();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;
			case 3:
			dequeue();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

            case 4:
			back='n';
		}
	}
}