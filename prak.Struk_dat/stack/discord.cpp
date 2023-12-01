#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

struct dataStack
{
    string info;
    int jumlah;

    // pointer
    dataStack *prev, *next;
};

dataStack *top, *bottom, *del, *newNode, *bantu;

void createStack();
int countStack();
void push(string IB, int JB);
void pop();
void printStack();
void clearr();
void changeData(string IC);

int main()
{
    createStack();
    int pilih, num, tambah;
    string str;
    char kembali = 'y';
    do
    {
        system("cls");
        printStack();
        cout << endl;
        cout << "[1] Catat Kardus       (Menambahkan Data Barang)" << endl;
        cout << "[2] Ambil Kardus       (Mengambil Data Barang)" << endl;
        cout << "[3] Buang Semua Kardus (Buang Semua Data Barang)" << endl;
        cout << "[4] Rombak Kardus      (Merombak Isi Barang dalam Kardus)" << endl;
        cout << "[5] Exit" << endl;
        cout << "[ TOP ] = " << countStack() << endl;
        cout << "\nChoose >> ";
        cin >> pilih;
        cout<<endl;

        switch (pilih)
        {
        case 1:
			cout<<"== Catat Kardus =="<<endl;
			cout<<"banyak kardus yang ditambahkan : ";
			cin>>tambah;
			for(int g = 1; g<= tambah; g++)
			{
			cout<<"\nData kardus #"<<g<<endl;
            cout << "  Isi Kardus    : ";
            cin.ignore();
            getline(cin, str);
           // cin >> str;
            cout<< "  Jumlah Barang : ";
            cin >> num;
            push(str,num);
			}
			cout<<"\n["<<tambah<<"] Kardus Berhasil Ditambahkan"; 
			getch();
            break;

        case 2:
            pop();
            cout << " Telah diambil ]" << endl;
            getch();
            break;

        case 3:
            clearr();
            cout << "[SEMUA KARDUS DIBUANG!]" << endl;
            getch();
            break;

        case 4:
            cout << "Cari Barang : ";
            cin.ignore();
            getline(cin, str);
          //  cin >> str;

            changeData(str);
            getch();
            break;

        case 5:
            exit(0);
            break;

        default:
            break;
        }
    } while (kembali == 'y');

    return 0;
}

void createStack()
{
    top = NULL;
    bottom = NULL;
}

int countStack()
{
    if (top == NULL)
        return 0;
    else
    {
        int banyak = 0;
        bantu = top;
        while (bantu != NULL)
        {
            bantu = bantu->prev;
            ++banyak;
        }
        return banyak;
    }
}

void push(string IB, int JB)
{
    newNode = new dataStack();
    newNode->info = IB;
    newNode->jumlah = JB;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (countStack() == 0)
    {
        top = newNode;
        bottom = newNode;
    }
    else
    {
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }
}

void pop()
{
    if (countStack() == 0)
        printf("Tidak ada Tumpukan Kardus!");
    else
    {
        del = top;
        cout<<"[ "<<del->info;
        if (top->prev != NULL)
        {
        top = top->prev;
        delete del;
        top->next = NULL;
		}
        else
        createStack();
        
    }
}

void printStack()
{
    bantu = top;

    cout << "                 Stack : ";
    cout << "\n========================================" << endl;
    while (bantu != NULL)
    {
        cout << "        [ ";
        cout <<left<<setw(15) << bantu->info<<", ";
        cout <<left<<setw(3) <<bantu->jumlah << " ]     " << endl;
        bantu = bantu->prev;
    }
    cout << "========================================" << endl;
}

void clearr()
{
    bantu = top;
    while (bantu != NULL)
    {
        del = bantu;
        bantu = bantu->prev;
        delete del;
    }
    top = NULL;
    bottom = NULL;
}

void changeData(string IC)
{
    if (countStack() == 0)
        printf("Tidak ada tumpukan kardus !");
    else
    {
		string temp0;
        int temp1;
        bantu = top;
        while (bantu->prev != NULL && bantu->info != IC)
            bantu = bantu->prev;

        if (bantu->info == IC)
        {
            cout << "Isi Baru    : ";
            cin >> temp0;
            cout << "Jumlah     : ";
            cin >> temp1;
            
            bantu->info = temp0;
            bantu->jumlah = temp1;
            cout << "[Kardus Telah Berhasil Dirombak]" << endl;
        }
        else
            printf("[TIdak ada Kardus yang dicari]");
    }
}