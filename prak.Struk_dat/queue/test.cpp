#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct node
{
    string nama;
    int no;
    node *next, *prev;
};  
struct stack
{
    string nama;
    int no;
    stack *next, *prev;
};

stack *Sbantu, *Shapus, *SNB, *Sfirst, *Slast;
node *bantu, *hapus, *NB, *first, *last;
int jmlh=1;

void createStack()
{
 Slast = NULL;
 Sfirst = NULL;
}

void createQueue() {
    first = NULL;
    last = first;
}
bool queuekosong()
{
    if (first == NULL)
        return true;
    else
        return false;
}

void baca(){
int i=0;
bantu = first;
Sbantu = Sfirst;
    cout << "\n\nWaiting List\n";
	cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
  while (bantu != NULL)
  {
    cout <<"| no\t\t: "<< bantu->no << endl; 
    cout <<"| Nama\t\t: "<<bantu->nama << endl; 
    cout << endl;
    bantu=bantu->next; 
    i++;
  } 
	cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
  cout << endl<< endl;   

    cout << "Done\n";
	cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
  while (Sbantu != NULL)
  {
    cout <<"| no\t\t: "<< Sbantu->no << endl; 
    cout <<"| Nama\t\t: "<<Sbantu->nama << endl; 
    cout << endl;
    Sbantu=Sbantu->next; 
    i++;
  }    
	cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
}
void output (){
    baca();
}

void sisip(string namanode, int antreannode){
    NB = new node();
    NB->nama = namanode;
    NB->no = antreannode;
    if (first==NULL)
    {
        first = NB;
    } else {
        last->next = NB;
    } 
    last = NB;
    last->next = NULL;
}

void enqueue () {
    int banyak=0, inputantrean;
    string inputnama;
    cout << "masukan jmlh pelanggan : "; cin >> banyak;
    for (int i = 1; i<= banyak; i++)
    {
        inputantrean = jmlh;
        cout << "Nama Mhs\t: "; 
        getline(cin >> ws, inputnama);
        sisip(inputnama, inputantrean);
        jmlh++;
    }
}

int countStack()
{
 if (Slast == NULL)
 return 0;
 else
 {
 int banyak = 0;
 Sbantu = Slast;
 while (Sbantu != NULL)
 {
 Sbantu = Sbantu->prev;
 ++banyak;
 }
 return banyak;
 }
}

void push(string namanode, int antreannode){
    SNB = new stack();
    SNB->nama = namanode;
    SNB->no = antreannode;
    SNB->next = NULL;
    SNB->prev = NULL;
    if (countStack() == 0)
    {
    Slast = SNB;
    Sfirst = SNB;
    }
    else
    {
    Slast->next = SNB;
    SNB->prev = Slast;
    Slast = SNB;
    }
}

void dequeue (){
    if (queuekosong())
    {
        cout << "Queue masih kosong !";
    }
    else
    {
        hapus = first;
        first = hapus->next;
        free(hapus);
        cout << "Dequeue berhasil !";
    }
    }

int main () {
    
    createStack();
    createQueue();
	char back;
	int menu;
	for (back='y'; back=='y'; ) {
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
            push(first->nama, first->no);
			dequeue();
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

            case 4:
			back='n';
		}
	}
}
