#include <iostream>
using namespace std;

// struct Tanggal{
//     int hari;
//     int bulan;
//     int tahun;
// };

// struct Mahasiswa{
//     string nama;
//     int nim;
//     string gender;
//     Tanggal tanggalLahir;
// };

// int main() {

    // Mahasiswa mhsbaru;
    // Mahasiswa mhslama;

    // mhsbaru.nama = "Rangga";
    // mhsbaru.nim = 43;
    // mhsbaru.gender = "Lakik";
    // mhsbaru.tanggalLahir.hari = 3;
    // mhsbaru.tanggalLahir.bulan = 3;
    // mhsbaru.tanggalLahir.tahun = 2005;

    // cout << mhsbaru.nama << endl;
    // cout << mhsbaru.nim << endl;
    // cout << mhsbaru.gender << endl; 
    // cout << "Tanggal Lahir: " << mhsbaru.tanggalLahir.hari << "/" << mhsbaru.tanggalLahir.bulan << "/" << mhsbaru.tanggalLahir.tahun << endl;

    // Mahasiswa mhsAbadi [5];
    // mhsAbadi[0].nama = "Rangdit";
    // mhsAbadi[1].nama = "Ranglaw";
    // mhsAbadi[2].nama = "Jidan";
    // mhsAbadi[3].nama = "Ridho";

    // for (int i = 0; i < size(mhsAbadi); i++){
    //     cout << mhsAbadi[i].nama << endl;
    // }

//     return 0;
// }



int main()
{

    // batas maksimal panjang array
    const int max = 100;

    string buah[max][2]; // Array 2 dimensi untuk menyimpan nama dan warna buah
    int panjang_sekarang = 0;
    int pilihan, index;

    do
    {
        cout << "MENU" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Ubah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Tampilkan Data" << endl;
        cout << "5. Keluar" << endl;

        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        system("clear || cls");

        switch (pilihan)
        {
        case 1:
            if (panjang_sekarang < max)
            {
                cout << "Masukkan nama buah: ";
                getline(cin, buah[panjang_sekarang][0]);
                cout << "Masukkan warna buah: ";
                getline(cin, buah[panjang_sekarang][1]);
                panjang_sekarang++;

                system("clear || cls");
                cout << "Data buah berhasil ditambahkan" << endl;
            }
            else
            {
                cout << "Data buah sudah penuh" << endl;
            }
            break;
        case 2:
            if (panjang_sekarang > 0)
            {
                cout << "Data Buah" << endl;
                for (int i = 0; i < panjang_sekarang; i++)
                {
                    cout << i + 1 << ". " << buah[i][0] << " - " << buah[i][1] << endl;
                }
                cout << "====================" << endl;
                cout << "Pilih index data yang akan diubah: ";
                cin >> index;
                cin.ignore();

                if (index > 0 && index <= panjang_sekarang)
                {
                    cout << "Masukkan nama baru: ";
                    getline(cin, buah[index - 1][0]);
                    cout << "Masukkan warna baru: ";
                    getline(cin, buah[index - 1][1]);

                    system("clear || cls");
                    cout << "Data buah berhasil diedit" << endl;
                }
                else
                {
                    cout << "Index tidak valid" << endl;
                }
            }
            else
            {
                cout << "Data buah masih kosong" << endl;
            }
            break;
        case 3:
            if (panjang_sekarang > 0)
            {
                cout << "Data Buah" << endl;
                for (int i = 0; i < panjang_sekarang; i++)
                {
                    cout << i + 1 << ". " << buah[i][0] << " - " << buah[i][1] << endl;
                }
                cout << "====================" << endl;
                cout << "Pilih index data yang akan dihapus: ";
                cin >> index;
                cin.ignore();
                system("clear || cls");

                if (index > 0 && index <= panjang_sekarang)
                {
                    for (int i = index - 1; i < panjang_sekarang - 1; i++)
                    {
                        buah[i][0] = buah[i + 1][0];
                        buah[i][1] = buah[i + 1][1];
                    }
                    panjang_sekarang--;
                    cout << "Data buah berhasil dihapus" << endl;
                }
                else
                {
                    cout << "Index tidak valid" << endl;
                }
            }
            else
            {
                cout << "Data buah masih kosong" << endl;
            }
            break;
        case 4:
            if (panjang_sekarang > 0)
            {
                cout << "Data Buah" << endl;
                for (int i = 0; i < panjang_sekarang; i++)
                {
                    cout << i + 1 << ". " << buah[i][0] << " - " << buah[i][1] << endl;
                }
            }
            else
            {
                cout << "Data buah masih kosong" << endl;
            }
            break;
        case 5:
            cout << "Keluar" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}