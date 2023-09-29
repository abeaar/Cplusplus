#include <iostream>

using namespace std; 

void input ();
void output ();
void penjumlahan(int *x){
    *x = *x + 2;
}

struct mahasiswa {
    string name[4] ;
    int nilai[5] ;
    char kelas [3] ;
};

mahasiswa mhs;

int main (){
system ("cls");

//input ();
output ();

int x = 2;
cout << x << endl;
penjumlahan(&x);
cout << x;
}


void input () {
cout << "=== LIST DATA MHS ===\n";
for (int i = 0; i < 3; i++)
{
cin >> mhs.name[i];
cin >> mhs.nilai[i];
cin >> mhs.kelas[i];
}

for (int i = 0; i < 3; i++)
{
cout << mhs.name[i] << " "<< mhs.nilai[i] << " " << mhs.kelas[i] << endl;
}

}

void output () {

}

