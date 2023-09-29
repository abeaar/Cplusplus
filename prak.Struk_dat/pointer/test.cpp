#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan data siswa
struct Siswa {
    string nama;
    string alamat;
};

// Fungsi untuk mencari siswa berdasarkan nama dan mengubah alamatnya
void ubahAlamatSiswa(Siswa siswa[], int jumlahSiswa, string namaSiswa, string alamatBaru) {
    for (int i = 0; i < jumlahSiswa; i++) {
        if (siswa[i].nama == namaSiswa) {
            Siswa* siswaPtr = &siswa[i]; // Menggunakan pointer untuk mengakses siswa yang sesuai
            siswaPtr->alamat = alamatBaru; // Mengubah alamat siswa melalui pointer
            cout << "Alamat siswa " << namaSiswa << " berhasil diubah menjadi: " << alamatBaru << endl;
            return; // Keluar dari fungsi setelah menemukan siswa yang sesuai
        }
    }
    cout << "Siswa dengan nama " << namaSiswa << " tidak ditemukan." << endl;
}

int main() {
    Siswa siswa[3]; // Membuat array siswa dengan 3 elemen

    // Mengisi data siswa
    siswa[0].nama = "John";
    siswa[0].alamat = "Jl. A";
    siswa[1].nama = "Alice";
    siswa[1].alamat = "Jl. B";
    siswa[2].nama = "Bob";
    siswa[2].alamat = "Jl. C";

    // Panggil fungsi untuk mengubah alamat siswa
    ubahAlamatSiswa(siswa, 3, "Alice", "Jl. D");

    // Cek apakah alamat siswa berhasil diubah
    cout << "Alamat siswa Alice setelah perubahan: " << siswa[1].alamat << endl;

    return 0;
}
