#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    // Inisialisasi daftar astronot dari 1 sampai N
    vector<int> astronot;
    for (int i = 1; i <= N; i++) {
        astronot.push_back(i);
    }

    vector<int> urutan_eliminasi;
    int indeks_saat_ini = 0;

    // Simulasi perulangan hingga tersisa 1 astronot
    while (astronot.size() > 1) {
        // Menghitung posisi astronot yang tereliminasi menggunakan operasi modulo
        indeks_saat_ini = (indeks_saat_ini + K - 1) % astronot.size();
        
        int astronot_keluar = astronot[indeks_saat_ini];
        urutan_eliminasi.push_back(astronot_keluar);

        // Menghapus astronot dari barisan
        astronot.erase(astronot.begin() + indeks_saat_ini);

        // Memperbarui nilai K berdasarkan paritas astronot yang keluar
        if (astronot_keluar % 2 == 0) {
            K += 2; // Jika genap, K ditambah 2
        } else {
            K -= 1; // Jika ganjil, K dikurangi 1
        }

        // Batas minimal nilai K adalah 2
        if (K < 2) {
            K = 2;
        }
    }

    // Menampilkan output urutan eliminasi dan astronot terakhir
    cout << "\nUrutan astronot tereliminasi: ";
    for (int i = 0; i < urutan_eliminasi.size(); i++) {
        cout << urutan_eliminasi[i] << " ";
    }
    cout << "\nAstronot terakhir yang tersisa: " << astronot[0] << endl;

    return 0;
}
