#include<iostream>

using namespace std;

int maksimal = 5;
string buku[5];
int top = 0;

bool full() {
    if (top == maksimal) {
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

void push(string data) {
    if (full()) {
        cout << "Data Penuh!!" << endl;
    } else {
        buku[top] = data;
        top++;
    }
}

void pop() {
    if (empty()) {
        cout << "Data KOSONG!!";
    } else {
        buku[top - 1] = "";
        top--;
    }
}

void peek(int posisi) {
    int index = top;
    if (empty()) {
        cout << "Data Kosong!!";
    } else {
        for (int i = 0; i < posisi; i++) {
            index--;
        }
        cout << "data Posisi ke-" << posisi << " : " << buku[index] << endl;
    }
}

void change(string data, int posisi) {
    if (empty()) {
        cout << "Data Kosong!!";
    } else {
        int index = top;
        for (int i = 0; i < posisi; i++) {
            index--;
        }
        buku[index] = data;
    }
}

void display() {
    if (empty()) {
        cout << "Data Kosong!!";
        cout << endl;
    } else {

        cout << "Data Stak : \n";
        for (int i = maksimal - 1; i >= 0; i--) {
            if (buku[i] != "") {
                cout << "Buku : " << buku[i] << endl;
            }
        }
        cout << endl;
    }
}

int count() {
    if (empty()) {
        return 0;
    } else {
        return top;
    }
}

void destroy() {
    for (int i = 0; i < top; i++) {
        buku[i] = "";
    }
    top = 0;
}


// linklist

struct databarang {
    string namabarang;
    int hargabarang;

    databarang * next, * prev;
};

databarang * head, * tail, * hapus, * newnode, * cur;
int maksimalL = 5;

int countlinklist() {
    if (head == NULL) {
        return 0;
    } else {
        int banyak = 0;
        cur = head;
        while ( cur != NULL ){
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

void pushL ( string namabarang, int hargabarang){
    if(countlinklist() == maksimalL){
        cout << "Stack FULL!!";
    } else {
        if(countlinklist() == 0){
            head = new databarang();
            head -> namabarang = namabarang;
            head -> hargabarang = hargabarang;
            head-> prev = NULL;
            head-> next = NULL;
            tail = head;
        }
    }
}

int main() {
    system("cls");
    push("Matematika");
    display();
    push("Pemrogaman Web");
    push("Struktur data");
    push("Riset Operasi");
    pop();
    display();
    push("Riset Operasi");
    display();
    peek(3);
    cout << endl;
    cout << count() << endl;
    cout << endl;
    change("Database system", 2);
    display();
    destroy();
    display();
}