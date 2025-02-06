#include <iostream>
#include <map>

using namespace std;

// Struktur untuk menyimpan data pengguna
struct User {
    string pin;
    double balance;
};

// Database akun (key: nomor rekening, value: User)
map<string, User> accounts;

// Fungsi untuk registrasi akun baru
void registerAccount() {
    string accountNumber, pin;
    cout << "=== REGISTRASI AKUN ===\n";
    cout << "Masukkan nomor rekening: ";
    cin >> accountNumber;

    // Cek apakah rekening sudah terdaftar
    if (accounts.find(accountNumber) != accounts.end()) {
        cout << "Nomor rekening sudah terdaftar!\n";
        return;
    }

    cout << "Masukkan PIN: ";
    cin >> pin;

    // Simpan akun baru
    accounts[accountNumber] = {pin, 0.0};
    cout << "Registrasi berhasil! Silakan login.\n";
}

// Fungsi untuk login
bool login(string &accountNumber) {
    string pin;
    cout << "=== LOGIN ===\n";
    cout << "Masukkan nomor rekening: ";
    cin >> accountNumber;

    // Cek apakah rekening terdaftar
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Rekening tidak ditemukan!\n";
        return false;
    }

    cout << "Masukkan PIN: ";
    cin >> pin;

    // Cek PIN
    if (accounts[accountNumber].pin != pin) {
        cout << "PIN salah!\n";
        return false;
    }

    cout << "Login berhasil!\n";
    return true;
}

// Fungsi untuk menyetor uang
void deposit(string accountNumber) {
    double amount;
    cout << "Masukkan jumlah setoran: ";
    cin >> amount;

    if (amount > 0) {
        accounts[accountNumber].balance += amount;
        cout << "Setoran berhasil! Saldo saat ini: Rp" << accounts[accountNumber].balance << endl;
    } else {
        cout << "Jumlah tidak valid!\n";
    }
}

// Fungsi untuk menarik uang
void withdraw(string accountNumber) {
    double amount;
    cout << "Masukkan jumlah penarikan: ";
    cin >> amount;

    if (amount > 0 && amount <= accounts[accountNumber].balance) {
        accounts[accountNumber].balance -= amount;
        cout << "Penarikan berhasil! Saldo saat ini: Rp" << accounts[accountNumber].balance << endl;
    } else {
        cout << "Saldo tidak mencukupi atau jumlah tidak valid!\n";
    }
}

// Fungsi untuk mengecek saldo
void checkBalance(string accountNumber) {
    cout << "Saldo Anda: Rp" << accounts[accountNumber].balance << endl;
}

// Fungsi utama (Main Menu)
int main() {
    int choice;
    string currentAccount;

    do {
        cout << "\n=== SISTEM BANK SEDERHANA ===\n";
        cout << "1. Registrasi Akun\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerAccount();
                break;
            case 2:
                if (login(currentAccount)) {
                    int subChoice;
                    do {
                        cout << "\n=== MENU TRANSAKSI ===\n";
                        cout << "1. Setor Uang\n";
                        cout << "2. Tarik Uang\n";
                        cout << "3. Cek Saldo\n";
                        cout << "4. Logout\n";
                        cout << "Pilihan: ";
                        cin >> subChoice;

                        switch (subChoice) {
                            case 1:
                                deposit(currentAccount);
                                break;
                            case 2:
                                withdraw(currentAccount);
                                break;
                            case 3:
                                checkBalance(currentAccount);
                                break;
                            case 4:
                                cout << "Logout berhasil!\n";
                                break;
                            default:
                                cout << "Pilihan tidak valid!\n";
                        }
                    } while (subChoice != 4);
                }
                break;
            case 3:
                cout << "Terima kasih telah menggunakan sistem bank kami!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 3);

    return 0;
}