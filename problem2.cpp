#include <iostream> 
#include <string>

using namespace std;

int main () {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string Human_words;
    string Encrypted_messages = "";
    int value_current = 0;
    int value_prev = 0;
    int shift_value = 0;

    cout << "Masukkan Pesan Asli: ";
    cin >> Human_words;

    for (char Char : Human_words) {
        // Mengubah huruf kecil ke huruf besar jika input berupa huruf kecil
        if (Char >= 'a' && Char <= 'z') {
            Char = Char - 32;
        }

        // Mencari posisi huruf di dalam variabel alphabet
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] == Char) {
                value_current = i + 1;
                break;
            }
        }
        
        // Menghitung pergeseran nilai
        shift_value = value_current + value_prev;
        if (shift_value > 26) {
            shift_value = shift_value - 26;
        }
        
        char new_Char = alphabet[shift_value - 1];
        Encrypted_messages += new_Char;
        value_prev = value_current;
    }

    cout << "Pesan Sandi Alien: " << Encrypted_messages << endl;
    return 0;
}