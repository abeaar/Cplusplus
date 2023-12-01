#include <iostream>
#include <malloc.h>
#include <iomanip>
#define True 1
#define False 0
using namespace std;
typedef int info;
typedef struct typestack *typeptr; // Linked List untuk oprasi stack
typedef struct typestack_sampah *typeptr_sampah; // linked list untuk oprasi stack sampah
struct typestack{ // deklarasi
    info info;
    typeptr next;
};
struct typestack_sampah{ //deklarasi
    info sampah;
    typeptr_sampah next_sampah;
};
typeptr awalstack, akhirstack;
typeptr_sampah awalsampah,akhirsampah;
void buat_stack();
void buat_stack2();
int  stack_kosong();
int stack_sampah_kosong();
void push(info IB);
void sampah();
void pop();
void cetak_stack();
void cetak_sampah();

int main(){
    string pilih_menu,ulang;
    info input_sampah,input_push,input_pop;
    int jumlah,jumlah_stack=0;
    buat_stack();
    buat_stack2();
    menu:
    cout<<"Program Stack"<<endl;
    cout<<"--- Menu ---"<<endl;
    cout<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Lihat Stack"<<endl;
    cout<<"4. Tumpukan Sampah"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Pilihan Menu : ";
    cin>>pilih_menu;
    if(pilih_menu=="1"){
        system("cls");
        cout<<"--- Menu Push ---\n";
        cout<<"Jumlah Angka Yang Ingin di Push : ";
        cin>>jumlah;
        for(int i=0;i<jumlah;i++){
            cout<<"push ke- "<<i+1<<endl;
            cout<<"Masukan Angka : ";
            cin>>input_push;
            push(input_push);
            jumlah_stack++; // menghitung jumlah stack
        }
        cout <<"Push Telah Berhasil\n";
        cout<<endl;
			cout<<"Apakah anda Ingin Kembali Ke Menu ? (y/n) : ";
			cin>>ulang;
		if (ulang=="y" || ulang=="Y"){
			system("cls");
			goto menu;
	    }
	    else {
		    return (0);
    	}
    }
    else if(pilih_menu=="2"){
        system("cls");
        cout<<"--- Menu Pop ---\n";
        if (stack_kosong()){ 
        cout << "Stack kosong !\n";
        goto ulang;
        }
        cout <<"Berapa Angka yang ingin di pop : ";
        cin>>input_pop;
        if(input_pop>jumlah_stack){ // jika jumlah pop yang diinginkan lebih banyak dari jumlah angka pada stack maka akan muncul error message
            cout<<"Jumlah Stack Kurang dari jumlah yang anda Inputkan\n";
            cout<<"Harap Mengulang\n";
            goto ulang;
        }
        else {
            cout<<"Sebelum Pop\n";
            cetak_stack();  
            cout<<endl;
            for (int i=0; i<input_pop; i++){
                sampah();
                pop();
                jumlah_stack--; // menghitung jumlah stack
            }
            cout<<"Sesudah Pop\n";
            cetak_stack();
            cout <<"Pop Telah Berhasil\n";
            cout<<endl;
        }
        ulang:
        cout<<"Apakah anda Ingin Kembali Ke Menu ? (y/n) : ";
        cin>>ulang;
		if (ulang=="y" || ulang=="Y"){
			system("cls");
			goto menu;
	    }
	    else {
		    return (0);
    	}
    }
    else if(pilih_menu=="3"){
        system("cls");
        cout<<"--- Menu Cetak Stack ---\n";
        if (stack_kosong()){  // jika stack kosong
        cout << "Stack kosong !\n";
        goto ulang;
        }
        cetak_stack();
        cout<<endl;
        cout<<endl;
		cout<<"Apakah anda Ingin Kembali Ke Menu ? (y/n) : ";
		cin>>ulang;
        if (ulang=="y" || ulang=="Y"){
			system("cls");
			goto menu;
	    }
	    else {
		    return (0);
    	}
    }
    else if(pilih_menu=="4"){
        system("cls");
        cout<<"--- Tumpukan Sampah Stack ---\n";
        if (stack_sampah_kosong()){ 
        cout << "Tumpukan Sampah Kosong !\n";
        goto ulang;
        }
        cetak_sampah();
        cout<<endl;
        cout<<endl;
		cout<<"Apakah anda Ingin Kembali Ke Menu ? (y/n) : ";
		cin>>ulang;
		if (ulang=="y" || ulang=="Y"){
			system("cls");
			goto menu;
	    }
	    else {
		    return (0);
    	}
    }
    else if(pilih_menu=="5"){
        cout<<"Terima Kasih Telah Menggunakan Program\n";
        return 0;
    }
    else {
        cout<<"Maaf Input Tidak Ditemukan Harap Mengulang\n";
        system("pause");
        system ("cls");
        goto menu;
    }
    
}

