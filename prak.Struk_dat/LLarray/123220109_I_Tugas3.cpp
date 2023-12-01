/*Program List Dengan Array*/
#include <iostream>
#include <iomanip>
#define max 12
#define true 1
#define false 0
using namespace std;
typedef struct {int info;	 int next;	}typenode;
typenode elemen[max];
int list,akhirlist,kosong,akhirkosong;
int listkosong();
void buatlist();
void sisipnode(int IB);
void hapusnode(int IH);
void cetaklist();

int main()
{ buatlist();
  cetaklist();
  int angka;
  int count;
	char back;
	int menu;
	for (back='y'; back=='y'; ) {
		system ("cls");
		cout << setw (44) << setfill ('=') << ' ' << endl;
		cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI PRAKTIKUM 2" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
		cout << setw (44) << setfill ('=') << ' ' << endl;
		cout << "| 1. cetak list                           |"<< endl;
		cout << "| 2. sisip node                           |"<< endl;
		cout << "| 3. hapus node                           |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "| 4. exit                                 |"<< endl;
		cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
		cout << "pilih : ";
		cin>>menu;
		switch (menu) {
			case 1:
			cetaklist(); 
			cout << "\n\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

			case 2:
      sisipnode(angka);
			cout << "\nkembali ke menu ? [y/n] ";
			cin>>back;
			break;

			case 3:
			hapusnode(angka);
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

void buatlist()
{ list=5;
kosong=3;
akhirlist=10;
akhirkosong=4;
elemen[1].info=25;	elemen[1].next=8;
elemen[2].info=0 ;	elemen[2].next=9;
elemen[3].info=0; 	elemen[3].next=6;
elemen[4].info=0; 	elemen[4].next=0;
elemen[5].info=10;	elemen[5].next=7;
elemen[6].info=0; 	elemen[6].next=2;
elemen[7].info=15;	elemen[7].next=1;
elemen[8].info=40;	elemen[8].next=10;
elemen[9].info=0;	   elemen[9].next=4;
elemen[10].info=60;	elemen[10].next=0;
}
int listkosong()
{ if (list==0)
	  return(true);
  else
	  return(false);
}
void sisipnode(int IB)
{ int listbaru,k,m,n,x;
	cout << setw (43) << setfill ('=') << ' ' << endl;
	cout << "|" << setw (6) <<  setfill (' ') << ' ' << "SELAMAT DATANG DI MENU SISIP" << setw (6) <<  setfill (' ') << ' ' << "|" << endl ;
	cout << setw (43) << setfill ('=') << ' ' << endl;
  cout << " Masukan angka : "; cin >> IB;
  if(IB<elemen[list].info)
//-------------------------- sisip di awal
  {listbaru=kosong;
	kosong=elemen[kosong].next;
	elemen[listbaru].info=IB;
	elemen[listbaru].next=list;
	list=listbaru;
  }

else
  //-------------------------sisip di akhir
  if(IB>elemen[akhirlist].info)
  {listbaru=kosong;
	kosong=elemen[kosong].next;
	elemen[listbaru].info=IB;
	elemen[listbaru].next=0;
	elemen[akhirlist].next=listbaru;
	akhirlist=listbaru;
  }
  else
  //--------------------------sisip di tengah
  {n=list;
	x=elemen[n].info;
	while(IB>x)
	{m=n;
	 n=elemen[n].next;
	 x=elemen[n].info;
	}
	k=elemen[kosong].next;
	elemen[m].next=kosong;
	elemen[kosong].info=IB;
	elemen[kosong].next=n;
	kosong=k;
	}
  
  }
void cetaklist()
{ int n,m;
  n=list;
  m=kosong;
  cout << "isi list : \n";
do{
  cout << elemen[n].info << " ";
  n=elemen[n].next;
  }while (elemen[n].next!=0);
  cout << " "<< elemen[akhirlist].info <<endl ;
  cout << "\nIndex tempat-tempat kosong: \n";
  do
  {cout << m << " ";
	m=elemen[m].next;
  }while(elemen[m].next!=0);
  cout << " " << akhirkosong;
}

void hapusnode(int IH)
{
    int listbaru, k;
    cout << setw(43) << setfill('=') << ' ' << endl;
    cout << "|" << setw(6) << setfill(' ') << ' ' << "SELAMAT DATANG DI MENU HAPUS" << setw(6) << setfill(' ') << ' ' << "|" << endl;
    cout << setw(43) << setfill('=') << ' ' << endl;
    cout << " Masukan angka : ";
    cin >> IH;

    bool found = false;

    //------------------------ hapus di awal
    if (IH == elemen[list].info)
    {
        listbaru = elemen[list].next;
        k = kosong;
        kosong = list;
        list = listbaru;
        elemen[kosong].next = k;
        found = true;
    }
    //------------------hapus di akhir
    else if (IH == elemen[akhirlist].info)
    {
        elemen[akhirlist].next = kosong;
        kosong = akhirlist;
        elemen[akhirlist].info = 0;
        for (int i = 1; i <= 10; i++)
        {
            if (elemen[i].next == akhirlist)
            {
                akhirlist = i;
                elemen[akhirlist].next = 0;
                found = true;
                break;
            }
        }
    }
    //------------------hapus di tengah
    else
    {
        int index, after, before;
        bool check = false;

        for (index = list; index != 0;)
        {
            if (elemen[index].info == IH)
            {
                check = true;
                after = index;
            }
            index = elemen[index].next;
        }

        if (check) // Jika ditemukan
        {
            check = false;
            for (index = list; check == false;)
            {
                if (elemen[index].next == after)
                {
                    check = true;
                    before = index;
                }
                index = elemen[index].next;
            }

            elemen[before].next = elemen[after].next;
            elemen[after].next = kosong;
            kosong = after;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Bilangan tidak ditemukan." << endl;
    }
}


  