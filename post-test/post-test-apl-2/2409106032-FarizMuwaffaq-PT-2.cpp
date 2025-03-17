#include <iostream>
using namespace std;
#define MAXChar 100
#define Desc 2

int main(){
    int percobaan;
    int elemen = 0;
    int pilihan, index;
    string usernamelogin, passwordlogin;
    string username = "Fariz";
    string password = "032";
    string character[MAXChar][Desc];
    percobaan = 3;

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
1. Tampilkan Data
2. Tampilkan Semua Data
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
                    cout << i + 1 << ". Nama: " << character[i][0] << "\n   Bounty: " << character[i][1] << endl;
                }
            }
            break;
            case 2:
            if (elemen < MAXChar) {
                cout << "Tambahkan Nama Karakter: ";
                cin >> character[elemen][0];
                cout << "Berikan Bounty Character: ";
                cin >> character[elemen][1];
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
                        cout << i + 1 << ". Nama: " << character[i][0] << "\n   Bounty: " << character[i][1] << endl;
                    }
                    cout << "Masukkan Nomor Data Yang Ingin Diubah: ";
                    cin >> index;
                    if (index > 0 && index <= elemen) {
                        cout << "Masukkan Nama Baru: ";
                        cin >> character[index - 1][0];
                        cout << "Masukkan Bounty Baru: ";
                        cin >> character[index - 1][1];
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
                        cout << i + 1 << ". Nama: " << character[i][0] << "\n   Bounty: " << character[i][1] << endl;
                    }
                    cout << "Masukkan Nomor Data Yang Ingin Dihapus: ";
                    cin >> index;
                    if (index > 0 && index <= elemen) {
                        for (int i = index - 1; i < elemen - 1; i++) {
                            character[i][0] = character[i + 1][0];
                            character[i][1] = character[i + 1][1];
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