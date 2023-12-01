#include <iostream>
using namespace std;

int maks = 5, front = 0, back = 0;

string antrian[5];

bool fullarray() {
    if (back == maks) {
        return true;
    } else {
        return false;
    }
}

bool emptyarray() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void tambahantri(string data) {
    if (fullarray()) {
        cout << "Antrian Penuh!!" << endl;
    } else {
        if (emptyarray()) {
            antrian[0] = data;
            front++;
            back++;
        } else {
            antrian[back] = data;
            back++;
        }
    }
}

void viewarray() {
    if (emptyarray()) {
        cout << "Antrian KOSONG!!\n";
    } else {
        cout << "Data Antrian : \n";
        for (int i = 0; i < maks; i++) {
            if (antrian[i] != "") {
                cout << i + 1 << ". " << antrian[i] << endl;
            } else {
                cout << i + 1 << ".(kosong)\n";
            }
        }
    }
}

void dequeuearray(){
    if (emptyarray()){
        cout << "Antrian KOSONG!!\n";
    } else {
        for(int i = 0 ; i < back ; i++){
            antrian[i] = antrian[i+1];
        }
        back = back - 1;
    }
}

int count(){
    if(emptyarray()){
        return 0;
    } else if (fullarray()){
        return maks;
    } else {
        return back;
    }
}

void destroy(){
    if(emptyarray()){
        cout << "Antrian KOSONG!!";
    } else {
        for(int i = 0 ; i < maks ; i++){
            antrian[i] = "";
        }
    }
}

int main() {
    system("cls");
    viewarray();
    tambahantri("Sigit");
    viewarray();
    cout << endl;
    tambahantri("Anu");
    tambahantri("Asep");
    viewarray();
    dequeuearray();
    viewarray();
    cout << endl;
    tambahantri("Asep");
    tambahantri("Wati");
    tambahantri("Jono");
    tambahantri("Hai");
    tambahantri("Anu");
    viewarray();
    dequeuearray();
    viewarray();
    cout << endl;
    system("pause");
    system("cls");
    destroy();
    viewarray();

}