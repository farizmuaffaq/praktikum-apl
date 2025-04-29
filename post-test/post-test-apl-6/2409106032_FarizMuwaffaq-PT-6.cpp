#include <iostream>
using namespace std;
#define MAXChar 100

struct Character {
    string nama[MAXChar];
    int bounty[MAXChar];
    int elemen = 0;
};

bool login(string UnBenar, string PwBenar) {
    string usernamelogin, passwordlogin;
    int percobaan = 3;
    while (percobaan > 0) {
        cout << "Masukkan Username: ";
        cin >> usernamelogin;
        cout << "Masukkan Password: ";
        cin >> passwordlogin;
        if (usernamelogin == UnBenar && passwordlogin == PwBenar) {
            cout << "Login berhasil" << endl;
            return true;
        } else {
            percobaan--;
            if (percobaan > 0)
                cout << "Username Atau Password Salah, Silahkan Coba Lagi" << endl;
            else {
                cout << "Anda Telah Mencoba Login Sebanyak 3 Kali, Program Akan Dihentikan" << endl;
                return false;
            }
        }
    }
    return false;
}

void tampilkanData(Character *karakter) {
    if (karakter->elemen == 0) {
        cout << "Belum Ada Data Yang Ditambahkan" << endl;
    } else {
        cout << "Daftar Karakter" << endl;
        for (int i = 0; i < karakter->elemen; i++) {
            cout << i + 1 << ". Nama: " << karakter->nama[i]
                 << "\n   Bounty: " << karakter->bounty[i] << endl;
        }
    }
}

void tambahData(Character &karakter) {
    if (karakter.elemen < MAXChar) {
        cout << "Tambahkan Nama Karakter: ";
        cin >> karakter.nama[karakter.elemen];
        cout << "Berikan Bounty Karakter(Masukkan Dalam Bentuk Angka!): ";
        cin >> karakter.bounty[karakter.elemen];
        karakter.elemen++;
        cout << "Karakter Berhasil Ditambahkan" << endl;
    } else {
        cout << "Kapasitas Penuh! Tidak Dapat Menambah Data." << endl;
    }
}

void ubahData(Character &karakter) {
    if (karakter.elemen == 0) {
        cout << "Belum Ada Data Yang Ditambahkan." << endl;
        return;
    }
    tampilkanData(&karakter);
    int index;
    cout << "Masukkan Nomor Data Yang Ingin Diubah: ";
    cin >> index;
    if (index > 0 && index <= karakter.elemen) {
        cout << "Masukkan Nama Baru: ";
        cin >> karakter.nama[index - 1];
        cout << "Masukkan Bounty Baru(Masukkan Dalam Bentuk Angka!): ";
        cin >> karakter.bounty[index - 1];
        cout << "Data Telah Berhasil Dirubah" << endl;
    } else {
        cout << "Nomor Data Tidak Valid" << endl;
    }
}

void hapusData(Character &karakter) {
    if (karakter.elemen == 0) {
        cout << "Belum Ada Data Yang Ditambahkan" << endl;
        return;
    }
    tampilkanData(&karakter);
    int index;
    cout << "Masukkan Nomor Data Yang Ingin Dihapus: ";
    cin >> index;
    if (index > 0 && index <= karakter.elemen) {
        for (int i = index - 1; i < karakter.elemen - 1; i++) {
            karakter.nama[i] = karakter.nama[i + 1];
            karakter.bounty[i] = karakter.bounty[i + 1];
        }
        karakter.elemen--;
        cout << "Data Telah Dihapus" << endl;
    } else {
        cout << "Nomor Data Tidak Valid" << endl;
    }
}

void bubbleSortDesc(int bounty[], string nama[], int panjang)
{
    int n = panjang;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (nama[j] < nama[j + 1])
            {
                string tempNama = nama[j];
                nama[j] = nama[j + 1];
                nama[j + 1] = tempNama;

                int tempBounty = bounty[j];
                bounty[j] = bounty[j + 1];
                bounty[j + 1] = tempBounty;
            }
        }
    }
    cout << "Data Berhasil Di Urutkan" << endl;
}

void selectionSortAsc(int bounty[], string nama[], int panjang)
{
    for (int i = 0; i < panjang - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < panjang; j++)
        {
            if (bounty[j] < bounty[min])
            {
                min = j;
            }
        }
        int tempBounty = bounty[i];
        bounty[i] = bounty[min];
        bounty[min] = tempBounty;

        string tempNama = nama[i];
        nama[i] = nama[min];
        nama[min] = tempNama;
    }
    cout << "Data Berhasil Di Urutkan" << endl;
}

void insertionSortDesc(int bounty[], string nama[], int panjang)
{
    for (int i = 1; i < panjang; i++)
    {
        int keyBounty = bounty[i];
        string keyNama = nama[i];
        int j = i - 1;

        while (j >= 0 && bounty[j] < keyBounty)
        {
            bounty[j + 1] = bounty[j];
            nama[j + 1] = nama[j];
            j--;
        }

        bounty[j + 1] = keyBounty;
        nama[j + 1] = keyNama;
    }
    cout << "Data Berhasil Di Urutkan" << endl;
}

int main() {
    string username = "Fariz";
    string password = "032";
    Character karakter;
    int pilihan;

    cout << "Selamat Datang Di One Piece Pirate List\nSilahkan Login Terlebih Dahulu\n";

    if (!login(username, password)) {
        return 0;
    }
    do {
        cout << R"(
============================
Pilihan Menu :
1. Tampilkan Semua Data
2. Tambahkan Data
3. Ubah Data
4. Hapus Data
5. Urutkan Data
6. Keluar Program
============================
)" << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: tampilkanData(&karakter); break;
            case 2: tambahData(karakter); break;
            case 3: ubahData(karakter); break;
            case 4: hapusData(karakter); break;
            case 5:
                if (karakter.elemen == 0) 
                {
                    cout << "Belum Ada Data Yang Ditambahkan" << endl;
                    break;
                }
                int PilihanSort;
                    cout << R"(
============================
Pilihan Sorting :
1. Urutkan Nama Descending
2. Urutkan Bounty Ascending 
3. Urutkan Bounty Descending
4. Kembali Ke Menu Utama
============================
)";
                    cout << "Masukkan Pilihan Anda: ";
                    cin >> PilihanSort;
                    switch (PilihanSort)
                    {
                        case 1:
                            bubbleSortDesc(karakter.bounty, karakter.nama, karakter.elemen);
                            break;
                        case 2:
                            selectionSortAsc(karakter.bounty, karakter.nama, karakter.elemen);
                            break;
                        case 3:
                            insertionSortDesc(karakter.bounty, karakter.nama, karakter.elemen);
                            break;
                        default:
                            cout << "Pilihan Tidak Valid" << endl;
                            break;
                    }
                break;
            case 6:
                cout << "Terimakasih Telah Menggunakan One Piece Pirate List. Program Akan Dihentikan." << endl;
                break;
            default:
                cout << "Pilihan Tidak Valid" << endl;
                break;
        }
    } while (pilihan != 6);
    return 0;
}