// Membuat sistem showroom mobil dengan autoid setiap data mobil ditambahkan
#include <iostream>
using namespace std;

//struktur showroom (autoid, merk, nama, tahun, harga)
struct showroom
{
    int autoid;
    string merk;
    string nama;
    int tahun;
    long long harga;
};


// void fungsi menambahkan data mobil
void tambahData(showroom mobil[], int &totalMobil, int &autoid){
    showroom mobilBaru;
    mobilBaru.autoid = autoid++;
    cout << "Masukkan merk mobil : ";
    getline(cin >> ws , mobilBaru.merk);
    cout << "Masukkan nama mobil : ";
    getline(cin >> ws , mobilBaru.nama);
    cout << "Masukkan tahun mobil : ";
    cin >> mobilBaru.tahun;
    cout << "Masukkan harga mobil : ";
    cin >> mobilBaru.harga;
    cin.ignore();
    mobil[totalMobil++] = mobilBaru;
    cout << "Data mobil berhasil ditambahkan ID : " << mobilBaru.autoid << endl;
}


// void fungsi melihat semua data mobil
void lihatData(showroom mobil[], int totalMobil){
    if(totalMobil == 0){
        cout << "DATA MOBIL KOSONG!!" << endl;
        return;
    }
    cout << "Daftar mobil di showroom : " << endl;
    for (int i = 0; i < totalMobil; i++)
    {
        cout << "------------------------" << endl;
        cout << "ID : " << mobil[i].autoid << endl;
        cout << "Merk : " << mobil[i].merk << endl;
        cout << "NAMA : " << mobil[i].nama << endl;
        cout << "TAHUN : " << mobil[i].tahun << endl;
        cout << "HARGA : " << mobil[i].harga << endl;
        cout << "------------------------" << endl;
    }
    
}

// void fungsi menghapus data mobil berdasarkan id
void hapusData(showroom mobil[], int &totalMobil){
    if (totalMobil == 0)
    {
        cout << "DATA MOBIL KOSONG TIDAK BISA DIHAPUS" << endl;
        return;
    }
    int idhapus;
    cout << "MASUKKAN ID MOBIL YANG INGIN DIHAPUS : ";
    cin >> idhapus;

    for (int i = 0; i < totalMobil; i++)
    {
        if(mobil[i].autoid == idhapus){
            for (int j = i; j < totalMobil - 1; j++)
            { mobil[j] = mobil[j + 1]; }
            {totalMobil--;
            cout << "DATA MOBIL BERHASIL DIHAPUS" << endl;
        return;
    }
            
        }
    }
    
}

// int main
int main(){
    showroom mobil[50];
    int totalMobil = 0;
    int autoid = 1;
    int pilihan;

    do
    {
        cout << "===SISTEM SHOWROOM MOBIL ===" << endl;
        cout << "1. Tambah data mobil " << endl;
        cout << "2. Lihat data mobil " << endl;
        cout << "3. Hapus data mobil " << endl;
        cout << "4. Keluar " << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;
        
        switch (pilihan)
        {
        case 1:
            tambahData(mobil,totalMobil,autoid);
            break;
           case 2:
            lihatData(mobil,totalMobil);
            break;
           case 3:
            hapusData(mobil,totalMobil);
            break;
            case 4:
            cout << "TERIMAKASIH !! SELAMAT TINGGAL!." << endl;
            break;
        default:
        cout << "INPUT TIDAK VALID, 1,2,3,4 SAJA" << endl;
            break;
        }

    } while (pilihan != 4);
    return 0;
}

