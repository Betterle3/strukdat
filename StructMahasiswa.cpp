#include <iostream>
#include <string>

using namespace std;

const int MAX_DATA = 100;
struct Mahasiswa {
    string nama;
    string nrp;
    int umur;
    string asal;
};

void menuAwal() {
    cout << "Menu:" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Ubah Data" << endl;
    cout << "4. Lihat Data" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu (1/2/3/4/5): ";
}

int tambahData(Mahasiswa* data, int jumlahData) {
    if (jumlahData < MAX_DATA) {
        Mahasiswa dataBaru;
        cout << "Masukkan Nama: ";
        cin >> dataBaru.nama;
        cout << "Masukkan NRP (3 digit akhir): ";
        cin >> dataBaru.nrp;
        cout << "Masukkan Umur: ";
        cin >> dataBaru.umur;
        cout << "Masukkan Asal: ";
        cin >> dataBaru.asal;

        data[jumlahData] = dataBaru;
        jumlahData++;

        cout << "Data berhasil disimpan!" << endl;
    } else {
        cout << "Data sudah penuh." << endl;
    }
    return jumlahData;
}

int hapusData(Mahasiswa* data, int jumlahData, string nrpHapus) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nrp == nrpHapus) {
            data[i] = data[jumlahData - 1];
            jumlahData--;
            ditemukan = true;
            cout << "Data berhasil dihapus!" << endl;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
    return jumlahData;
}

void ubahData(Mahasiswa* data, int jumlahData, string nrpUbah) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nrp == nrpUbah) {
            cout << "Masukkan Nama Baru: ";
            cin >> data[i].nama;
            cout << "Masukkan NRP Baru (3 digit akhir): ";
            cin >> data[i].nrp;
            cout << "Masukkan Umur Baru: ";
            cin >> data[i].umur;
            cout << "Masukkan Asal Baru: ";
            cin >> data[i].asal;
            ditemukan = true;
            cout << "Data berhasil diubah!" << endl;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

void lihatData(const Mahasiswa* data, int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data yang tersedia." << endl;
    } else {
        cout << "Daftar Data:" << endl;
        for (int i = 0; i < jumlahData; ++i) {
            cout << "Nama: " << data[i].nama << endl;
            cout << "NRP: " << data[i].nrp << endl;
            cout << "Umur: " << data[i].umur << endl;
            cout << "Asal: " << data[i].asal << endl;
            cout << "-------------------------" << endl;
        }
    }
}

int main() {
    Mahasiswa data[MAX_DATA];
    int jumlahData = 0;

    int pilihan;
    do {
        menuAwal();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                jumlahData = tambahData(data, jumlahData);
                break;
            }
            case 2: {
                string nrpHapus;
                cout << "Masukkan NRP (3 digit akhir) yang akan dihapus: ";
                cin >> nrpHapus;
                jumlahData = hapusData(data, jumlahData, nrpHapus);
                break;
            }
            case 3: {
                string nrpUbah;
                cout << "Masukkan NRP (3 digit akhir) yang akan diubah: ";
                cin >> nrpUbah;
                ubahData(data, jumlahData, nrpUbah);
                break;
            }
            case 4: {
                lihatData(data, jumlahData);
                break;
            }
            case 5: {
                cout << "Terima kasih!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    } while (pilihan != 5);

    return 0;
}
