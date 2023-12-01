#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct node
{
    string nama,stat;
    int nim, semester;
    node *next, *prev;
};  
node *bantu, *hapus, *NB, *first, *last;

void buatbaru() {
    first = NULL;
    last = NULL;
}
bool listkosong() {
	return (first==NULL);
}
void sisip(string namanode, int nimnode){
    NB = new node();
    NB->nama = namanode;
    NB->nim = nimnode;
    NB->prev = NULL;
    NB->next = NULL;
    if(listkosong()){
        last = NB;
        first = NB;
    } else if (nimnode <= first->nim){
        NB->next=first;
        first->prev = NB;
        first = NB;
    } else {
        for (bantu = first; bantu->next != NULL && nimnode >= bantu->next->nim;){
        bantu=bantu->next;
        }

        if (bantu==last){
            last=NB;
        }
        else {
            NB->next = bantu->next;
            NB->prev = bantu;
            bantu->next->prev=NB;
            bantu->next=NB;
        }
    }
}
void input (int *jmlh) {
    int banyak=0;
    string inputnama;
    int inputnim;
    cout << "masukan jmlh mahasiswa : "; cin >> banyak;
    for (int i = *jmlh; i < *jmlh+banyak; i++)
    {
        cout << "\nNIM Mhs\t\t: "; cin >> inputnim;
        cout << "Nama Mhs\t: "; 
        getline(cin >> ws, inputnama);
        sisip(inputnama, inputnim);
    }
}
void baca(){
    string status;
    int i=0, angkatan, outputsemester, tahun =24;
    node* bantu = first;
  while (bantu != NULL)
  {
    cout << "NO "<<i+1 << endl;
    cout <<"Nama\t\t: "<<bantu->nama << endl; 
    cout <<"Nim\t\t: "<<bantu->nim << endl; 
        angkatan = (bantu->nim/10000) % 100;
        bantu->semester = (tahun-angkatan)*2-1;  
    cout <<"Semester\t: " << bantu->semester << endl;
        if (bantu->semester<7)
        {
           status = "Bukan Prioritas";
        }else {
           status = "Prioritas";
        }
    cout << "Status\t\t: "<< status<< endl;
    cout << endl;
	cout << setw (44) << setfill ('-') << ' ' << endl;
    bantu=bantu->next; 
    i++;
  }    
}
void output (){
    baca();
}
void del ()
{   
    int infohapus;
    cout << "Masukkan NIM yang ingin dihapus: ";
    cin >> infohapus;
    if (listkosong())
    {
        cout << "List kosong, tidak ada data yang bisa dihapus." << endl;
        return;
    }
    if (first->nim == infohapus)
    {
        hapus = first;
        first = first->next;
        delete hapus;
        if (first != NULL)
        {
            first->prev = NULL;
        }
    }
    else if (last->nim == infohapus)
    {
        hapus = last;
        last = last->prev;
        delete hapus;
        if (last != NULL)
        {
            last->next = NULL;
        }
    }
    else
    {
        bantu = first;
        while (bantu != NULL && bantu->nim != infohapus)
        {
            bantu = bantu->next;
        }

        if (bantu == NULL)
        {
            cout << "Data dengan NIM " << infohapus << " tidak ditemukan." << endl;
            return;
        }
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
        delete bantu;
    }

    cout << "Data dengan NIM " << infohapus << " berhasil dihapus." << endl;
}

int main () {
    buatbaru();
	int count=0;
	char back;
	int menu;
	for (back='y'; back=='y'; ) {
		system ("cls");
		cout << "| 1. input                                |"<< endl;
		cout << "| 2. Output                               |"<< endl;
		cout << "| 3. Hapus                               |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "| 4. exit                                 |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "pilih : ";
		cin>>menu;
		switch (menu) {
			case 1:
            input(&count);
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;
			case 2:
			output();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

            case 3:
            del();
            cout << "\nkembali ke menu ? [y/n] ";
            cin >> back;
            break;

            case 4:
			back='n';
		}
	}
}