void buat_stack(){ 
    typeptr NS;
    NS=NULL;
    awalstack=NS;
    akhirstack=NS; 
    }

void buat_stack2(){ 
    typeptr_sampah NS;
    NS=NULL;
    awalsampah=NS;
    akhirsampah=NS; 
    }

int stack_kosong(){ 
    if(awalstack==NULL){
        return(True);
    }
    else{
        return(False); 
    }
}

int stack_sampah_kosong(){ 
    if(awalsampah==NULL){
        return(True);
    }
    else{
        return(False); 
    }
}


void push(info IB){ 
    typeptr NS;
    NS=(typestack *) malloc(sizeof(typestack));
    NS->info=IB;
    if (awalstack==NULL)
        awalstack=NS;
    else
        akhirstack->next=NS;
        akhirstack=NS;
        akhirstack->next=NULL; 
    }

void pop(){ 
    typeptr hapus, bantu;
    bantu=awalstack;
    hapus=akhirstack;
    if (hapus==awalstack)
        awalstack=NULL;
    else{ 
        while(bantu->next->next!=NULL){
    bantu=bantu->next;
    }
    akhirstack=bantu;
    akhirstack->next=NULL; }
    free(hapus); 
}

void cetak_stack(){ 
    typeptr depan,bantu;
    if(awalstack==akhirstack){
        cout<<awalstack->info <<endl;
    } 
    else { 
        depan=awalstack;
        awalstack=akhirstack;
        do { 
            bantu=depan;
            while (bantu->next!=akhirstack){
            bantu=bantu->next;
            }
            akhirstack->next=bantu;
            akhirstack=bantu;
        }
        while (akhirstack!=depan);
        akhirstack->next=NULL;
        bantu=awalstack;
        while(bantu!=NULL){ 
            cout << "" << bantu->info << endl;
            bantu=bantu->next; 
        }
    }
}

void cetak_sampah(){ 
    typeptr_sampah depan,bantu;
    if(awalsampah==akhirsampah){
        cout<<awalsampah->sampah <<endl;
    } 
    else { 
        depan=awalsampah;
        awalsampah=akhirsampah;
        do { 
            bantu=depan;
            while (bantu->next_sampah!=akhirsampah){
            bantu=bantu->next_sampah;
            }
            akhirsampah->next_sampah=bantu;
            akhirsampah=bantu;
        }
        while (akhirsampah!=depan);
        akhirsampah->next_sampah=NULL;
        bantu=awalsampah;
        while(bantu!=NULL){ 
            cout << "" << bantu->sampah << endl;
            bantu=bantu->next_sampah; 
        }
    }
}

void sampah(){
    typeptr_sampah NS;
    NS=(typestack_sampah *) malloc(sizeof(typestack_sampah)); 
    NS->sampah=akhirstack->info; // nilai NS akan sama dengan Nilai akhirstack
    if (awalsampah==NULL)
         awalsampah=NS;
    else
        akhirsampah->next_sampah=NS;
        akhirsampah=NS;
        akhirsampah->next_sampah=NULL;
        }