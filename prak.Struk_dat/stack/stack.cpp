#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

struct dataStack {
    string info;
    int ID;
    // pointer
    dataStack *prev,
    *next;
} ;
struct UseStack {
    string info;
    int ID;
    // pointer
    UseStack *prev,
    *next;
};
dataStack *top,*bottom,*del,*newNode,*bantu;
UseStack *usetop,*usebottom,*usedel,*usenewNode,*usebantu;
void createStack() {
    top=NULL;
    bottom=NULL;
}

void createStack1() {
    usetop=NULL;
    usebottom=NULL;
}

int countStack() {
    if (top==NULL) return 0;
    else {
        int banyak=0;
        bantu=top;
        while (bantu !=NULL) {
            bantu=bantu->prev;
            ++banyak;
        }
        return banyak;
    }
}

int countStack1() {
    if (usetop==NULL) return 0;
    else {
        int banyak=0;
        usebantu=usetop;
        while (usebantu !=NULL) {
            usebantu=usebantu->prev;
            ++banyak;
        }
        return banyak;
    }
}

void push(string IB, int JB) {
    newNode=new dataStack();
    newNode->info=IB;
    newNode->ID=JB;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (countStack()==0) {
        top=newNode;
        bottom=newNode;
    }
    else {
        top->next=newNode;
        newNode->prev=top;
        top=newNode;
    }
}

void usepush(string IB, int JB) {
    usenewNode=new UseStack();
    usenewNode->info=IB;
    usenewNode->ID=JB;
    usenewNode->next=NULL;
    usenewNode->prev=NULL;
    cout << usenewNode->info;
    if (countStack1()==0) {
        usetop=usenewNode;
        usebottom=usenewNode;
    }
    else {
        usetop->next=usenewNode;
        usenewNode->prev=usetop;
        usetop=usenewNode;
    }
}

void pop() {
    if (countStack()==0) {
        cout << "Tidak ada Tumpukan P3K!"<< endl;
    } else {
        del=top;
        cout << "[ "<< del->info;
        if (top->prev !=NULL) {
            top=top->prev;
            delete del;
            top->next=NULL;
        }
        else {
            delete del;
            createStack();
        }
    }
}

void printStack() {
    bantu=top;
    cout << " Stack : ";
    cout << "\n========================================"<< endl;
    while (bantu !=NULL) {
        cout << " [ ";
        cout <<left<<setw(15) << bantu->info<<", ";
        cout <<left<<setw(3) <<bantu->ID << " ] "<< endl;
        bantu=bantu->prev;
    }
    cout << "========================================"<< endl;
    cout << " Sampah Stack : ";
    cout << "\n========================================"<< endl;
    usebantu=usetop;
    while (usebantu !=NULL) {
        cout << " [ ";
        cout <<left<<setw(15) << usebantu->info<<", ";
        cout <<left<<setw(3) <<usebantu->ID << " ] "<< endl;
        usebantu=usebantu->prev;
    }
    cout << "========================================"<< endl;
}
int main() {
    createStack();
    createStack1();
    int pilih,
    num,
    tambah;
    string str;
    char kembali='y';
    do {
        system("cls");
        printStack();
        cout << endl;
        cout << "1. Catat P3K (Menambahkan P3K)"<< endl;
        cout << "2. Ambil P3K (Mengambil P3K)"<< endl;
        cout << "3. Exit"<< endl;
        cout << "[ TOP ] = "<< countStack() << endl;
        cout << "\n Pilih : ";
        cin>>pilih;
        cout<<endl;
        switch (pilih) {
            case 1:
                cout<<"== Catat P3K =="<<endl;
            cout<<"banyak P3K yang ditambahkan : ";
            cin>>tambah;

            for(int g=1; g<=tambah; g++) {
                cout<<"\nData P3K #"<<g<<endl;
                cout << " Isi P3K : ";
                cin.ignore();
                getline(cin, str);
                cout<< " ID P3K : ";
                cin>>num;
                push(str, num);
            }
            cout<<"\n["<<tambah<<"] P3K Berhasil Ditambahkan";
            getch();
            break;

            case 2 : if (countStack()==0) {
                cout << "Tumpukan P3K kosong. Tidak dapat mengambil P3K."<< endl;
            }
            else {
                cout << top->info << top->ID;
                usepush(top->info, top->ID);
                pop();
                cout << " Telah diambil ]"<< endl;
            }
            getch();
            ;
            break;
            case 3: exit(0);
            break;
            default: break;
        }
    }

    while (kembali=='y');
    return 0;
}