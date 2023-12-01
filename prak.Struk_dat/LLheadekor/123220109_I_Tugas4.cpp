#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct node
{
    string nama,stat;
    int nim, semester;
    node *next;
};  
node *first, *last, *bantu, *hapus, *NB, *head, *tail;
void buatbaru() {
    head = new node;
    tail = new node;
    tail -> nim = 0;
    head -> nim = 999999999;
    head -> next = tail;
    tail -> next = NULL;
}
bool listkosong()
{
    if (head->next == tail)
        return (1);
    else
        return (0);
}
void sisip(string namanode, int nimnode){
    NB = new node();
    bantu = new node();
    NB->nama=namanode;
    NB->nim=nimnode;    
    bantu = head;
    while (nimnode < bantu->next->nim){
    bantu = bantu->next;
    }
    NB-> next = bantu -> next;
    bantu->next = NB;       
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
    bantu = new node();
    bantu=head->next;
  while (bantu != tail)
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
void hapusnode(){
    hapus = new node;
    bantu = new node;
    int IH;
    if (listkosong())
    cout << "List masih kosong";
    else{
    baca();
    cout << "NIM yang ingin dihapus : "; cin >> IH;
    for (bantu = head; bantu->next != tail && IH != bantu->next->nim;){
        bantu = bantu->next;
        }
        if (IH == bantu->next->nim)
        {
            hapus = bantu->next;
            bantu->next = hapus->next;
            free(hapus);
            cout << "data berhasil di hapus\n\n";
        } else {
            cout << "Node tidak ada\n\n";
        }
    system("pause");
    system("cls");
    baca();
    }
    }
void cariNode(){
    int IC;
    string namabaru;
    int nimbaru;
    bantu = new node;
    cout << "NIM yang ingin diupdate : "; cin >> IC;
    for (bantu = head; bantu->next != tail && IC != bantu->nim;)
    {
        bantu=bantu->next;
    }
        cout << "nim baru : "; cin >> nimbaru;
        bantu->nim = nimbaru;
        cout << "Nama baru : "; cin >> namabaru;
        bantu->nama = namabaru;
}

void putarlinkedlist(){ //baca mundur
    first = head;
    head = tail;
    do
    {
        bantu = first;
        while (bantu->next != tail)
            bantu = bantu->next;
            tail->next = bantu;
            tail = bantu;
    } while (tail != first);
    tail->next = NULL;
}

int main () {
    int infohapus;
    buatbaru();
	int count=0;
	char back;
	int menu;
	for (back='y'; back=='y'; ) {
		system ("cls");
		cout << "| 1. input                                |"<< endl;
		cout << "| 2. Output                               |"<< endl;
		cout << "| 3. Update                               |"<< endl;
		cout << "| 4. Hapus                                |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "| 5. exit                                 |"<< endl;
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
			cariNode();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;
			case 4:
			hapusnode();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;
			case 5:
            putarlinkedlist();
            output();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
            break;
            case 6:
			back='n';
		}
	}
}