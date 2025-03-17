#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int number[3] = {1, 2, 4};

    for (int i = 1; i < 3; i++)
    {
        number[i] = number[i + 1];
    }    
    for(int i : number)
    {
        cout << "Nilai array : " << i << endl;
    }
    for(auto i = 0; i < 2; i++)
    {
        cout << "Nilai array : " << i << endl;
    }

    // number[1] = 5;
    // for (int i : number)
    // {
    //     cout << "Nilai array : " << i << endl;
    // }

    // for (int i : number)
    // {
    //     cout << "Nilai array : " << i << endl;
    // }
    // number[2] = 10;
    // for (int i : number)
    // {
    //     cout << "- Nilai array : " << i << endl;
    // }

    // int totalByte = sizeof(number);
    // int panjangArray = sizeof(number) / sizeof(number[0]);
    // for (int i = 0; i < panjangArray; i++)
    // {
    //     cout << "Nilai array : " << number[i] << endl;
    // }

    // for (int i : number)
    // {
    //     cout << "Nilai array : " << number << endl;
    // }

    // int totalByte = sizeof(number);
    // int singleByte = sizeof(number[0]);
    // int panjangArray = sizeof(number)/sizeof(number[0]);
    // int panjangArray2 = size(number);
    // cout << totalByte << "\n"
    //      << singleByte << "\n"
    //      << panjangArray;

    return 0;

}