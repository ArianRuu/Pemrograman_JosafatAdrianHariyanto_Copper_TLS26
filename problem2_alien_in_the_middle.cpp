#include <iostream>
using namespace std;

const int MAKS = 1000;

int panjang(const char s[]) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    return n;
}

int nilai(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return c - 'A' + 1;
}

char hurufDariNilai(int v) {
    return (char)('A' + v - 1);
}

int geser(int a, int b) {
    return ((a + b - 1) % 26) + 1;
}

int kurang(int a, int b) {
    return ((a - b + 26 - 1) % 26) + 1;
}

int main() {
    int mode;
    char pesan[MAKS];
    char hasil[MAKS];

    cout << "Mode (1 = enkripsi, selain 1 = dekripsi): ";
    cin >> mode;
    cout << "Pesan: ";
    cin >> pesan;

    int n = panjang(pesan);

    hasil[0] = pesan[0];    
    int i = 1;
    while (i < n) {
        int v;
        if (mode == 1) {

            int prev = nilai(pesan[i - 1]);
            v = geser(nilai(pesan[i]), prev);
        } else {

            int prev = nilai(hasil[i - 1]);
            v = kurang(nilai(pesan[i]), prev);
        }
        hasil[i] = hurufDariNilai(v);
        i = i + 1;
    }
    hasil[n] = '\0';

    cout << "Hasil: " << hasil << endl;
    return 0;
}
