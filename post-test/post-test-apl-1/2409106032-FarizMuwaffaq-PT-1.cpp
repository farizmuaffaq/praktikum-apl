#include <iostream>
using namespace std;

int main(){
    int percobaan;
    percobaan = 3;
    string usernamelogin, passwordlogin;
    string username = "Fariz";
    string password = "032";

    cout << "Selamat datang di program konversi suhu" << endl;
    cout << "Silahkan login terlebih dahulu" << endl;

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
                cout << "Username atau Password salah, silahkan coba lagi" << endl;
            } else {
                cout << "Anda telah mencoba login sebanyak 3 kali, program akan dihentikan" << endl;
                return 0;} 
            }
    }
    double Celcius, Fahrenheit, Reamur, Kelvin;
    int pilihan;

    while(true){
        cout<<R"(
Menu pilihan Konversi Suhu:
1. Celcius ke Fahrenheit, Reamur, dan Kelvin
2. Fahrenheit ke Celcius, Reamur, dan Kelvin
3. Reamur ke Celcius, Fahrenheit, dan Kelvin
4. Kelvin ke Celcius, Fahrenheit, dan Reamur
5. Keluar program)"<<endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilihan; 
        
        if (pilihan == 1){
            cout << "Masukkan nilai Celcius: ";
            cin >> Celcius;
            Fahrenheit = (Celcius * 9/5) + 32;
            Reamur = Celcius * 4/5;
            Kelvin = Celcius + 273.15;
            cout << "- Celcius ke Fahrenheit = " << Fahrenheit << endl;
            cout << "- Celcius ke Reamur = " << Reamur << endl;
            cout << "- Celcius ke Kelvin = " << Kelvin << endl;
        } else if (pilihan == 2){
            cout << "Masukkan nilai Fahrenheit: ";
            cin >> Fahrenheit;
            Celcius = (Fahrenheit - 32) * 5/9;
            Reamur = (Fahrenheit - 32) * 4/9;
            Kelvin = (Fahrenheit - 32) * 5/9 + 273.15;
            cout << "- Fahrenheit ke Celcius = " << Celcius << endl;
            cout << "- Fahrenheit ke Reamur = " << Reamur << endl;
            cout << "- Fahrenheit ke Kelvin = " << Kelvin << endl;
        } else if (pilihan == 3){
            cout << "Masukkan nilai Reamur: ";
            cin >> Reamur;
            Celcius = Reamur * 5/4;
            Fahrenheit = Reamur * 9/4 + 32;
            Kelvin = Reamur * 5/4 + 273.15;
            cout << "- Reamur ke Celcius = " << Celcius << endl;
            cout << "- Reamur ke Fahrenheit = " << Fahrenheit << endl;
            cout << "- Reamur ke Kelvin = " << Kelvin << endl;
        } else if (pilihan == 4){
            cout << "Masukkan nilai Kelvin: ";
            cin >> Kelvin;
            Celcius = Kelvin - 273.15;
            Fahrenheit = (Kelvin - 273.15) * 9/5 + 32;
            Reamur = (Kelvin - 273.15) * 4/5;
            cout << "- Kelvin ke Celcius = " << Celcius << endl;
            cout << "- Kelvin ke Fahrenheit = " << Fahrenheit << endl;
            cout << "- Kelvin ke Reamur = " << Reamur << endl;
        } else if (pilihan == 5){
            cout << "Program akan dihentikan." << endl;
            return 0;
        } else {
            cout << "Pilihan tidak valid, silahkan coba lagi" << endl;
        }
}
}
