#include <iostream>

#include <iomanip>

typedef struct node* tipeptr;

using namespace std;

tipeptr awal, akhir, hapus, bantu;
int pilih, pilihsisip;

struct data1 {
    string nama;
    int harga;
};
data1 buah;

struct node {
    data1 info;
    tipeptr next;
};

void buatbaru() {
    awal = NULL;
    akhir = NULL;
}

void sisipdepanbuah(data1 IB) {
    tipeptr NB = new node;
    NB -> info = IB;
    NB -> next = awal;
    awal = NB;
    if (akhir == NULL)
        akhir = NB;
}

void sisipbelakangbuah(data1 IB) {
    tipeptr NB = new node;
    NB-> info = IB;
    NB-> next = NULL;
    if (akhir != NULL)
        akhir -> next = NB;
    akhir = NB;
    if (awal == NULL)
        awal = NB;
}

void sisiptengahbuah(data1 IB) {
    tipeptr NB = new node;
    NB -> info = IB;
    NB -> next = NULL;
    tipeptr bantu = awal;
    while (bantu -> next -> info.nama < IB.nama) {
        bantu = bantu -> next;
    }
    NB -> next = bantu -> next;
    bantu -> next = NB;
}

void cek(data1 IB){
    tipeptr NB = new node;
        NB -> info = IB;
        NB -> next = NULL;
        if (awal == NULL) {
            awal = NB;
            akhir = NB;
        } else if (IB.nama < awal -> info.nama) {
            sisipdepanbuah(IB);
        } else if (IB.nama >= akhir -> info.nama) {
            sisipbelakangbuah(IB);
        } else {
            sisiptengahbuah(IB);
        }
}

void header() {
    system("cls");
    cout << setw(3) << setfill(' ') << " ";
    cout << setw(47) << setfill('=') << "=" << endl;
    cout << setw(3) << setfill(' ') << " ";
    cout << "|     SELAMAT data1NG DI PROGRAM TOKO BUAH     |" << endl;
    cout << setw(3) << setfill(' ') << " ";
    cout << setw(47) << setfill('=') << "=" << endl;
    cout << "   Anugraha Galih Saputra" << endl << endl;
}

void sisip() {
    int banyak;
    header();
    cout << "Masukan Banyak Buah : ";
    cin >> banyak;
    for (int i = 0; i < banyak; i++) {
        header();
        cout << "Nama Buah\t: ";
        getline(cin >> ws, buah.nama);
        cout << "Harga Buah\t: ";
        cin >> buah.harga;
        cek(buah);
        system ("pause");
    }
}

void cetak() {
    int i = 0;
    tipeptr depan, bantu;

    cout << setw(47) << setfill('=') << "=" << endl;
    cout << "|";
    cout << right << setw(2) << setfill(' ') << "NO";
    cout << "|";
    cout << right << setw((22 - 4) / 2 + 4) << setfill(' ') << "Nama";
    cout << right << setw(9) << setfill(' ') << "";
    cout << "| ";
    cout << right << setw((15 - 5) / 2 + 5) << setfill(' ') << "Harga";
    cout << right << setw(7) << setfill(' ') << "";
    cout << " | ";
    cout << endl;
    cout << setw(47) << setfill('=') << "=" << endl;

    if (awal == akhir) {
        bantu = awal;
        cout << "|";
        cout << left << setw(2) << setfill(' ') << 1;
        cout << "| ";
        cout << left << setw(20) << setfill(' ') << bantu -> info.nama;
        cout << " | ";
        cout << left << setw(17) << setfill(' ') << bantu -> info.harga;
        cout << " | ";
        cout << endl;
        cout << setw(47) << setfill('=') << "=" << endl;
        cout << endl;
    } else {
        depan = awal;
        awal = akhir;
        do {
            bantu = depan;
            while (bantu -> next != akhir)
                bantu = bantu -> next;
            akhir -> next = bantu;
            akhir = bantu;
        } while (akhir != depan);

        akhir -> next = NULL;
        bantu = awal;
        while (bantu != NULL) {
            cout << "|";
            cout << left << setw(2) << setfill(' ') << i + 1;
            cout << "| ";
            cout << left << setw(20) << setfill(' ') << bantu -> info.nama;
            cout << " | ";
            cout << left << setw(17) << setfill(' ') << bantu -> info.harga;
            cout << " | ";
            cout << endl;
            bantu = bantu -> next;
            i++;
        }
        cout << setw(47) << setfill('=') << "=" << endl;
        cout << endl;
    }
    system("pause");
}

void hapusnode(string IB) {
    if (awal == NULL)
    {
        cout << "List kosong" << endl;
        return;
    }

    if (awal->info.nama == IB)
    {
        hapus = awal;
        awal = awal->next;
        delete (hapus);
        if (awal == NULL)
            akhir = NULL;
        cout<<"data1 telah dihapus"<<endl;
        return;
    }

    bantu = awal;
    while (bantu->next != NULL && bantu->next->info.nama != IB)
    {
        bantu = bantu->next;
    }
    if (bantu->next == NULL)
    {
        cout << "data1 tidak ditemukan" << endl;
        return;
    }
    hapus = bantu->next;
    bantu->next = hapus->next;
    if (hapus == akhir)
        akhir = bantu;
    delete (hapus);
    cout<<"data1 berhasil dihapus"<<endl;
    system("pause");
}

int main() {
    string menu, ulang = "y";
    while (ulang == "y") {
        header();
        cout << "Menu utama\n";
        cout << "1. Sisip Buah\n";
        cout << "2. Cetak Buah\n";
        cout << "3. Hapus Buah\n";
        cout << "0. Exit\n";
        cout << "Pilih : ";
        cin >> menu;

        if (menu == "1") {
            sisip();
        } else if (menu == "2") {
            cetak();
        } else if (menu == "3") {
            string nama;
            cout << "Nama buah yang akan dihapus : ";
            getline(cin >> ws, nama);
            hapusnode(nama);
        } else if (menu == "0") {
            ulang = "x";
        }
    }
}