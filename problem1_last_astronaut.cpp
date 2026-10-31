#include <iostream>
using namespace std;

void hapusElemen(int circle[], int size, int idx) {
    for (int i = idx; i <= size - 2; i++) {
        circle[i] = circle[i + 1];
    }
}

int updateK(int K, int out) {
    if (out % 2 == 0) {
        K = K + 2;     
    } else {
        K = K - 1;      
    }
    if (K < 2) {
        K = 2;          
    }
    return K;
}

int main() {
    int N, K;
    cout << "Masukkan N dan K: ";
    cin >> N >> K;

    if (N < 1) {
        cout << "N harus minimal 1" << endl;
        return 0;
    }

    int *circle = new int[N];
    for (int i = 0; i < N; i++) {
        circle[i] = i + 1;
    }

    int size = N;
    int pos = 0;    

    cout << "Urutan eliminasi:";
    while (size > 1) {
        int idx = (pos + K - 1) % size;  
        int out = circle[idx];
        cout << " " << out;             

        hapusElemen(circle, size, idx);
        size = size - 1;

        pos = idx;
        if (pos == size) {
            pos = 0;                     
        }

        K = updateK(K, out);
    }
    cout << endl;

    cout << "Astronot terakhir: " << circle[0] << endl;

    delete[] circle;
    return 0;
}
