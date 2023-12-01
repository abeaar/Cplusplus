#include <iostream>

#include <iomanip>
#include <string>
#include <stdio.h>

typedef struct node *tipeptr;

using namespace std;

tipeptr head, tail, hapus, bantu;

struct dt {
    string nama;
    int harga;
};
dt buah;

struct node {
    dt info;
    tipeptr next;
};

void buatbaru() {
    head = new node;
    tail = new node;
    head -> info.nama = "AAAAAA";
    tail -> info.nama = "zzzzzz";
    head -> info.harga = -100000;
    tail -> info.harga = 100000;
    head -> next = tail;
    tail -> next = NULL;
}

void header() {
    system("cls");
    cout << setw(3) << setfill(' ') << " ";
    cout << setw(47) << setfill('=') << "=" << endl;
    cout << setw(3) << setfill(' ') << " ";
    cout << "|     SELAMAT DATANG DI PROGRAM TOKO BUAH     |" << endl;
    cout << setw(3) << setfill(' ') << " ";
    cout << setw(47) << setfill('=') << "=" << endl;
    cout << "   Anugraha Galih Saputra" << endl << endl;
}

void input(dt Buahh){
    tipeptr NE, bantu;
    NE = new node;
    NE->info = Buahh;
    bantu = head;
    while(Buahh.harga > bantu->next->info.harga)
    bantu = bantu->next;
    NE->next = bantu->next;
    bantu->next = NE;
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
        system ("pause");
        input(buah);
    }
}

void cetak() {
    int i = 0;
    tipeptr bantu;
    bantu=head->next;
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
    while (bantu != tail) {
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
    system("pause");
}

void hapusnode(string IB) {
    if (head == NULL)
    {
        cout << "List kosong" << endl;
        return;
    }

    if (head->info.nama == IB)
    {
        hapus = head;
        head = head->next;
        delete (hapus);
        if (head == NULL)
            tail = NULL;
        cout<<"Data telah dihapus"<<endl;
        return;
    }

    bantu = head;
    while (bantu->next != NULL && bantu->next->info.nama != IB)
    {
        bantu = bantu->next;
    }
    if (bantu->next == NULL)
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    hapus = bantu->next;
    bantu->next = hapus->next;
    if (hapus == tail)
        tail = bantu;
    delete (hapus);
    cout<<"Data berhasil dihapus"<<endl;
    system("pause");
}

int main() {
    string menu, ulang = "y";
    buatbaru();
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
    system("pause");
}