#include <iostream>
using namespace std;
#define MAXChar 100

struct character {
    string nama[MAXChar];
    int bounty[MAXChar];
};

int main(){
    int percobaan;
    int elemen = 0;
    int pilihan, index;
    string usernamelogin, passwordlogin;
    string username = "Fariz";
    string password = "032";
    percobaan = 3;
    character karakter;

    cout << "Selamat Datang Di One Piece Pirate List" << endl;
    cout << "Silahkan Login Terlebih Dahulu" << endl;

    while (percobaan > 0){
        cout << "Masukkan Username: ";
        cin >> usernamelogin;
        cout << "Masukkan Password: ";
        cin >> passwordlogin;
        
        if (username == usernamelogin && password == passwordlogin){
            cout << "Login berhasil" << endl;
            break;
        } else {
            percobaan -= 1;
            if (percobaan > 0){
                cout << "Username Atau Password Salah, Silahkan Coba Lagi" << endl;
            } else {
                cout << "Anda Telah Mencoba Login Sebanyak 3 Kali, Program Akan Dihentikan" << endl;
                return 0;} 
            }
    }

    do {
        cout<<R"(
============================
Pilihan Menu :
1. Tampilkan Semua Data
2. Tambahkan Data
3. Ubah Data
4. Hapus Data
5. Keluar Program
============================
)"<<endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilihan; 
        
        switch (pilihan) {
            case 1:
            if (elemen == 0) {
                cout << "Belum Ada Data Yang Ditambahkan" << endl;
            } else {
                cout << "Daftar Karakter" << endl;
                for (int i = 0; i < elemen; i++) {
                    cout << i + 1 << ". Nama: " << karakter.nama[i] << "\n   Bounty: " << karakter.bounty[i] << endl;
                }
            }
            break;
            case 2:
            if (elemen < MAXChar) {
                cout << "Tambahkan Nama Karakter: ";
                cin >> karakter.nama[elemen];
                cout << "Berikan Bounty Karakter(Masukkan Dalam Bentuk Angka!): ";
                cin >> karakter.bounty[elemen];
                elemen++;
                cout << "Karakter Berhasil Ditambahkan" << endl;
            } else {
                cout << "Kapasitas Penuh! Tidak Dapat Menambah Data." << endl;
            }
            break;
            case 3:
                if (elemen == 0) {
                    cout << "Belum Ada Data Yang Ditambahkan." << endl;
                } else {
                    for (int i = 0; i < elemen; i++) {
                        cout << i + 1 << ". Nama: " << karakter.nama[i] << "\n   Bounty: " << karakter.bounty[i] << endl;
                    }
                    cout << "Masukkan Nomor Data Yang Ingin Diubah: ";
                    cin >> index;
                    if (index > 0 && index <= elemen) {
                        cout << "Masukkan Nama Baru: ";
                        cin >> karakter.nama[index - 1];
                        cout << "Masukkan Bounty Baru(Masukkan Dalam Bentuk Angka!): ";
                        cin >> karakter.bounty[index - 1];
                        cout << "Data Telah Berhasil Dirubah" << endl;
                    } else {
                        cout << "Nomor Data Tidak Valid" << endl;
                    }
                }
            break;
            case 4:
                if (elemen == 0) {
                    cout << "Belum Ada Data Yang Ditambahkan" << endl;
                } else {
                    for (int i = 0; i < elemen; i++) {
                        cout << i + 1 << ". Nama: " << karakter.nama[i] << "\n   Bounty: " << karakter.bounty[i] << endl;
                    }
                    cout << "Masukkan Nomor Data Yang Ingin Dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= elemen) {
                        for (int i = index - 1; i < elemen - 1; i++) {
                            karakter.nama[i] = karakter.nama[i + 1];
                            karakter.bounty[i] = karakter.bounty[i + 1];
                        }
                        elemen--;
                        cout << "Data Telah Dihapus" << endl;
                    } else {
                        cout << "Nomor Data Tidak Valid" << endl;
                    }
                }
            break;
            case 5:
            cout << "Terimakasih Telah Menggunakan One Piece Pirate List. Program Akan Dihentikan." << endl;
            break;
            default:
            cout << "Pilihan Tidak Valid" << endl;
            break;
            }

    } while (pilihan != 5);

    return 0;
}